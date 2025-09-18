#ifndef ARRAY_H
#define ARRAY_H

#include "ast/AbstractTerminal.h"
#include "entorno/tipos.h"

typedef struct Array {
    NodoBase base;
    TipoExpresion tipo;
    char *iden;    
    char *identifer;   
    NodoBase *size;     
    NodoBase *list;   
    NodoBase *agreg;    
    NodoBase *index;   
    NodoBase *value;   
} Array;

typedef struct ArrForEach
{
    NodoBase base;
    char *ides;      
    char *vec;    
    NodoBase *scop;     
} ArrForEach;

// Constructor para declaracion normal
Array *NewArray(int lin, int col, TipoExpresion tipo, char *iden, NodoBase *size, NodoBase *list);

// Constructor para .add()
Array *NewArrayADD(int lin, int col, TipoExpresion tipo, char *nombreOriginal, char *nombreNuevo, NodoBase *agreg);

Array *NewArrayGET(int lin, int col, char *id, NodoBase *index);
Array *NewArraySET(int lin, int col, char *id, NodoBase *index, NodoBase *valor);

ArrForEach *NewArrForEach(int lin, int col, char *ides, char *vec, NodoBase *scop);

#endif

