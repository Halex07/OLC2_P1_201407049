#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 🧠 Enumeración de tipos de datos
typedef enum {
    ENTERO,
    DECIMAL,
    CADENA,
    CARACTER,
    BOOLEANO,
    VOID
} tipoDato;

// 📦 Estructura de Tipo
typedef struct {
    tipoDato tipo;
} Tipo;

Tipo crearTipo(tipoDato t) {
    Tipo nuevo;
    nuevo.tipo = t;
    return nuevo;
}

// 🧠 Estructura base de Instrucción
typedef struct Instruccion {
    Tipo tipo;
    int linea;
    int columna;
    void* (*interpretar)(struct Instruccion*, void* arbol, void* tabla);
} Instruccion;

// 📚 Estructura de tabla de símbolos
typedef struct tablaSimbolos {
    struct tablaSimbolos* padre;
} tablaSimbolos;

tablaSimbolos* crearTablaSimbolos(tablaSimbolos* padre) {
    tablaSimbolos* nueva = malloc(sizeof(tablaSimbolos));
    if (!nueva) return NULL;
    nueva->padre = padre;
    return nueva;
}

// ⚠️ Estructura de error
typedef struct {
    char* tipo;
    char* mensaje;
    int linea;
    int columna;
} Errores;

Errores* crearError(const char* tipo, const char* mensaje, int linea, int columna) {
    Errores* err = malloc(sizeof(Errores));
    if (!err) return NULL;
    err->tipo = strdup(tipo);
    err->mensaje = strdup(mensaje);
    err->linea = linea;
    err->columna = columna;
    return err;
}

void liberarError(Errores* err) {
    if (err) {
        free(err->tipo);
        free(err->mensaje);
        free(err);
    }
}

// 🔀 Estructura de If
typedef struct {
    Instruccion base;
    Instruccion* condicion;
    Instruccion** instrucciones;
    int cantidad;
} If;

If* crearIf(Instruccion* condicion, Instruccion** instrucciones, int cantidad, int linea, int columna) {
    If* nuevo = malloc(sizeof(If));
    if (!nuevo) return NULL;
    nuevo->base.tipo = crearTipo(VOID);
    nuevo->base.linea = linea;
    nuevo->base.columna = columna;
    nuevo->condicion = condicion;
    nuevo->instrucciones = instrucciones;
    nuevo->cantidad = cantidad;
    return nuevo;
}

// 🧠 Interpretar If
void* interpretarIf(Instruccion* instr, void* arbol, void* tabla) {
    if (!instr || !tabla) return NULL;

    If* si = (If*)instr;
    if (!si->condicion || !si->condicion->interpretar) return crearError("SEMANTICO", "Condición nula o inválida", instr->linea, instr->columna);

    void* cond = si->condicion->interpretar(si->condicion, arbol, tabla);
    if (cond && ((Errores*)cond)->tipo != NULL) {
        return cond;
    }

    if (si->condicion->tipo.tipo != BOOLEANO) {
        return crearError("SEMANTICO", "Expresión condicional no booleana", instr->linea, instr->columna);
    }

    tablaSimbolos* newTabla = crearTablaSimbolos((tablaSimbolos*)tabla);
    if (!newTabla) return crearError("SEMANTICO", "Error al crear entorno", instr->linea, instr->columna);

    if ((bool)cond) {
        for (int i = 0; i < si->cantidad; i++) {
            Instruccion* actual = si->instrucciones[i];
            if (!actual || !actual->interpretar) continue;

            void* resultado = actual->interpretar(actual, arbol, newTabla);
            if (resultado && ((Errores*)resultado)->tipo != NULL) {
                return resultado;
            }
        }
    }

    return NULL;
}
