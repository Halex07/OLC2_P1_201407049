#ifndef LOOPWHILE_H
#define LOOPWHILE_H

#include "ast/AbstractTerminal.h"

typedef struct LoopWhile
{
  NodoBase base;
  NodoBase *condicion;
  NodoBase *scop;
} LoopWhile;

LoopWhile *NewLoopWhile(int lin, int col, NodoBase *condicion, NodoBase *scop);

#endif
