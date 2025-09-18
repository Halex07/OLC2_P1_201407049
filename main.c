#include <stdio.h>
#include <stdlib.h>
#include "entorno/ast.h"
#include "ast/AbstractTerminal.h"
#include "entorno/environment.h"
#include "ast/sentencias/declaration.h"
#include "ast/sentencias/function.h"
#include "ast/sentencias/block.h"
#include "ast/expresiones/operacion.h"
#include "ast/expresiones/primitivos.h"
#include "ast/expresiones/callFunc.h"



/* del parser */
int yyparse(void);
extern FILE *yyin;

/* arreglo global de instrucciones construido por el parser */
extern struct NodoBase *g_root;

// =========================  archivo dot ===============================
static int nodo_counter = 0;

// --- Función auxiliar: devuelve lista de hijos de un nodo ---
static int get_children(NodoBase *node, NodoBase **out_children, int max_children) {
    int count = 0;

    if (!node) return 0;

    if (strstr(node->nombre, "Operation")) {
        Operation *op = (Operation *)node;
        if (op->izq && count < max_children) out_children[count++] = op->izq;
        if (op->der && count < max_children) out_children[count++] = op->der;
    }
    else if (strstr(node->nombre, "Block")) {
        Block *block = (Block *)node;
        StmtCell *cur = block->head;
        while (cur && count < max_children) {
            out_children[count++] = cur->stmt;
            cur = cur->next;
        }
    }
    else if (strstr(node->nombre, "Function")) {
        Function *func = (Function *)node;
        Param *cur = func->params;
        while (cur && count < max_children) {
            out_children[count++] = (NodoBase *)cur;
            cur = cur->next;
        }
        if (func->body && count < max_children) out_children[count++] = func->body;
    }
    else if (strstr(node->nombre, "Declaration")) {
        Declaration *decl = (Declaration *)node;
        if (decl->expr && count < max_children) out_children[count++] = decl->expr;
    }
    else if (strstr(node->nombre, "CallFunc")) {
        CallFunc *call = (CallFunc *)node;
        ArgList *arg = call->args;
        while (arg && count < max_children) {
            if (arg->expr) out_children[count++] = arg->expr;
            arg = arg->next;
        }
    }

    return count;
}

// --- Imprimir un nodo y recorrer hijos ---
static void print_dot_nodes(FILE *out, NodoBase *node, int parent_id) {
    if (!node) return;

    int current_id = nodo_counter++;
    fprintf(out, "  node_%d [label=\"%s\\n[%d:%d]\"];\n",
            current_id, node->nombre, node->lin, node->col);

    if (parent_id >= 0) {
        fprintf(out, "  node_%d -> node_%d;\n", parent_id, current_id);
    }

    // recorrer hijos dinámicamente
    NodoBase *children[32];  // soporte hasta 32 hijos
    int n = get_children(node, children, 32);
    for (int i = 0; i < n; i++) {
        print_dot_nodes(out, children[i], current_id);
    }
}

// --- Función pública ---
void generate_ast_graphviz(NodoBase *root, const char *filename) {
    if (!root) return;

    FILE *out = fopen(filename, "w");
    if (!out) {
        perror("No se pudo abrir archivo .dot");
        return;
    }

    fprintf(out, "digraph AST {\n");
    fprintf(out, "rankdir=TB;\n");
    fprintf(out, "node [shape=ellipse, style=filled, fontname=\"Arial\"];\n");

    nodo_counter = 0;
    print_dot_nodes(out, root, -1);

    fprintf(out, "}\n");
    fclose(out);
}
int main(int argc, char **argv)
{
    /* abrir archivo o stdin */
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (!yyin)
        {
            perror("archivo");
            return 1;
        }
    }
    else
    {
        yyin = stdin;
    }

    /* parsear: llena g_code con instrucciones */
    if (yyparse() != 0)
    {
        fprintf(stderr, "Fallo en el parseo\n");
        if (yyin != stdin)
            fclose(yyin);
        return 1;
    }
    if (yyin != stdin)
        fclose(yyin);

    /* ejecutar: recorrer instrucciones */
    AST ast;
    AST_Init(&ast);
    Environment global;
    Env_init(&global, NULL, "GLOBAL");
    if (g_root)
        (void)NodoBase_Ejecutar(g_root, &ast, &global);

    /* imprimir salida o errores */
    if (ast.errors[0])
    {
        fputs(ast.prints, stdout);
        fputs(ast.errors, stderr);
    }
    else
    {
        fputs(ast.prints, stdout);
    }

    if (g_root)
    {
        generate_ast_graphviz(g_root, "ast.dot");
        system("dot -Tpng ast.dot -o ast.png");
    }

    /* liberar nodos (cada uno tiene el metodo para destruirse) */
    if (g_root)
        NodoBase_Destruir(g_root);
    Env_free(&global);

    return 0;
}