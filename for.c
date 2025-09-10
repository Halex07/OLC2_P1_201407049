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

// Estructura de For
typedef struct