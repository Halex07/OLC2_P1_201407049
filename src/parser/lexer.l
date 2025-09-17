%option noyywrap nodefault noinput nounput
%{
  #include <stdlib.h>
  typedef struct NodoBase NodoBase;
  #include "parser.tab.h"
%}


DIGIT   [0-9]
DCIMAL    [0-9]+"."[0-9]+
FLTANT    [0-9]+"."[0-9]+[Ff]
NUM     {DIGIT}+
STR   \"([^\\\n]|\\.)*\"
CH  \'([^\\\n]|\\.)\'
ID [A-Za-z_][A-Za-z0-9_]*

%%

"join"                 { return JOIN; }
"indexOf"              { return INDEXOF; }
"Arrays"               { return ARRAYS; }
"length"               { return LENGTH; }
"add"                  { return ADD; }
"final"                { return FINAL; }
"case"                 { return CASE; }
"switch"               { return SWITCH; }
"default"              { return DEFAULT; }
"for"                  { return FOR; }
"while"                { return WHILE; }
"forEach"              { return FOREACH; }
"if"                   { return IF; }
"else"                 { return ELSE; }
"break"                { return BREAK; }
"return"               { return RETURN; }
"continue"             { return CONTINUE; }
"void"                 { return VOID; }
"static"               { return STATIC; }
"public"               { return PUBLIC; }
"new"                  { return NEW; }
"equals"               { return EQUALS; }
"print"                { return PRINT; }
"out"                  { return OUT; }
"System"               { return SYSTEM; }
"println"              { return PRINTLN; }
"true"                 { return TRUE; }
"array"                { return ARRAY; }
"false"                { return FALSE; }
"String.valueOf"       { return VALUEOF; }
"Integer.parseInt"     { return PARSEINT; }
"Float.parseFloat"     { return PARSEFLOAT; }
"Double.parseDouble"   { return PARSEDOUBLE; }


{DCIMAL}              { yylval.dble = atof(yytext); return DECIMAL; }
{FLTANT}              { yylval.ftnt = atof(yytext); return FLOAD; }
{NUM}                 { yylval.num=atoi(yytext); return NUMBER;}
{STR}                 { yylval.str = strdup(yytext + 1); yylval.str[strlen(yylval.str) - 1] = '\0'; return STRING; }
{CH}                  { yylval.ch = yytext[1]; return CHAR; }
double                {return TP_DOUBLE;}
int                   { return INTEGER; }
float                 { return TP_FLOAT; }
Integer               { return INTEGER_I; }
String                { return TP_STRING; }
char                  { return TP_CHAR; }
boolean               { return BOOLEAN; }
{ID}                  { yylval.str = strdup(yytext); return ID; }


[ \t\r\n]+              { /* skip */ }
"//".*                { /* ignora comentarios de una línea */ }
"/*"([^*]|\*+[^*/])*\*+"/"   { /* ignora comentarios de múltiples líneas */ }

":"                   { return DOSPUNTOS; }
"+"                   { return '+'; }
"/"                   { return '/'; }
"-"                   { return '-'; }
"*"                   { return '*'; }
"%"                   { return '%'; }
"["                   { return '['; }
"]"                   { return ']'; }
"("                   { return '('; }
")"                   { return ')'; }
"{"                   { return '{'; }
"}"                   { return '}'; }
";"                   { return ';'; }
","                   { return ','; }
"."                   { return '.'; } 
"=="   { return EQ; }
"!="   { return NEQ; }
"<="   { return LE; }
"<"    { return '<'; }
">="   { return GE; }
">"    { return '>'; }
"="    { return '='; }
"<<"   { return SHL; }
">>"   { return SHR; }
"||"   { return OR; }
"&&"   { return AND; }
"&"    { return '&'; }
"|"    { return '|'; }
"^"    { return '^'; }
"!"    { return '!'; }
.                     { /* ignora otros */ }
%%
