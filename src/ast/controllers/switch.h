#ifndef SWITCH_H
#define SWITCH_H

#include "ast/AbstractTerminal.h"

/* Lista de expresiones para un case */
typedef struct ExprList {
    NodoBase* expr;
    struct ExprList* next;
} ExprList;

typedef struct CaseNode {
    ExprList* exprs;     // antes: NodoBase* expr
    NodoBase* block;
    struct CaseNode* next;
} CaseNode;


typedef struct Switch {
    NodoBase base;
    NodoBase* expr;
    CaseNode* cases;
} Switch;

/* Constructores */
ExprList* NewExprList(NodoBase* expr);
ExprList* AddExpr(ExprList* list, NodoBase* expr);

CaseNode* NewCaseNode(ExprList* exprs, NodoBase* block);
CaseNode* AddCaseNode(CaseNode* list, CaseNode* nuevo);
Switch* NewSwitch(int lin, int col, NodoBase* expr, CaseNode* cases);

#endif