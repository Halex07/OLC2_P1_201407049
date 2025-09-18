#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ast/controllers/equals.h"
#include "entorno/ast.h"
#include "entorno/environment.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env) {
    Equals *cad = (Equals *)self;

    Symbol a= NodoBase_Ejecutar(cad->operandoA, ast, env);
    Symbol b= NodoBase_Ejecutar(cad->operandoB, ast, env);

    if (a.tipo != T_STRING) {
        AST_SetError(ast, "ERROR: equals() requiere que el primer operando sea una cadena");
        return SymNull(self->lin, self->col);
    }

    if (b.tipo != T_STRING) {
        AST_SetError(ast, "ERROR: equals() requiere que el segundo operando sea una cadena");
        return SymNull(self->lin, self->col);
    }

    int result = strcmp(a.val.s, b.val.s) == 0;

    return SymBool(self->lin, self->col, result);
}

static void Destruir(NodoBase *self) {
    Equals *cad = (Equals *)self;
    if (cad->operandoA) NodoBase_Destruir(cad->operandoA);
    if (cad->operandoB) NodoBase_Destruir(cad->operandoB);
    free(cad);
}
Equals *NewEquals(int lin, int col, NodoBase *operandoA, NodoBase *operandoB) {
    Equals *cad = (Equals *)malloc(sizeof(Equals));
    NodoBase_init(&cad->base, "EQUALS", lin, col, Ejecutar, Destruir);
    cad->operandoA = operandoA;
    cad->operandoB = operandoB;
    return cad;
}
