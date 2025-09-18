#ifndef SWITCH_H
#define SWITCH_H

#include "ast/AbstractTerminal.h"

typedef struct {
    NodoBase* expr;
    NodoBase* block;
} CaseArray;

typedef struct {
    NodoBase base;
    NodoBase* expr;    
    CaseArray* cases; 
    int count;        
    int capacity;      
} SwitchArray;

SwitchArray* NewSwitchArray(int lin, int col, NodoBase* expr);
void AddCaseArray(SwitchArray* s, NodoBase* expr, NodoBase* block);

#endif
