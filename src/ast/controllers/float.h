#ifndef FLOAT_H
#define FLOAT_H

#include "ast/AbstractTerminal.h"

typedef struct {
    NodoBase base;
    NodoBase* expr;  
} Float;

Float* NewFloat(int lin, int col, NodoBase* expr);

#endif
