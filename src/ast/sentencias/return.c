#include <stdlib.h>
#include <stdio.h>
#include "ast/sentencias/return.h"
#include "entorno/environment.h"
#include "entorno/ast.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env) {
    Return *retun = (Return *)self;
    Symbol s = retun->expr ? NodoBase_Ejecutar(retun->expr, ast, env) : (Symbol){ .tipo = T_VOID };

    s.tipo = T_RETURN;
    s.lin = self->lin;
    s.col = self->col;
    return s;
}

static void Destruir(NodoBase *self) {
    Return *retun = (Return *)self;
    if (retun->expr) NodoBase_Destruir(retun->expr);
    free(retun);
}


Return *NewReturn(int lin, int col, NodoBase *expr) {
    Return *retun = (Return *)malloc(sizeof(Return));
    retun->expr = expr;
    NodoBase_init(&retun->base, "RETURN", lin, col, Ejecutar, Destruir);
    return retun;
}
