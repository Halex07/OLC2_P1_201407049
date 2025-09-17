%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "ast/AbstractTerminal.h"
  #include "ast/expresiones/primitivos.h"
  #include "ast/expresiones/operacion.h"
  #include "ast/sentencias/print.h"
  #include "ast/sentencias/declaration.h"
  #include "ast/sentencias/assigment.h"
  #include "ast/expresiones/variable.h" 
  #include "ast/controllers/if.h"
  #include "ast/controllers/ifElse.h"
  #include "ast/sentencias/block.h"
  #include "ast/controllers/for.h"
  #include "ast/controllers/forEach.h"
  #include "ast/sentencias/continue.h"
  #include "ast/sentencias/params.h"
  #include "ast/sentencias/function.h"
  #include "ast/controllers/loopWhile.h"
  #include "ast/expresiones/callFunc.h"
  #include "ast/expresiones/args.h"
  #include "ast/sentencias/break.h"
  #include "ast/controllers/float.h"
  #include "ast/controllers/int.h"
  #include "ast/sentencias/return.h"
  #include "ast/controllers/array.h"
  #include "ast/controllers/casteo.h"
  #include "ast/controllers/listaDimen.h"
  #include "ast/controllers/switch.h"
  #include "ast/controllers/indexOf.h"
  #include "ast/controllers/length.h"
  #include "ast/controllers/add.h"
  #include "ast/controllers/valueof.h"
 

  extern int yylex(void);
  void yyerror(const char *s);

  /* Lista global de instrucciones */
  NodoBase* g_root = NULL;
  

%}

%define parse.error verbose
%locations
%debug

%union {
  double     dble;
  float      ftnt;
  NodoBase*  node;
  struct ArgList* args;  /* lista de argumentos */
  struct Param*   plist; /* lista de parámetros */  
  char*      str;
  char       ch;
  int         num;
  int tipo;
}
%token <ftnt> FLOAD
%token <str> STRING ID
%token <ch> CHAR
%token <dble> DECIMAL
%token <num> NUMBER TRUE FALSE
%token  BOOLEAN TP_DOUBLE TP_FLOAT TP_STRING TP_CHAR INTEGER_I INTEGER
%token GE LE EQ NEQ SHR SHL OR AND 
%token IF ELSE WHILE FOR FOREACH SWITCH CASE DEFAULT BREAK CONTINUE RETURN
%token PUBLIC STATIC VOID EQUALS  
%token INT NEW ARRAYS INDEXOF 
%token SYSTEM OUT PRINTLN VALUEOF PRINT JOIN ARRAY LENGTH ADD
%token PARSEINT PARSEFLOAT PARSEDOUBLE FINAL DOSPUNTOS 


%left '>' '<'
%left '+' '-'
%left '*' '/'
%right UMINUS

%type <node> program lines line expr declaration assigment block function callFunction loopFor multiDimension  
%type <node> loopWhile sentenciasIf sentenciasSwitch case_list case_stmt larray elementos 
%type <tipo> tipo
%type <plist> params paramlist
%type <args> args arglist

%start program 


%%

program
  : lines { g_root = $1; $$ = $1; }
  ;

lines
  : /* vacío */ { $$ = (NodoBase*)NewBlock(@$.first_line, @$.first_column); }
  | lines line  { addBlockStmt((Block*)$1, $2); $$ = $1; }
  ;

line
  : expr end                 { $$ = $1; }
  | SYSTEM '.' OUT '.' PRINTLN '(' expr')' end   { $$ = (NodoBase*)NewPrint(@1.first_line,@1.first_column,$7); }
  | SYSTEM '.' OUT '.' PRINTLN '('')' end   { $$ = (NodoBase*)NewPrint(@1.first_line,@1.first_column,NULL); }
  | declaration end          {  $$ = $1;  }
  | declaration              {  $$ = $1;  }
  | assigment end            {  $$ = $1;  }
  | assigment             {  $$ = $1;  }
  | block                    { $$ = $1; }
  | sentenciasIf {$$ = $1;}
  | loopWhile {$$ = $1;}
  | loopFor {$$ = $1;}
  | function                 { $$ = $1; }  
  | sentenciasSwitch {$$ = $1;}  
  | BREAK end{ $$ = (NodoBase*)NewBreak(@1.first_line,@1.first_column);}
  | RETURN expr end { $$ = (NodoBase*)NewReturn(@1.first_line,@1.first_column,$2);}
  | RETURN end { $$ = (NodoBase*)NewReturn(@1.first_line,@1.first_column,NULL);}
  | larray {$$ = $1;}
  | multiDimension {$$ = $1;}
  ;

sentenciasIf
   : IF '(' expr ')' block    { $$ = (NodoBase*)NewIf(@1.first_line,@1.first_column,$3,$5); }  
   | IF '(' expr ')' block ELSE block { $$ = (NodoBase*)NewElse(@1.first_line,@1.first_column,$3,$5,$7); }
   ;

loopWhile 
    : WHILE '(' expr ')' block { $$ = (NodoBase*)NewLoopWhile(@1.first_line,@1.first_column,$3,$5); }
    ;

loopFor 
    : FOR '(' declaration end expr end assigment ')' block { $$ = (NodoBase*)NewFor(@1.first_line,@1.first_column,$3,$5,$7,$9); }
    | FOR'(' tipo ID DOSPUNTOS  ID ')' block { $$ = (NodoBase*) NewForEach(@1.first_line, @1.first_column, $4, $6, $8); }
    ;

block
  : '{' lines '}'            { $$ = $2; }
  ;

end
  : ';'
  ;


case_list
    : /* vacío */ {
        $$ = (NodoBase*)NewSwitchArray(@$.first_line, @$.first_column, NULL);
    }
    | case_list case_stmt {
        $$ = $1;
        SwitchArray* tmp = (SwitchArray*)$$;
        AddCaseArray(tmp, ((SwitchArray*)$2)->cases[0].expr,
                          ((SwitchArray*)$2)->cases[0].block);
    }
    ;

case_stmt
    : CASE expr DOSPUNTOS lines {$$ = (NodoBase*)NewSwitchArray(@1.first_line, @1.first_column, NULL);
                                       AddCaseArray((SwitchArray*)$$, $2, $4);
    }
    | DEFAULT DOSPUNTOS lines {
        $$ = (NodoBase*)NewSwitchArray(@1.first_line, @1.first_column, NULL);
        AddCaseArray((SwitchArray*)$$, NULL, $3); 
    }
  ;

function
  : PUBLIC tipo ID '(' params ')' block {$$ = (NodoBase*)NewFunction(@1.first_line, @1.first_column, $3, $2, (Param*)$5, $7);}
  | PUBLIC STATIC tipo ID '(' params ')' block {$$ = (NodoBase*)NewFunction(@1.first_line, @1.first_column, $4, $3, (Param*)$6, $8);}
  ; 

params
  : /* vacío */ { $$ = NULL; }
  | paramlist { $$ = $1; }
  ;

paramlist
  : tipo ID {
    Param *p = NewParam(@1.first_line, @1.first_column, $2, $1);
    $$ = p;
  }
  | tipo ID ',' paramlist {
    Param *p = NewParam(@1.first_line, @1.first_column, $2, $1);
    p->next = $4;
    $$ = p;
  }
;

declaration
  : tipo ID '=' expr {$$ = (NodoBase*)NewDeclaration(@1.first_line,@1.first_column,$2,$1,$4);}
  | tipo ID {$$ = (NodoBase*)NewDeclaration(@1.first_line,@1.first_column,$2,$1,NULL);}
  | FINAL tipo ID '=' expr {$$ = (NodoBase*)NewDeclaration(@1.first_line,@1.first_column,$3,$2,$5);}
  ;

assigment
  : ID '=' expr {$$ = (NodoBase*)NewAssigment(@1.first_line,@1.first_column,$1,$3);}

multiDimension : tipo '[' ']' '[' ']' ID '=' NEW tipo '[' expr ']' '[' expr ']' end { $$ = (NodoBase*)NewLista(@1.first_line,@1.first_column,$1,$6,$11,$14);}
               | tipo '[' ']' '[' ']' ID '=' '{' elementos  '}' end { $$ = (NodoBase*)NewListaInici(@1.first_line, @1.first_column, $1, $6, $9); }
               ;
       
tipo
  : INTEGER   { $$ = T_INTEGER; }
  | TP_STRING { $$ = T_STRING; }
  | TP_FLOAT     { $$ = T_FLOAT; }
  | TP_DOUBLE    { $$ = T_DOUBLE;}
  | BOOLEAN   { $$ = T_BOOLEAN; }
  | TP_CHAR   { $$ = T_CHAR; }
  | VOID      { $$ = T_VOID; }
  | BREAK     { $$ = T_BREAK; }
  | ARRAY     { $$ = T_ARRAY; }
  | CONTINUE  { $$ = T_CONTINUE;}
  ;

expr
  : expr '+' expr            { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"+",$3); }
  | expr '-' expr            { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"-",$3); }
  | expr '*' expr            { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"*",$3); }
  | expr '/' expr            { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"/",$3); }
  | expr '%' expr            { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"%",$3); }
  | '-' expr %prec UMINUS    { $$ = (NodoBase*)NewOperation(@1.first_line,@1.first_column, (NodoBase*)NewPrimitive(@2.first_line,@2.first_column, SymInt(@2.first_line,@2.first_column,0)), "-", $2); }
  | expr AND expr            { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"&&",$3); }  
  | expr OR expr             { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"||",$3); }
  | expr LE expr        { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"<=",$3); }
  | expr GE expr        { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,">=",$3); }
  | expr '<' expr          { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"<",$3); }
  | expr '>' expr          { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,">",$3); }
  | expr EQ expr     { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"==",$3); }
  | expr NEQ expr      { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"!=",$3); }
  | expr '&' expr         { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"&",$3); }
  | expr '|' expr          { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"|",$3); }
  | expr '^' expr         { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"^",$3); }
  | expr SHR expr      { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,">>",$3); }
  | expr SHL expr      { $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"<<",$3); }
  | '!' expr                 { $$ = (NodoBase*)NewOperation(@1.first_line,@1.first_column, (NodoBase*)NewPrimitive(@2.first_line,@2.first_column, SymInt(@2.first_line,@2.first_column,0)), "!", $2); }
  | '(' expr ')'             { $$ = $2; }
  | '(' tipo ')' expr        {$$ = (NodoBase*)NewCasteo(@1.first_line,@1.first_column,$2,$4);}
  | VALUEOF '(' expr ')' { $$ = (NodoBase*)NewValueOf(@1.first_line,@1.first_column,$3); }
  | callFunction             { $$ = $1; }
  | ID '[' expr ']'{ $$ = (NodoBase*) NewArrayGET(@1.first_line, @1.first_column, $1, $3); }
  | ID '[' expr ']' '=' expr  {$$ = (NodoBase*) NewArraySET(@1.first_line, @1.first_column, $1, $3, $6);}
  | NUMBER {$$ = (NodoBase*)NewPrimitive(@1.first_line,@1.first_column, SymInt(@1.first_line,@1.first_column,$1));}
  | DECIMAL {$$ = (NodoBase*)NewPrimitive(@1.first_line,@1.first_column,SymDouble(@1.first_line,@1.first_column,$1));}
  | FLOAD {$$ = (NodoBase*)NewPrimitive(@1.first_line,@1.first_column, SymFloat(@1.first_line,@1.first_column, $1));}
  | STRING {$$ = (NodoBase*)NewPrimitive(@1.first_line,@1.first_column, SymStr(@1.first_line,@1.first_column,$1));}
  | CHAR {$$ = (NodoBase*)NewPrimitive(@1.first_line,@1.first_column, SymChar(@1.first_line,@1.first_column,$1));}
  | ID {$$ = (NodoBase*)NewVariable(@1.first_line,@1.first_column,$1);}
  | TRUE {$$ = (NodoBase*)NewPrimitive(@1.first_line,@1.first_column, SymBool(@1.first_line,@1.first_column,1));}
  | FALSE {$$ = (NodoBase*)NewPrimitive(@1.first_line,@1.first_column, SymBool(@1.first_line,@1.first_column,0));}
  | CONTINUE { $$ = (NodoBase*)NewContinue(@1.first_line,@1.first_column);}
  | ID '[' expr ']' '['expr']' {$$ = (NodoBase*) NewListaGET(@1.first_line, @1.first_column, $1, $3, $6);}
  | ID '[' expr ']' '['expr']' '=' expr {$$ = (NodoBase*) NewListaSET(@1.first_line, @1.first_column, $1, $3, $6,$9);}
  | ARRAYS '.' INDEXOF '(' expr ',' expr ')' {$$ = (NodoBase*)NewIndexOf(@1.first_line, @1.first_column, $5, $7); }
  | expr '.' EQUALS '(' expr ')'{ $$ = (NodoBase*)NewOperation(@2.first_line,@2.first_column,$1,"equals",$5); }
  | expr '.' LENGTH    { $$ = (NodoBase*) NewLength(@2.first_line, @2.first_column, $1); }
  | PARSEINT '(' expr ')' { $$ = (NodoBase*)NewInt(@1.first_line,@1.first_column,$3);}
  | PARSEFLOAT '(' expr ')' { $$ = (NodoBase*)NewFloat(@1.first_line,@1.first_column,$3); }
  ;

callFunction
  : ID '(' args ')' {$$ = (NodoBase*)NewCallFunc(@1.first_line, @1.first_column, $1, $3);}
  ;

args
  : /* vacío */ { $$ = NULL; }
  | arglist     { $$ = $1; }
  ;

arglist
  : expr             { $$ = NewArgList($1, NULL); }
  | expr ',' arglist { $$ = NewArgList($1, $3); }
  ;

sentenciasSwitch 
    : SWITCH '(' expr ')' '{' case_list '}' {
        $$ = (NodoBase*)NewSwitchArray(@1.first_line, @1.first_column, $3);     
        SwitchArray* tmp = (SwitchArray*)$6;
        for (int i = 0; i < tmp->count; i++) {
            AddCaseArray((SwitchArray*)$$, tmp->cases[i].expr, tmp->cases[i].block);
        }
         
    }
;
elementos 
  : expr ',' elementos       { $1->siguiente = $3; $$ = $1; }
  | elementos ',' elementos  { NodoBase *last = $1; while (last->siguiente) last = last->siguiente; last->siguiente = $3; $$ = $1;}
  | '{' elementos  '}'       { $$ = $2; }  
  | expr                     { $$ = $1; }
  ;

  larray : tipo '[' ']' ID '=' NEW tipo '[' expr ']' end   { $$ = (NodoBase*)NewArray(@1.first_line, @1.first_column, $1, $4, $9, NULL); }
       | tipo '[' ']' ID '=' '{' elementos '}' end       { $$ = (NodoBase*)NewArray(@1.first_line, @1.first_column, $1, $4, NULL, $7); }
       | tipo '[' ']' ID '=' ID '.' ADD '(' expr ')' end { $$ = (NodoBase*)NewArrayADD(@1.first_line,@1.first_column,$1,$6,$4,$10);}
       ;

%%
void yyerror(const char *s) {
  fprintf(stderr, "Error de sintaxis: %s\n", s);
}
