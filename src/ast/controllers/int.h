#ifndef INT_H
#define INT_H
#include "ast/controllers/int.h"
#include "ast/AbstractTerminal.h"

typedef struct {
    NodoBase base;
    NodoBase* expr;   
} Int;
 
Int* NewInt(int lin, int col, NodoBase* expr);

#endif
