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

// AsignacionVar como subestructura de Instruccion
typedef struct {
    Instruccion base;
    char* id;
    Instruccion* exp;  // expresión que se asigna
} AsignacionVar;

// Constructor de AsignacionVar
AsignacionVar* crearAsignacionVar(const char* id, Instruccion* exp, int linea, int columna) {
    AsignacionVar* nueva = (AsignacionVar*)malloc(sizeof(AsignacionVar));
    nueva->base.tipo.tipo = VOID;
    nueva->base.linea = linea;
    nueva->base.columna = columna;
    nueva->id = strdup(id);  // copia segura del identificador
    nueva->exp = exp;
    return nueva;
}

// Destructor (opcional)
void liberarAsignacionVar(AsignacionVar* asignacion) {
    if (asignacion) {
        free(asignacion->id);
        // Si exp fue asignado dinámicamente, liberarlo también
        // liberarInstruccion(asignacion->exp); // si tienes una función para esto
        free(asignacion);
    }
}
