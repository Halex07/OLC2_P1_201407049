/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser/parser.y"

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
  


#line 115 "build/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FLOAD = 3,                      /* FLOAD  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_DECIMAL = 7,                    /* DECIMAL  */
  YYSYMBOL_NUMBER = 8,                     /* NUMBER  */
  YYSYMBOL_TRUE = 9,                       /* TRUE  */
  YYSYMBOL_FALSE = 10,                     /* FALSE  */
  YYSYMBOL_BOOLEAN = 11,                   /* BOOLEAN  */
  YYSYMBOL_TP_DOUBLE = 12,                 /* TP_DOUBLE  */
  YYSYMBOL_TP_FLOAT = 13,                  /* TP_FLOAT  */
  YYSYMBOL_TP_STRING = 14,                 /* TP_STRING  */
  YYSYMBOL_TP_CHAR = 15,                   /* TP_CHAR  */
  YYSYMBOL_INTEGER_I = 16,                 /* INTEGER_I  */
  YYSYMBOL_INTEGER = 17,                   /* INTEGER  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_LE = 19,                        /* LE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_SHR = 22,                       /* SHR  */
  YYSYMBOL_SHL = 23,                       /* SHL  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_FOREACH = 30,                   /* FOREACH  */
  YYSYMBOL_SWITCH = 31,                    /* SWITCH  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_DEFAULT = 33,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 36,                    /* RETURN  */
  YYSYMBOL_PUBLIC = 37,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 38,                    /* STATIC  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_EQUALS = 40,                    /* EQUALS  */
  YYSYMBOL_INT = 41,                       /* INT  */
  YYSYMBOL_NEW = 42,                       /* NEW  */
  YYSYMBOL_ARRAYS = 43,                    /* ARRAYS  */
  YYSYMBOL_INDEXOF = 44,                   /* INDEXOF  */
  YYSYMBOL_SYSTEM = 45,                    /* SYSTEM  */
  YYSYMBOL_OUT = 46,                       /* OUT  */
  YYSYMBOL_PRINTLN = 47,                   /* PRINTLN  */
  YYSYMBOL_VALUEOF = 48,                   /* VALUEOF  */
  YYSYMBOL_PRINT = 49,                     /* PRINT  */
  YYSYMBOL_JOIN = 50,                      /* JOIN  */
  YYSYMBOL_ARRAY = 51,                     /* ARRAY  */
  YYSYMBOL_LENGTH = 52,                    /* LENGTH  */
  YYSYMBOL_ADD = 53,                       /* ADD  */
  YYSYMBOL_PARSEINT = 54,                  /* PARSEINT  */
  YYSYMBOL_PARSEFLOAT = 55,                /* PARSEFLOAT  */
  YYSYMBOL_PARSEDOUBLE = 56,               /* PARSEDOUBLE  */
  YYSYMBOL_FINAL = 57,                     /* FINAL  */
  YYSYMBOL_DOSPUNTOS = 58,                 /* DOSPUNTOS  */
  YYSYMBOL_59_ = 59,                       /* '>'  */
  YYSYMBOL_60_ = 60,                       /* '<'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_UMINUS = 65,                    /* UMINUS  */
  YYSYMBOL_66_ = 66,                       /* '.'  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
  YYSYMBOL_69_ = 69,                       /* '{'  */
  YYSYMBOL_70_ = 70,                       /* '}'  */
  YYSYMBOL_71_ = 71,                       /* ';'  */
  YYSYMBOL_72_ = 72,                       /* ','  */
  YYSYMBOL_73_ = 73,                       /* '='  */
  YYSYMBOL_74_ = 74,                       /* '['  */
  YYSYMBOL_75_ = 75,                       /* ']'  */
  YYSYMBOL_76_ = 76,                       /* '%'  */
  YYSYMBOL_77_ = 77,                       /* '&'  */
  YYSYMBOL_78_ = 78,                       /* '|'  */
  YYSYMBOL_79_ = 79,                       /* '^'  */
  YYSYMBOL_80_ = 80,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 81,                  /* $accept  */
  YYSYMBOL_program = 82,                   /* program  */
  YYSYMBOL_lines = 83,                     /* lines  */
  YYSYMBOL_line = 84,                      /* line  */
  YYSYMBOL_sentenciasIf = 85,              /* sentenciasIf  */
  YYSYMBOL_loopWhile = 86,                 /* loopWhile  */
  YYSYMBOL_loopFor = 87,                   /* loopFor  */
  YYSYMBOL_block = 88,                     /* block  */
  YYSYMBOL_end = 89,                       /* end  */
  YYSYMBOL_case_list = 90,                 /* case_list  */
  YYSYMBOL_case_stmt = 91,                 /* case_stmt  */
  YYSYMBOL_function = 92,                  /* function  */
  YYSYMBOL_params = 93,                    /* params  */
  YYSYMBOL_paramlist = 94,                 /* paramlist  */
  YYSYMBOL_declaration = 95,               /* declaration  */
  YYSYMBOL_assigment = 96,                 /* assigment  */
  YYSYMBOL_multiDimension = 97,            /* multiDimension  */
  YYSYMBOL_tipo = 98,                      /* tipo  */
  YYSYMBOL_expr = 99,                      /* expr  */
  YYSYMBOL_callFunction = 100,             /* callFunction  */
  YYSYMBOL_args = 101,                     /* args  */
  YYSYMBOL_arglist = 102,                  /* arglist  */
  YYSYMBOL_sentenciasSwitch = 103,         /* sentenciasSwitch  */
  YYSYMBOL_elementos = 104,                /* elementos  */
  YYSYMBOL_larray = 105                    /* larray  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  270

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,     2,    76,    77,     2,
      67,    68,    63,    61,    72,    62,    66,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    71,
      60,    73,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    78,    70,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    95,    96,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   121,   122,   126,   130,   131,   135,   139,
     144,   147,   156,   159,   166,   167,   171,   172,   176,   180,
     188,   189,   190,   194,   196,   197,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   259,   263,
     264,   268,   269,   273,   283,   284,   285,   286,   289,   290,
     291
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FLOAD", "STRING",
  "ID", "CHAR", "DECIMAL", "NUMBER", "TRUE", "FALSE", "BOOLEAN",
  "TP_DOUBLE", "TP_FLOAT", "TP_STRING", "TP_CHAR", "INTEGER_I", "INTEGER",
  "GE", "LE", "EQ", "NEQ", "SHR", "SHL", "OR", "AND", "IF", "ELSE",
  "WHILE", "FOR", "FOREACH", "SWITCH", "CASE", "DEFAULT", "BREAK",
  "CONTINUE", "RETURN", "PUBLIC", "STATIC", "VOID", "EQUALS", "INT", "NEW",
  "ARRAYS", "INDEXOF", "SYSTEM", "OUT", "PRINTLN", "VALUEOF", "PRINT",
  "JOIN", "ARRAY", "LENGTH", "ADD", "PARSEINT", "PARSEFLOAT",
  "PARSEDOUBLE", "FINAL", "DOSPUNTOS", "'>'", "'<'", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "'.'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='",
  "'['", "']'", "'%'", "'&'", "'|'", "'^'", "'!'", "$accept", "program",
  "lines", "line", "sentenciasIf", "loopWhile", "loopFor", "block", "end",
  "case_list", "case_stmt", "function", "params", "paramlist",
  "declaration", "assigment", "multiDimension", "tipo", "expr",
  "callFunction", "args", "arglist", "sentenciasSwitch", "elementos",
  "larray", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -214,    13,   345,  -214,  -214,  -214,   -53,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   -38,   -37,
      -9,    -8,   -34,     4,   100,   570,  -214,    -6,    -4,    -3,
    -214,     0,     8,   201,   491,   423,  -214,   491,  -214,  -214,
    -214,  -214,  -214,  -214,   -34,   -34,  -214,     3,   488,  -214,
    -214,  -214,   491,   491,   491,   491,   491,   274,   491,  -214,
    -214,   -51,  -214,  -214,   488,  -214,  -214,   201,    63,    36,
      50,   491,   491,   491,    96,   108,    34,   554,   267,  1291,
    -214,  -214,    38,    47,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   -25,   491,
     491,   491,   491,  -214,   575,    55,  -214,  1291,   637,   658,
     686,   -34,   120,   748,  -214,   129,    69,    70,    72,   769,
     831,   852,    66,   491,  -214,  -214,   491,     7,  1291,  1291,
    1291,  1291,  1291,  1291,  1291,  1291,  1299,  1299,  1308,  1308,
     108,   108,    73,  -214,  1291,  1291,  1291,  1291,   491,  -214,
     -56,    75,    75,   491,   -54,    78,    74,   201,   491,    95,
    -214,  -214,  -214,   491,  1291,  1291,    76,    77,   491,  -214,
     491,   491,   123,  -214,   488,   152,  -214,   201,    91,  -214,
     155,   914,   103,  1291,     5,   168,   935,  1291,   997,    75,
     171,   111,   -30,   113,    75,   116,   491,   110,   125,   201,
     413,   109,  -214,   119,  -214,   124,   121,    75,   491,   138,
    -214,  -214,    75,  -214,   201,  1018,   -34,  1046,   145,   126,
     413,  1108,   -36,   -31,   491,    75,  -214,  1130,  -214,  -214,
    -214,  -214,  -214,   -34,   132,   491,   -28,   413,   -34,   413,
     201,   413,  1291,  -214,  -214,   345,  -214,   491,  1138,  -214,
     130,  -214,   130,   127,   -15,   345,  1200,   -34,   491,   -34,
     -34,  -214,  1221,  -214,  -214,   133,   491,  1229,   -34,  -214
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    84,    85,    87,    86,    83,    82,
      88,    89,    50,    49,    48,    47,    51,    46,     0,     0,
       0,     0,    53,    90,     0,     0,    52,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     3,     0,     4,    13,
      14,    15,    12,    16,     9,    11,    22,     0,     0,    79,
      17,    21,    99,     0,     0,     0,     0,     0,     0,    29,
      18,    87,    90,    20,     0,    53,    55,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,    75,
       8,    10,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,   101,     0,   100,    43,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    28,     0,     0,    65,    64,
      68,    69,    73,    74,    63,    62,    67,    66,    56,    57,
      58,    59,     0,    95,    60,    70,    71,    72,     0,    98,
      80,     0,     0,     0,    41,     0,     0,    36,     0,     0,
      78,    96,    97,     0,    77,    40,     0,     0,     0,   102,
       0,     0,    23,    25,     0,     0,    30,    36,     0,    37,
       0,     0,     0,    42,     0,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,    94,    91,    24,     0,     0,     0,     0,     0,
     103,    31,     0,    34,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,    27,     0,     3,    35,
      39,    93,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    26,     3,    33,     6,     0,     0,   106,
     104,   109,   105,     0,     0,    32,     0,     0,     0,     0,
       0,   108,     0,    45,   110,     0,     0,     0,     0,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,   -35,  -214,  -214,  -214,  -214,  -146,     1,  -214,
    -214,  -214,    26,   -10,   151,    20,  -214,     6,    -2,  -214,
    -214,    71,  -214,  -213,  -214
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    38,    39,    40,    41,    42,    60,   192,
     211,    43,   178,   179,    44,    45,    46,    47,   221,    49,
     105,   106,    50,   222,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    78,   208,   209,   175,   172,   173,   236,    82,   -55,
     198,   240,   166,     3,    52,   142,    52,   170,   171,   126,
      53,    54,    64,    54,   250,    63,   252,   143,   254,    55,
      56,    68,    75,    77,   238,    79,   239,    59,   241,    74,
     210,    76,   249,   204,   239,    80,    81,   199,   213,   103,
     104,   107,   108,   109,   110,   259,   113,   239,    57,    58,
      69,   226,    70,   112,    71,   114,   229,    72,   116,   119,
     120,   121,   -55,   115,   200,    73,    48,    83,   -55,   243,
     117,   167,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   118,   144,   145,   146,
     147,   122,   123,     4,     5,    61,     7,     8,     9,    10,
      11,   126,   153,     4,     5,    61,     7,     8,     9,    10,
      11,   164,   127,   149,   165,   154,    84,    85,    86,    87,
      88,    89,    90,    91,   156,    62,   157,   158,   159,   163,
     168,   177,   182,    27,    36,    62,   104,   176,    29,   184,
     189,   174,   185,    27,    31,    32,   181,   191,    29,   194,
     195,   183,    34,   180,    31,    32,   186,    35,   187,   188,
     197,    59,    34,   201,    98,   190,   205,    35,   216,   207,
      37,   212,   223,   180,    99,   100,   101,   102,   214,   225,
      37,   218,   224,   245,   215,   217,   228,    53,   234,   247,
     235,   258,   239,   193,   230,   219,   227,   266,   111,   255,
     206,     0,    12,    13,    14,    15,    16,   232,    17,   169,
     180,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   246,    65,    66,     0,     0,   251,
      26,     0,     0,    48,     0,   256,   253,     0,     0,     0,
       0,     0,    30,    48,     0,     0,   262,     0,   261,     0,
     263,   264,     0,     0,   267,     0,     0,     0,     0,   269,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    12,    13,    14,    15,    16,
       0,    17,     0,    18,     0,    19,    20,     0,    21,     0,
       0,    22,    23,    24,    25,     0,    26,     0,    65,    66,
      27,     0,    28,    26,     0,    29,     0,     0,    30,     0,
       0,    31,    32,     0,    33,    30,     0,     0,     0,    34,
       0,    33,     0,     0,    35,     0,    36,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,     0,    21,     0,     0,    22,
      23,    24,    25,     0,    26,     0,     0,     0,    27,     0,
      28,     0,     0,    29,     0,     0,    30,     0,     0,    31,
      32,     0,    33,     0,     0,     0,     0,    34,     0,     0,
       0,     0,    35,     0,    36,     0,     4,     5,    61,     7,
       8,     9,    10,    11,     0,    37,     4,     5,    61,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      17,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,     0,    27,    65,    23,     0,
       0,    29,    26,     0,     0,     0,    27,    31,    32,     0,
       0,    29,     0,     0,    30,    34,     0,    31,    32,     0,
      35,     0,   220,     0,     0,    34,     0,     0,     0,     0,
      35,     0,     0,    37,     4,     5,    61,     7,     8,     9,
      10,    11,     0,    37,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,    29,
       0,     0,     0,     0,     0,    31,    32,    92,    93,    94,
      95,    96,    97,    34,    98,     0,     0,     0,    35,    59,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,    37,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    12,    13,    14,    15,    16,     0,    17,     0,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    65,    66,     0,     0,    67,    26,
       0,     0,     0,    92,    93,    94,    95,    96,    97,     0,
      98,    30,   124,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,    92,    93,    94,    95,    96,    97,
       0,    98,     0,     0,     0,     0,     0,   148,     0,     0,
       0,    99,   100,   101,   102,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,     0,    98,    84,    85,    86,    87,    88,    89,
      90,    91,   150,    99,   100,   101,   102,    92,    93,    94,
      95,    96,    97,     0,    98,     0,   151,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,     0,    98,     0,   152,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,     0,    98,     0,   155,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,    92,    93,
      94,    95,    96,    97,     0,    98,     0,   160,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    97,     0,    98,     0,   161,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,    92,    93,    94,    95,    96,    97,     0,    98,     0,
     162,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,     0,
      98,     0,     0,     0,     0,     0,   196,     0,     0,     0,
      99,   100,   101,   102,    92,    93,    94,    95,    96,    97,
       0,    98,     0,   202,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,     0,    98,    84,    85,    86,    87,    88,    89,
      90,    91,   203,    99,   100,   101,   102,    92,    93,    94,
      95,    96,    97,     0,    98,     0,   231,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,     0,    98,     0,   233,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,    92,    93,    94,
      95,    96,    97,     0,    98,     0,     0,     0,     0,     0,
     237,     0,     0,     0,    99,   100,   101,   102,   244,    92,
      93,    94,    95,    96,    97,     0,    98,    92,    93,    94,
      95,    96,    97,     0,    98,     0,    99,   100,   101,   102,
       0,     0,     0,   257,    99,   100,   101,   102,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,     0,    98,     0,   260,     0,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
      92,    93,    94,    95,    96,    97,     0,    98,    92,    93,
      94,    95,    96,    97,     0,    98,   265,    99,   100,   101,
     102,     0,     0,     0,   268,    99,   100,   101,   102,    84,
      85,    86,    87,    88,    89,    90,    91,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    97,     0,    98,     0,     0,
      94,    95,    96,    97,     0,    98,     0,    99,   100,   101,
     102,    96,    97,     0,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,    99,   100,   101,   102
};

static const yytype_int16 yycheck[] =
{
       2,    36,    32,    33,    58,   151,   152,   220,     5,     5,
       5,    42,     5,     0,    67,    40,    67,    73,    74,    73,
      73,    74,    24,    74,   237,    24,   239,    52,   241,    67,
      67,    25,    34,    35,    70,    37,    72,    71,    69,    33,
      70,    35,    70,   189,    72,    44,    45,    42,   194,    48,
      52,    53,    54,    55,    56,    70,    58,    72,    67,    67,
      66,   207,    66,    57,    67,    64,   212,    67,     5,    71,
      72,    73,    68,    67,    69,    67,    78,    74,    74,   225,
      44,    74,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    46,    99,   100,   101,
     102,     5,    68,     3,     4,     5,     6,     7,     8,     9,
      10,    73,   111,     3,     4,     5,     6,     7,     8,     9,
      10,   123,    75,    68,   126,     5,    18,    19,    20,    21,
      22,    23,    24,    25,     5,    35,    67,    67,    66,    73,
      67,    67,    47,    43,    69,    35,   148,    69,    48,    73,
      27,   153,    75,    43,    54,    55,   158,     5,    48,    68,
       5,   163,    62,   157,    54,    55,   168,    67,   170,   171,
      67,    71,    62,     5,    66,   174,     5,    67,    68,    68,
      80,    68,    73,   177,    76,    77,    78,    79,    72,    68,
      80,    66,    73,   228,   196,   197,    58,    73,    53,    67,
      74,    74,    72,   177,   214,   199,   208,    74,    57,   244,
     190,    -1,    11,    12,    13,    14,    15,   216,    17,   148,
     214,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   233,    34,    35,    -1,    -1,   238,
      39,    -1,    -1,   245,    -1,   247,   240,    -1,    -1,    -1,
      -1,    -1,    51,   255,    -1,    -1,   258,    -1,   257,    -1,
     259,   260,    -1,    -1,   266,    -1,    -1,    -1,    -1,   268,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    11,    12,    13,    14,    15,
      -1,    17,    -1,    26,    -1,    28,    29,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    -1,    39,    -1,    34,    35,
      43,    -1,    45,    39,    -1,    48,    -1,    -1,    51,    -1,
      -1,    54,    55,    -1,    57,    51,    -1,    -1,    -1,    62,
      -1,    57,    -1,    -1,    67,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    -1,    43,    -1,
      45,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    80,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    34,    35,    -1,
      -1,    48,    39,    -1,    -1,    -1,    43,    54,    55,    -1,
      -1,    48,    -1,    -1,    51,    62,    -1,    54,    55,    -1,
      67,    -1,    69,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    80,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    80,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    54,    55,    59,    60,    61,
      62,    63,    64,    62,    66,    -1,    -1,    -1,    67,    71,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    -1,    -1,
      -1,    80,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    11,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,    39,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    -1,
      66,    51,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    59,    60,    61,    62,    63,    64,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    77,    78,    79,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    18,    19,    20,    21,    22,    23,
      24,    25,    75,    76,    77,    78,    79,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    59,    60,
      61,    62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    59,    60,    61,    62,    63,    64,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    77,    78,    79,    59,    60,    61,    62,    63,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    18,    19,    20,    21,    22,    23,
      24,    25,    75,    76,    77,    78,    79,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    77,    78,    79,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    59,    60,    61,
      62,    63,    64,    -1,    66,    -1,    76,    77,    78,    79,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    -1,    66,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      59,    60,    61,    62,    63,    64,    -1,    66,    59,    60,
      61,    62,    63,    64,    -1,    66,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    75,    76,    77,    78,    79,    18,
      19,    20,    21,    22,    23,    24,    25,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    -1,    66,    -1,    -1,
      61,    62,    63,    64,    -1,    66,    -1,    76,    77,    78,
      79,    63,    64,    -1,    66,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    82,    83,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    17,    26,    28,
      29,    31,    34,    35,    36,    37,    39,    43,    45,    48,
      51,    54,    55,    57,    62,    67,    69,    80,    84,    85,
      86,    87,    88,    92,    95,    96,    97,    98,    99,   100,
     103,   105,    67,    73,    74,    67,    67,    67,    67,    71,
      89,     5,    35,    89,    99,    34,    35,    38,    98,    66,
      66,    67,    67,    67,    98,    99,    98,    99,    83,    99,
      89,    89,     5,    74,    18,    19,    20,    21,    22,    23,
      24,    25,    59,    60,    61,    62,    63,    64,    66,    76,
      77,    78,    79,    89,    99,   101,   102,    99,    99,    99,
      99,    95,    98,    99,    89,    98,     5,    44,    46,    99,
      99,    99,     5,    68,    68,    70,    73,    75,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    40,    52,    99,    99,    99,    99,    72,    68,
      75,    68,    68,    89,     5,    68,     5,    67,    67,    66,
      68,    68,    68,    73,    99,    99,     5,    74,    67,   102,
      73,    74,    88,    88,    99,    58,    69,    67,    93,    94,
      98,    99,    47,    99,    73,    75,    99,    99,    99,    27,
      89,     5,    90,    93,    68,     5,    72,    67,     5,    42,
      69,     5,    68,    75,    88,     5,    96,    68,    32,    33,
      70,    91,    68,    88,    72,    99,    68,    99,    66,    98,
      69,    99,   104,    73,    73,    68,    88,    99,    58,    88,
      94,    68,    89,    68,    53,    74,   104,    72,    70,    72,
      42,    69,    99,    88,    58,    83,    89,    67,    99,    70,
     104,    89,   104,    98,   104,    83,    99,    75,    74,    70,
      68,    89,    99,    89,    89,    75,    74,    99,    75,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    81,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    87,    87,    88,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   101,
     101,   102,   102,   103,   104,   104,   104,   104,   105,   105,
     105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     9,     8,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     1,     1,     5,     7,     5,     9,     8,     3,     1,
       0,     2,     4,     3,     7,     8,     0,     1,     2,     4,
       4,     2,     5,     3,    16,    11,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     4,     4,     1,
       4,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     9,     8,     6,     3,     4,     4,     4,     0,
       1,     1,     3,     7,     3,     3,     3,     1,    11,     9,
      12
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: lines  */
#line 91 "src/parser/parser.y"
          { g_root = (yyvsp[0].node); (yyval.node) = (yyvsp[0].node); }
#line 1991 "build/parser.tab.c"
    break;

  case 3: /* lines: %empty  */
#line 95 "src/parser/parser.y"
                 { (yyval.node) = (NodoBase*)NewBlock((yyloc).first_line, (yyloc).first_column); }
#line 1997 "build/parser.tab.c"
    break;

  case 4: /* lines: lines line  */
#line 96 "src/parser/parser.y"
                { addBlockStmt((Block*)(yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 2003 "build/parser.tab.c"
    break;

  case 5: /* line: expr end  */
#line 100 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 2009 "build/parser.tab.c"
    break;

  case 6: /* line: SYSTEM '.' OUT '.' PRINTLN '(' expr ')' end  */
#line 101 "src/parser/parser.y"
                                                 { (yyval.node) = (NodoBase*)NewPrint((yylsp[-8]).first_line,(yylsp[-8]).first_column,(yyvsp[-2].node)); }
#line 2015 "build/parser.tab.c"
    break;

  case 7: /* line: SYSTEM '.' OUT '.' PRINTLN '(' ')' end  */
#line 102 "src/parser/parser.y"
                                            { (yyval.node) = (NodoBase*)NewPrint((yylsp[-7]).first_line,(yylsp[-7]).first_column,NULL); }
#line 2021 "build/parser.tab.c"
    break;

  case 8: /* line: declaration end  */
#line 103 "src/parser/parser.y"
                             {  (yyval.node) = (yyvsp[-1].node);  }
#line 2027 "build/parser.tab.c"
    break;

  case 9: /* line: declaration  */
#line 104 "src/parser/parser.y"
                             {  (yyval.node) = (yyvsp[0].node);  }
#line 2033 "build/parser.tab.c"
    break;

  case 10: /* line: assigment end  */
#line 105 "src/parser/parser.y"
                             {  (yyval.node) = (yyvsp[-1].node);  }
#line 2039 "build/parser.tab.c"
    break;

  case 11: /* line: assigment  */
#line 106 "src/parser/parser.y"
                          {  (yyval.node) = (yyvsp[0].node);  }
#line 2045 "build/parser.tab.c"
    break;

  case 12: /* line: block  */
#line 107 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2051 "build/parser.tab.c"
    break;

  case 13: /* line: sentenciasIf  */
#line 108 "src/parser/parser.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2057 "build/parser.tab.c"
    break;

  case 14: /* line: loopWhile  */
#line 109 "src/parser/parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2063 "build/parser.tab.c"
    break;

  case 15: /* line: loopFor  */
#line 110 "src/parser/parser.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2069 "build/parser.tab.c"
    break;

  case 16: /* line: function  */
#line 111 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2075 "build/parser.tab.c"
    break;

  case 17: /* line: sentenciasSwitch  */
#line 112 "src/parser/parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2081 "build/parser.tab.c"
    break;

  case 18: /* line: BREAK end  */
#line 113 "src/parser/parser.y"
             { (yyval.node) = (NodoBase*)NewBreak((yylsp[-1]).first_line,(yylsp[-1]).first_column);}
#line 2087 "build/parser.tab.c"
    break;

  case 19: /* line: RETURN expr end  */
#line 114 "src/parser/parser.y"
                    { (yyval.node) = (NodoBase*)NewReturn((yylsp[-2]).first_line,(yylsp[-2]).first_column,(yyvsp[-1].node));}
#line 2093 "build/parser.tab.c"
    break;

  case 20: /* line: RETURN end  */
#line 115 "src/parser/parser.y"
               { (yyval.node) = (NodoBase*)NewReturn((yylsp[-1]).first_line,(yylsp[-1]).first_column,NULL);}
#line 2099 "build/parser.tab.c"
    break;

  case 21: /* line: larray  */
#line 116 "src/parser/parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2105 "build/parser.tab.c"
    break;

  case 22: /* line: multiDimension  */
#line 117 "src/parser/parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2111 "build/parser.tab.c"
    break;

  case 23: /* sentenciasIf: IF '(' expr ')' block  */
#line 121 "src/parser/parser.y"
                              { (yyval.node) = (NodoBase*)NewIf((yylsp[-4]).first_line,(yylsp[-4]).first_column,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2117 "build/parser.tab.c"
    break;

  case 24: /* sentenciasIf: IF '(' expr ')' block ELSE block  */
#line 122 "src/parser/parser.y"
                                      { (yyval.node) = (NodoBase*)NewElse((yylsp[-6]).first_line,(yylsp[-6]).first_column,(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2123 "build/parser.tab.c"
    break;

  case 25: /* loopWhile: WHILE '(' expr ')' block  */
#line 126 "src/parser/parser.y"
                               { (yyval.node) = (NodoBase*)NewLoopWhile((yylsp[-4]).first_line,(yylsp[-4]).first_column,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2129 "build/parser.tab.c"
    break;

  case 26: /* loopFor: FOR '(' declaration end expr end assigment ')' block  */
#line 130 "src/parser/parser.y"
                                                           { (yyval.node) = (NodoBase*)NewFor((yylsp[-8]).first_line,(yylsp[-8]).first_column,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2135 "build/parser.tab.c"
    break;

  case 27: /* loopFor: FOR '(' tipo ID DOSPUNTOS ID ')' block  */
#line 131 "src/parser/parser.y"
                                             { (yyval.node) = (NodoBase*) NewForEach((yylsp[-7]).first_line, (yylsp[-7]).first_column, (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].node)); }
#line 2141 "build/parser.tab.c"
    break;

  case 28: /* block: '{' lines '}'  */
#line 135 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 2147 "build/parser.tab.c"
    break;

  case 30: /* case_list: %empty  */
#line 144 "src/parser/parser.y"
                   {
        (yyval.node) = (NodoBase*)NewSwitchArray((yyloc).first_line, (yyloc).first_column, NULL);
    }
#line 2155 "build/parser.tab.c"
    break;

  case 31: /* case_list: case_list case_stmt  */
#line 147 "src/parser/parser.y"
                          {
        (yyval.node) = (yyvsp[-1].node);
        SwitchArray* tmp = (SwitchArray*)(yyval.node);
        AddCaseArray(tmp, ((SwitchArray*)(yyvsp[0].node))->cases[0].expr,
                          ((SwitchArray*)(yyvsp[0].node))->cases[0].block);
    }
#line 2166 "build/parser.tab.c"
    break;

  case 32: /* case_stmt: CASE expr DOSPUNTOS lines  */
#line 156 "src/parser/parser.y"
                                {(yyval.node) = (NodoBase*)NewSwitchArray((yylsp[-3]).first_line, (yylsp[-3]).first_column, NULL);
                                       AddCaseArray((SwitchArray*)(yyval.node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2174 "build/parser.tab.c"
    break;

  case 33: /* case_stmt: DEFAULT DOSPUNTOS lines  */
#line 159 "src/parser/parser.y"
                              {
        (yyval.node) = (NodoBase*)NewSwitchArray((yylsp[-2]).first_line, (yylsp[-2]).first_column, NULL);
        AddCaseArray((SwitchArray*)(yyval.node), NULL, (yyvsp[0].node)); 
    }
#line 2183 "build/parser.tab.c"
    break;

  case 34: /* function: PUBLIC tipo ID '(' params ')' block  */
#line 166 "src/parser/parser.y"
                                        {(yyval.node) = (NodoBase*)NewFunction((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].str), (yyvsp[-5].tipo), (Param*)(yyvsp[-2].plist), (yyvsp[0].node));}
#line 2189 "build/parser.tab.c"
    break;

  case 35: /* function: PUBLIC STATIC tipo ID '(' params ')' block  */
#line 167 "src/parser/parser.y"
                                               {(yyval.node) = (NodoBase*)NewFunction((yylsp[-7]).first_line, (yylsp[-7]).first_column, (yyvsp[-4].str), (yyvsp[-5].tipo), (Param*)(yyvsp[-2].plist), (yyvsp[0].node));}
#line 2195 "build/parser.tab.c"
    break;

  case 36: /* params: %empty  */
#line 171 "src/parser/parser.y"
                 { (yyval.plist) = NULL; }
#line 2201 "build/parser.tab.c"
    break;

  case 37: /* params: paramlist  */
#line 172 "src/parser/parser.y"
              { (yyval.plist) = (yyvsp[0].plist); }
#line 2207 "build/parser.tab.c"
    break;

  case 38: /* paramlist: tipo ID  */
#line 176 "src/parser/parser.y"
            {
    Param *p = NewParam((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].str), (yyvsp[-1].tipo));
    (yyval.plist) = p;
  }
#line 2216 "build/parser.tab.c"
    break;

  case 39: /* paramlist: tipo ID ',' paramlist  */
#line 180 "src/parser/parser.y"
                          {
    Param *p = NewParam((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].str), (yyvsp[-3].tipo));
    p->next = (yyvsp[0].plist);
    (yyval.plist) = p;
  }
#line 2226 "build/parser.tab.c"
    break;

  case 40: /* declaration: tipo ID '=' expr  */
#line 188 "src/parser/parser.y"
                     {(yyval.node) = (NodoBase*)NewDeclaration((yylsp[-3]).first_line,(yylsp[-3]).first_column,(yyvsp[-2].str),(yyvsp[-3].tipo),(yyvsp[0].node));}
#line 2232 "build/parser.tab.c"
    break;

  case 41: /* declaration: tipo ID  */
#line 189 "src/parser/parser.y"
            {(yyval.node) = (NodoBase*)NewDeclaration((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[0].str),(yyvsp[-1].tipo),NULL);}
#line 2238 "build/parser.tab.c"
    break;

  case 42: /* declaration: FINAL tipo ID '=' expr  */
#line 190 "src/parser/parser.y"
                           {(yyval.node) = (NodoBase*)NewDeclaration((yylsp[-4]).first_line,(yylsp[-4]).first_column,(yyvsp[-2].str),(yyvsp[-3].tipo),(yyvsp[0].node));}
#line 2244 "build/parser.tab.c"
    break;

  case 43: /* assigment: ID '=' expr  */
#line 194 "src/parser/parser.y"
                {(yyval.node) = (NodoBase*)NewAssigment((yylsp[-2]).first_line,(yylsp[-2]).first_column,(yyvsp[-2].str),(yyvsp[0].node));}
#line 2250 "build/parser.tab.c"
    break;

  case 44: /* multiDimension: tipo '[' ']' '[' ']' ID '=' NEW tipo '[' expr ']' '[' expr ']' end  */
#line 196 "src/parser/parser.y"
                                                                                    { (yyval.node) = (NodoBase*)NewLista((yylsp[-15]).first_line,(yylsp[-15]).first_column,(yyvsp[-15].tipo),(yyvsp[-10].str),(yyvsp[-5].node),(yyvsp[-2].node));}
#line 2256 "build/parser.tab.c"
    break;

  case 45: /* multiDimension: tipo '[' ']' '[' ']' ID '=' '{' elementos '}' end  */
#line 197 "src/parser/parser.y"
                                                                    { (yyval.node) = (NodoBase*)NewListaInici((yylsp[-10]).first_line, (yylsp[-10]).first_column, (yyvsp[-10].tipo), (yyvsp[-5].str), (yyvsp[-2].node)); }
#line 2262 "build/parser.tab.c"
    break;

  case 46: /* tipo: INTEGER  */
#line 201 "src/parser/parser.y"
              { (yyval.tipo) = T_INTEGER; }
#line 2268 "build/parser.tab.c"
    break;

  case 47: /* tipo: TP_STRING  */
#line 202 "src/parser/parser.y"
              { (yyval.tipo) = T_STRING; }
#line 2274 "build/parser.tab.c"
    break;

  case 48: /* tipo: TP_FLOAT  */
#line 203 "src/parser/parser.y"
                 { (yyval.tipo) = T_FLOAT; }
#line 2280 "build/parser.tab.c"
    break;

  case 49: /* tipo: TP_DOUBLE  */
#line 204 "src/parser/parser.y"
                 { (yyval.tipo) = T_DOUBLE;}
#line 2286 "build/parser.tab.c"
    break;

  case 50: /* tipo: BOOLEAN  */
#line 205 "src/parser/parser.y"
              { (yyval.tipo) = T_BOOLEAN; }
#line 2292 "build/parser.tab.c"
    break;

  case 51: /* tipo: TP_CHAR  */
#line 206 "src/parser/parser.y"
              { (yyval.tipo) = T_CHAR; }
#line 2298 "build/parser.tab.c"
    break;

  case 52: /* tipo: VOID  */
#line 207 "src/parser/parser.y"
              { (yyval.tipo) = T_VOID; }
#line 2304 "build/parser.tab.c"
    break;

  case 53: /* tipo: BREAK  */
#line 208 "src/parser/parser.y"
              { (yyval.tipo) = T_BREAK; }
#line 2310 "build/parser.tab.c"
    break;

  case 54: /* tipo: ARRAY  */
#line 209 "src/parser/parser.y"
              { (yyval.tipo) = T_ARRAY; }
#line 2316 "build/parser.tab.c"
    break;

  case 55: /* tipo: CONTINUE  */
#line 210 "src/parser/parser.y"
              { (yyval.tipo) = T_CONTINUE;}
#line 2322 "build/parser.tab.c"
    break;

  case 56: /* expr: expr '+' expr  */
#line 214 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"+",(yyvsp[0].node)); }
#line 2328 "build/parser.tab.c"
    break;

  case 57: /* expr: expr '-' expr  */
#line 215 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"-",(yyvsp[0].node)); }
#line 2334 "build/parser.tab.c"
    break;

  case 58: /* expr: expr '*' expr  */
#line 216 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"*",(yyvsp[0].node)); }
#line 2340 "build/parser.tab.c"
    break;

  case 59: /* expr: expr '/' expr  */
#line 217 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"/",(yyvsp[0].node)); }
#line 2346 "build/parser.tab.c"
    break;

  case 60: /* expr: expr '%' expr  */
#line 218 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"%",(yyvsp[0].node)); }
#line 2352 "build/parser.tab.c"
    break;

  case 61: /* expr: '-' expr  */
#line 219 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column, (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymInt((yylsp[0]).first_line,(yylsp[0]).first_column,0)), "-", (yyvsp[0].node)); }
#line 2358 "build/parser.tab.c"
    break;

  case 62: /* expr: expr AND expr  */
#line 220 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"&&",(yyvsp[0].node)); }
#line 2364 "build/parser.tab.c"
    break;

  case 63: /* expr: expr OR expr  */
#line 221 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"||",(yyvsp[0].node)); }
#line 2370 "build/parser.tab.c"
    break;

  case 64: /* expr: expr LE expr  */
#line 222 "src/parser/parser.y"
                        { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"<=",(yyvsp[0].node)); }
#line 2376 "build/parser.tab.c"
    break;

  case 65: /* expr: expr GE expr  */
#line 223 "src/parser/parser.y"
                        { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),">=",(yyvsp[0].node)); }
#line 2382 "build/parser.tab.c"
    break;

  case 66: /* expr: expr '<' expr  */
#line 224 "src/parser/parser.y"
                           { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"<",(yyvsp[0].node)); }
#line 2388 "build/parser.tab.c"
    break;

  case 67: /* expr: expr '>' expr  */
#line 225 "src/parser/parser.y"
                           { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),">",(yyvsp[0].node)); }
#line 2394 "build/parser.tab.c"
    break;

  case 68: /* expr: expr EQ expr  */
#line 226 "src/parser/parser.y"
                     { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"==",(yyvsp[0].node)); }
#line 2400 "build/parser.tab.c"
    break;

  case 69: /* expr: expr NEQ expr  */
#line 227 "src/parser/parser.y"
                       { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"!=",(yyvsp[0].node)); }
#line 2406 "build/parser.tab.c"
    break;

  case 70: /* expr: expr '&' expr  */
#line 228 "src/parser/parser.y"
                          { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"&",(yyvsp[0].node)); }
#line 2412 "build/parser.tab.c"
    break;

  case 71: /* expr: expr '|' expr  */
#line 229 "src/parser/parser.y"
                           { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"|",(yyvsp[0].node)); }
#line 2418 "build/parser.tab.c"
    break;

  case 72: /* expr: expr '^' expr  */
#line 230 "src/parser/parser.y"
                          { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"^",(yyvsp[0].node)); }
#line 2424 "build/parser.tab.c"
    break;

  case 73: /* expr: expr SHR expr  */
#line 231 "src/parser/parser.y"
                       { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),">>",(yyvsp[0].node)); }
#line 2430 "build/parser.tab.c"
    break;

  case 74: /* expr: expr SHL expr  */
#line 232 "src/parser/parser.y"
                       { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-2].node),"<<",(yyvsp[0].node)); }
#line 2436 "build/parser.tab.c"
    break;

  case 75: /* expr: '!' expr  */
#line 233 "src/parser/parser.y"
                             { (yyval.node) = (NodoBase*)NewOperation((yylsp[-1]).first_line,(yylsp[-1]).first_column, (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymInt((yylsp[0]).first_line,(yylsp[0]).first_column,0)), "!", (yyvsp[0].node)); }
#line 2442 "build/parser.tab.c"
    break;

  case 76: /* expr: '(' expr ')'  */
#line 234 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 2448 "build/parser.tab.c"
    break;

  case 77: /* expr: '(' tipo ')' expr  */
#line 235 "src/parser/parser.y"
                             {(yyval.node) = (NodoBase*)NewCasteo((yylsp[-3]).first_line,(yylsp[-3]).first_column,(yyvsp[-2].tipo),(yyvsp[0].node));}
#line 2454 "build/parser.tab.c"
    break;

  case 78: /* expr: VALUEOF '(' expr ')'  */
#line 236 "src/parser/parser.y"
                         { (yyval.node) = (NodoBase*)NewValueOf((yylsp[-3]).first_line,(yylsp[-3]).first_column,(yyvsp[-1].node)); }
#line 2460 "build/parser.tab.c"
    break;

  case 79: /* expr: callFunction  */
#line 237 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2466 "build/parser.tab.c"
    break;

  case 80: /* expr: ID '[' expr ']'  */
#line 238 "src/parser/parser.y"
                   { (yyval.node) = (NodoBase*) NewArrayGET((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].str), (yyvsp[-1].node)); }
#line 2472 "build/parser.tab.c"
    break;

  case 81: /* expr: ID '[' expr ']' '=' expr  */
#line 239 "src/parser/parser.y"
                              {(yyval.node) = (NodoBase*) NewArraySET((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));}
#line 2478 "build/parser.tab.c"
    break;

  case 82: /* expr: NUMBER  */
#line 240 "src/parser/parser.y"
           {(yyval.node) = (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymInt((yylsp[0]).first_line,(yylsp[0]).first_column,(yyvsp[0].num)));}
#line 2484 "build/parser.tab.c"
    break;

  case 83: /* expr: DECIMAL  */
#line 241 "src/parser/parser.y"
            {(yyval.node) = (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column,SymDouble((yylsp[0]).first_line,(yylsp[0]).first_column,(yyvsp[0].dble)));}
#line 2490 "build/parser.tab.c"
    break;

  case 84: /* expr: FLOAD  */
#line 242 "src/parser/parser.y"
          {(yyval.node) = (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymFloat((yylsp[0]).first_line,(yylsp[0]).first_column, (yyvsp[0].ftnt)));}
#line 2496 "build/parser.tab.c"
    break;

  case 85: /* expr: STRING  */
#line 243 "src/parser/parser.y"
           {(yyval.node) = (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymStr((yylsp[0]).first_line,(yylsp[0]).first_column,(yyvsp[0].str)));}
#line 2502 "build/parser.tab.c"
    break;

  case 86: /* expr: CHAR  */
#line 244 "src/parser/parser.y"
         {(yyval.node) = (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymChar((yylsp[0]).first_line,(yylsp[0]).first_column,(yyvsp[0].ch)));}
#line 2508 "build/parser.tab.c"
    break;

  case 87: /* expr: ID  */
#line 245 "src/parser/parser.y"
       {(yyval.node) = (NodoBase*)NewVariable((yylsp[0]).first_line,(yylsp[0]).first_column,(yyvsp[0].str));}
#line 2514 "build/parser.tab.c"
    break;

  case 88: /* expr: TRUE  */
#line 246 "src/parser/parser.y"
         {(yyval.node) = (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymBool((yylsp[0]).first_line,(yylsp[0]).first_column,1));}
#line 2520 "build/parser.tab.c"
    break;

  case 89: /* expr: FALSE  */
#line 247 "src/parser/parser.y"
          {(yyval.node) = (NodoBase*)NewPrimitive((yylsp[0]).first_line,(yylsp[0]).first_column, SymBool((yylsp[0]).first_line,(yylsp[0]).first_column,0));}
#line 2526 "build/parser.tab.c"
    break;

  case 90: /* expr: CONTINUE  */
#line 248 "src/parser/parser.y"
             { (yyval.node) = (NodoBase*)NewContinue((yylsp[0]).first_line,(yylsp[0]).first_column);}
#line 2532 "build/parser.tab.c"
    break;

  case 91: /* expr: ID '[' expr ']' '[' expr ']'  */
#line 249 "src/parser/parser.y"
                               {(yyval.node) = (NodoBase*) NewListaGET((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));}
#line 2538 "build/parser.tab.c"
    break;

  case 92: /* expr: ID '[' expr ']' '[' expr ']' '=' expr  */
#line 250 "src/parser/parser.y"
                                        {(yyval.node) = (NodoBase*) NewListaSET((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-8].str), (yyvsp[-6].node), (yyvsp[-3].node),(yyvsp[0].node));}
#line 2544 "build/parser.tab.c"
    break;

  case 93: /* expr: ARRAYS '.' INDEXOF '(' expr ',' expr ')'  */
#line 251 "src/parser/parser.y"
                                             {(yyval.node) = (NodoBase*)NewIndexOf((yylsp[-7]).first_line, (yylsp[-7]).first_column, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2550 "build/parser.tab.c"
    break;

  case 94: /* expr: expr '.' EQUALS '(' expr ')'  */
#line 252 "src/parser/parser.y"
                                { (yyval.node) = (NodoBase*)NewOperation((yylsp[-4]).first_line,(yylsp[-4]).first_column,(yyvsp[-5].node),"equals",(yyvsp[-1].node)); }
#line 2556 "build/parser.tab.c"
    break;

  case 95: /* expr: expr '.' LENGTH  */
#line 253 "src/parser/parser.y"
                       { (yyval.node) = (NodoBase*) NewLength((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].node)); }
#line 2562 "build/parser.tab.c"
    break;

  case 96: /* expr: PARSEINT '(' expr ')'  */
#line 254 "src/parser/parser.y"
                          { (yyval.node) = (NodoBase*)NewInt((yylsp[-3]).first_line,(yylsp[-3]).first_column,(yyvsp[-1].node));}
#line 2568 "build/parser.tab.c"
    break;

  case 97: /* expr: PARSEFLOAT '(' expr ')'  */
#line 255 "src/parser/parser.y"
                            { (yyval.node) = (NodoBase*)NewFloat((yylsp[-3]).first_line,(yylsp[-3]).first_column,(yyvsp[-1].node)); }
#line 2574 "build/parser.tab.c"
    break;

  case 98: /* callFunction: ID '(' args ')'  */
#line 259 "src/parser/parser.y"
                    {(yyval.node) = (NodoBase*)NewCallFunc((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].str), (yyvsp[-1].args));}
#line 2580 "build/parser.tab.c"
    break;

  case 99: /* args: %empty  */
#line 263 "src/parser/parser.y"
                 { (yyval.args) = NULL; }
#line 2586 "build/parser.tab.c"
    break;

  case 100: /* args: arglist  */
#line 264 "src/parser/parser.y"
                { (yyval.args) = (yyvsp[0].args); }
#line 2592 "build/parser.tab.c"
    break;

  case 101: /* arglist: expr  */
#line 268 "src/parser/parser.y"
                     { (yyval.args) = NewArgList((yyvsp[0].node), NULL); }
#line 2598 "build/parser.tab.c"
    break;

  case 102: /* arglist: expr ',' arglist  */
#line 269 "src/parser/parser.y"
                     { (yyval.args) = NewArgList((yyvsp[-2].node), (yyvsp[0].args)); }
#line 2604 "build/parser.tab.c"
    break;

  case 103: /* sentenciasSwitch: SWITCH '(' expr ')' '{' case_list '}'  */
#line 273 "src/parser/parser.y"
                                            {
        (yyval.node) = (NodoBase*)NewSwitchArray((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].node));     
        SwitchArray* tmp = (SwitchArray*)(yyvsp[-1].node);
        for (int i = 0; i < tmp->count; i++) {
            AddCaseArray((SwitchArray*)(yyval.node), tmp->cases[i].expr, tmp->cases[i].block);
        }
         
    }
#line 2617 "build/parser.tab.c"
    break;

  case 104: /* elementos: expr ',' elementos  */
#line 283 "src/parser/parser.y"
                             { (yyvsp[-2].node)->siguiente = (yyvsp[0].node); (yyval.node) = (yyvsp[-2].node); }
#line 2623 "build/parser.tab.c"
    break;

  case 105: /* elementos: elementos ',' elementos  */
#line 284 "src/parser/parser.y"
                             { NodoBase *last = (yyvsp[-2].node); while (last->siguiente) last = last->siguiente; last->siguiente = (yyvsp[0].node); (yyval.node) = (yyvsp[-2].node);}
#line 2629 "build/parser.tab.c"
    break;

  case 106: /* elementos: '{' elementos '}'  */
#line 285 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 2635 "build/parser.tab.c"
    break;

  case 107: /* elementos: expr  */
#line 286 "src/parser/parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2641 "build/parser.tab.c"
    break;

  case 108: /* larray: tipo '[' ']' ID '=' NEW tipo '[' expr ']' end  */
#line 289 "src/parser/parser.y"
                                                           { (yyval.node) = (NodoBase*)NewArray((yylsp[-10]).first_line, (yylsp[-10]).first_column, (yyvsp[-10].tipo), (yyvsp[-7].str), (yyvsp[-2].node), NULL); }
#line 2647 "build/parser.tab.c"
    break;

  case 109: /* larray: tipo '[' ']' ID '=' '{' elementos '}' end  */
#line 290 "src/parser/parser.y"
                                                         { (yyval.node) = (NodoBase*)NewArray((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-8].tipo), (yyvsp[-5].str), NULL, (yyvsp[-2].node)); }
#line 2653 "build/parser.tab.c"
    break;

  case 110: /* larray: tipo '[' ']' ID '=' ID '.' ADD '(' expr ')' end  */
#line 291 "src/parser/parser.y"
                                                         { (yyval.node) = (NodoBase*)NewArrayADD((yylsp[-11]).first_line,(yylsp[-11]).first_column,(yyvsp[-11].tipo),(yyvsp[-6].str),(yyvsp[-8].str),(yyvsp[-2].node));}
#line 2659 "build/parser.tab.c"
    break;


#line 2663 "build/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 294 "src/parser/parser.y"

void yyerror(const char *s) {
  fprintf(stderr, "Error de sintaxis: %s\n", s);
}
