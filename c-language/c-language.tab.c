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
#line 5 "c-language.y"

#include <stdio.h>
#include <stdlib.h>
#include "TabDeSimbolos.h"

// Informações usadas pelo Bison que vem do Flex:
extern int line_number; // Número da linha do erro léxico;
extern int column_number; // Número de coluna do erro léxico;
extern int errors_count; // Contador de erros léxicos;
extern int yylex(); // Retorna os tokens para o parser;
extern int yyparse(); // Função principal para iniciar a análise léxica;
extern FILE *yyin; // Indica que a entrada do analisador léxico é um arquivo;

// Informações usadas na análise sintática:
int syntax_error_occurred = 0; // Contador de erro sintático;
void yyerror(const char *s); // Definição da função de erro (somente para o Bison não reclamar);
void print_error(const char *msg); // Nossa função de erro;

#line 90 "c-language.tab.c"

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

#include "c-language.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_STRUCT = 8,                     /* STRUCT  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_SOMA = 13,                      /* SOMA  */
  YYSYMBOL_MULT = 14,                      /* MULT  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_RELOP = 16,                     /* RELOP  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_OCB = 19,                       /* OCB  */
  YYSYMBOL_CCB = 20,                       /* CCB  */
  YYSYMBOL_OP = 21,                        /* OP  */
  YYSYMBOL_CP = 22,                        /* CP  */
  YYSYMBOL_OB = 23,                        /* OB  */
  YYSYMBOL_CB = 24,                        /* CB  */
  YYSYMBOL_NUM_INT = 25,                   /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 26,                 /* NUM_FLOAT  */
  YYSYMBOL_CHARACTER = 27,                 /* CHARACTER  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_programa = 29,                  /* programa  */
  YYSYMBOL_decl_lista = 30,                /* decl_lista  */
  YYSYMBOL_decl = 31,                      /* decl  */
  YYSYMBOL_var_decl = 32,                  /* var_decl  */
  YYSYMBOL_dimen_matriz = 33,              /* dimen_matriz  */
  YYSYMBOL_tipo_especificador = 34,        /* tipo_especificador  */
  YYSYMBOL_atributos_decl = 35,            /* atributos_decl  */
  YYSYMBOL_func_decl = 36,                 /* func_decl  */
  YYSYMBOL_params = 37,                    /* params  */
  YYSYMBOL_params_lista = 38,              /* params_lista  */
  YYSYMBOL_param = 39,                     /* param  */
  YYSYMBOL_composto_decl = 40,             /* composto_decl  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_local_decl = 42,                /* local_decl  */
  YYSYMBOL_comando_lista = 43,             /* comando_lista  */
  YYSYMBOL_comando = 44,                   /* comando  */
  YYSYMBOL_comando_casado = 45,            /* comando_casado  */
  YYSYMBOL_comando_singular = 46,          /* comando_singular  */
  YYSYMBOL_expressao_decl = 47,            /* expressao_decl  */
  YYSYMBOL_iteracao_decl = 48,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 49,              /* retorno_decl  */
  YYSYMBOL_expressao = 50,                 /* expressao  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_var_aux = 52,                   /* var_aux  */
  YYSYMBOL_expressao_simples = 53,         /* expressao_simples  */
  YYSYMBOL_expressao_soma = 54,            /* expressao_soma  */
  YYSYMBOL_expressao_somatorio = 55,       /* expressao_somatorio  */
  YYSYMBOL_termo = 56,                     /* termo  */
  YYSYMBOL_termo_aux = 57,                 /* termo_aux  */
  YYSYMBOL_fator = 58,                     /* fator  */
  YYSYMBOL_ativacao = 59,                  /* ativacao  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_arg_list = 61                   /* arg_list  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    57,    58,    59,    63,    64,    65,    70,
      74,    81,    82,    86,    87,    88,    89,    90,    93,    94,
      98,   104,   105,   106,   110,   111,   112,   116,   120,   125,
     129,   129,   135,   139,   140,   144,   145,   149,   150,   151,
     155,   156,   157,   158,   159,   163,   164,   168,   169,   173,
     177,   178,   182,   183,   184,   187,   192,   200,   201,   205,
     206,   209,   210,   214,   215,   218,   219,   223,   224,   228,
     229,   230,   231,   232,   236,   239,   240,   244,   245,   246
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT", "FLOAT",
  "CHAR", "VOID", "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "SOMA",
  "MULT", "EQ", "RELOP", "SEMICOLON", "COMMA", "OCB", "CCB", "OP", "CP",
  "OB", "CB", "NUM_INT", "NUM_FLOAT", "CHARACTER", "$accept", "programa",
  "decl_lista", "decl", "var_decl", "dimen_matriz", "tipo_especificador",
  "atributos_decl", "func_decl", "params", "params_lista", "param",
  "composto_decl", "$@1", "local_decl", "comando_lista", "comando",
  "comando_casado", "comando_singular", "expressao_decl", "iteracao_decl",
  "retorno_decl", "expressao", "var", "var_aux", "expressao_simples",
  "expressao_soma", "expressao_somatorio", "termo", "termo_aux", "fator",
  "ativacao", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     186,   164,  -101,  -101,  -101,  -101,    -2,     4,  -101,   178,
    -101,    26,  -101,  -101,  -101,    22,  -101,  -101,    60,   169,
    -101,   194,    11,    31,   169,    41,    36,  -101,    29,    67,
      50,  -101,    46,    69,  -101,  -101,    65,  -101,    27,    72,
      84,   169,    80,    82,    87,    54,  -101,   169,  -101,  -101,
    -101,  -101,    94,   169,  -101,  -101,   169,    75,  -101,   102,
      -8,    99,   104,     6,  -101,     9,  -101,  -101,  -101,   103,
      75,  -101,  -101,  -101,  -101,  -101,   111,   114,  -101,   117,
     118,   116,  -101,  -101,    17,     9,  -101,     9,     9,  -101,
    -101,   130,   126,  -101,  -101,  -101,     9,    64,    64,  -101,
      64,  -101,   132,   139,   136,  -101,   128,   142,   158,  -101,
    -101,  -101,  -101,  -101,   118,   116,   141,   141,  -101,   138,
      96,   115,  -101,  -101,  -101,  -101,  -101,  -101,   153,   167,
    -101,   134,     9,  -101,  -101,   174,   115,   179,   115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,    14,    15,    16,     0,     0,     2,     0,
       6,     0,     7,     8,     5,     0,     1,     3,     0,     0,
       9,     0,     0,     0,    18,     0,     0,    23,    16,     0,
       0,    21,     0,     0,    10,    19,     0,    17,     0,     0,
       0,     0,    11,     0,     0,     0,    20,     0,    25,    12,
      29,    28,     0,    34,    26,    32,    34,     0,    33,     0,
      55,     0,     0,     0,    48,     0,    73,    72,    41,     0,
       0,    37,    38,    40,    42,    43,     0,    70,    53,    60,
      61,    65,    71,    39,     0,     0,    56,     0,     0,    54,
      50,     0,     0,    31,    35,    47,     0,     0,     0,    62,
       0,    66,    54,    77,     0,    75,     0,     0,     0,    51,
      69,    52,    70,    59,    63,    67,     0,     0,    74,    57,
       0,     0,    64,    68,    79,    78,    58,    45,    37,     0,
      49,     0,     0,    44,    46,     0,     0,     0,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,    10,  -101,   -16,   155,     5,   180,  -101,  -101,
      57,  -101,   166,  -101,   147,   137,    86,    18,    77,  -101,
    -101,  -101,   -63,    12,    90,  -101,   113,    97,   119,    98,
     112,  -101,  -101,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    23,    25,    26,    12,    30,
      31,    32,    68,    53,    57,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    86,    78,    79,    99,    80,   101,
      81,    82,   104,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    15,    92,    24,    16,    11,    11,    89,    24,    60,
      89,    14,    60,    84,    11,    85,   124,   125,   102,    17,
      60,   103,   106,    90,   107,   108,    29,    65,    43,    18,
      65,    66,    67,   111,    66,    67,    33,    56,    65,   -76,
      56,    19,    66,    67,    36,   -27,    29,    40,    34,   -27,
      44,   -22,    29,   103,   103,    52,    37,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,    41,   -30,   -30,    60,   -24,   135,
      38,   -30,    39,   -30,   -30,   -30,    59,    20,    60,   -30,
     -30,    21,    20,    22,    61,    65,    62,    63,    22,    66,
      67,    45,    64,    42,    45,   -36,    65,    59,    48,    60,
      66,    67,    47,    22,    54,    61,    50,    62,    63,   112,
     112,    51,   112,    64,    55,    45,    89,    65,    60,    83,
      87,    66,    67,    93,   129,    88,    62,    63,    95,    96,
     100,    98,    64,    97,    45,    89,    65,    60,   128,   130,
      66,    67,   102,    61,    60,    62,    63,   109,   110,   133,
     116,    64,   119,    45,   137,    65,   133,   117,   118,    66,
      67,    85,    65,   131,   120,     1,    66,    67,     2,     3,
       4,     5,     6,     2,     3,     4,     5,     6,    -4,     1,
     121,    13,     2,     3,     4,     5,     6,     1,   132,   138,
       2,     3,     4,     5,     6,    27,   136,    49,     2,     3,
       4,    28,     6,    58,    35,    46,   127,    94,   134,   126,
     113,   122,   115,   123,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      63,     3,    65,    19,     0,     0,     1,     1,    24,     3,
       1,     1,     3,    21,     9,    23,   116,   117,     1,     9,
       3,    84,    85,    17,    87,    88,    21,    21,     1,     3,
      21,    25,    26,    96,    25,    26,    25,    53,    21,    22,
      56,    19,    25,    26,     3,    18,    41,     1,    17,    22,
      23,    22,    47,   116,   117,     1,    20,     3,     4,     5,
       6,     7,     8,     9,    18,    11,    12,     3,    22,   132,
       3,    17,    22,    19,    20,    21,     1,    17,     3,    25,
      26,    21,    17,    23,     9,    21,    11,    12,    23,    25,
      26,    19,    17,    24,    19,    20,    21,     1,    41,     3,
      25,    26,    18,    23,    47,     9,    24,    11,    12,    97,
      98,    24,   100,    17,    20,    19,     1,    21,     3,    17,
      21,    25,    26,    20,     9,    21,    11,    12,    17,    15,
      14,    13,    17,    16,    19,     1,    21,     3,   120,   121,
      25,    26,     1,     9,     3,    11,    12,    17,    22,   131,
      18,    17,    24,    19,   136,    21,   138,    18,    22,    25,
      26,    23,    21,    10,    22,     1,    25,    26,     4,     5,
       6,     7,     8,     4,     5,     6,     7,     8,     0,     1,
      22,    17,     4,     5,     6,     7,     8,     1,    21,    10,
       4,     5,     6,     7,     8,     1,    22,    42,     4,     5,
       6,     7,     8,    56,    24,    39,   120,    70,   131,   119,
      97,   114,   100,   115,    -1,    -1,    -1,    98
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     8,    29,    30,    31,
      32,    34,    36,    17,    30,     3,     0,    30,     3,    19,
      17,    21,    23,    33,    32,    34,    35,     1,     7,    34,
      37,    38,    39,    25,    17,    35,     3,    20,     3,    22,
       1,    18,    24,     1,    23,    19,    40,    18,    38,    33,
      24,    24,     1,    41,    38,    20,    32,    42,    42,     1,
       3,     9,    11,    12,    17,    21,    25,    26,    40,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    53,    54,
      56,    58,    59,    17,    21,    23,    52,    21,    21,     1,
      17,    50,    50,    20,    43,    17,    15,    16,    13,    55,
      14,    57,     1,    50,    60,    61,    50,    50,    50,    17,
      22,    50,    51,    54,    56,    58,    18,    18,    22,    24,
      22,    22,    55,    57,    61,    61,    52,    44,    45,     9,
      45,    10,    21,    45,    46,    50,    22,    45,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    30,    30,    31,    31,    31,    32,
      32,    33,    33,    34,    34,    34,    34,    34,    35,    35,
      36,    37,    37,    37,    38,    38,    38,    39,    39,    39,
      41,    40,    40,    42,    42,    43,    43,    44,    44,    44,
      45,    45,    45,    45,    45,    46,    46,    47,    47,    48,
      49,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    59,    60,    60,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     3,
       4,     3,     4,     1,     1,     1,     1,     5,     1,     2,
       6,     1,     1,     1,     1,     3,     4,     2,     4,     4,
       0,     5,     3,     2,     0,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     7,     5,     7,     2,     1,     5,
       2,     3,     3,     1,     1,     1,     2,     3,     4,     3,
       1,     1,     2,     2,     3,     1,     2,     2,     3,     3,
       1,     1,     1,     1,     4,     1,     0,     1,     3,     3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* decl_lista: error decl_lista  */
#line 59 "c-language.y"
                                  { print_error("Error in declaration list."); yyerrok; }
#line 1244 "c-language.tab.c"
    break;

  case 8: /* decl: error SEMICOLON  */
#line 65 "c-language.y"
                             { print_error("Invalid declaration."); yyerrok; }
#line 1250 "c-language.tab.c"
    break;

  case 9: /* var_decl: tipo_especificador ID SEMICOLON  */
#line 70 "c-language.y"
                                                {
                printf("Inserindo id %s do tipo %d\n", (yyvsp[-1].identifier), (yyvsp[-2].tipo));
                    TDS_novoSimbolo((yyvsp[-1].identifier), (yyvsp[-2].tipo)); 
                }
#line 1259 "c-language.tab.c"
    break;

  case 10: /* var_decl: tipo_especificador ID dimen_matriz SEMICOLON  */
#line 74 "c-language.y"
                                                              {
                printf("Inserindo id %s do tipo %d\n", (yyvsp[-2].identifier), (yyvsp[-3].tipo));
                    TDS_novoSimbolo((yyvsp[-2].identifier), (yyvsp[-3].tipo));
                }
#line 1268 "c-language.tab.c"
    break;

  case 13: /* tipo_especificador: INT  */
#line 86 "c-language.y"
                           { (yyval.tipo) = TIPO_INT; }
#line 1274 "c-language.tab.c"
    break;

  case 14: /* tipo_especificador: FLOAT  */
#line 87 "c-language.y"
                            { (yyval.tipo) = TIPO_FLOAT; }
#line 1280 "c-language.tab.c"
    break;

  case 15: /* tipo_especificador: CHAR  */
#line 88 "c-language.y"
                            { (yyval.tipo) = TIPO_CHAR; }
#line 1286 "c-language.tab.c"
    break;

  case 16: /* tipo_especificador: VOID  */
#line 89 "c-language.y"
                            { (yyval.tipo) = TIPO_VOID; }
#line 1292 "c-language.tab.c"
    break;

  case 17: /* tipo_especificador: STRUCT ID OCB atributos_decl CCB  */
#line 90 "c-language.y"
                                                      { (yyval.tipo) = STRUCT; }
#line 1298 "c-language.tab.c"
    break;

  case 20: /* func_decl: tipo_especificador ID OP params CP composto_decl  */
#line 98 "c-language.y"
                                                                {
                    TDS_novoSimbolo((yyvsp[-4].identifier), (yyvsp[-5].tipo));
                }
#line 1306 "c-language.tab.c"
    break;

  case 23: /* params: error  */
#line 106 "c-language.y"
                    {print_error("Parâmetro inválido."); yyerrok;}
#line 1312 "c-language.tab.c"
    break;

  case 26: /* params_lista: param error COMMA params_lista  */
#line 112 "c-language.y"
                                                    { print_error("Invalid parameter. Skipping."); yyerrok; }
#line 1318 "c-language.tab.c"
    break;

  case 27: /* param: tipo_especificador ID  */
#line 116 "c-language.y"
                                  {
                printf("Inserindo id %s do tipo %d\n", (yyvsp[0].identifier), (yyvsp[-1].tipo));
                TDS_novoSimbolo((yyvsp[0].identifier), (yyvsp[-1].tipo));
            }
#line 1327 "c-language.tab.c"
    break;

  case 28: /* param: tipo_especificador ID OB CB  */
#line 120 "c-language.y"
                                        {
                printf("Inserindo id %s do tipo %d\n", (yyvsp[-2].identifier), (yyvsp[-3].tipo));
                TDS_novoSimbolo((yyvsp[-2].identifier), (yyvsp[-3].tipo));
            }
#line 1336 "c-language.tab.c"
    break;

  case 29: /* param: tipo_especificador ID error CB  */
#line 125 "c-language.y"
                                            {print_error("Missing open bracket: '['"); yyerrok;}
#line 1342 "c-language.tab.c"
    break;

  case 30: /* $@1: %empty  */
#line 129 "c-language.y"
                    {
                    new_TabDeSimbolos();
                }
#line 1350 "c-language.tab.c"
    break;

  case 31: /* composto_decl: OCB $@1 local_decl comando_lista CCB  */
#line 132 "c-language.y"
                                             {
                    delete_TabDeSimbolos();
                }
#line 1358 "c-language.tab.c"
    break;

  case 32: /* composto_decl: OCB error CCB  */
#line 135 "c-language.y"
                                { print_error("Error inside function body."); yyerrok; }
#line 1364 "c-language.tab.c"
    break;

  case 39: /* comando: error SEMICOLON  */
#line 151 "c-language.y"
                              { print_error("Invalid command."); yyerrok; }
#line 1370 "c-language.tab.c"
    break;

  case 54: /* expressao: error  */
#line 184 "c-language.y"
                        { print_error("Invalid expression."); yyerrok; }
#line 1376 "c-language.tab.c"
    break;

  case 55: /* var: ID  */
#line 187 "c-language.y"
                {
                if (TDS_encontrarSimbolo((yyvsp[0].identifier)) == NULL) {
                    print_error("Variável usada mas não declarada.");
                }
            }
#line 1386 "c-language.tab.c"
    break;

  case 56: /* var: ID var_aux  */
#line 192 "c-language.y"
                        {
                if (TDS_encontrarSimbolo((yyvsp[-1].identifier)) == NULL) {
                    print_error("Variável usada mas não declarada.");
                }
            }
#line 1396 "c-language.tab.c"
    break;

  case 79: /* arg_list: error COMMA arg_list  */
#line 246 "c-language.y"
                                      { print_error("Invalid argument. Skipping."); yyerrok; }
#line 1402 "c-language.tab.c"
    break;


#line 1406 "c-language.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 248 "c-language.y"


#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

void yyerror(const char *s) {
    fprintf(stderr, RED "!SYNTATIC ERROR ocurred at (%d, %d):\n" RESET,
                    line_number, column_number);
    syntax_error_occurred++;
}

void print_error(const char *msg) {
    fprintf(stderr, BLUE "Message:" RESET " %s\n\n", msg);
}

int main(int argc, char **argv) {
    TabDeSimbolos *tab = new_TabDeSimbolos("TabDeSimbolos");

    if (argc < 2){
        printf("Please provide an input file.");
        return -1;
    }
    FILE *arq_compilado = fopen(argv[1], "r");
    if (!arq_compilado) {
        printf("The input file provided is not recognizeble.");
        return -2;
    }

    yyin = arq_compilado;
    yyparse(); // Chamada para iniciar a análise sintática;

    // Verifica se houve erros léxicos OU sintáticos
    if (errors_count > 0 || syntax_error_occurred) {
        printf(RED "*-------------------------------------------------*\n");
        printf("| !!! Syntatic analysis concluded with ERRORS !!! |\n");
        printf(RED "*-------------------------------------------------*\n" RESET);
    } else {
        printf(GREEN"*------------------------------------------------------*\n");
        printf("| !!! Syntatic analysis was successfully concluded !!! |\n");
        printf("*------------------------------------------------------*\n"RESET);
    }

    TDS_imprimir(tab);

    fclose(arq_compilado); // Fecha o arquivo utilizado na análise;


    return 0;
}

