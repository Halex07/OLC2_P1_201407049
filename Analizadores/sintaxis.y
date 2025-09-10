%{
/* Código C/C++ de inclusión */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "scanner.hpp"
#include "ast.hpp" // Aquí defines tus clases como Instruccion, Print, etc.

std::vector<Errores> listaErrores;
%}

/* Declaración de tokens */
%token CADENA ENTERO DECIMAL ID
%token FINCADENA PRINTLN INT DOUBLE STRING
%token PAR1 PAR2 MAS MENOS UMENOS
%token MULT DIV MOD POTENCIA
%token IGUAL EQUALS NOEQUALS MAYOR MAYOREQ MENOREQ
%token TRUE FALSE IF BOOL MATCH
%token LLAVE1 LLAVE2
%token FOR MENOR DIF WHILE DOWHILE
%token CASA AMP BARRA OR AND XOR NOT
%token VAR CONST BREAK

/* Precedencias */
%left OR
%left AND
%left XOR
%right NOT
%left EQUALS NOEQUALS MAYOR MENOR MAYOREQ MENOREQ DIF
%left MAS MENOS
%left MULT DIV MOD
%right POTENCIA
%left UMENOS

/* Tipos de retorno */
%union {
    Instruccion* instr;
    std::vector<Instruccion*>* instrList;
    Tipo* tipo;
    Expresion* expr;
    char* text;
    int number;
    double decimal;
}

/* Tipos asociados a tokens */
%type <instr> INSTRUCCION IMPRESION DECLARACION ASIGNACION SIF SMATCH CFOR CWHILE CDOWHILE BREAKK ACTUALIZA_FOR
%type <instrList> INICIO INSTRUCCIONES
%type <tipo> TIPOS
%type <expr> EXPRESION

%%

/* Reglas gramaticales */
INICIO:
    INSTRUCCIONES { $$ = $1; }
;

INSTRUCCIONES:
    INSTRUCCIONES INSTRUCCION { $1->push_back($2); $$ = $1; }
  | INSTRUCCION { $$ = new std::vector<Instruccion*>(); $$->push_back($1); }
;

INSTRUCCION:
    IMPRESION
  | DECLARACION
  | ASIGNACION
  | SIF
  | SMATCH
  | CFOR
  | CWHILE
  | CDOWHILE
  | BREAKK
;

IMPRESION:
    PRINTLN PAR1 EXPRESION PAR2 FINCADENA { $$ = new Print($3); }
;

DECLARACION:
    TIPOS ID IGUAL EXPRESION FINCADENA { $$ = new Declaracion($2, $4, $1); }
  | VAR ID ':' ID EQUALS EXPRESION FINCADENA { $$ = new Declaracion($2, $6, new Tipo($4)); }
  | CONST ID ':' ID EQUALS EXPRESION FINCADENA { $$ = new Declaracion($2, $6, new Tipo($4)); }
;

ASIGNACION:
    ID IGUAL EXPRESION FINCADENA { $$ = new AsignacionVar($1, $3); }
;

SIF:
    IF PAR1 EXPRESION PAR2 LLAVE1 INSTRUCCIONES LLAVE2 { $$ = new If($3, $6); }
;

/* ... y así sucesivamente para las demás reglas ... */

%%

/* Manejo de errores */
void yyerror(const char* msg) {
    fprintf(stderr, "Error sintáctico: %s\n", msg);
}
