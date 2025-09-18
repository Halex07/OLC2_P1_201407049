#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast/controllers/valueof.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env) {
    ValueOf *vofs = (ValueOf *)self;
    Symbol val = NodoBase_Ejecutar(vofs->expr, ast, env);

    char *str = NULL;

    switch (val.tipo) {
        case T_INTEGER: {
            size_t len = snprintf(NULL, 0, "%d", val.val.i) + 1;
            str = malloc(len);
            snprintf(str, len, "%d", val.val.i);
            break;
        }
        case T_DOUBLE: {
            size_t len = snprintf(NULL, 0, "%f", val.val.d) + 1;
            str = malloc(len);
            snprintf(str, len, "%f", val.val.d);
            break;
        }
        case T_FLOAT: {
            size_t len = snprintf(NULL, 0, "%f", val.val.fl) + 1;
            str = malloc(len);
            snprintf(str, len, "%f", val.val.fl);
            break;
        }
        case T_BOOLEAN:
            str = strdup(val.val.i ? "true" : "false");
            break;
        case T_STRING:
            str = strdup(val.val.s ? val.val.s : "");
            break;
        case T_CHAR:
            str = malloc(2);
            str[0] = val.val.c;
            str[1] = '\0';
            break;
        case T_NULL:
            str = strdup("null");
            break;
        default:
            str = strdup("[objeto]");
            break;
    }

    return SymStr(self->lin, self->col, str);
}

static void Destruir(NodoBase *self) {
    ValueOf *vofs = (ValueOf *)self;
    if (vofs->expr) NodoBase_Destruir(vofs->expr);
    free(vofs);
}
ValueOf *NewValueOf(int lin, int col, NodoBase *expr) {
    ValueOf *vofs = (ValueOf *)malloc(sizeof(ValueOf));
    NodoBase_init(&vofs->base, "ValueOf", lin, col, Ejecutar, Destruir);
    vofs->expr = expr;
    return vofs;
}
