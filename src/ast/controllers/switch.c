#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/switch.h"

static Symbol EjecutarArray(NodoBase* self, AST* ast, void* env);
static void DestruirArray(NodoBase* self);


SwitchArray* NewSwitchArray(int lin, int col, NodoBase* expr) {
    SwitchArray* s = (SwitchArray*)malloc(sizeof(SwitchArray));
    NodoBase_init(&s->base, "SWITCH_ARRAY", lin, col, EjecutarArray, DestruirArray);
    s->expr = expr;
    s->count = 0;
    s->capacity = 4;
    s->cases = (CaseArray*)malloc(sizeof(CaseArray) * s->capacity);
    return s;
}


void AddCaseArray(SwitchArray* s, NodoBase* expr, NodoBase* block) {
    if (s->count >= s->capacity) {
        s->capacity *= 2;
        s->cases = (CaseArray*)realloc(s->cases, sizeof(CaseArray) * s->capacity);
    }
    s->cases[s->count].expr = expr;
    s->cases[s->count].block = block;
    s->count++;
}

static Symbol EjecutarArray(NodoBase* self, AST* ast, void* env) {
    SwitchArray* s = (SwitchArray*)self;
    Symbol cond = NodoBase_Ejecutar(s->expr, ast, env);

    for (int i = 0; i < s->count; i++) {
        CaseArray c = s->cases[i];
        if (c.expr) {
            Symbol val = NodoBase_Ejecutar(c.expr, ast, env);
            if (val.tipo == cond.tipo && val.val.i == cond.val.i) {
                NodoBase_Ejecutar(c.block, ast, env);
                return SymNull(self->lin, self->col);
            }
        } else {
            
            NodoBase_Ejecutar(c.block, ast, env);
            return SymNull(self->lin, self->col);
        }
    }
    return SymNull(self->lin, self->col);
}

static void DestruirArray(NodoBase* self) {
    SwitchArray* s = (SwitchArray*)self;
    free(s->cases);
    free(s);
}
