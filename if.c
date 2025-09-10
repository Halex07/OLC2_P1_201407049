#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Enumeración de tipos de datos
typedef enum {
    ENTERO,
    DECIMAL,
    CADENA,
    CARACTER,
    BOOLEANO,
    VOID
} tipoDato;

// Estructura de Tipo
typedef struct {
    tipoDato tipo;
} Tipo;

// Estructura base de Instrucción
typedef struct Instruccion {
    Tipo tipo;
    int linea;
    int columna;
    void* (*interpretar)(struct Instruccion*, void* arbol, void* tabla);
} Instruccion;

// Estructura de tabla de símbolos
typedef struct tablaSimbolos {
    struct tablaSimbolos* padre;
} tablaSimbolos;

tablaSimbolos* crearTablaSimbolos(tablaSimbolos* padre) {
    tablaSimbolos* nueva = (tablaSimbolos*)malloc(sizeof(tablaSimbolos));
    nueva->padre = padre;
    return nueva;
}

// Estructura de error
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

// Estructura de If
typedef struct {
    Instruccion base;
    Instruccion* condicion;
    Instruccion** instrucciones;
    int cantidad;
} If;

// Constructor de If
If* crearIf(Instruccion* condicion, Instruccion** instrucciones, int cantidad, int linea, int columna) {
    If* nuevo = (If*)malloc(sizeof(If));
    nuevo->base.tipo.tipo = VOID;
    nuevo->base.linea = linea;
    nuevo->base.columna = columna;
    nuevo->condicion = condicion;
    nuevo->instrucciones = instrucciones;
    nuevo->cantidad = cantidad;
    return nuevo;
}

// Interpretar If
void* interpretarIf(Instruccion* instr, void* arbol, void* tabla) {
    If* si = (If*)instr;

    void* cond = si->condicion->interpretar(si->condicion, arbol, tabla);
    if (cond != NULL && ((Errores*)cond)->tipo != NULL) {
        return cond;
    }

