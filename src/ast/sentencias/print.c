#include <stdio.h>
#include <stdlib.h>
#include "ast/sentencias/print.h"
#include <string.h>


static void append_symbol_array(char *buf, Symbol s) {
    if (!s.val.arr) {
        strcat(buf, "[]");
        return;
    }

    strcat(buf, "[");
    for (int i = 0; i < s.val.arr->tam; i++) {
        Symbol item = s.val.arr->items[i];
        switch (item.tipo) {
            case T_INTEGER: {
                char tmp[32]; sprintf(tmp, "%d", item.val.i); strcat(buf, tmp);
                break;
            }
            case T_FLOAT: {
                char tmp[32]; sprintf(tmp, "%f", item.val.fl); strcat(buf, tmp);
                break;
            }
            case T_DOUBLE: {
                char tmp[32]; sprintf(tmp, "%lf", item.val.d); strcat(buf, tmp);
                break;
            }
            case T_STRING:
                strcat(buf, "\""); strcat(buf, item.val.s); strcat(buf, "\"");
                break;
            case T_CHAR: {
                char tmp[4]; sprintf(tmp, "'%c'", item.val.c); strcat(buf, tmp);
                break;
            }
            default:
                
        }
        if (i < s.val.arr->tam - 1) strcat(buf, ", ");
    }
    strcat(buf, "]");
}


static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{
    Print *p = (Print *)self;
    Symbol s = NodoBase_Ejecutar(p->expr, ast, env);

    char buf[1024] = {0}; // buffer más grande para arrays
    switch (s.tipo)
    {
        case T_INTEGER: snprintf(buf, sizeof buf, "%d", s.val.i); break;
        case T_DOUBLE:  snprintf(buf, sizeof buf, "%f", s.val.d); break;
        case T_FLOAT:   snprintf(buf, sizeof buf, "%g", s.val.fl); break;
        case T_BOOLEAN: snprintf(buf, sizeof buf, "%s", s.val.i ? "true" : "false"); break;
        case T_STRING:  snprintf(buf, sizeof buf, "%s", s.val.s ? s.val.s : ""); break;
        case T_CHAR:    snprintf(buf, sizeof buf, "%c", s.val.c); break;
        case T_ARRAY:   append_symbol_array(buf, s); break;
        default:        snprintf(buf, sizeof buf, "null"); break;
    }

    strcat(buf, "\n"); // añadir salto de línea al final
    AST_AppendPrint(ast, buf);

    return s;
}

static void Destruir(NodoBase *self)
{
    Print *p = (Print *)self;
    NodoBase_Destruir(p->expr);
    free(self);
}

Print *NewPrint(int lin, int col, NodoBase *expr)
{
    Print *n = (Print *)malloc(sizeof(Print));
    NodoBase_init(&n->base, "Print", lin, col, Ejecutar, Destruir);
    n->expr = expr;
    return n;
}
