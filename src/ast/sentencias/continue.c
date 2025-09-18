#include <stdlib.h>
#include <stdio.h>
#include "entorno/ast.h"
#include "entorno/environment.h"
#include "ast/sentencias/continue.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env) {
    (void)ast; (void)env;
    return (Symbol){ .tipo = T_CONTINUE, .lin = self->lin, .col = self->col };
}

static void Destruir(NodoBase *self) {
    free((Continue *)self);
}

Continue *NewContinue(int lin, int col) {
    Continue *d = malloc(sizeof(Continue));
    NodoBase_init(&d->base, "CONTINUE", lin, col, Ejecutar, Destruir);
    return d;
}
