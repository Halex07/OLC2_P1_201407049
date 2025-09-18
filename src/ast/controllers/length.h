#ifndef LENGTN_H
#define LENGTN_H

#include "ast/AbstractTerminal.h"

typedef struct {
    NodoBase base;
    NodoBase *tama; 
} Length;

Length *NewLength(int lin, int col, NodoBase *tama);

#endif
