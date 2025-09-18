#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/indexOf.h"

// Función auxiliar para comparar dos símbolos
static int SymbolsEqual(Symbol a, Symbol b) {
    if (a.tipo != b.tipo) return 0;
    switch (a.tipo) {
        case T_INTEGER: return a.val.i == b.val.i;
        case T_DOUBLE:  return a.val.d == b.val.d;
        case T_FLOAT:   return a.val.fl == b.val.fl;
        case T_CHAR:    return a.val.c == b.val.c;
        case T_STRING:  return a.val.s && b.val.s && strcmp(a.val.s, b.val.s) == 0;
        case T_BOOLEAN:return a.val.i == b.val.i;
        default: return 0;
    }
}

static Symbol EjecutarIndexOf(NodoBase *self, AST *ast, void *env) {
    IndexOf *d = (IndexOf *)self;  // <-- Aquí estaba el error

    Symbol arrSym = NodoBase_Ejecutar(d->list, ast, env);
    Symbol keySym = NodoBase_Ejecutar(d->key, ast, env);

    if (arrSym.tipo != T_ARRAY || arrSym.val.arr == NULL)
        return SymInt(self->lin, self->col, -1);

    ArrayType *arr = arrSym.val.arr;
    for (int i = 0; i < arr->tam; i++) {
        if (SymbolsEqual(arr->items[i], keySym))
            return SymInt(self->lin, self->col, i);
    }

    return SymInt(self->lin, self->col, -1);
}

static void Destruir(NodoBase *self) {
    IndexOf *d = (IndexOf *)self;  // <-- También aquí
    free(d);
}

IndexOf *NewIndexOf(int lin, int col, NodoBase *list, NodoBase *key) {
    IndexOf *d = (IndexOf *)malloc(sizeof(IndexOf));
    NodoBase_init(&d->base, "INDEXOF", lin, col, EjecutarIndexOf, Destruir);
    d->list = list;
    d->key = key;
    return d;
}
