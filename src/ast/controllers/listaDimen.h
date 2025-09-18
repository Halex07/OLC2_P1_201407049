#ifndef LISTADIMEN_H
#define LISTADIMEN_H

#include "ast/AbstractTerminal.h"
#include "entorno/tipos.h"

typedef struct LISTA {
    NodoBase base;
    TipoExpresion tipo;
    char *nombre;  
    NodoBase *lista;  
    NodoBase *value;
    NodoBase *filas;
    NodoBase *posFila;
    NodoBase *columnas;
    NodoBase *posColumn;
} LISTA;

LISTA *NewLista(int lin, int col, TipoExpresion tipo, char *nombre, NodoBase *filas, NodoBase *columnas);
LISTA *NewListaInici(int lin, int col, TipoExpresion tipo, char *nombre, NodoBase *lista);
LISTA *NewListaGET(int lin, int col, char *nombre, NodoBase *fila, NodoBase *columna);
LISTA *NewListaSET(int lin, int col, char *nombre, NodoBase *fila, NodoBase *columna, NodoBase *valor);

#endif
