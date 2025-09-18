#include <stdlib.h>
#include <stdio.h>
#include "ast/controllers/int.h"
 
 /* Marcamos la función como usada para silenciar el warning */
static Symbol Ejecutar(NodoBase* self, AST* ast, void* env) __attribute__((used));
static Symbol Ejecutar(NodoBase* self, AST* ast, void* env) {
    Int* ent= (Int*)self;

    Symbol val = NodoBase_Ejecutar(ent->expr, ast, env);

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

    char *endptr;
    long num = strtol(val.val.s, &endptr, 10);

    if (*endptr != '\0') {
        return SymNull(self->lin, self->col);
    }

    return SymInt(self->lin, self->col, (int)num);
}

static void Destruir(NodoBase* self) {
    Int* ent= (Int*)self;
    if (ent->expr) NodoBase_Destruir(ent->expr);
    free(ent);
}

Int* NewInt(int lin, int col, NodoBase* expr) {
    Int* ent= (Int*)malloc(sizeof(Int));
    NodoBase_init(&ent->base, "Int", lin, col, Ejecutar, Destruir);
    ent->expr = expr;
    return ent;
}

