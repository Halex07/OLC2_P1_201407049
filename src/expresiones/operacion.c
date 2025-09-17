#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ast/expresiones/operacion.h"

static int isInt(Symbol s) { return s.tipo == T_INTEGER; }
static int isDlt(Symbol s) { return s.tipo == T_DOUBLE; }
static int isFlt(Symbol s) { return s.tipo == T_FLOAT; }
static int isStr(Symbol s) { return s.tipo == T_STRING;}
static int isBlan(Symbol s) { return s.tipo == T_BOOLEAN; }
static int isChar(Symbol s) { return s.tipo == T_CHAR; }

static char* asStr(Symbol s) {
    static char buffer[128];
    switch (s.tipo) {
        case T_STRING:
            return s.val.s;
        case T_INTEGER:
            snprintf(buffer, sizeof(buffer), "%d", s.val.i);
            return buffer;
        case T_DOUBLE:
            snprintf(buffer, sizeof(buffer), "%lf", s.val.d);
            return buffer;
        case T_FLOAT:
            snprintf(buffer, sizeof(buffer), "%f", s.val.fl);
            return buffer;
        case T_BOOLEAN:
            return s.val.i ? "true" : "false";
        case T_CHAR:
            snprintf(buffer, sizeof(buffer), "%c", s.val.c);
            return buffer;
        default:
            return "";
    }
}

static Symbol Ejecutar(NodoBase *self, AST *ast, void *env)
{
  Operation *o = (Operation *)self;
  Symbol a = NodoBase_Ejecutar(o->izq, ast, env);
  Symbol b = NodoBase_Ejecutar(o->der, ast, env);

if (strcmp(o->op, "+") == 0) {
    if (isStr(a) || isStr(b)) {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s%s", asStr(a), asStr(b));
        return SymStr(o->base.lin, o->base.col, strdup(buffer));
    }

    if (isInt(a) && isInt(b))
        return SymInt(o->base.lin, o->base.col, a.val.i + b.val.i);
    if (isInt(a) && isChar(b))
        return SymInt(o->base.lin, o->base.col, a.val.i + b.val.c);
    if (isInt(a) && isFlt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.i + b.val.fl);
    if (isInt(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.i + b.val.d);

    if (isDlt(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d + b.val.d);
    if (isDlt(a) && isChar(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d + b.val.c);
    if (isDlt(a) && isInt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d + b.val.i);
    if (isDlt(a) && isFlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d + b.val.fl);

    if (isFlt(a) && isFlt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.fl + b.val.fl);
    if (isFlt(a) && isChar(b))
        return SymFloat(o->base.lin, o->base.col, a.val.fl + b.val.c);
    if (isFlt(a) && isInt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.fl + b.val.i);
    if (isFlt(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.fl + b.val.d);

    if (isChar(a) && isChar(b))
        return SymInt(o->base.lin, o->base.col, a.val.c + b.val.c);
    if (isChar(a) && isInt(b))
        return SymInt(o->base.lin, o->base.col, a.val.c + b.val.i);
    if (isChar(a) && isFlt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.c + b.val.fl);
    if (isChar(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.c + b.val.d);

    AST_SetError(ast, "Errror: Semantico operacion no valida para la suma");
    return SymNull(o->base.lin, o->base.col);
}
if (strcmp(o->op, "-") == 0)
{
    if (isStr(a) || isStr(b)) {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s%s", asStr(a), asStr(b));
        return SymStr(o->base.lin, o->base.col, strdup(buffer));
    }
    if (isInt(a) && isInt(b)) return SymInt(o->base.lin, o->base.col, a.val.i - b.val.i);
    if (isInt(a) && isChar(b)) return SymInt(o->base.lin, o->base.col, a.val.i - b.val.c);
    if (isInt(a) && isFlt(b)) return SymFloat(o->base.lin, o->base.col, a.val.i - b.val.fl);
    if (isInt(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.i - b.val.d);

    if (isDlt(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.d - b.val.d);
    if (isDlt(a) && isChar(b)) return SymDouble(o->base.lin, o->base.col, a.val.d - b.val.c);
    if (isDlt(a) && isInt(b)) return SymDouble(o->base.lin, o->base.col, a.val.d - b.val.i);
    if (isDlt(a) && isFlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.d - b.val.fl);

    if (isFlt(a) && isFlt(b)) return SymFloat(o->base.lin, o->base.col, a.val.fl - b.val.fl);
    if (isFlt(a) && isChar(b)) return SymFloat(o->base.lin, o->base.col, a.val.fl - b.val.c);
    if (isFlt(a) && isInt(b)) return SymFloat(o->base.lin, o->base.col, a.val.fl - b.val.i);
    if (isFlt(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.fl - b.val.d);

    if (isChar(a) && isChar(b)) return SymInt(o->base.lin, o->base.col, a.val.c - b.val.c);
    if (isChar(a) && isInt(b)) return SymInt(o->base.lin, o->base.col, a.val.c - b.val.i);
    if (isChar(a) && isFlt(b)) return SymFloat(o->base.lin, o->base.col, a.val.c - b.val.fl);
    if (isChar(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.c - b.val.d);

    AST_SetError(ast, "ERROR: Semantico operacion navalida para la resta");
    return SymNull(o->base.lin, o->base.col);
}
if (strcmp(o->op, "*") == 0)
{
    if (isStr(a) || isStr(b)) {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s%s", asStr(a), asStr(b));
        return SymStr(o->base.lin, o->base.col, strdup(buffer));
    }
    if (isInt(a) && isInt(b)) return SymInt(o->base.lin, o->base.col, a.val.i * b.val.i);
    if (isInt(a) && isChar(b)) return SymInt(o->base.lin, o->base.col, a.val.i * b.val.c);
    if (isInt(a) && isFlt(b)) return SymFloat(o->base.lin, o->base.col, a.val.i * b.val.fl);
    if (isInt(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.i * b.val.d);

    if (isDlt(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.d * b.val.d);
    if (isDlt(a) && isChar(b)) return SymDouble(o->base.lin, o->base.col, a.val.d * b.val.c);
    if (isDlt(a) && isInt(b)) return SymDouble(o->base.lin, o->base.col, a.val.d * b.val.i);
    if (isDlt(a) && isFlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.d * b.val.fl);

    if (isFlt(a) && isFlt(b)) return SymFloat(o->base.lin, o->base.col, a.val.fl * b.val.fl);
    if (isFlt(a) && isChar(b)) return SymFloat(o->base.lin, o->base.col, a.val.fl * b.val.c);
    if (isFlt(a) && isInt(b)) return SymFloat(o->base.lin, o->base.col, a.val.fl * b.val.i);
    if (isFlt(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.fl * b.val.d);

    if (isChar(a) && isChar(b)) return SymInt(o->base.lin, o->base.col, a.val.c * b.val.c);
    if (isChar(a) && isInt(b)) return SymInt(o->base.lin, o->base.col, a.val.c * b.val.i);
    if (isChar(a) && isFlt(b)) return SymFloat(o->base.lin, o->base.col, a.val.c * b.val.fl);
    if (isChar(a) && isDlt(b)) return SymDouble(o->base.lin, o->base.col, a.val.c * b.val.d);

    AST_SetError(ast, "ERROR: Semantico operacion no validad para el producto");
    return SymNull(o->base.lin, o->base.col);
}  
if (strcmp(o->op, "/") == 0)
{
    if (isInt(a) && isInt(b))
        return SymInt(o->base.lin, o->base.col, a.val.i / b.val.i);
    if (isInt(a) && isChar(b))
        return SymInt(o->base.lin, o->base.col, a.val.i / b.val.c);
    if (isInt(a) && isFlt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.i / b.val.fl);
    if (isInt(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.i / b.val.d);
    if (isInt(a) && isStr(b)) {
        AST_SetError(ast, " Error division entero con cadena null ");
        return SymNull(o->base.lin, o->base.col);
    }

    if (isDlt(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d / b.val.d);
    if (isDlt(a) && isChar(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d / b.val.c);
    if (isDlt(a) && isInt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d / b.val.i);
    if (isDlt(a) && isFlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.d / b.val.fl);
    if (isDlt(a) && isStr(b)) {
        AST_SetError(ast, " Error deivion double con cadena null ");
        return SymNull(o->base.lin, o->base.col);
    }

    if (isFlt(a) && isFlt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.fl / b.val.fl);
    if (isFlt(a) && isChar(b))
        return SymFloat(o->base.lin, o->base.col, a.val.fl / b.val.c);
    if (isFlt(a) && isInt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.fl / b.val.i);
    if (isFlt(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.fl / b.val.d);
    if (isFlt(a) && isStr(b)) {
        AST_SetError(ast, " Error deivion float con cadena null ");
        return SymNull(o->base.lin, o->base.col);
    }

    if (isChar(a) && isChar(b))
        return SymInt(o->base.lin, o->base.col, a.val.c / b.val.c);
    if (isChar(a) && isInt(b))
        return SymInt(o->base.lin, o->base.col, a.val.c / b.val.i);
    if (isChar(a) && isFlt(b))
        return SymFloat(o->base.lin, o->base.col, a.val.c / b.val.fl);
    if (isChar(a) && isDlt(b))
        return SymDouble(o->base.lin, o->base.col, a.val.c / b.val.d);
    if (isChar(a) && isStr(b)) {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s%s", asStr(a), asStr(b));
        return SymStr(o->base.lin, o->base.col, strdup(buffer));
    }

    if (isStr(a) && isStr(b)) {
        AST_SetError(ast, " Error deivion cadena con cadena null ");
        return SymNull(o->base.lin, o->base.col);
    }
    if (isStr(a) && isInt(b)) {
        AST_SetError(ast, " Error deivion cadena con entero null ");
        return SymNull(o->base.lin, o->base.col);
    }
    if (isStr(a) && isChar(b)) {
        AST_SetError(ast, " Error deivion cadena con caracter null ");
        return SymNull(o->base.lin, o->base.col);
    }
    if (isStr(a) && isDlt(b)) {
        AST_SetError(ast, " Error deivion cadenacon double null ");
        return SymNull(o->base.lin, o->base.col);
    }
    if (isStr(a) && isFlt(b)) {
        AST_SetError(ast, " Error deivion cadena con float null ");
        return SymNull(o->base.lin, o->base.col);
    }

    AST_SetError(ast, "ERROR: Semantico operacion de division no valida ");
    return SymNull(o->base.lin, o->base.col);
}
if (strcmp(o->op, "%") == 0)
{
    if (isInt(a) && isInt(b))
        return SymInt(o->base.lin, o->base.col, a.val.i % b.val.i);

    if (isInt(a) && isChar(b))
        return SymInt(o->base.lin, o->base.col, a.val.i % b.val.c);

    if (isChar(a) && isChar(b))
        return SymInt(o->base.lin, o->base.col, a.val.c % b.val.c);

    if (isChar(a) && isInt(b))
        return SymInt(o->base.lin, o->base.col, a.val.c % b.val.i);

    if (isBlan(a) && isBlan(b))
        return SymBool(o->base.lin, o->base.col, a.val.s && b.val.s);

    if (isInt(a) && isBlan(b))
        return SymBool(o->base.lin, o->base.col, a.val.i && b.val.i);

    AST_SetError(ast, "ERROR: Semantico operacion de modulo no valida");
    return SymNull(o->base.lin, o->base.col);
}
  if (strcmp(o->op, "unario") == 0)
  {
    if (isInt(a))
      return SymInt(o->base.lin, o->base.col, -1 * a.val.i);    
    if (isInt(b))    
      return SymInt(o->base.lin, o->base.col, -1 * b.val.i);    
    if (isDlt(a))    
      return SymDouble(o->base.lin, o->base.col, -1 * a.val.i);    
    if (isDlt(b))    
      return SymDouble(o->base.lin, o->base.col, -1 * b.val.i);    
    if (isFlt(a))    
      return SymFloat(o->base.lin, o->base.col, -1 * a.val.i);    
    if (isFlt(b))    
      return SymFloat(o->base.lin, o->base.col, -1 * b.val.i);

    AST_SetError(ast, "ERROR: Semantico operacion de negacion no valida");
    return SymNull(o->base.lin, o->base.col);
  }

  if (strcmp(o->op, "<") == 0)
  {
 
    if (isInt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i < b.val.i);
    if (isInt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.i < b.val.c);
    if (isInt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i < b.val.fl);
    if (isInt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i < b.val.d);

    if (isDlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d < b.val.d);
    if (isDlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.d < b.val.c);
    if (isDlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d < b.val.i);
    if (isDlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d < b.val.fl);
 
    if (isFlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl < b.val.fl);
    if (isFlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl < b.val.c);
    if (isFlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl < b.val.i);
    if (isFlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl < b.val.d);

    if (isChar(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.c < b.val.c);
    if (isChar(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c < b.val.i);
    if (isChar(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c < b.val.fl);
    if (isChar(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c < b.val.d);

    AST_SetError(ast, "ERROR: Semantico operador < no valida ");
    return SymNull(o->base.lin, o->base.col);
  }

  if (strcmp(o->op, ">") == 0)
  {
    if (isInt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i > b.val.i);
    if (isInt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.i > b.val.c);
    if (isInt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i > b.val.fl);
    if (isInt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i > b.val.d);
   
    if (isDlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d > b.val.d);
    if (isDlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.d > b.val.c);
    if (isDlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d > b.val.i);
    if (isDlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d > b.val.fl);
  
    if (isFlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl > b.val.fl);
    if (isFlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl > b.val.c);
    if (isFlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl > b.val.i);
    if (isFlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl > b.val.d);
  
    if (isChar(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.c > b.val.c);
    if (isChar(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c > b.val.i);
    if (isChar(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c > b.val.fl);
    if (isChar(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c > b.val.d);

    AST_SetError(ast, "ERROR: Semantico operador > no valida ");
    return SymNull(o->base.lin, o->base.col);
  }
  if (strcmp(o->op, "<=") == 0)
  {
    if (isInt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i <= b.val.i);
    if (isInt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.i <= b.val.c);
    if (isInt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i <= b.val.fl);
    if (isInt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i <= b.val.d);

    if (isDlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d <= b.val.d);
    if (isDlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.d <= b.val.c);
    if (isDlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d <= b.val.i);
    if (isDlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d <= b.val.fl);
 
    if (isFlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl <= b.val.fl);
    if (isFlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl <= b.val.c);
    if (isFlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl <= b.val.i);
    if (isFlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl <= b.val.d);
  
    if (isChar(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.c <= b.val.c);
    if (isChar(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c <= b.val.i);
    if (isChar(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c <= b.val.fl);
    if (isChar(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c <= b.val.d);

    AST_SetError(ast, "ERROR: Semantico operador <= no valida ");
    return SymNull(o->base.lin, o->base.col);
  }
  if (strcmp(o->op, ">=") == 0)
  {
    if (isInt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i >= b.val.i);
    if (isInt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.i >= b.val.c);
    if (isInt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i >= b.val.fl);
    if (isInt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i >= b.val.d);
 
    if (isDlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d >= b.val.d);
    if (isDlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.d >= b.val.c);
    if (isDlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d >= b.val.i);
    if (isDlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d >= b.val.fl);
  
    if (isFlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl >= b.val.fl);
    if (isFlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl >= b.val.c);
    if (isFlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl >= b.val.i);
    if (isFlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl >= b.val.d);
  
    if (isChar(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.c >= b.val.c);
    if (isChar(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c >= b.val.i);
    if (isChar(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c >= b.val.fl);
    if (isChar(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c >= b.val.d);

    AST_SetError(ast, "ERROR: Semantico operador >= no valida ");
    return SymNull(o->base.lin, o->base.col);
  }
  if (strcmp(o->op, "==") == 0)
  {
    if (isInt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i == b.val.i);
    if (isInt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.i == b.val.c);
    if (isInt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i == b.val.fl);
    if (isInt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i == b.val.d);

    if (isDlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d == b.val.d);
    if (isDlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.d == b.val.c);
    if (isDlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d == b.val.i);
    if (isDlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d == b.val.fl);
 
    if (isFlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl == b.val.fl);
    if (isFlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl == b.val.c);
    if (isFlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl == b.val.i);
    if (isFlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl == b.val.d);
 
    if (isChar(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.c == b.val.c);
    if (isChar(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c == b.val.i);
    if (isChar(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c == b.val.fl);
    if (isChar(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c == b.val.d);
   
    if (isBlan(a) && isBlan(b))
      return SymBool(o->base.lin, o->base.col, a.val.i == b.val.i);

    AST_SetError(ast, "ERROR: Semantico operador == no valido ");
    return SymNull(o->base.lin, o->base.col);
  }
  if (strcmp(o->op, "&&") == 0)
  {
    if (isBlan(a) && isBlan(b))    
      return SymBool(o->base.lin, o->base.col, a.val.i && b.val.i);    

    AST_SetError(ast, "ERROR: Operador AND no soportado\n");
    return SymNull(o->base.lin, o->base.col);
  }
  if (strcmp(o->op, "||") == 0)
  {
    if (isBlan(a) && isBlan(b))
      return SymBool(o->base.lin, o->base.col, a.val.i || b.val.i);

    AST_SetError(ast, "ERROR: Operador OR no soportado\n");
    return SymNull(o->base.lin, o->base.col);
  }
  if (strcmp(o->op, "equals") == 0)
  {
    int resultado = strcmp(a.val.s, b.val.s) == 0;
    return SymBool(o->base.lin, o->base.col, resultado);
  }
  if (strcmp(o->op, "!") == 0) {
      if (isBlan(a)) 
          return SymBool(o->base.lin, o->base.col, !a.val.s);    
  }


  if (strcmp(o->op, "!=") == 0)
  { /* === BOOLEAN === */
    if (isBlan(a) && isBlan(b))
      return SymBool(o->base.lin, o->base.col, a.val.i != b.val.i);
  
    if (isInt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i != b.val.i);
    if (isInt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.i != b.val.c);
    if (isInt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i != b.val.fl);
    if (isInt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.i != b.val.d);
   
    if (isDlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d != b.val.d);
    if (isDlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.d != b.val.c);
    if (isDlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d != b.val.i);
    if (isDlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.d != b.val.fl);
   
    if (isFlt(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl != b.val.fl);
    if (isFlt(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl != b.val.c);
    if (isFlt(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl != b.val.i);
    if (isFlt(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.fl != b.val.d);
   
    if (isChar(a) && isChar(b))
      return SymBool(o->base.lin, o->base.col, a.val.c != b.val.c);
    if (isChar(a) && isInt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c != b.val.i);
    if (isChar(a) && isFlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c != b.val.fl);
    if (isChar(a) && isDlt(b))
      return SymBool(o->base.lin, o->base.col, a.val.c != b.val.d);

    AST_SetError(ast, "ERROR: Semantico operador != no valida ");
    return SymNull(o->base.lin, o->base.col);
  } 
  if (strcmp(o->op, "|") == 0)
  {
    if (isInt(a) && isInt(b))
      return SymInt(o->base.lin, o->base.col, a.val.i | b.val.i);
  }
  if (strcmp(o->op, "&") == 0)
  {
    if (isInt(a) && isInt(b))
      return SymInt(o->base.lin, o->base.col, a.val.i & b.val.i);
  } 
  if (strcmp(o->op, ">>") == 0)
  {
    if (isInt(a) && isInt(b))
    return SymInt(o->base.lin, o->base.col, a.val.i >> b.val.i);
  }
  if (strcmp(o->op, "<<") == 0)
  {
    if (isInt(a) && isInt(b))
    return SymInt(o->base.lin, o->base.col, a.val.i << b.val.i);    
  }
  if (strcmp(o->op, "^") == 0)
  {
    if (isInt(a) && isInt(b))
      return SymInt(o->base.lin, o->base.col, a.val.i ^ b.val.i);
  }
  AST_SetError(ast, "ERROR: Operador no soportado");
  return SymNull(o->base.lin, o->base.col);
}

static void Destruir(NodoBase *self)
{
  Operation *o = (Operation *)self;
  NodoBase_Destruir(o->izq);
  NodoBase_Destruir(o->der);
  free(self);
}

Operation *NewOperation(int lin, int col, NodoBase *izq, const char *op, NodoBase *der)
{
  Operation *n = (Operation *)malloc(sizeof(Operation));
  NodoBase_init(&n->base, "Operation", lin, col, Ejecutar, Destruir);
  n->izq = izq;
  n->op = op;
  n->der = der;
  return n;
}