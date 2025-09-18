#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/forEach.h"
#include "ast/controllers/array.h"

static Symbol EjecutarForEach(NodoBase *self, AST *ast, void *env)
{
    ForEach *d = (ForEach *)self;
    Symbol arrSym = Env_GetVariable(env, d->idenLista);
    if (!arrSym.val.arr)
        return SymNull(self->lin, self->col);
    ArrayType *arr = arrSym.val.arr;
    int i = 0;

    // Mientras queden elementos en el arreglo
    while (i < arr->tam)
    {
        Env_SaveVariable(env, d->iden, arr->items[i]);
        if (d->scop)
        {
            Symbol res = NodoBase_Ejecutar(d->scop, ast, env);
            if (res.tipo == T_CONTINUE)
            {
                i++;
                continue;
            }
            if (res.tipo == T_BREAK)
                break;
        }

        i++;
    }

    return SymNull(self->lin, self->col);
}

static void DestruirForEach(NodoBase *self)
{
    ForEach *d = (ForEach *)self;
    free(d);
}

ForEach *NewForEach(int lin, int col, char *iden, char *idenLista, NodoBase *scop)
{
    ForEach *d = (ForEach *)malloc(sizeof(ForEach));
    NodoBase_init(&d->base, "FOREACH", lin, col, EjecutarForEach, DestruirForEach);
    d->iden = iden;
    d->idenLista = idenLista;
    d->scop = scop;
    return d;
}
