#ifndef SYMBOL_H
#define SYMBOL_H

#include "entorno/tipos.h"
#include "helpers/helper.h"

 
typedef struct Symbol Symbol;

typedef struct
{
    int tam;
    Symbol *items;   
} ArrayType;

struct Symbol
{
    int lin;
    int col;
    TipoExpresion tipo;
    union
    {
        int i;
        double d;
        float fl;
        char *s;
        char c;
        ArrayType *arr;
    } val;
};

static inline Symbol SymInt(int lin, int col, int v)
{
  Symbol s = {lin, col, T_INTEGER, {0}};
  s.val.i = v;
  return s;
}
static inline Symbol SymDouble(int lin, int col, double v){
  Symbol s = {lin, col, T_DOUBLE, {0}};
  s.val.d = v; 
  return s;
}
static inline Symbol SymFloat(int lin, int col, float v)
{
  Symbol s = {lin, col, T_FLOAT, {0}};
  s.val.fl = v;
  return s;
}
static inline Symbol SymBool(int lin, int col, int v)
{
  Symbol s = {lin, col, T_BOOLEAN, {0}};
  s.val.i = !!v;
  return s;
}
static inline Symbol SymStr(int lin, int col, const char *v)
{
  Symbol s = {lin, col, T_STRING, {0}};
  s.val.s = v ? strDuplicate(v) : NULL;
  return s;
}
static inline Symbol SymChar(int lin, int col, char v)
{
  Symbol s = {lin, col, T_CHAR, {0}};
  s.val.c = v;
  return s;
}
//array
static inline Symbol SymArray(int lin, int col, ArrayType *v)
{
  Symbol s = {lin, col, T_ARRAY, {0}};
  s.val.arr = v;
  return s;
}
static inline Symbol SymNull(int lin, int col)
{
  Symbol s = {lin, col, T_NULL, {0}};
  return s;
}

#endif