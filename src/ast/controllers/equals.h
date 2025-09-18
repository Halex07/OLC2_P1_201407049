#ifndef EQUALS_H
#define EQUALS_H

#include "ast/AbstractTerminal.h"

typedef struct Equals {
    NodoBase base;
    NodoBase *operandoA;    
    NodoBase *operandoB;   
} Equals;

Equals *NewEquals(int lin, int col, NodoBase *operandoA, NodoBase *operandoB);

#endif
