#ifndef BREAK_H
#define BREAK_H

#include "ast/AbstractTerminal.h"

/* Nodo AST para la sentencia 'break' */
typedef struct Break {
    NodoBase base;
} Break;

/* Constructor */
Break *NewBreak(int lin, int col);

#endif /* BREAK_H */
