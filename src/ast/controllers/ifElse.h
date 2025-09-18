#ifndef IFELSE_H
#define IFELSE_H

#include "ast/AbstractTerminal.h"

typedef struct Else
{
    NodoBase base;
    NodoBase *condicion;   
    NodoBase *scop;    
    NodoBase *scopAnidado;  
} Else;

Else *NewElse(int lin, int col, NodoBase *condicion, NodoBase *scop, NodoBase *scopAnidado);

#endif
