#ifndef FOR_H
#define FOR_H

#include "ast/AbstractTerminal.h"

typedef struct For
{
    NodoBase base;
    NodoBase *dcl;
    NodoBase *condicion;
    NodoBase *masMenos;
    NodoBase *scop;
} For;

For *NewFor(int lin, int col, NodoBase *dcl, NodoBase *condicion, NodoBase *masMenos, NodoBase *scop);

#endif
