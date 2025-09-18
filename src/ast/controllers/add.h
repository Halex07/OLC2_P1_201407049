#ifndef ADD_H
#define ADD_H
#include "ast/AbstractTerminal.h"


typedef struct Add{
    NodoBase base;
    NodoBase *arrays;
    NodoBase *expr;
} Add;

Add* NewAdd(int lin, int col, NodoBase *arrys, NodoBase *expr);

#endif
