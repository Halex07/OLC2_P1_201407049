#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/add.h"
#include "entorno/symbol.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env) {
    Add *d = (Add *)self;


    Symbol arrSym = NodoBase_Ejecutar(d->arrays, ast, env);
    Symbol valSym = NodoBase_Ejecutar(d->expr, ast, env);

    if (arrSym.tipo != T_ARRAY || arrSym.val.arr == NULL) {
        AST_SetError(ast, "ERROR: ADD solo se aplica a arreglos");
        return SymNull(self->lin, self->col);
    }

    ArrayType *arr = arrSym.val.arr;

  
    arr->items = realloc(arr->items, sizeof(Symbol) * (arr->tam + 1));
    if (!arr->items) {
        AST_SetError(ast, "ERROR: realloc falló en ARRAY_ADD");
        return SymNull(self->lin, self->col);
    }

    arr->items[arr->tam] = valSym;
    arr->tam += 1;

    return SymArray(self->lin, self->col, arr);
}

static void Destruir(NodoBase *self) {
    Add *d = (Add *)self;
    NodoBase_Destruir(d->arrays);
    NodoBase_Destruir(d->expr);
    free(d);
}

Add* NewAdd(int lin, int col, NodoBase *arrys, NodoBase *expr) {
    Add *d = (Add *)malloc(sizeof(Add));
    NodoBase_init(&d->base, "ARRAY_ADD", lin, col, Ejecutar, Destruir);
    d->arrays = arrys;
    d->expr = expr;
    return d;
}
