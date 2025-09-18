#ifndef INDEXOF_H
#define INDEXOF_H

#include "ast/AbstractTerminal.h"

typedef struct IndexOf {
    NodoBase base;
    NodoBase *list; 
    NodoBase *key;   
} IndexOf;

IndexOf *NewIndexOf(int lin, int col, NodoBase *list, NodoBase *key);

#endif
