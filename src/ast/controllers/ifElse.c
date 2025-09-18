#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/ifElse.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{
    Else*d = (Else*)self;

    Symbol v = NodoBase_Ejecutar(d->condicion, ast, env);

    if (v.tipo != T_BOOLEAN) {
        return SymNull(self->lin, self->col);
    }

    if (v.val.i == 1) {
        Environment if_stmt;
        Env_init(&if_stmt, env, "IF");
        (void)NodoBase_Ejecutar(d->scop, ast, &if_stmt);
        Env_free(&if_stmt);
    } else if (d->scopAnidado != NULL) {
        Environment else_stmt;
        Env_init(&else_stmt, env, "ELSE");
        (void)NodoBase_Ejecutar(d->scopAnidado, ast, &else_stmt);
        Env_free(&else_stmt);
    }

    return SymNull(self->lin, self->col);
}

static void Destruir(NodoBase *self)
{
    Else*d = (Else*)self;
    free(d);
}

Else *NewElse(int lin, int col, NodoBase *condicion, NodoBase *scop, NodoBase *scopAnidado)
{
    Else*d = (Else*)malloc(sizeof(Else));
    NodoBase_init(&d->base, "IFELSE", lin, col, Ejecutar, Destruir);
    d->condicion = condicion;
    d->scop = scop;
    d->scopAnidado = scopAnidado;
    return d;
}
