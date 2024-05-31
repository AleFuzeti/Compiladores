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
#line 1 "sintatico.y"

#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include "hash.h"
#include "ast.h"

// Var Bison 
extern int yylex();
void yyerror(char *s);
extern char* yytext;
extern char* buffer;

// Var globais
float h_view_lo = H_VIEW_LO_;
float h_view_hi = H_VIEW_HI_;
float v_view_lo = V_VIEW_LO_;
float v_view_hi = V_VIEW_HI_;
int float_precision = FLOAT_PRECISION;
int   integral_steps = INTEGRAL_STEPS__;
int   draw_axis = DRAW_AXIS; 
int   erase_plot = ERASE_PLOT;
int   connect_dots = CONNECT_DOTS_;
char plot[HEIGHT][WIDTH];

hash_table* ht;
TreeNode * AST = NULL;
TreeNode * Expre = NULL;
TreeNode * Rpn_Exp = NULL;

float x_expr = 0.0;
int tem_x = 0;
int var_n_found = 0;
int op_error = 0;
int error = 0;


matrix* Mat;
int matrix_value = 0;

#line 112 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_ABOUT = 6,                      /* ABOUT  */
  YYSYMBOL_ABS = 7,                        /* ABS  */
  YYSYMBOL_AXIS = 8,                       /* AXIS  */
  YYSYMBOL_CONNECT_DOTS = 9,               /* CONNECT_DOTS  */
  YYSYMBOL_COS = 10,                       /* COS  */
  YYSYMBOL_DETERMINANT = 11,               /* DETERMINANT  */
  YYSYMBOL_E = 12,                         /* E  */
  YYSYMBOL_ERASE = 13,                     /* ERASE  */
  YYSYMBOL_FLOAT = 14,                     /* FLOAT  */
  YYSYMBOL_H_VIEW = 15,                    /* H_VIEW  */
  YYSYMBOL_INTEGRAL_STEPS = 16,            /* INTEGRAL_STEPS  */
  YYSYMBOL_INTEGRATE = 17,                 /* INTEGRATE  */
  YYSYMBOL_LINEAR_SYSTEM = 18,             /* LINEAR_SYSTEM  */
  YYSYMBOL_MATRIX = 19,                    /* MATRIX  */
  YYSYMBOL_OFF = 20,                       /* OFF  */
  YYSYMBOL_ON = 21,                        /* ON  */
  YYSYMBOL_PI = 22,                        /* PI  */
  YYSYMBOL_PLOT = 23,                      /* PLOT  */
  YYSYMBOL_PRECISION = 24,                 /* PRECISION  */
  YYSYMBOL_QUIT = 25,                      /* QUIT  */
  YYSYMBOL_RESET = 26,                     /* RESET  */
  YYSYMBOL_RPN = 27,                       /* RPN  */
  YYSYMBOL_SEN = 28,                       /* SEN  */
  YYSYMBOL_SET = 29,                       /* SET  */
  YYSYMBOL_SETTINGS = 30,                  /* SETTINGS  */
  YYSYMBOL_SHOW = 31,                      /* SHOW  */
  YYSYMBOL_SOLVE = 32,                     /* SOLVE  */
  YYSYMBOL_SUM = 33,                       /* SUM  */
  YYSYMBOL_SYMBOLS = 34,                   /* SYMBOLS  */
  YYSYMBOL_TAN = 35,                       /* TAN  */
  YYSYMBOL_V_VIEW = 36,                    /* V_VIEW  */
  YYSYMBOL_X = 37,                         /* X  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_TIMES = 40,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 41,                    /* DIVIDE  */
  YYSYMBOL_POWER = 42,                     /* POWER  */
  YYSYMBOL_MOD = 43,                       /* MOD  */
  YYSYMBOL_OPEN_PAR = 44,                  /* OPEN_PAR  */
  YYSYMBOL_CLOSE_PAR = 45,                 /* CLOSE_PAR  */
  YYSYMBOL_COLON = 46,                     /* COLON  */
  YYSYMBOL_EQUAL = 47,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 48,                    /* ASSIGN  */
  YYSYMBOL_OPEN_BRA = 49,                  /* OPEN_BRA  */
  YYSYMBOL_CLOSE_BRA = 50,                 /* CLOSE_BRA  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 52,                     /* COMMA  */
  YYSYMBOL_ERROR = 53,                     /* ERROR  */
  YYSYMBOL_NEW_LINE = 54,                  /* NEW_LINE  */
  YYSYMBOL_EXIT = 55,                      /* EXIT  */
  YYSYMBOL_END_OF_FILE = 56,               /* END_OF_FILE  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_Programa = 58,                  /* Programa  */
  YYSYMBOL_Sentenca = 59,                  /* Sentenca  */
  YYSYMBOL_Settings = 60,                  /* Settings  */
  YYSYMBOL_Set = 61,                       /* Set  */
  YYSYMBOL_Plot = 62,                      /* Plot  */
  YYSYMBOL_Rpn = 63,                       /* Rpn  */
  YYSYMBOL_Integrate = 64,                 /* Integrate  */
  YYSYMBOL_Sum = 65,                       /* Sum  */
  YYSYMBOL_Matrix = 66,                    /* Matrix  */
  YYSYMBOL_Dimensao = 67,                  /* Dimensao  */
  YYSYMBOL_Value = 68,                     /* Value  */
  YYSYMBOL_Solve = 69,                     /* Solve  */
  YYSYMBOL_About = 70,                     /* About  */
  YYSYMBOL_Atribuicao = 71,                /* Atribuicao  */
  YYSYMBOL_Expressao = 72,                 /* Expressao  */
  YYSYMBOL_Termo = 73,                     /* Termo  */
  YYSYMBOL_Pow = 74,                       /* Pow  */
  YYSYMBOL_Fator = 75,                     /* Fator  */
  YYSYMBOL_Funcao = 76,                    /* Funcao  */
  YYSYMBOL_Num = 77,                       /* Num  */
  YYSYMBOL_Cons = 78                       /* Cons  */
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
#define YYFINAL  84
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   120,   121,   122,   150,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   182,   183,
     184,   188,   191,   194,   195,   196,   197,   198,   200,   207,
     225,   232,   242,   253,   275,   303,   308,   312,   322,   323,
     327,   328,   332,   340,   351,   355,   387,   388,   389,   393,
     394,   395,   399,   400,   404,   405,   406,   407,   411,   412,
     413,   414,   418,   419,   420,   421,   422,   423,   428,   429,
     430,   431,   432,   433,   434,   447
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER", "REAL", "ABOUT", "ABS", "AXIS", "CONNECT_DOTS", "COS",
  "DETERMINANT", "E", "ERASE", "FLOAT", "H_VIEW", "INTEGRAL_STEPS",
  "INTEGRATE", "LINEAR_SYSTEM", "MATRIX", "OFF", "ON", "PI", "PLOT",
  "PRECISION", "QUIT", "RESET", "RPN", "SEN", "SET", "SETTINGS", "SHOW",
  "SOLVE", "SUM", "SYMBOLS", "TAN", "V_VIEW", "X", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "POWER", "MOD", "OPEN_PAR", "CLOSE_PAR", "COLON",
  "EQUAL", "ASSIGN", "OPEN_BRA", "CLOSE_BRA", "SEMICOLON", "COMMA",
  "ERROR", "NEW_LINE", "EXIT", "END_OF_FILE", "$accept", "Programa",
  "Sentenca", "Settings", "Set", "Plot", "Rpn", "Integrate", "Sum",
  "Matrix", "Dimensao", "Value", "Solve", "About", "Atribuicao",
  "Expressao", "Termo", "Pow", "Fator", "Funcao", "Num", "Cons", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      86,    27,  -147,  -147,   -23,    -5,     5,  -147,     9,    15,
    -147,   -28,    17,    43,   -20,    53,     4,    31,    52,    58,
      63,  -147,    76,    42,    -1,    33,  -147,   110,    66,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    44,
     117,    80,  -147,  -147,  -147,  -147,   131,  -147,  -147,    -1,
      -1,     3,    93,    -1,  -147,  -147,    81,    -1,  -147,    -1,
      64,   114,   128,     3,     3,     3,   104,   116,   122,   123,
     125,   159,    -1,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,    13,  -147,  -147,  -147,    -1,    -1,    -1,    -1,
      -1,   129,    18,    21,    29,   124,   119,   130,    56,  -147,
      61,    88,   126,   132,   140,     3,   135,   133,   136,  -147,
    -147,  -147,  -147,  -147,   134,   106,  -147,   117,   117,    80,
      80,  -147,     3,  -147,  -147,  -147,     3,     3,   137,   138,
    -147,  -147,  -147,   139,   141,   142,     3,  -147,     3,   181,
    -147,   144,   143,   145,   146,  -147,  -147,  -147,  -147,  -147,
     147,   148,   154,   149,     3,    -1,   149,  -147,  -147,   183,
     153,   155,  -147,   109,   156,   151,     3,   157,   158,   160,
      -1,   162,  -147,  -147,  -147,   111,   149,   163,  -147,  -147
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    74,    62,    63,     0,     0,     0,    70,     0,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     4,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     5,
      46,    49,    52,    56,    54,    57,     0,    17,    44,     0,
       0,     0,     0,     0,    30,     3,     0,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    66,    75,    65,    64,    71,    69,
      73,    74,     0,     6,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      18,    20,    43,    42,     0,     0,    55,    47,    48,    50,
      51,    53,     0,    45,    61,    59,     0,     0,     0,     0,
      58,    24,    23,     0,     0,     0,     0,    27,     0,     0,
      60,     0,    40,     0,     0,    29,    31,    26,    25,    28,
       0,     0,     0,    39,     0,     0,    39,    21,    22,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    33,    35,     0,    39,     0,    38,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -146,  -122,  -147,  -147,  -147,   -24,    77,    83,   101,  -147,
     -50,  -147
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     161,   141,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      82,    96,    81,     2,     3,   144,     5,     2,     3,     6,
     164,     7,    60,   106,   107,   108,    53,    61,    62,    63,
      64,    10,    92,    54,    57,    93,    94,    15,    48,    98,
     178,    58,   162,   100,    20,   101,    21,    22,    23,    49,
      65,    22,    95,    24,   171,    75,    76,    77,   115,    50,
      66,    86,    87,    51,    78,   135,    86,    87,   116,    86,
      87,    67,    52,    69,    79,    68,   124,    86,    87,   123,
      70,    55,   142,    56,   125,    46,   143,   142,    47,    80,
      73,    74,    86,    87,   102,   103,   150,    83,   151,     1,
       2,     3,     4,     5,    86,    87,     6,    59,     7,    86,
      87,   128,    71,     8,   142,     9,   129,    72,    10,    11,
      84,    12,    13,    14,    15,    16,   142,    17,    18,    19,
      85,    20,    90,    21,    22,    23,    86,    87,    76,    77,
      24,   163,    99,   130,    81,     2,     3,   104,     5,    25,
      26,     6,    97,     7,    86,    87,   175,    86,    87,    86,
      87,   140,   105,    10,   168,   109,   177,    88,    89,    15,
     133,   134,   114,   117,   118,   126,    20,   110,    21,    22,
      23,   119,   120,   111,   112,    24,   113,   131,   122,   127,
      91,   136,   138,   132,   137,   152,   139,   165,   145,   146,
     147,   121,   148,   149,   153,   154,   156,   155,   157,   158,
     159,   160,   166,   170,     0,   167,   169,     0,   172,   173,
       0,   174,   176,     0,   179
};

static const yytype_int16 yycheck[] =
{
      24,    51,     3,     4,     5,   127,     7,     4,     5,    10,
     156,    12,     8,    63,    64,    65,    44,    13,    14,    15,
      16,    22,    46,    51,    44,    49,    50,    28,    51,    53,
     176,    51,   154,    57,    35,    59,    37,    38,    39,    44,
      36,    38,    39,    44,   166,     3,     4,     5,    72,    44,
      19,    38,    39,    44,    12,   105,    38,    39,    45,    38,
      39,    30,    47,    11,    22,    34,    45,    38,    39,    51,
      18,    54,   122,    30,    45,    48,   126,   127,    51,    37,
       4,     5,    38,    39,    20,    21,   136,    54,   138,     3,
       4,     5,     6,     7,    38,    39,    10,    44,    12,    38,
      39,    45,    44,    17,   154,    19,    45,    44,    22,    23,
       0,    25,    26,    27,    28,    29,   166,    31,    32,    33,
      54,    35,    42,    37,    38,    39,    38,    39,     4,     5,
      44,   155,    51,    45,     3,     4,     5,    23,     7,    53,
      54,    10,    49,    12,    38,    39,   170,    38,    39,    38,
      39,    45,    24,    22,    45,    51,    45,    40,    41,    28,
      20,    21,     3,    86,    87,    46,    35,    51,    37,    38,
      39,    88,    89,    51,    51,    44,    51,    51,    49,    49,
      49,    46,    46,    51,    51,     4,    52,     4,    51,    51,
      51,    90,    51,    51,    50,    52,    50,    52,    51,    51,
      46,    52,    49,    52,    -1,    50,    50,    -1,    51,    51,
      -1,    51,    50,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    12,    17,    19,
      22,    23,    25,    26,    27,    28,    29,    31,    32,    33,
      35,    37,    38,    39,    44,    53,    54,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    48,    51,    51,    44,
      44,    44,    47,    44,    51,    54,    30,    44,    51,    44,
       8,    13,    14,    15,    16,    36,    19,    30,    34,    11,
      18,    44,    44,     4,     5,     3,     4,     5,    12,    22,
      37,     3,    72,    54,     0,    54,    38,    39,    40,    41,
      42,    49,    72,    72,    72,    39,    77,    49,    72,    51,
      72,    72,    20,    21,    23,    24,    77,    77,    77,    51,
      51,    51,    51,    51,     3,    72,    45,    73,    73,    74,
      74,    75,    49,    51,    45,    45,    46,    49,    45,    45,
      45,    51,    51,    20,    21,    77,    46,    51,    46,    52,
      45,    68,    77,    77,    68,    51,    51,    51,    51,    51,
      77,    77,     4,    50,    52,    52,    50,    51,    51,    46,
      52,    67,    68,    72,    67,     4,    49,    50,    45,    50,
      52,    68,    51,    51,    51,    72,    50,    45,    67,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    65,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    72,    72,    72,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     6,     6,     4,     4,     5,     5,     4,     5,     5,
       2,     5,     2,     9,    11,     9,     9,     3,     5,     0,
       1,     3,     3,     3,     2,     4,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     4,     4,
       4,     4,     1,     1,     2,     2,     2,     2,     1,     2,
       1,     2,     1,     2,     1,     2
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
  case 2: /* Programa: Sentenca NEW_LINE  */
#line 119 "sintatico.y"
                        { return 0; }
#line 1297 "sintatico.tab.c"
    break;

  case 3: /* Programa: QUIT NEW_LINE  */
#line 120 "sintatico.y"
                    { return QUIT_; }
#line 1303 "sintatico.tab.c"
    break;

  case 4: /* Programa: NEW_LINE  */
#line 121 "sintatico.y"
               { return NEW_LINE; }
#line 1309 "sintatico.tab.c"
    break;

  case 5: /* Programa: Expressao  */
#line 122 "sintatico.y"
                            {
        AST = (yyvsp[0].ast);
        if (AST != NULL) {
            Eval_Ast(AST);
            if (!var_n_found && !op_error){
                //Set_Expre(AST);
                if (!tem_x) {
                    TreeNode* Aux = NULL;
                    Aux = Eval_Ast(AST);
                    //printf("aux->type: %c\n", Aux->type);
                    if (Aux->type == 'f') {
                        print_formated_number(Aux->value, 1);
                        printf("\n");
                    } else {
                        matrix_print(Aux->m);
                    }
                } else {
                    printf("\nThe x variable cannot be present on expressions.\n\n");
                    tem_x = 0;
                }
            } else {
                var_n_found = 0; 
                op_error = 0;
                Delete_Tree(AST);
            }
        } else printf("ast null\n");
        return 0;
    }
#line 1342 "sintatico.tab.c"
    break;

  case 6: /* Programa: ERROR NEW_LINE  */
#line 150 "sintatico.y"
                     { return 0; }
#line 1348 "sintatico.tab.c"
    break;

  case 7: /* Sentenca: Settings  */
#line 154 "sintatico.y"
               { }
#line 1354 "sintatico.tab.c"
    break;

  case 8: /* Sentenca: Set  */
#line 155 "sintatico.y"
          { }
#line 1360 "sintatico.tab.c"
    break;

  case 9: /* Sentenca: Plot  */
#line 156 "sintatico.y"
           { }
#line 1366 "sintatico.tab.c"
    break;

  case 10: /* Sentenca: Rpn  */
#line 157 "sintatico.y"
          { }
#line 1372 "sintatico.tab.c"
    break;

  case 11: /* Sentenca: Integrate  */
#line 158 "sintatico.y"
                { }
#line 1378 "sintatico.tab.c"
    break;

  case 12: /* Sentenca: Sum  */
#line 159 "sintatico.y"
          { }
#line 1384 "sintatico.tab.c"
    break;

  case 13: /* Sentenca: Matrix  */
#line 160 "sintatico.y"
             { }
#line 1390 "sintatico.tab.c"
    break;

  case 14: /* Sentenca: Solve  */
#line 161 "sintatico.y"
            { }
#line 1396 "sintatico.tab.c"
    break;

  case 15: /* Sentenca: About  */
#line 162 "sintatico.y"
            { }
#line 1402 "sintatico.tab.c"
    break;

  case 16: /* Sentenca: Atribuicao  */
#line 163 "sintatico.y"
                 { }
#line 1408 "sintatico.tab.c"
    break;

  case 17: /* Sentenca: IDENTIFIER SEMICOLON  */
#line 164 "sintatico.y"
                           {
        float num = hash_table_search(ht, (yyvsp[-1].strval)); 
        if (num == NOT_FIND) {
            printf("Undefined symbol [%s]\n", (yyvsp[-1].strval));
        }
        else {
            if (get_type(ht, (yyvsp[-1].strval)) == 'f'){
                printf("\n%s = ", (yyvsp[-1].strval));
                print_formated_number(num, 0);
                printf("\n\n");
            } else {
                get_print_matrix(ht, (yyvsp[-1].strval));
            }
        }
     }
#line 1428 "sintatico.tab.c"
    break;

  case 18: /* Settings: SHOW SETTINGS SEMICOLON  */
#line 182 "sintatico.y"
                              { ShowSettings(); }
#line 1434 "sintatico.tab.c"
    break;

  case 19: /* Settings: RESET SETTINGS SEMICOLON  */
#line 183 "sintatico.y"
                               { ResetSettings(); }
#line 1440 "sintatico.tab.c"
    break;

  case 20: /* Settings: SHOW SYMBOLS SEMICOLON  */
#line 184 "sintatico.y"
                             { hash_table_print(ht); }
#line 1446 "sintatico.tab.c"
    break;

  case 21: /* Set: SET H_VIEW Num COLON Num SEMICOLON  */
#line 188 "sintatico.y"
                                        { float hhi = Get_Value((yyvsp[-1].ast)); float hlo = Get_Value((yyvsp[-3].ast));
        if (hhi < hlo) printf("\nERROR: h_view_lo must be smaller than h_view_hi\n\n"); else { h_view_hi = hhi; h_view_lo = hlo; }
        initialize_plot(plot);}
#line 1454 "sintatico.tab.c"
    break;

  case 22: /* Set: SET V_VIEW Num COLON Num SEMICOLON  */
#line 191 "sintatico.y"
                                        { float vhi = Get_Value((yyvsp[-1].ast)); float vlo = Get_Value((yyvsp[-3].ast));
        if (vhi < vlo) printf("\nERROR: v_view_lo must be smaller than v_view_hi\n\n"); else { v_view_hi = vhi; v_view_lo = vlo; }
        initialize_plot(plot);}
#line 1462 "sintatico.tab.c"
    break;

  case 23: /* Set: SET AXIS ON SEMICOLON  */
#line 194 "sintatico.y"
                           { draw_axis = 1; }
#line 1468 "sintatico.tab.c"
    break;

  case 24: /* Set: SET AXIS OFF SEMICOLON  */
#line 195 "sintatico.y"
                            { draw_axis = 0; }
#line 1474 "sintatico.tab.c"
    break;

  case 25: /* Set: SET ERASE PLOT ON SEMICOLON  */
#line 196 "sintatico.y"
                                 { erase_plot = 1; }
#line 1480 "sintatico.tab.c"
    break;

  case 26: /* Set: SET ERASE PLOT OFF SEMICOLON  */
#line 197 "sintatico.y"
                                  { erase_plot = 0; }
#line 1486 "sintatico.tab.c"
    break;

  case 27: /* Set: SET INTEGRAL_STEPS Num SEMICOLON  */
#line 198 "sintatico.y"
                                       { if ((int)Get_Value((yyvsp[-1].ast))<1) printf("\nERROR: integral_steps must be a positive non-zero integer\n\n"); 
        else integral_steps = (int)Get_Value((yyvsp[-1].ast)); }
#line 1493 "sintatico.tab.c"
    break;

  case 28: /* Set: SET FLOAT PRECISION Num SEMICOLON  */
#line 200 "sintatico.y"
                                        { 
        int pre = (int)Get_Value((yyvsp[-1].ast));
        if(pre < 0 || pre > 8) printf("\nERROR: float precision must be from 0 to 8\n\n");
        else float_precision = pre; }
#line 1502 "sintatico.tab.c"
    break;

  case 29: /* Plot: PLOT OPEN_PAR Expressao CLOSE_PAR SEMICOLON  */
#line 207 "sintatico.y"
                                                 {
        AST = (yyvsp[-2].ast);
        if (AST != NULL) {
            printf("\n");
            Eval_Ast(AST);
            if (!var_n_found && !op_error){
                Set_Expre(AST);
                plot_function(plot, Expre);
            }
            else {
                var_n_found = 0; 
                op_error = 0;
                Delete_Tree(AST);
            }
        }
        printf("\n");
        tem_x = 0;
    }
#line 1525 "sintatico.tab.c"
    break;

  case 30: /* Plot: PLOT SEMICOLON  */
#line 225 "sintatico.y"
                    { 
        if(!Expre) printf("\n No Function defined!\n\n");
        else plot_function(plot, Expre);
    }
#line 1534 "sintatico.tab.c"
    break;

  case 31: /* Rpn: RPN OPEN_PAR Expressao CLOSE_PAR SEMICOLON  */
#line 232 "sintatico.y"
                                                 { 
        AST = (yyvsp[-2].ast);
        if (AST != NULL) {
            printf("\nExpression in RPN format:\n\n");
            RPN_Walk(AST);
            Set_Rpn_Exp(AST);
            printf("\n");
        } else printf("ast null\n");
        printf("\n");
    }
#line 1549 "sintatico.tab.c"
    break;

  case 32: /* Rpn: RPN SEMICOLON  */
#line 242 "sintatico.y"
                    { 
        if(!Rpn_Exp) printf("\n No Function defined!\n\n");
        else{
            printf("\nExpression in RPN format:\n\n");
            RPN_Walk(Rpn_Exp);
            printf("\n");
        }
    }
#line 1562 "sintatico.tab.c"
    break;

  case 33: /* Integrate: INTEGRATE OPEN_PAR Num COLON Num COMMA Expressao CLOSE_PAR SEMICOLON  */
#line 253 "sintatico.y"
                                                                           { 
        AST = (yyvsp[-2].ast);
        if (AST != NULL) {
        float inf = Get_Value((yyvsp[-6].ast));
        float sup = Get_Value((yyvsp[-4].ast));
        printf("\n");
        float result = integral_ast(AST, inf, sup, integral_steps);
        if (!var_n_found && !op_error){
            printf("%f\n", result);
        }
        else {
            var_n_found = 0; 
            op_error = 0;
        }
        Delete_Tree(AST);
        printf("\n");
        } else printf("ast null\n");
        tem_x = 0;
    }
#line 1586 "sintatico.tab.c"
    break;

  case 34: /* Sum: SUM OPEN_PAR IDENTIFIER COMMA INTEGER COLON INTEGER COMMA Expressao CLOSE_PAR SEMICOLON  */
#line 275 "sintatico.y"
                                                                                             {
        AST = (yyvsp[-2].ast);
        float sum = 0;
        float inf = (float)(yyvsp[-6].intval);
        float sup = (float)(yyvsp[-4].intval);
        var_n_found = 0;
        if (AST != NULL) {
            float num = hash_table_search(ht, (yyvsp[-8].strval)); 
            for (int i = inf; i <= sup; i++) {
                if(var_n_found) break;
                hash_table_insert(ht, (yyvsp[-8].strval), (float)i);
                sum += Get_Value(Eval_Ast(AST));
                hash_table_remove(ht, (yyvsp[-8].strval));
            }
            if(num != NOT_FIND) hash_table_insert(ht, (yyvsp[-8].strval), num);
            if (!var_n_found && !op_error){
                printf("\n%f\n\n", sum);
            }
            else {
                var_n_found = 0; 
                op_error = 0;
            }
            Delete_Tree(AST);
        } else printf("ast null\n");
    }
#line 1616 "sintatico.tab.c"
    break;

  case 35: /* Matrix: MATRIX EQUAL OPEN_BRA OPEN_BRA Value CLOSE_BRA Dimensao CLOSE_BRA SEMICOLON  */
#line 303 "sintatico.y"
                                                                                 { 
        matrix_value   = 1;
        Mat = matrix_grammar(buffer, "matrix", ht);
        // matrix_print(Mat);
    }
#line 1626 "sintatico.tab.c"
    break;

  case 36: /* Matrix: IDENTIFIER ASSIGN OPEN_BRA OPEN_BRA Value CLOSE_BRA Dimensao CLOSE_BRA SEMICOLON  */
#line 308 "sintatico.y"
                                                                                      {
        matrix_grammar(buffer, (yyvsp[-8].strval), ht);
        get_print_matrix(ht, (yyvsp[-8].strval));
    }
#line 1635 "sintatico.tab.c"
    break;

  case 37: /* Matrix: SHOW MATRIX SEMICOLON  */
#line 312 "sintatico.y"
                           {
        if (matrix_value == 0) {
            printf("\nNo Matrix defined!\n\n");
        } else {
            matrix_print(Mat);
        }
    }
#line 1647 "sintatico.tab.c"
    break;

  case 38: /* Dimensao: COMMA OPEN_BRA Value CLOSE_BRA Dimensao  */
#line 322 "sintatico.y"
                                               { }
#line 1653 "sintatico.tab.c"
    break;

  case 39: /* Dimensao: %empty  */
#line 323 "sintatico.y"
      { }
#line 1659 "sintatico.tab.c"
    break;

  case 40: /* Value: Num  */
#line 327 "sintatico.y"
          { }
#line 1665 "sintatico.tab.c"
    break;

  case 41: /* Value: Num COMMA Value  */
#line 328 "sintatico.y"
                      { }
#line 1671 "sintatico.tab.c"
    break;

  case 42: /* Solve: SOLVE LINEAR_SYSTEM SEMICOLON  */
#line 332 "sintatico.y"
                                    { 
        if (matrix_value == 0) {
            printf("\nNo Matrix defined!\n\n");
        } else {
            //matrix_print(Mat);
            solve_linear_system(Mat);
        }
     }
#line 1684 "sintatico.tab.c"
    break;

  case 43: /* Solve: SOLVE DETERMINANT SEMICOLON  */
#line 340 "sintatico.y"
                                  {  
        if (matrix_value == 0) {
            printf("\nNo Matrix defined!\n\n");
        } else {
            if (matrix_determinant(Mat) != NOT_FIND)
            printf("\n%f\n\n", matrix_determinant(Mat));
        }
     }
#line 1697 "sintatico.tab.c"
    break;

  case 44: /* About: ABOUT SEMICOLON  */
#line 351 "sintatico.y"
                     { About(); }
#line 1703 "sintatico.tab.c"
    break;

  case 45: /* Atribuicao: IDENTIFIER ASSIGN Expressao SEMICOLON  */
#line 355 "sintatico.y"
                                            { 
        AST = (yyvsp[-1].ast);
        if (AST != NULL) { 
            Eval_Ast(AST);
            if (!var_n_found && !op_error){
                if (!tem_x) {
                    TreeNode* Aux = NULL;
                    Aux = Eval_Ast(AST);
                    //printf("aux->type: %c\n", Aux->type);
                    if (Aux->type == 'f') {
                        print_formated_number(Aux->value, 1);
                        printf("\n");
                        hash_table_insert(ht, (yyvsp[-3].strval), Aux->value);
                    } else {
                        matrix_print(Aux->m);
                        htable_insert_matrix(ht, (yyvsp[-3].strval), Aux->m);
                    } 
                } else {
                    printf("\nThe x variable cannot be present on expressions.\n\n");
                    tem_x = 0;
                }
            Delete_Tree(AST); 
            } else {
                var_n_found = 0; 
                op_error = 0;
                Delete_Tree(AST);
            }
        }
    }
#line 1737 "sintatico.tab.c"
    break;

  case 46: /* Expressao: Termo  */
#line 387 "sintatico.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1743 "sintatico.tab.c"
    break;

  case 47: /* Expressao: Expressao PLUS Termo  */
#line 388 "sintatico.y"
                                       { (yyval.ast) = Create_Node(PLUS, (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1749 "sintatico.tab.c"
    break;

  case 48: /* Expressao: Expressao MINUS Termo  */
#line 389 "sintatico.y"
                                    { (yyval.ast) = Create_Node(MINUS, (yyvsp[-2].ast), (yyvsp[0].ast), 0);}
#line 1755 "sintatico.tab.c"
    break;

  case 49: /* Termo: Pow  */
#line 393 "sintatico.y"
          { (yyval.ast) = (yyvsp[0].ast); }
#line 1761 "sintatico.tab.c"
    break;

  case 50: /* Termo: Termo TIMES Pow  */
#line 394 "sintatico.y"
                                  { (yyval.ast) = Create_Node(TIMES, (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1767 "sintatico.tab.c"
    break;

  case 51: /* Termo: Termo DIVIDE Pow  */
#line 395 "sintatico.y"
                                  { (yyval.ast) = Create_Node(DIVIDE, (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1773 "sintatico.tab.c"
    break;

  case 52: /* Pow: Fator  */
#line 399 "sintatico.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1779 "sintatico.tab.c"
    break;

  case 53: /* Pow: Pow POWER Fator  */
#line 400 "sintatico.y"
                      { (yyval.ast) = Create_Node(POWER, (yyvsp[-2].ast), (yyvsp[0].ast), 0);}
#line 1785 "sintatico.tab.c"
    break;

  case 54: /* Fator: Num  */
#line 404 "sintatico.y"
          { (yyval.ast) = (yyvsp[0].ast); }
#line 1791 "sintatico.tab.c"
    break;

  case 55: /* Fator: OPEN_PAR Expressao CLOSE_PAR  */
#line 405 "sintatico.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 1797 "sintatico.tab.c"
    break;

  case 56: /* Fator: Funcao  */
#line 406 "sintatico.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1803 "sintatico.tab.c"
    break;

  case 57: /* Fator: Cons  */
#line 407 "sintatico.y"
           { (yyval.ast) = (yyvsp[0].ast); }
#line 1809 "sintatico.tab.c"
    break;

  case 58: /* Funcao: SEN OPEN_PAR Expressao CLOSE_PAR  */
#line 411 "sintatico.y"
                                        { (yyval.ast)  = Create_Node(SEN, (yyvsp[-1].ast), NULL, 0); }
#line 1815 "sintatico.tab.c"
    break;

  case 59: /* Funcao: COS OPEN_PAR Expressao CLOSE_PAR  */
#line 412 "sintatico.y"
                                        { (yyval.ast)  = Create_Node(COS, (yyvsp[-1].ast), NULL, 0); }
#line 1821 "sintatico.tab.c"
    break;

  case 60: /* Funcao: TAN OPEN_PAR Expressao CLOSE_PAR  */
#line 413 "sintatico.y"
                                        { (yyval.ast)  = Create_Node(TAN, (yyvsp[-1].ast), NULL, 0); }
#line 1827 "sintatico.tab.c"
    break;

  case 61: /* Funcao: ABS OPEN_PAR Expressao CLOSE_PAR  */
#line 414 "sintatico.y"
                                         { (yyval.ast)  = Create_Node(ABS, (yyvsp[-1].ast), NULL, 0); }
#line 1833 "sintatico.tab.c"
    break;

  case 62: /* Num: INTEGER  */
#line 418 "sintatico.y"
              { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, (float)(yyvsp[0].intval));}
#line 1839 "sintatico.tab.c"
    break;

  case 63: /* Num: REAL  */
#line 419 "sintatico.y"
           { (yyval.ast) =  Create_Node(INTEGER, NULL, NULL, (yyvsp[0].realval));}
#line 1845 "sintatico.tab.c"
    break;

  case 64: /* Num: MINUS REAL  */
#line 420 "sintatico.y"
                 { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, -(yyvsp[0].realval)); }
#line 1851 "sintatico.tab.c"
    break;

  case 65: /* Num: MINUS INTEGER  */
#line 421 "sintatico.y"
                    { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, (float)-(yyvsp[0].intval)); }
#line 1857 "sintatico.tab.c"
    break;

  case 66: /* Num: PLUS REAL  */
#line 422 "sintatico.y"
                { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, (yyvsp[0].realval)); }
#line 1863 "sintatico.tab.c"
    break;

  case 67: /* Num: PLUS INTEGER  */
#line 423 "sintatico.y"
                   { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, (float)(yyvsp[0].intval)); }
#line 1869 "sintatico.tab.c"
    break;

  case 68: /* Cons: PI  */
#line 428 "sintatico.y"
         { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, PI_); }
#line 1875 "sintatico.tab.c"
    break;

  case 69: /* Cons: MINUS PI  */
#line 429 "sintatico.y"
               { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, -PI_); }
#line 1881 "sintatico.tab.c"
    break;

  case 70: /* Cons: E  */
#line 430 "sintatico.y"
        { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, E_); }
#line 1887 "sintatico.tab.c"
    break;

  case 71: /* Cons: MINUS E  */
#line 431 "sintatico.y"
              { (yyval.ast) = Create_Node(INTEGER, NULL, NULL, -E_); }
#line 1893 "sintatico.tab.c"
    break;

  case 72: /* Cons: X  */
#line 432 "sintatico.y"
        { (yyval.ast) = Create_Node(X, NULL, NULL, 0); tem_x = 1; }
#line 1899 "sintatico.tab.c"
    break;

  case 73: /* Cons: MINUS X  */
#line 433 "sintatico.y"
              { (yyval.ast) = Create_Node(X, NULL, NULL, 0); tem_x = 1; }
#line 1905 "sintatico.tab.c"
    break;

  case 74: /* Cons: IDENTIFIER  */
#line 434 "sintatico.y"
                 { 
        float num = hash_table_search(ht, (yyvsp[0].strval)); 
            if (num == NOT_FIND) {
                //printf("Undefined symbol [%s]\n", $1);
                var_n_found = 1;
                (yyval.ast) = Create_Node(IDENTIFIER, NULL, NULL, 0);
                Set_Name((yyval.ast),(yyvsp[0].strval));
            }
            else {
                (yyval.ast) = Create_Node(IDENTIFIER, NULL, NULL, (float)num);
                Set_Name((yyval.ast),(yyvsp[0].strval));
            }
        }
#line 1923 "sintatico.tab.c"
    break;

  case 75: /* Cons: MINUS IDENTIFIER  */
#line 447 "sintatico.y"
                       { 
        float num = hash_table_search(ht, (yyvsp[0].strval)); 
            if (num == NOT_FIND) {
                //printf("Undefined symbol [%s]\n", $2);
                var_n_found = 1;
                (yyval.ast) = Create_Node(IDENTIFIER, NULL, NULL, 0);
                Set_Name((yyval.ast),(yyvsp[0].strval));
            }
            else {
                (yyval.ast) = Create_Node(IDENTIFIER, NULL, NULL, -(float)num);
                Set_Name((yyval.ast),(yyvsp[0].strval));
                Set_Sinal((yyval.ast), 1);
            }
        }
#line 1942 "sintatico.tab.c"
    break;


#line 1946 "sintatico.tab.c"

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

#line 463 "sintatico.y"


void yyerror(char *s) {
    // if (yytext = '\n') {
    //     printf("SYNTAX ERROR: Incomplete Command\n", yytext);
    // } else
     printf("SYNTAX ERROR: [%s]\n", yytext);
}
 
int main(int argc, char *argv[]){

    // falta :

    //      >>
    //      -identifier
    //      plot eixo x y
    //      SYNTAX ERROR: Incomplete Comman 5.2
    //      tirar rpn; 

    int result = 1;
    // Inicializa a hash table
    ht = hash_table_create(MAX_SIZE, hash_f);

    // Inicializa o buffer para o gráfico
    initialize_plot(plot);

    while (result != QUIT_){    
        printf(">");
        result = yyparse();
    }
    printf("hash_table:\n");
    hash_table_print(ht);
    hash_table_destroy(ht);
    Set_Expre(NULL);
    return 0; 
}

void Set_Expre(TreeNode * expre){
    if (Expre != NULL) Delete_Tree(Expre);
    Expre = expre;
}

void Set_Rpn_Exp(TreeNode * rpn_exp){
    if (Rpn_Exp != NULL) Delete_Tree(Rpn_Exp);
    Rpn_Exp = rpn_exp;
}
