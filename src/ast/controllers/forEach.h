#ifndef FOREACH_H
#define FOREACH_H

#include "ast/AbstractTerminal.h"

typedef struct ForEach
{
    NodoBase base;
    char *iden;
    char *idenLista;
    NodoBase *scop;
} ForEach;

ForEach *NewForEach(int lin, int col, char *iden, char *idenLista, NodoBase *scop);

#endif
