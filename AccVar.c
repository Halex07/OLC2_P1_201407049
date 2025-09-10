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

// AccesoVar como subestructura de Instruccion
typedef struct {
    Instruccion base;
    char* id;
} AccesoVar;

// Constructor de AccesoVar
AccesoVar* crearAccesoVar(const char* id, int linea, int columna) {
    AccesoVar* nuevo = (AccesoVar*)malloc(sizeof(AccesoVar));
    nuevo->base.tipo.tipo = VOID;
    nuevo->base.linea = linea;
    nuevo->base.columna = columna;
    nuevo->id = strdup(id); // copia segura del string
    return nuevo;
}

// Destructor (opcional)
void liberarAccesoVar(AccesoVar* var) {
    if (var) {
        free(var->id);
        free(var);
    }
}
