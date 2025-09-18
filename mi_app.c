#include <gtk/gtk.h>
#include <stdlib.h>
#include <unistd.h>

#define COMPILER_CMD "./build/calc"  // Ruta al binario

typedef struct {
    GtkWidget *win;
    GtkTextBuffer *in_buf, *out_buf;
} App;

// --- Funciones auxiliares ---
static void set_output(App *app, const char *txt){
    gtk_text_buffer_set_text(app->out_buf, txt ? txt : "", -1);
}

static char* get_input(App *app){
    GtkTextIter a, b;
    gtk_text_buffer_get_bounds(app->in_buf, &a, &b);
    return gtk_text_buffer_get_text(app->in_buf, &a, &b, FALSE); // g_free luego
}

// --- Ventana AST ---
void on_ast_button_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget;
    GtkWidget *parent_window = GTK_WIDGET(data);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "AST");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_transient_for(GTK_WINDOW(window), GTK_WINDOW(parent_window));

    GtkWidget *image = gtk_image_new_from_file("ast.png");
    gtk_container_add(GTK_CONTAINER(window), image);

    gtk_widget_show_all(window);
}

// --- Ventana Tabla de Símbolos ---
void simbolo(GtkWidget *parent) {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tabla de Símbolos");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 200);
    gtk_window_set_transient_for(GTK_WINDOW(window), GTK_WINDOW(parent));

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_set_border_width(GTK_CONTAINER(grid), 10);

    // Cabecera
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("ID"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tipo"), 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Valor"), 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Fila"), 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Columna"), 4, 0, 1, 1);

    // Datos "quemados"
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("1"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("variable"), 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("hola"), 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("13"), 3, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("2"), 4, 1, 1, 1);

    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_widget_show_all(window);
}

// --- Callback Botón Tabla Símbolos ---
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *parent_window = GTK_WIDGET(data);
    simbolo(parent_window);
}

// --- Botón Ejecutar ---
static void on_run(GtkButton *btn, gpointer u){
    (void)btn;
    App *app = u;

    char *code = get_input(app);
    gchar *tmp_path = NULL;
    GError *err = NULL;

    int fd = g_file_open_tmp("temporal-XXXXXX.txt", &tmp_path, &err);
    if (fd == -1){
        set_output(app, err ? err->message : "Error al crear tmp");
        if (err) g_error_free(err);
        g_free(code);
        return;
    }
    close(fd);

    if (!g_file_set_contents(tmp_path, code, -1, &err)){
        set_output(app, err ? err->message : "Error al escribir tmp");
        if (err) g_error_free(err);
        g_free(tmp_path);
        g_free(code);
        return;
    }

    gchar *cmd = g_strdup_printf("%s %s 2>&1", COMPILER_CMD, tmp_path);
    gchar *out = NULL;
    gint status = 0;
    GError *spawn_err = NULL;

    gboolean ok = g_spawn_command_line_sync(cmd, &out, NULL, &status, &spawn_err);
    if (!ok){
        set_output(app, spawn_err ? spawn_err->message : "Error al ejecutar");
        if (spawn_err) g_error_free(spawn_err);
    } else {
        set_output(app, (out && *out) ? out : "No hay mensaje de salida");
    }

    if (out) g_free(out);
    unlink(tmp_path);
    g_free(tmp_path);
    g_free(cmd);
    g_free(code);
}

// --- Botón Abrir ---
static void on_open(GtkButton *btn, gpointer u){
    (void)btn;
    App *app = u;

    GtkWidget *dialog = gtk_file_chooser_dialog_new(
        "Abrir archivo",
        GTK_WINDOW(app->win),
        GTK_FILE_CHOOSER_ACTION_OPEN,
        "_Cancelar", GTK_RESPONSE_CANCEL,
        "_Abrir", GTK_RESPONSE_ACCEPT,
        NULL
    );

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT){
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        gchar *contents = NULL;
        gsize len = 0;
        GError *err = NULL;

        if (g_file_get_contents(filename, &contents, &len, &err)){
            gtk_text_buffer_set_text(app->in_buf, contents, len);
            g_free(contents);
        } else {
            set_output(app, err ? err->message : "Error al abrir archivo");
            if (err) g_error_free(err);
        }

        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

// --- Crear ventana principal ---
static void on_activate(GtkApplication *app, gpointer u){
    (void)u;
    App *A = g_new0(App, 1);

    // Ventana
    A->win = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(A->win), "IDE JavaLang");
    gtk_window_set_default_size(GTK_WINDOW(A->win), 900, 600);

    // Caja vertical principal
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(A->win), vbox);

    // Botones
    GtkWidget *hbox_buttons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    GtkWidget *b_open = gtk_button_new_with_label("Abrir");
    GtkWidget *b_run  = gtk_button_new_with_label("Ejecutar");
    GtkWidget *b_ast  = gtk_button_new_with_label("Grafica AST");
    GtkWidget *b_bt   = gtk_button_new_with_label("Tabla Simbolos");
    GtkWidget *b_te   = gtk_button_new_with_label("Tabla Errores");

    gtk_box_pack_start(GTK_BOX(hbox_buttons), b_open, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), b_run,  FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), b_ast,  FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), b_bt,  FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), b_te,  FALSE, FALSE, 0);
    
    gtk_box_pack_start(GTK_BOX(vbox), hbox_buttons, FALSE, FALSE, 0);

    // Entrada de código
    GtkWidget *in_view = gtk_text_view_new();
    A->in_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(in_view));
    GtkWidget *scr_in = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scr_in), in_view);
    gtk_box_pack_start(GTK_BOX(vbox), scr_in, TRUE, TRUE, 0);

    // Salida
    GtkWidget *out_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(out_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(out_view), FALSE);
    A->out_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(out_view));
    GtkWidget *scr_out = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scr_out), out_view);
    gtk_box_pack_start(GTK_BOX(vbox), scr_out, TRUE, TRUE, 0);

    // Conectar señales
    g_signal_connect(b_open, "clicked", G_CALLBACK(on_open), A);
    g_signal_connect(b_run,  "clicked", G_CALLBACK(on_run),  A);
    g_signal_connect(b_bt,   "clicked", G_CALLBACK(on_button_clicked), A->win);
    g_signal_connect(b_ast,  "clicked", G_CALLBACK(on_ast_button_clicked), A->win);  

    gtk_widget_show_all(A->win);
}

// --- main ---
int main(int argc, char **argv){
    GtkApplication *app = gtk_application_new("com.example.minigui", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int st = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return st;
}