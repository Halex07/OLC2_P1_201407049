#ifndef CONTINUE_H
#define CONTINUE_H

#include "ast/AbstractTerminal.h"

/* Nodo AST para la sentencia 'continue' */
typedef struct Continue {
    NodoBase base;
} Continue;

static inline Symbol SymContinue(int lin, int col)
{
    Symbol s = {lin, col, T_CONTINUE, {0}};
    return s;
}

/* Constructor */
Continue *NewContinue(int lin, int col);

#endif /* CONTINUE_H */
