#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/array.h"
 
static ArrayType* CrearArray(int size, Symbol init)
{
    ArrayType *arr = malloc(sizeof(ArrayType));
    arr->tam = size;
    arr->items = malloc(sizeof(Symbol) * size);
    for (int i = 0; i < size; i++) {
        arr->items[i] = init;
    }
    return arr;
}

static ArrayType* CopiarArray(ArrayType *src)
{
    if (!src) return NULL;
    ArrayType *copy = malloc(sizeof(ArrayType));
    copy->tam = src->tam;
    copy->items = malloc(sizeof(Symbol) * copy->tam);
    for (int i = 0; i < copy->tam; i++) {
        copy->items[i] = src->items[i];
    }
    return copy;
}
 
static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{
    Array *d = (Array *)self;
    ArrayType *arr = NULL;

    if (d->size) {
        Symbol len = NodoBase_Ejecutar(d->size, ast, env);
        arr = CrearArray(len.val.i, SymNull(self->lin, self->col));
    } 
    else if (d->list) {
        int count = 0;
        for (NodoBase *tmp = d->list; tmp; tmp = tmp->siguiente) count++;

        arr = malloc(sizeof(ArrayType));
        arr->tam = count;
        arr->items = malloc(sizeof(Symbol) * arr->tam);

        int i = 0;
        for (NodoBase *tmp = d->list; tmp; tmp = tmp->siguiente) {
            arr->items[i++] = NodoBase_Ejecutar(tmp, ast, env);
        }
    }

    Env_SaveVariable(env, d->iden, SymArray(self->lin, self->col, arr));
    return SymNull(self->lin, self->col);
}

static Symbol EjecutarArrayAdd(NodoBase *self, AST *ast, void *env)
{
    Array *d = (Array *)self;   
    Symbol inicial = Env_GetVariable(env, d->iden);

    if (!inicial.val.arr) return SymNull(self->lin, self->col);

    ArrayType *newArr = CopiarArray(inicial.val.arr);
    newArr->items = realloc(newArr->items, sizeof(Symbol) * (newArr->tam + 1));

    Symbol nuevo = NodoBase_Ejecutar(d->agreg, ast, env);
    newArr->items[newArr->tam] = nuevo;
    newArr->tam++;

    Env_SaveVariable(env, d->identifer, SymArray(self->lin, self->col, newArr));
    return SymNull(self->lin, self->col);
}

static Symbol EjecutarArrayGet(NodoBase *self, AST *ast, void *env)
{
    Array *d = (Array *)self;
    Symbol arrSym = Env_GetVariable(env, d->iden);

    if (!arrSym.val.arr) return SymNull(self->lin, self->col);

    Symbol idx = NodoBase_Ejecutar(d->index, ast, env);
    if (idx.tipo != T_INTEGER) return SymNull(self->lin, self->col);

    int pos = idx.val.i;
    if (pos < 0 || pos >= arrSym.val.arr->tam) return SymNull(self->lin, self->col);

    return arrSym.val.arr->items[pos];
}

static Symbol EjecutarArraySet(NodoBase *self, AST *ast, void *env)
{
    Array *d = (Array *)self;
    Symbol arrSym = Env_GetVariable(env, d->iden);

    if (!arrSym.val.arr) return SymNull(self->lin, self->col);

    Symbol idx = NodoBase_Ejecutar(d->index, ast, env);
    if (idx.tipo != T_INTEGER) return SymNull(self->lin, self->col);

    int pos = idx.val.i;
    if (pos < 0 || pos >= arrSym.val.arr->tam) return SymNull(self->lin, self->col);

    arrSym.val.arr->items[pos] = NodoBase_Ejecutar(d->value, ast, env);
    return SymNull(self->lin, self->col);
}
static void Destruir(NodoBase *self)
{
    Array *d = (Array *)self;
    if (d->size || d->list || d->agreg) {
        // liberando la mente
    }

    free(d);
}

Array *NewArray(int lin, int col, TipoExpresion tipo, char *iden, NodoBase *size, NodoBase *list)
{
    Array *d = malloc(sizeof(Array));
    NodoBase_init(&d->base, "ARRAY", lin, col, Ejecutar, Destruir);
    d->tipo = tipo;
    d->iden = iden;
    d->size = size;
    d->list = list;
    d->identifer = NULL;
    d->agreg = NULL;
    return d;
}

Array *NewArrayADD(int lin, int col, TipoExpresion tipo, char *nombreOriginal, char *nombreNuevo, NodoBase *agreg)
{
    Array *d = malloc(sizeof(Array));
    NodoBase_init(&d->base, "ARRAY", lin, col, EjecutarArrayAdd, Destruir);
    d->tipo = tipo;
    d->iden = nombreOriginal;
    d->identifer = nombreNuevo;
    d->agreg = agreg;
    d->size = NULL;
    d->list = NULL;
    return d;
}

Array *NewArrayGET(int lin, int col, char *iden, NodoBase *index)
{
    Array *d = malloc(sizeof(Array));
    NodoBase_init(&d->base, "ARRAY_GET", lin, col, EjecutarArrayGet, Destruir);
    d->iden = iden;
    d->index = index;
    d->value = NULL;
    d->identifer = NULL;
    d->size = NULL;
    d->list = NULL;
    d->agreg = NULL;
    return d;
}

Array *NewArraySET(int lin, int col, char *iden, NodoBase *index, NodoBase *value)
{
    Array *d = malloc(sizeof(Array));
    NodoBase_init(&d->base, "ARRAY_SET", lin, col, EjecutarArraySet, Destruir);
    d->iden = iden;
    d->index = index;
    d->value = value;
    d->identifer = NULL;
    d->size = NULL;
    d->list = NULL;
    d->agreg = NULL;
    return d;
}
