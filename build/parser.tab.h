/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FLOAD = 258,                   /* FLOAD  */
    STRING = 259,                  /* STRING  */
    ID = 260,                      /* ID  */
    CHAR = 261,                    /* CHAR  */
    DECIMAL = 262,                 /* DECIMAL  */
    NUMBER = 263,                  /* NUMBER  */
    TRUE = 264,                    /* TRUE  */
    FALSE = 265,                   /* FALSE  */
    BOOLEAN = 266,                 /* BOOLEAN  */
    TP_DOUBLE = 267,               /* TP_DOUBLE  */
    TP_FLOAT = 268,                /* TP_FLOAT  */
    TP_STRING = 269,               /* TP_STRING  */
    TP_CHAR = 270,                 /* TP_CHAR  */
    INTEGER_I = 271,               /* INTEGER_I  */
    INTEGER = 272,                 /* INTEGER  */
    GE = 273,                      /* GE  */
    LE = 274,                      /* LE  */
    EQ = 275,                      /* EQ  */
    NEQ = 276,                     /* NEQ  */
    SHR = 277,                     /* SHR  */
    SHL = 278,                     /* SHL  */
    OR = 279,                      /* OR  */
    AND = 280,                     /* AND  */
    IF = 281,                      /* IF  */
    ELSE = 282,                    /* ELSE  */
    WHILE = 283,                   /* WHILE  */
    FOR = 284,                     /* FOR  */
    FOREACH = 285,                 /* FOREACH  */
    SWITCH = 286,                  /* SWITCH  */
    CASE = 287,                    /* CASE  */
    DEFAULT = 288,                 /* DEFAULT  */
    BREAK = 289,                   /* BREAK  */
    CONTINUE = 290,                /* CONTINUE  */
    RETURN = 291,                  /* RETURN  */
    PUBLIC = 292,                  /* PUBLIC  */
    STATIC = 293,                  /* STATIC  */
    VOID = 294,                    /* VOID  */
    EQUALS = 295,                  /* EQUALS  */
    INT = 296,                     /* INT  */
    NEW = 297,                     /* NEW  */
    ARRAYS = 298,                  /* ARRAYS  */
    INDEXOF = 299,                 /* INDEXOF  */
    SYSTEM = 300,                  /* SYSTEM  */
    OUT = 301,                     /* OUT  */
    PRINTLN = 302,                 /* PRINTLN  */
    VALUEOF = 303,                 /* VALUEOF  */
    PRINT = 304,                   /* PRINT  */
    JOIN = 305,                    /* JOIN  */
    ARRAY = 306,                   /* ARRAY  */
    LENGTH = 307,                  /* LENGTH  */
    ADD = 308,                     /* ADD  */
    PARSEINT = 309,                /* PARSEINT  */
    PARSEFLOAT = 310,              /* PARSEFLOAT  */
    PARSEDOUBLE = 311,             /* PARSEDOUBLE  */
    FINAL = 312,                   /* FINAL  */
    DOSPUNTOS = 313,               /* DOSPUNTOS  */
    UMINUS = 314                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "src/parser/parser.y"

  double     dble;
  float      ftnt;
  NodoBase*  node;
  struct ArgList* args;  /* lista de argumentos */
  struct Param*   plist; /* lista de parámetros */  
  char*      str;
  char       ch;
  int         num;
  int tipo;

#line 135 "build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
