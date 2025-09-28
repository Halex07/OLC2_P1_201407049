#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/switch.h"


ExprList *NewExprList(NodoBase *expr)
{
    ExprList *e = (ExprList *)malloc(sizeof(ExprList));
    e->expr = expr;
    e->next = NULL;
    return e;
}

ExprList *AddExpr(ExprList *list, NodoBase *expr)
{
    if (!list)
        return NewExprList(expr);
    ExprList *tmp = list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = NewExprList(expr);
    return list;
}

CaseNode *NewCaseNode(ExprList *exprs, NodoBase *block)
{
    CaseNode *c = (CaseNode *)malloc(sizeof(CaseNode));
    c->exprs = exprs;
    c->block = block;
    c->next = NULL;
    return c;
}

CaseNode *AddCaseNode(CaseNode *list, CaseNode *nuevo)
{
    if (!list)
        return nuevo;
    CaseNode *tmp = list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = nuevo;
    return list;
}

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{
    Switch *s = (Switch *)self;
    Symbol cond = NodoBase_Ejecutar(s->expr, ast, env);

    CaseNode *tmp = s->cases;
    int matched = 0;
    while (tmp)
    {
        if (tmp->exprs)
        {
            ExprList *e = tmp->exprs;
            while (e)
            {
                Symbol val = NodoBase_Ejecutar(e->expr, ast, env);
               // printf("Comparando %d con %d\n", cond.val.i, val.val.i);

                if (val.tipo == cond.tipo || val.val.i == cond.val.i)
                {
                    matched = 1;
                    if (val.val.i % 2 == 0)
                    {
                        NodoBase_Ejecutar(tmp->block, ast, env);
                        goto end; 
                    }
                  
                }
                e = e->next;
            }
        }
        else
        {  
            if (!matched)
            {
                NodoBase_Ejecutar(tmp->block, ast, env);
                goto end;
            }
        }
        tmp = tmp->next;
    }

end:
    return SymNull(self->lin, self->col);
}

static void Destruir(NodoBase *self)
{
    Switch *s = (Switch *)self;
    CaseNode *tmp = s->cases;
    while (tmp)
    {
        ExprList *e = tmp->exprs;
        while (e)
        {
            ExprList *nextE = e->next;
            free(e);
            e = nextE;
        }
        CaseNode *next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(s);
}

Switch *NewSwitch(int lin, int col, NodoBase *expr, CaseNode *cases)
{
    Switch *s = (Switch *)malloc(sizeof(Switch));
    NodoBase_init(&s->base, "SWITCH", lin, col, Ejecutar, Destruir);
    s->expr = expr;
    s->cases = cases;
    return s;
}