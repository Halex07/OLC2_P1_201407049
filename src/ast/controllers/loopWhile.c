#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/loopWhile.h"
#include "ast/sentencias/continue.h"
#include "ast/sentencias/break.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{
    LoopWhile *d = (LoopWhile *)self;

    Symbol cond = NodoBase_Ejecutar(d->condicion, ast, env);

    while (cond.tipo == T_BOOLEAN && cond.val.i == 1) {
        Symbol body = NodoBase_Ejecutar(d->scop, ast, env);

        if (body.tipo == T_CONTINUE) {
            cond = NodoBase_Ejecutar(d->condicion, ast, env);
            continue;
        }

        if (body.tipo == T_BREAK) {
            break;
        }

        cond = NodoBase_Ejecutar(d->condicion, ast, env);
    }

    return SymNull(self->lin, self->col);
}

static void Destruir(NodoBase *self)
{
    LoopWhile *d = (LoopWhile *)self;
    free(d);
}

LoopWhile *NewLoopWhile(int lin, int col, NodoBase *condicion, NodoBase *scop)
{
    LoopWhile *d = (LoopWhile *)malloc(sizeof(LoopWhile));
    NodoBase_init(&d->base, "LOOPWHILE", lin, col, Ejecutar, Destruir);
    d->condicion = condicion;
    d->scop = scop;
    return d;
}
