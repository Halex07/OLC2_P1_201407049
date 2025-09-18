#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/for.h"

static Symbol EjecutarFor(NodoBase *self, AST *ast, void *env) {
    For *d = (For *)self;

    if (d->dcl) NodoBase_Ejecutar(d->dcl, ast, env);

    Symbol cond = NodoBase_Ejecutar(d->condicion, ast, env);
    while (cond.tipo == T_BOOLEAN && cond.val.i) {
        if (d->scop) {
            Symbol res = NodoBase_Ejecutar(d->scop, ast, env);
            if (res.tipo == T_CONTINUE) {
                // Continuar después de la actualización
            } else if (res.tipo == T_BREAK) {
                break;
            }
        }

        if (d->masMenos) NodoBase_Ejecutar(d->masMenos, ast, env);  
        cond = NodoBase_Ejecutar(d->condicion, ast, env);
    }
    return SymNull(self->lin, self->col);
}

static void DestruirFor(NodoBase *self)
{
    For *d = (For *)self;
    free(d);
}

For *NewFor(int lin, int col, NodoBase *dcl, NodoBase *condicion, NodoBase *masMenos, NodoBase *scop)
{
    For *d = (For *)malloc(sizeof(For));
    NodoBase_init(&d->base, "FOR", lin, col, EjecutarFor, DestruirFor);
    d->dcl = dcl;
    d->condicion = condicion;
    d->masMenos = masMenos;
    d->scop = scop;
    return d;
}
