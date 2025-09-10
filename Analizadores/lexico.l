%{
#include "parser.tab.h"  // generado por Bison
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para errores léxicos
typedef struct {
    char* tipo;
    char* mensaje;
    int linea;
    int columna;
} Error;

Error* crearError(const char* tipo, const char* mensaje, int linea, int columna) {
    Error* err = (Error*)malloc(sizeof(Error));
    err->tipo = strdup(tipo);
    err->mensaje = strdup(mensaje);
    err->linea = linea;
    err->columna = columna;
    return err;
}

// Lista de errores (puedes adaptarla a tu sistema)
Error* listaErrores[1000];
int numErrores = 0;

int yyline = 1;
int yycolumn = 1;
%}

%option noyywrap
%option case-insensitive

DIGIT      [0-9]
LETTER     [a-zA-Z]
ID         {LETTER}({LETTER}|{DIGIT}|_)*
ENTERO     {DIGIT}+
DECIMAL    {DIGIT}"."{DIGIT}+
CADENA     \"([^"])*\"

BLANCOS    [ \t\r\f]+
NUEVA_LINEA \n

%%

// Palabras reservadas
"println"       { return PRINTLN; }
"int"           { return INT; }
"double"        { return DOUBLE; }
"string"        { return STRING; }
"char"          { return CHAR; }
"true"          { return TRUE; }
"false"         { return FALSE; }
"if"            { return IF; }
"match"         { return MATCH; }
"bool"          { return BOOL; }
"for"           { return FOR; }
"while"         { return WHILE; }
"dowhile"       { return DOWHILE; }
"var"           { return VAR; }
"const"         { return CONST; }
"break"         { return BREAK; }

// Símbolos
"("             { return PAR1; }
")"             { return PAR2; }
"{"             { return LLAVE1; }
"}"             { return LLAVE2; }
"+"             { return MAS; }
"-"             { return MENOS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"="             { return IGUAL; }
";"             { return FINCADENA; }
"<"             { return MENOR; }
">"             { return MAYOR; }
"!"             { return DIF; }
"|"             { return BARRA; }
"&"             { return AMP; }
"^"             { return CASA; }

// Literales
{DECIMAL}       { yylval.str = strdup(yytext); return DECIMAL; }
{ENTERO}        { yylval.str = strdup(yytext); return ENTERO; }
{ID}            { yylval.str = strdup(yytext); return ID; }
{CADENA}        {
                    char* texto = strdup(yytext);
                    texto[strlen(texto)-1] = '\0'; // quitar comillas
                    yylval.str = texto + 1;
                    return CADENA;
                }

// Espacios y líneas
{BLANCOS}       { yycolumn += yyleng; }
{NUEVA_LINEA}   { yyline++; yycolumn = 1; }

// Caracter no reconocido
.               {
                    char mensaje[128];
                    snprintf(mensaje, sizeof(mensaje), "El caracter '%s' NO pertenece al lenguaje", yytext);
                    listaErrores[numErrores++] = crearError("LEXICO", mensaje, yyline, yycolumn);
                }

%%

int yywrap() {
    return 1;
}
