#ifndef RETURN_H
#define RETURN_H
#include "ast/AbstractTerminal.h"

typedef struct Return {
    NodoBase base;
    NodoBase *expr; /* expresión opcional */
} Return;

Return *NewReturn(int lin, int col, NodoBase *expr);

#endif
