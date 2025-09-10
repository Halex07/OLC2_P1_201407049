#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulación de tipoDato enum
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

// Simulación de Instruccion (clase base)
typedef struct {
    Tipo tipo;
    int linea;
    int columna;
} Instruccion;

// Declaracion como subestructura de Instruccion
typedef struct {
    Instruccion base;
    char* identificador;
    Instruccion* valor;  // expresión asignada
} Declaracion;

// Constructor de Declaracion
Declaracion* crearDeclaracion(const char* identificador, Instruccion* valor, Tipo tipo, int linea, int columna) {
    Declaracion* nueva = (Declaracion*)malloc(sizeof(Declaracion));
    nueva->base.tipo = tipo;
    nueva->base.linea = linea;
    nueva->base.columna = columna;
    nueva->identificador = strdup(identificador);  // copia segura del string
    nueva->valor = valor;
    return nueva;
}

// Destructor (opcional)
void liberarDeclaracion(Declaracion* decl) {
    if (decl) {
        free(decl->identificador);
        // liberarInstruccion(decl->valor); // si tienes una función para liberar Instruccion
        free(decl);
    }
}
