#include <stdlib.h>
#include <stdio.h>
#include "entorno/environment.h"
#include "entorno/ast.h"
#include "ast/controllers/listaDimen.h"

static ArrayType *CrearFila(int columnas, NodoBase *self) {
    ArrayType *row = malloc(sizeof(ArrayType));
    row->tam = columnas;
    row->items = malloc(sizeof(Symbol) * columnas);
    for (int j = 0; j < columnas; j++)
        row->items[j] = SymNull(self->lin, self->col);
    return row;
}

static ArrayType *CrearLista(int filas, int columnas, NodoBase *self) {
    ArrayType *dimen = malloc(sizeof(ArrayType));
    dimen->tam = filas;
    dimen->items = malloc(sizeof(Symbol) * filas);
    for (int i = 0; i < filas; i++)
        dimen->items[i] = SymArray(self->lin, self->col, CrearFila(columnas, self));
    return dimen;
}
static Symbol EjecutarLista(NodoBase *self, AST *ast, void *env)
{
    LISTA *d = (LISTA *)self;
    ArrayType *dimen = malloc(sizeof(ArrayType));

    if (d->filas && d->columnas)
    {
        Symbol f = NodoBase_Ejecutar(d->filas, ast, env);
        Symbol c = NodoBase_Ejecutar(d->columnas, ast, env);

        dimen->tam = f.val.i;
        dimen->items = malloc(sizeof(Symbol) * f.val.i);

        char buffer[256];

        for (int i = 0; i < f.val.i; i++)
        {
            ArrayType *row = malloc(sizeof(ArrayType));
            row->tam = c.val.i;
            row->items = malloc(sizeof(Symbol) * c.val.i);

            buffer[0] = 0;
            for (int j = 0; j < c.val.i; j++)
            {
                row->items[j] = SymNull(self->lin, self->col);
                char temp[16];
                snprintf(temp, sizeof(temp), "0 "); // inicializamos con 0 para mostrar
                strncat(buffer, temp, sizeof(buffer) - strlen(buffer) - 1);
            }
            dimen->items[i] = SymArray(self->lin, self->col, row);
            strncat(buffer, "\n", sizeof(buffer) - strlen(buffer) - 1);
            AST_AppendPrint(ast, buffer);  // agregamos fila al prints
        }
    }

    Env_SaveVariable(env, d->nombre, SymArray(self->lin, self->col, dimen));
    return SymNull(self->lin, self->col);
}


static Symbol ValidarIndices(LISTA *d, AST *ast, void *env, int *outI, int *outJ, Symbol *matSym) {
    *matSym = Env_GetVariable(env, d->nombre);
    if (!matSym->val.arr) return SymNull(d->base.lin, d->base.col);

    Symbol rowIdx = NodoBase_Ejecutar(d->posFila, ast, env);
    Symbol colIdx = NodoBase_Ejecutar(d->posColumn, ast, env);
    if (rowIdx.tipo != T_INTEGER || colIdx.tipo != T_INTEGER) return SymNull(d->base.lin, d->base.col);

    *outI = rowIdx.val.i;
    *outJ = colIdx.val.i;
    return SymNull(d->base.lin, d->base.col);
}

static Symbol EjecutarListaGet(NodoBase *self, AST *ast, void *env) {
    LISTA *d = (LISTA *)self;
    int i, j;
    Symbol matSym;
    ValidarIndices(d, ast, env, &i, &j, &matSym);

    ArrayType *dimen = matSym.val.arr;
    if (i < 0 || i >= dimen->tam) return SymNull(self->lin, self->col);

    ArrayType *row = dimen->items[i].val.arr;
    if (j < 0 || j >= row->tam) return SymNull(self->lin, self->col);

    return row->items[j];
}

static Symbol EjecutarListaSet(NodoBase *self, AST *ast, void *env) {
    LISTA *d = (LISTA *)self;
    int i, j;
    Symbol matSym;
    ValidarIndices(d, ast, env, &i, &j, &matSym);

    ArrayType *dimen = matSym.val.arr;
    ArrayType *row = dimen->items[i].val.arr;
    Symbol val = NodoBase_Ejecutar(d->value, ast, env);
    row->items[j] = val;

    return SymNull(self->lin, self->col);
}

static void DestruirLista(NodoBase *self) {
    LISTA *d = (LISTA *)self;
    Symbol matSym = Env_GetVariable(NULL, d->nombre);
    if (matSym.val.arr) {
        ArrayType *dimen = matSym.val.arr;
        for (int i = 0; i < dimen->tam; i++) {
            ArrayType *row = dimen->items[i].val.arr;
            if (row) { free(row->items); free(row); }
        }
        free(dimen->items);
        free(dimen);
    }
    free(d);
}
LISTA *NewListaInici(int lin, int col, TipoExpresion tipo, char *nombre, NodoBase *lista) {
    LISTA *d = malloc(sizeof(LISTA));
    NodoBase_init(&d->base, "LISTA", lin, col, EjecutarLista, DestruirLista);
    d->tipo = tipo;
    d->nombre = nombre;
    d->filas = NULL;
    d->columnas = NULL;
    d->lista = lista;
    return d;
}

LISTA *NewLista(int lin, int col, TipoExpresion tipo, char *nombre, NodoBase *filas, NodoBase *columnas) {
    LISTA *d = malloc(sizeof(LISTA));
    NodoBase_init(&d->base, "LISTA", lin, col, EjecutarLista, DestruirLista);
    d->tipo = tipo;
    d->nombre = nombre;
    d->filas = filas;
    d->columnas = columnas;
    d->lista = NULL;
    return d;
}

LISTA *NewListaGET(int lin, int col, char *nombre, NodoBase *fila, NodoBase *columna) {
    LISTA *d = malloc(sizeof(LISTA));
    NodoBase_init(&d->base, "MATRIZ_GET", lin, col, EjecutarListaGet, DestruirLista);
    d->nombre = nombre;
    d->posFila = fila;
    d->posColumn = columna;
    return d;
}

LISTA *NewListaSET(int lin, int col, char *nombre, NodoBase *fila, NodoBase *columna, NodoBase *valor) {
    LISTA *d = malloc(sizeof(LISTA));
    NodoBase_init(&d->base, "MATRIZ_SET", lin, col, EjecutarListaSet, DestruirLista);
    d->nombre = nombre;
    d->posFila = fila;
    d->posColumn = columna;
    d->value = valor;
    return d;
}
