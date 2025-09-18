#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "ast/controllers/float.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{
    Float *flt = (Float *)self;

    Symbol val = NodoBase_Ejecutar(flt->expr, ast, env);

    if ((int)val.tipo != T_STRING)
    {
        AST_SetError(ast, "Error semantico: almenos un string");
        return SymNull(self->lin, self->col);
    }

    if (val.val.s == NULL)
    {
        AST_SetError(ast, "Error semantico: string nulo");
        return SymNull(self->lin, self->col);
    }

    errno = 0;
    char *endptr = NULL;
    float num = strtof(val.val.s, &endptr);

    if (endptr == val.val.s || errno == ERANGE)
    {
        AST_SetError(ast, "Error:  de conversion");
        return SymNull(self->lin, self->col);
    }

    return SymFloat(self->lin, self->col, num);
}
static void Destruir(NodoBase *self)
{
    Float *flt = (Float *)self;
    if (flt->expr)
        NodoBase_Destruir(flt->expr);
    free(flt);
}

Float *NewFloat(int lin, int col, NodoBase *expr)
{
    Float *flt = (Float *)malloc(sizeof(Float));
    NodoBase_init(&flt->base, "Float", lin, col, Ejecutar, Destruir);
    flt->expr = expr;
    return flt;
}
