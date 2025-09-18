#ifndef CASTEO_H
#define CASTEO_H

#include "ast/AbstractTerminal.h"

typedef struct Casteo{
    NodoBase base;
    int tipo;        
    NodoBase *eprex;    
} Casteo;

Casteo *NewCasteo(int lin, int col, int tipo, NodoBase *eprex);

#endif
