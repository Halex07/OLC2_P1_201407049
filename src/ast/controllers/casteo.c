#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "casteo.h"
#include "entorno/tipos.h"

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env) {
    Casteo *c = (Casteo *)self;
    Symbol v = NodoBase_Ejecutar(c->eprex, ast, env);
  
    if ((int)v.tipo == c->tipo) {
        return v;
    }

    switch (c->tipo) {
        case T_DOUBLE: {
            double value = 0.0;
            if (v.tipo == T_INTEGER) value = (double)v.val.i;
            if (v.tipo == T_CHAR)    value = (double)v.val.c;
            if (v.tipo == T_FLOAT)   value = (double)v.val.fl;
            return SymDouble(self->lin, self->col, value);
        }    
                case T_FLOAT: {
            float value = 0.0f;
            if (v.tipo == T_INTEGER) value = (float)v.val.i;
            if (v.tipo == T_CHAR)    value = (float)v.val.c;
            if (v.tipo == T_DOUBLE)  value = (float)v.val.d;
            return SymFloat(self->lin, self->col, value);
        }    
        case T_INTEGER: {
            int value = 0;
            if (v.tipo == T_CHAR)   value = (int)v.val.c;
            if (v.tipo == T_FLOAT)  value = (int)v.val.fl;
            if (v.tipo == T_DOUBLE) value = (int)v.val.d;
            return SymInt(self->lin, self->col, value);
        }
        case T_CHAR: {
            char value = 0;
            if (v.tipo == T_INTEGER) value = (char)v.val.i;
            if (v.tipo == T_FLOAT)   value = (char)v.val.fl;
            if (v.tipo == T_DOUBLE)  value = (char)v.val.d;
            return SymChar(self->lin, self->col, value);
        }
        default:
            return SymNull(self->lin, self->col);
    }
}

static void Destruir(NodoBase *self) {
    Casteo *c = (Casteo *)self;
    NodoBase_Destruir(c->eprex); 
    free(c);
}

Casteo *NewCasteo(int lin, int col, int tipo, NodoBase *eprex) {
    Casteo *c = (Casteo *)malloc(sizeof(Casteo));
    NodoBase_init(&c->base, "Casteo", lin, col, Ejecutar, Destruir);
    c->tipo = tipo;
    c->eprex = eprex;
    return c;
}
