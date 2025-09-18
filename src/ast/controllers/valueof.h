#ifndef VALUEOF_H
#define VALUEOF_H

#include "ast/AbstractTerminal.h"

typedef struct {
    NodoBase base;
    NodoBase* expr;  // expresión que puede devolver cualquier tipo
} ValueOf;

/* Constructor */
ValueOf* NewValueOf(int lin, int col, NodoBase* expr);

#endif
