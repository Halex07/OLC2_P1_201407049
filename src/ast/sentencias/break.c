#include <stdlib.h>
#include <stdio.h>
#include "ast/sentencias/break.h"
#include "entorno/environment.h"
#include "entorno/ast.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env) {
    (void)ast;
    (void)env;
    return (Symbol){ .tipo = T_BREAK, .lin = self->lin, .col = self->col };
}

static void Destruir(NodoBase *self) {
    free((Break *)self);
}

Break *NewBreak(int lin, int col) {
    Break *b = (Break *)malloc(sizeof(Break));
    NodoBase_init(&b->base, "BREAK", lin, col, Ejecutar, Destruir);
    return b;
}
