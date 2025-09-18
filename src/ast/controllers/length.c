#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/length.h"


static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{ 
    Symbol arrSym = NodoBase_Ejecutar(((Length *)self)->tama, ast, env);

    if (arrSym.tipo != T_ARRAY || arrSym.val.arr == NULL) {
        AST_SetError(ast, "ERROR: LENGTH ");
        return SymNull(self->lin, self->col);
    }

    // Retornar tamaño
    return SymInt(self->lin, self->col, arrSym.val.arr->tam);
}


static void Destruir(NodoBase *self)
{
    Length *d = (Length *)self;
    NodoBase_Destruir(d->tama);
    free(d);
}


Length *NewLength(int lin, int col, NodoBase *tama)
{
    Length *d = (Length *)malloc(sizeof(Length));
    NodoBase_init(&d->base, "Length", lin, col, Ejecutar, Destruir);
    d->tama = tama;  
    return d;
}
