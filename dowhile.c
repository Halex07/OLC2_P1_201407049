#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Simulación de tipoDato
typedef enum {
    ENTERO,
    DECIMAL,
    CADENA,
    CARACTER,
    BOOLEANO,
    VOID
} tipoDato;

// Simulación de Tipo
typedef struct {
    tipoDato tipo;
} Tipo;

// Simulación de Instruccion base
typedef struct Instruccion {
    Tipo tipo;
    int linea;
    int columna;
    void* (*interpretar)(struct Instruccion*, void* arbol, void* tabla);
} Instruccion;

// Simulación de tabla de símbolos y árbol (definiciones mínimas)
typedef struct tablaSimbolos {
    struct tablaSimbolos* padre;
} tablaSimbolos;

tablaSimbolos* crearTablaSimbolos(tablaSimbolos* padre) {
    tablaSimbolos* nueva = (tablaSimbolos*)malloc(sizeof(tablaSimbolos));
    nueva->padre = padre;
    return nueva;
}

// Simulación de error
typedef struct {
    char* tipo;
    char* mensaje;
    int linea;
    int columna;
} Errores;

Errores* crearError(const char* tipo, const char* mensaje, int linea, int columna) {
    Errores* err = (Errores*)malloc(sizeof(Errores));
    err->tipo = strdup(tipo);
    err->mensaje = strdup(mensaje);
    err->linea = linea;
    err->columna = columna;
    return err;
}

// Simulación de Break
typedef struct {
    Instruccion base;
} Break;

// DoWhile
typedef struct {
    Instruccion base;
    Instruccion* condicion;
    Instruccion** instrucciones;
    int cantidad;
} DoWhile;

// Constructor de DoWhile
DoWhile* crearDoWhile(Instruccion* condicion, Instruccion** instrucciones, int cantidad, int linea, int columna) {
    DoWhile* nuevo = (DoWhile*)malloc(sizeof(DoWhile));
    nuevo->base.tipo.tipo = VOID;
    nuevo->base.linea = linea;
    nuevo->base.columna = columna;
    nuevo->condicion = condicion;
    nuevo->instrucciones = instrucciones;
    nuevo->cantidad = cantidad;
    return nuevo;
}

// Interpretar DoWhile
void* interpretarDoWhile(Instruccion* instr, void* arbol, void* tabla) {
    DoWhile* dw = (DoWhile*)instr;
    tablaSimbolos* newTabla = crearTablaSimbolos((tablaSimbolos*)tabla);

    if (dw->condicion->tipo.tipo != BOOLEANO) {
        return crearError("SEMANTICO", "La condición debe ser booleana", instr->linea, instr->columna);
    }

    do {
        tablaSimbolos* newTabla2 = crearTablaSimbolos(newTabla);

        for (int i = 0; i < dw->cantidad; i++) {
            Instruccion* actual = dw->instrucciones[i];
            if (actual->interpretar == interpretarDoWhile) { // simulación de Break
                return NULL;
            }
            void* res = actual->interpretar(actual, arbol, newTabla2);
            if (res != NULL && actual->interpretar == interpretarDoWhile) {
                return NULL;
            }
        }
    } while ((bool)(dw->condicion->interpretar(dw->condicion, arbol, newTabla)));

    return NULL;
}
