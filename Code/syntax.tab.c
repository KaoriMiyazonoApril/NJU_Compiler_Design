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
#line 3 "./syntax.y"

    #include "Node/Node.h"
    #include "lex.yy.c"
    #include "syntax.tab.h"
    extern Node* root;
    extern int yylineno,lab1_sign,bison_last_error_line,last_error_line;
    void yyerror(const char *msg);

#line 80 "./syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_ASSIGNOP = 8,                   /* ASSIGNOP  */
  YYSYMBOL_RELOP = 9,                      /* RELOP  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_STAR = 12,                      /* STAR  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_DOT = 16,                       /* DOT  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_LP = 18,                        /* LP  */
  YYSYMBOL_RP = 19,                        /* RP  */
  YYSYMBOL_LB = 20,                        /* LB  */
  YYSYMBOL_RB = 21,                        /* RB  */
  YYSYMBOL_LC = 22,                        /* LC  */
  YYSYMBOL_RC = 23,                        /* RC  */
  YYSYMBOL_STRUCT = 24,                    /* STRUCT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_TYPE = 29,                      /* TYPE  */
  YYSYMBOL_LOWER_THAN_ELSE = 30,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_ExtDefList = 34,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 35,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 36,                /* ExtDecList  */
  YYSYMBOL_Specifier = 37,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 38,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 39,                    /* OptTag  */
  YYSYMBOL_Tag = 40,                       /* Tag  */
  YYSYMBOL_VarDec = 41,                    /* VarDec  */
  YYSYMBOL_FunDec = 42,                    /* FunDec  */
  YYSYMBOL_VarList = 43,                   /* VarList  */
  YYSYMBOL_ParamDec = 44,                  /* ParamDec  */
  YYSYMBOL_CompSt = 45,                    /* CompSt  */
  YYSYMBOL_StmtList = 46,                  /* StmtList  */
  YYSYMBOL_Stmt = 47,                      /* Stmt  */
  YYSYMBOL_DefList = 48,                   /* DefList  */
  YYSYMBOL_Def = 49,                       /* Def  */
  YYSYMBOL_DecList = 50,                   /* DecList  */
  YYSYMBOL_Dec = 51,                       /* Dec  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Args = 53                       /* Args  */
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   632

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    53,    56,    59,    62,    64,    67,    70,
      73,    76,    79,    82,    86,    89,    92,    95,    99,   102,
     106,   109,   112,   116,   119,   121,   125,   128,   131,   134,
     137,   141,   144,   147,   150,   153,   156,   160,   163,   167,
     171,   174,   177,   180,   184,   187,   188,   192,   195,   198,
     201,   204,   207,   210,   213,   216,   219,   222,   225,   228,
     231,   235,   238,   239,   243,   246,   250,   253,   256,   259,
     262,   266,   269,   272,   276,   279,   282,   285,   288,   291,
     294,   297,   300,   303,   306,   309,   312,   315,   318,   321,
     324,   327,   330,   333,   336,   339,   342,   345,   348,   351,
     354,   357,   360,   363,   366,   371,   374
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "SEMI", "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV",
  "AND", "OR", "DOT", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "TYPE", "LOWER_THAN_ELSE", "UMINUS",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-71)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,    27,    47,   -78,    60,   -78,    24,   130,   -78,    24,
     -78,   136,    41,    44,   -78,   -78,   -78,    95,    62,   -78,
     102,     9,    22,   -78,   -78,    54,   -78,   114,   -78,    83,
     -78,   186,   104,    19,    76,    64,   -78,   105,   119,   107,
      93,   104,   113,   159,   156,   -78,   165,   -78,   -78,   -78,
     -78,   149,   169,   -78,   122,   203,    93,   -78,   -78,    43,
      71,   190,    12,   -78,   -78,   178,   -78,   114,   -78,   -78,
     -78,   -78,   -78,   151,   -78,   -78,   179,   343,   361,   366,
     384,   183,   194,   -78,   192,   229,   304,   -78,   148,   389,
     -78,   236,   148,   -78,   177,   -78,    35,   -78,   338,   -78,
     600,   -78,   147,   197,   561,   207,   320,   407,   412,   -78,
     -78,   -78,   -78,   430,   435,   453,   458,   476,   481,   499,
     504,   213,   522,   212,   -78,   -78,   600,   -78,   -78,   208,
     -78,   534,   216,   -78,   -78,   -78,   -78,   -78,   217,   574,
     219,   587,   -78,   600,   -78,   258,   -78,   173,   -78,   173,
     -78,   147,   -78,   147,   -78,   284,   -78,   612,   -78,   201,
     547,   -78,   206,   -78,   255,   281,   255,   255,   -78,   -78,
     -78,     3,   218,     3,   221,   -78,   -78,   255,   255,   -78,
     -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    24,    18,     0,     2,     0,     0,    19,     0,
       4,     0,    25,     0,    21,     1,     5,    28,    26,    12,
       0,     0,     0,     3,     9,     0,     8,     0,    33,     0,
      11,     0,     0,     0,    10,     0,    13,     0,     0,     0,
       0,     0,     0,    38,    35,    32,     0,    28,    26,    17,
      15,    30,     0,    41,     0,     0,     0,    22,    63,    28,
      71,     0,     0,    20,    61,    39,    36,     0,    34,    31,
      29,    27,    42,     0,    90,    91,    89,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,    65,     0,     0,
      64,     0,     0,    37,     0,    53,    41,    46,     0,   103,
      83,   104,    84,     0,     0,     0,     0,     0,     0,    40,
      44,    54,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    68,    73,    72,    69,    67,     0,
      86,   106,     0,    92,    82,    55,    56,    49,     0,     0,
       0,     0,    95,    74,    98,    77,    99,    78,   100,    79,
     101,    80,   102,    81,    96,    75,    97,    76,    88,     0,
       0,    93,     0,    85,     0,     0,     0,     0,    94,    87,
     105,     0,    57,    58,    50,    60,    52,     0,     0,    59,
      51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,    94,   -78,   133,     5,   -78,   -78,   -78,   -34,
     -78,   -21,   -78,   222,   -38,    -6,    36,   -78,   -18,   -78,
     -77,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    20,    38,     8,    13,    14,    21,
      22,    42,    43,    83,    97,    85,    58,    40,    61,    62,
      86,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,   102,   104,   106,    60,     7,    11,    65,    46,    95,
      31,     7,   126,    91,     7,   -14,    32,    84,   -66,    92,
      51,   131,    52,    34,    -6,     1,    53,    -6,     1,    33,
     139,   141,    41,     9,    41,   -43,   143,   145,   147,   149,
     151,   153,   155,   157,    35,   160,    93,   110,     2,    87,
      88,     2,    12,     3,    60,    37,     3,    60,    60,   -43,
      15,    39,   -43,   -23,   -43,    54,    25,   -62,   -62,   -62,
     124,    55,    41,   127,   128,   -62,    64,   -62,     2,    89,
      29,   -62,   -62,     3,    44,   131,   -62,   -62,     2,   -62,
     -62,    33,   -62,     3,    56,    10,   -62,   -62,   -62,    53,
      16,    26,    45,    23,   -62,    47,    56,     2,    30,    48,
     -62,   -62,     3,    27,    28,   -62,   -62,     2,   -62,   -62,
      59,   -62,     3,    56,    48,   -62,   -62,   -62,    57,     2,
      63,    17,    66,   -62,     3,    18,    19,    17,     2,   -62,
     -62,    18,    24,     3,   -62,    72,     2,   -62,   -62,   123,
     -62,     3,    94,    48,    74,    75,    76,    95,   172,   174,
     175,   176,    77,   121,    49,    50,    67,   122,    78,    79,
      70,   179,   180,    35,    96,    68,    80,    81,    94,    82,
      74,    75,    76,    95,    69,   117,   118,    47,    77,   121,
      71,    48,   -16,   122,    78,    79,    90,    98,    33,    35,
      53,   107,    80,    81,    73,    82,    74,    75,    76,    74,
      75,    76,   108,   135,    77,   109,   133,    77,   158,    88,
      78,    79,   168,    78,    79,    35,   -45,   161,    80,    81,
      94,    82,    74,    75,    76,   163,   164,   123,   166,   170,
      77,    48,   -70,     0,    36,   177,    78,    79,   178,     0,
       0,    35,   -45,     0,    80,    81,   171,    82,    74,    75,
      76,     0,     0,     0,     0,     0,    77,   -71,   115,   116,
     117,   118,    78,    79,   121,     0,     0,    35,   122,     0,
      80,    81,   173,    82,    74,    75,    76,     0,     0,     0,
       0,     0,    77,   114,   115,   116,   117,   118,    78,    79,
     121,     0,     0,    35,   122,   111,    80,    81,     0,    82,
     112,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   136,     0,     0,   122,     0,   137,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,   129,
     122,    74,    75,    76,    99,     0,    74,    75,    76,    77,
       0,     0,     0,     0,    77,    78,    79,   130,     0,     0,
      78,    79,   101,     0,    74,    75,    76,   103,     0,    74,
      75,    76,    77,     0,     0,     0,     0,    77,    78,    79,
       0,     0,     0,    78,    79,   105,     0,    74,    75,    76,
     125,     0,    74,    75,    76,    77,     0,     0,     0,     0,
      77,    78,    79,     0,     0,     0,    78,    79,   138,     0,
      74,    75,    76,   140,     0,    74,    75,    76,    77,     0,
       0,     0,     0,    77,    78,    79,     0,     0,     0,    78,
      79,   142,     0,    74,    75,    76,   144,     0,    74,    75,
      76,    77,     0,     0,     0,     0,    77,    78,    79,     0,
       0,     0,    78,    79,   146,     0,    74,    75,    76,   148,
       0,    74,    75,    76,    77,     0,     0,     0,     0,    77,
      78,    79,     0,     0,     0,    78,    79,   150,     0,    74,
      75,    76,   152,     0,    74,    75,    76,    77,     0,     0,
       0,     0,    77,    78,    79,     0,     0,     0,    78,    79,
     154,     0,    74,    75,    76,   156,     0,    74,    75,    76,
      77,     0,     0,     0,     0,    77,    78,    79,     0,     0,
       0,    78,    79,   159,     0,    74,    75,    76,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,    78,
      79,   162,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,     0,     0,   122,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,   122,   169,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
     134,   122,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,     0,   165,   122,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,   167,   122,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
     122,   114,   115,   116,   117,   118,   119,     0,   121,     0,
       0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      77,    78,    79,    80,    38,     0,     1,    41,    29,     6,
       1,     6,    89,     1,     9,     6,     7,    55,     6,     7,
       1,    98,     3,     1,     0,     1,    23,     0,     1,    20,
     107,   108,    27,     6,    29,     0,   113,   114,   115,   116,
     117,   118,   119,   120,    22,   122,    67,    85,    24,     6,
       7,    24,     5,    29,    88,     1,    29,    91,    92,    24,
       0,    25,    27,    22,    29,     1,    22,     3,     4,     5,
      88,    35,    67,    91,    92,    11,    40,    23,    24,     8,
      18,    17,    18,    29,     1,   162,    22,    23,    24,    25,
      26,    20,    28,    29,     1,     1,     3,     4,     5,    23,
       6,     6,    19,     9,    11,     1,     1,    24,     6,     5,
      17,    18,    29,    18,    19,    22,    23,    24,    25,    26,
       1,    28,    29,     1,     5,     3,     4,     5,    23,    24,
      23,     1,    19,    11,    29,     5,     6,     1,    24,    17,
      18,     5,     6,    29,    22,    23,    24,    25,    26,     1,
      28,    29,     1,     5,     3,     4,     5,     6,   164,   165,
     166,   167,    11,    16,    31,    32,     7,    20,    17,    18,
      21,   177,   178,    22,    23,    19,    25,    26,     1,    28,
       3,     4,     5,     6,    19,    12,    13,     1,    11,    16,
      21,     5,     6,    20,    17,    18,     6,    18,    20,    22,
      23,    18,    25,    26,     1,    28,     3,     4,     5,     3,
       4,     5,    18,     6,    11,    23,    19,    11,     5,     7,
      17,    18,    21,    17,    18,    22,    23,    19,    25,    26,
       1,    28,     3,     4,     5,    19,    19,     1,    19,   162,
      11,     5,     6,    -1,    22,    27,    17,    18,    27,    -1,
      -1,    22,    23,    -1,    25,    26,     1,    28,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    11,     9,    10,    11,
      12,    13,    17,    18,    16,    -1,    -1,    22,    20,    -1,
      25,    26,     1,    28,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    11,     9,    10,    11,    12,    13,    17,    18,
      16,    -1,    -1,    22,    20,     1,    25,    26,    -1,    28,
       6,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     1,    -1,    -1,    20,    -1,     6,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,     1,
      20,     3,     4,     5,     1,    -1,     3,     4,     5,    11,
      -1,    -1,    -1,    -1,    11,    17,    18,    19,    -1,    -1,
      17,    18,     1,    -1,     3,     4,     5,     1,    -1,     3,
       4,     5,    11,    -1,    -1,    -1,    -1,    11,    17,    18,
      -1,    -1,    -1,    17,    18,     1,    -1,     3,     4,     5,
       1,    -1,     3,     4,     5,    11,    -1,    -1,    -1,    -1,
      11,    17,    18,    -1,    -1,    -1,    17,    18,     1,    -1,
       3,     4,     5,     1,    -1,     3,     4,     5,    11,    -1,
      -1,    -1,    -1,    11,    17,    18,    -1,    -1,    -1,    17,
      18,     1,    -1,     3,     4,     5,     1,    -1,     3,     4,
       5,    11,    -1,    -1,    -1,    -1,    11,    17,    18,    -1,
      -1,    -1,    17,    18,     1,    -1,     3,     4,     5,     1,
      -1,     3,     4,     5,    11,    -1,    -1,    -1,    -1,    11,
      17,    18,    -1,    -1,    -1,    17,    18,     1,    -1,     3,
       4,     5,     1,    -1,     3,     4,     5,    11,    -1,    -1,
      -1,    -1,    11,    17,    18,    -1,    -1,    -1,    17,    18,
       1,    -1,     3,     4,     5,     1,    -1,     3,     4,     5,
      11,    -1,    -1,    -1,    -1,    11,    17,    18,    -1,    -1,
      -1,    17,    18,     1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    20,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    20,    21,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      20,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    24,    29,    33,    34,    35,    37,    38,     6,
      34,    37,     5,    39,    40,     0,    34,     1,     5,     6,
      36,    41,    42,    34,     6,    22,     6,    18,    19,    18,
       6,     1,     7,    20,     1,    22,    45,     1,    37,    48,
      49,    37,    43,    44,     1,    19,    43,     1,     5,    36,
      36,     1,     3,    23,     1,    48,     1,    23,    48,     1,
      41,    50,    51,    23,    48,    41,    19,     7,    19,    19,
      21,    21,    23,     1,     3,     4,     5,    11,    17,    18,
      25,    26,    28,    45,    46,    47,    52,     6,     7,     8,
       6,     1,     7,    43,     1,     6,    23,    46,    18,     1,
      52,     1,    52,     1,    52,     1,    52,    18,    18,    23,
      46,     1,     6,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    20,     1,    50,     1,    52,    50,    50,     1,
      19,    52,    53,    19,    19,     6,     1,     6,     1,    52,
       1,    52,     1,    52,     1,    52,     1,    52,     1,    52,
       1,    52,     1,    52,     1,    52,     1,    52,     5,     1,
      52,    19,     7,    19,    19,    19,    19,    19,    21,    21,
      53,     1,    47,     1,    47,    47,    47,    27,    27,    47,
      47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    34,    34,    35,    35,    35,
      35,    35,    35,    35,    36,    36,    36,    36,    37,    37,
      38,    38,    38,    39,    39,    40,    41,    41,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    43,    43,    44,
      45,    45,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     0,     2,     3,     3,
       3,     3,     2,     3,     1,     3,     2,     3,     1,     1,
       5,     2,     5,     1,     0,     1,     1,     4,     1,     4,
       3,     4,     3,     2,     4,     3,     4,     3,     1,     2,
       4,     2,     3,     4,     2,     0,     2,     2,     1,     3,
       5,     7,     5,     2,     2,     3,     3,     5,     5,     7,
       5,     2,     0,     2,     3,     3,     1,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     3,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     1
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
  case 2: /* Program: ExtDefList  */
#line 48 "./syntax.y"
                    {
    (yyval.node) = newNodeN("Program","", (yyvsp[0].node) ? (yyvsp[0].node)->lineNo : (yyloc).first_line, 1, (yyvsp[0].node));
    root = (yyval.node);
}
#line 1448 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: error SEMI ExtDefList  */
#line 53 "./syntax.y"
                                   {

}
#line 1456 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: error ExtDefList  */
#line 56 "./syntax.y"
                   {

}
#line 1464 "./syntax.tab.c"
    break;

  case 5: /* ExtDefList: ExtDef ExtDefList  */
#line 59 "./syntax.y"
                    {
    (yyval.node) = newNodeN("ExtDefList","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1472 "./syntax.tab.c"
    break;

  case 6: /* ExtDefList: %empty  */
#line 62 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1478 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: error SEMI  */
#line 64 "./syntax.y"
                    {

}
#line 1486 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier error SEMI  */
#line 67 "./syntax.y"
                       {

}
#line 1494 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: error Specifier SEMI  */
#line 70 "./syntax.y"
                       {

}
#line 1502 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: Specifier FunDec error  */
#line 73 "./syntax.y"
                         {

}
#line 1510 "./syntax.tab.c"
    break;

  case 11: /* ExtDef: Specifier ExtDecList SEMI  */
#line 76 "./syntax.y"
                            {
    (yyval.node) = newNodeN("ExtDef","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1518 "./syntax.tab.c"
    break;

  case 12: /* ExtDef: Specifier SEMI  */
#line 79 "./syntax.y"
                 {
    (yyval.node) = newNodeN("ExtDef","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1526 "./syntax.tab.c"
    break;

  case 13: /* ExtDef: Specifier FunDec CompSt  */
#line 82 "./syntax.y"
                          {
    (yyval.node) = newNodeN("ExtDef","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1534 "./syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec  */
#line 86 "./syntax.y"
                    {
    (yyval.node) = newNodeN("ExtDecList","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1542 "./syntax.tab.c"
    break;

  case 15: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 89 "./syntax.y"
                          {
    (yyval.node) = newNodeN("ExtDecList","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1550 "./syntax.tab.c"
    break;

  case 16: /* ExtDecList: VarDec error  */
#line 92 "./syntax.y"
             {

}
#line 1558 "./syntax.tab.c"
    break;

  case 17: /* ExtDecList: VarDec error ExtDecList  */
#line 95 "./syntax.y"
                        {

}
#line 1566 "./syntax.tab.c"
    break;

  case 18: /* Specifier: TYPE  */
#line 99 "./syntax.y"
                 {
    (yyval.node) = newNodeN("Specifier","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1574 "./syntax.tab.c"
    break;

  case 19: /* Specifier: StructSpecifier  */
#line 102 "./syntax.y"
                  {
    (yyval.node) = newNodeN("Specifier","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1582 "./syntax.tab.c"
    break;

  case 20: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 106 "./syntax.y"
                                              {
    (yyval.node) = newNodeN("StructSpecifier","", (yyvsp[-4].node)->lineNo, 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1590 "./syntax.tab.c"
    break;

  case 21: /* StructSpecifier: STRUCT Tag  */
#line 109 "./syntax.y"
             {
    (yyval.node) = newNodeN("StructSpecifier","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1598 "./syntax.tab.c"
    break;

  case 22: /* StructSpecifier: STRUCT OptTag LC error RC  */
#line 112 "./syntax.y"
                          {

}
#line 1606 "./syntax.tab.c"
    break;

  case 23: /* OptTag: ID  */
#line 116 "./syntax.y"
            {
    (yyval.node) = newNodeN("OptTag","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1614 "./syntax.tab.c"
    break;

  case 24: /* OptTag: %empty  */
#line 119 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1620 "./syntax.tab.c"
    break;

  case 25: /* Tag: ID  */
#line 121 "./syntax.y"
         {
    (yyval.node) = newNodeN("Tag","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1628 "./syntax.tab.c"
    break;

  case 26: /* VarDec: ID  */
#line 125 "./syntax.y"
            {
    (yyval.node) = newNodeN("VarDec","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1636 "./syntax.tab.c"
    break;

  case 27: /* VarDec: VarDec LB INT RB  */
#line 128 "./syntax.y"
                   {
    (yyval.node) = newNodeN("VarDec","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1644 "./syntax.tab.c"
    break;

  case 28: /* VarDec: error  */
#line 131 "./syntax.y"
        {

}
#line 1652 "./syntax.tab.c"
    break;

  case 29: /* VarDec: VarDec LB error RB  */
#line 134 "./syntax.y"
                     {

}
#line 1660 "./syntax.tab.c"
    break;

  case 30: /* VarDec: VarDec LB error  */
#line 137 "./syntax.y"
                 {

}
#line 1668 "./syntax.tab.c"
    break;

  case 31: /* FunDec: ID LP VarList RP  */
#line 141 "./syntax.y"
                          {
    (yyval.node) = newNodeN("FunDec","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1676 "./syntax.tab.c"
    break;

  case 32: /* FunDec: ID LP RP  */
#line 144 "./syntax.y"
           {
    (yyval.node) = newNodeN("FunDec","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1684 "./syntax.tab.c"
    break;

  case 33: /* FunDec: error RP  */
#line 147 "./syntax.y"
           {

}
#line 1692 "./syntax.tab.c"
    break;

  case 34: /* FunDec: ID LP error RP  */
#line 150 "./syntax.y"
                 {

}
#line 1700 "./syntax.tab.c"
    break;

  case 35: /* FunDec: ID LP error  */
#line 153 "./syntax.y"
             {

}
#line 1708 "./syntax.tab.c"
    break;

  case 36: /* FunDec: error LP VarList RP  */
#line 156 "./syntax.y"
                    {

}
#line 1716 "./syntax.tab.c"
    break;

  case 37: /* VarList: ParamDec COMMA VarList  */
#line 160 "./syntax.y"
                                 {
    (yyval.node) = newNodeN("VarList","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1724 "./syntax.tab.c"
    break;

  case 38: /* VarList: ParamDec  */
#line 163 "./syntax.y"
           {
    (yyval.node) = newNodeN("VarList","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1732 "./syntax.tab.c"
    break;

  case 39: /* ParamDec: Specifier VarDec  */
#line 167 "./syntax.y"
                            {
    (yyval.node) = newNodeN("ParamDec","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1740 "./syntax.tab.c"
    break;

  case 40: /* CompSt: LC DefList StmtList RC  */
#line 171 "./syntax.y"
                                {
    (yyval.node) = newNodeN("CompSt","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1748 "./syntax.tab.c"
    break;

  case 41: /* CompSt: error RC  */
#line 174 "./syntax.y"
           {

}
#line 1756 "./syntax.tab.c"
    break;

  case 42: /* CompSt: LC error RC  */
#line 177 "./syntax.y"
              {

}
#line 1764 "./syntax.tab.c"
    break;

  case 43: /* CompSt: LC DefList error RC  */
#line 180 "./syntax.y"
                      {

}
#line 1772 "./syntax.tab.c"
    break;

  case 44: /* StmtList: Stmt StmtList  */
#line 184 "./syntax.y"
                         {
    (yyval.node) = newNodeN("StmtList","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1780 "./syntax.tab.c"
    break;

  case 45: /* StmtList: %empty  */
#line 187 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1786 "./syntax.tab.c"
    break;

  case 46: /* StmtList: error StmtList  */
#line 188 "./syntax.y"
                 {

}
#line 1794 "./syntax.tab.c"
    break;

  case 47: /* Stmt: Exp SEMI  */
#line 192 "./syntax.y"
                {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1802 "./syntax.tab.c"
    break;

  case 48: /* Stmt: CompSt  */
#line 195 "./syntax.y"
         {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1810 "./syntax.tab.c"
    break;

  case 49: /* Stmt: RETURN Exp SEMI  */
#line 198 "./syntax.y"
                  {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1818 "./syntax.tab.c"
    break;

  case 50: /* Stmt: IF LP Exp RP Stmt  */
#line 201 "./syntax.y"
                                          {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-4].node)->lineNo, 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1826 "./syntax.tab.c"
    break;

  case 51: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 204 "./syntax.y"
                              {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-6].node)->lineNo, 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1834 "./syntax.tab.c"
    break;

  case 52: /* Stmt: WHILE LP Exp RP Stmt  */
#line 207 "./syntax.y"
                       {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-4].node)->lineNo, 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1842 "./syntax.tab.c"
    break;

  case 53: /* Stmt: error SEMI  */
#line 210 "./syntax.y"
             {

}
#line 1850 "./syntax.tab.c"
    break;

  case 54: /* Stmt: Exp error  */
#line 213 "./syntax.y"
          {

}
#line 1858 "./syntax.tab.c"
    break;

  case 55: /* Stmt: RETURN error SEMI  */
#line 216 "./syntax.y"
                    {

}
#line 1866 "./syntax.tab.c"
    break;

  case 56: /* Stmt: RETURN Exp error  */
#line 219 "./syntax.y"
                 {

}
#line 1874 "./syntax.tab.c"
    break;

  case 57: /* Stmt: IF LP error RP Stmt  */
#line 222 "./syntax.y"
                                            {

}
#line 1882 "./syntax.tab.c"
    break;

  case 58: /* Stmt: IF LP Exp RP error  */
#line 225 "./syntax.y"
                                           {

}
#line 1890 "./syntax.tab.c"
    break;

  case 59: /* Stmt: IF LP error RP Stmt ELSE Stmt  */
#line 228 "./syntax.y"
                                {

}
#line 1898 "./syntax.tab.c"
    break;

  case 60: /* Stmt: WHILE LP error RP Stmt  */
#line 231 "./syntax.y"
                         {

}
#line 1906 "./syntax.tab.c"
    break;

  case 61: /* DefList: Def DefList  */
#line 235 "./syntax.y"
                      {
    (yyval.node) = newNodeN("DefList","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1914 "./syntax.tab.c"
    break;

  case 62: /* DefList: %empty  */
#line 238 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1920 "./syntax.tab.c"
    break;

  case 63: /* DefList: error DefList  */
#line 239 "./syntax.y"
                {

}
#line 1928 "./syntax.tab.c"
    break;

  case 64: /* Def: Specifier DecList SEMI  */
#line 243 "./syntax.y"
                             {
    (yyval.node) = newNodeN("Def","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1936 "./syntax.tab.c"
    break;

  case 65: /* Def: Specifier error SEMI  */
#line 246 "./syntax.y"
                     {

}
#line 1944 "./syntax.tab.c"
    break;

  case 66: /* DecList: Dec  */
#line 250 "./syntax.y"
              {
    (yyval.node) = newNodeN("DecList","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1952 "./syntax.tab.c"
    break;

  case 67: /* DecList: Dec COMMA DecList  */
#line 253 "./syntax.y"
                    {
    (yyval.node) = newNodeN("DecList","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1960 "./syntax.tab.c"
    break;

  case 68: /* DecList: error COMMA DecList  */
#line 256 "./syntax.y"
                      {

}
#line 1968 "./syntax.tab.c"
    break;

  case 69: /* DecList: Dec error DecList  */
#line 259 "./syntax.y"
                  {

}
#line 1976 "./syntax.tab.c"
    break;

  case 70: /* DecList: Dec error  */
#line 262 "./syntax.y"
          {

}
#line 1984 "./syntax.tab.c"
    break;

  case 71: /* Dec: VarDec  */
#line 266 "./syntax.y"
             {
    (yyval.node) = newNodeN("Dec","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1992 "./syntax.tab.c"
    break;

  case 72: /* Dec: VarDec ASSIGNOP Exp  */
#line 269 "./syntax.y"
                      {
    (yyval.node) = newNodeN("Dec","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2000 "./syntax.tab.c"
    break;

  case 73: /* Dec: VarDec ASSIGNOP error  */
#line 272 "./syntax.y"
                      {

}
#line 2008 "./syntax.tab.c"
    break;

  case 74: /* Exp: Exp ASSIGNOP Exp  */
#line 276 "./syntax.y"
                       {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2016 "./syntax.tab.c"
    break;

  case 75: /* Exp: Exp AND Exp  */
#line 279 "./syntax.y"
              {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2024 "./syntax.tab.c"
    break;

  case 76: /* Exp: Exp OR Exp  */
#line 282 "./syntax.y"
             {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2032 "./syntax.tab.c"
    break;

  case 77: /* Exp: Exp RELOP Exp  */
#line 285 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2040 "./syntax.tab.c"
    break;

  case 78: /* Exp: Exp PLUS Exp  */
#line 288 "./syntax.y"
               {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2048 "./syntax.tab.c"
    break;

  case 79: /* Exp: Exp MINUS Exp  */
#line 291 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2056 "./syntax.tab.c"
    break;

  case 80: /* Exp: Exp STAR Exp  */
#line 294 "./syntax.y"
               {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2064 "./syntax.tab.c"
    break;

  case 81: /* Exp: Exp DIV Exp  */
#line 297 "./syntax.y"
              {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2072 "./syntax.tab.c"
    break;

  case 82: /* Exp: LP Exp RP  */
#line 300 "./syntax.y"
            {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-1].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2080 "./syntax.tab.c"
    break;

  case 83: /* Exp: MINUS Exp  */
#line 303 "./syntax.y"
                         {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2088 "./syntax.tab.c"
    break;

  case 84: /* Exp: NOT Exp  */
#line 306 "./syntax.y"
          {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2096 "./syntax.tab.c"
    break;

  case 85: /* Exp: ID LP Args RP  */
#line 309 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2104 "./syntax.tab.c"
    break;

  case 86: /* Exp: ID LP RP  */
#line 312 "./syntax.y"
           {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2112 "./syntax.tab.c"
    break;

  case 87: /* Exp: Exp LB Exp RB  */
#line 315 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2120 "./syntax.tab.c"
    break;

  case 88: /* Exp: Exp DOT ID  */
#line 318 "./syntax.y"
             {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2128 "./syntax.tab.c"
    break;

  case 89: /* Exp: ID  */
#line 321 "./syntax.y"
     {
    (yyval.node) = newNodeN("Exp","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2136 "./syntax.tab.c"
    break;

  case 90: /* Exp: INT  */
#line 324 "./syntax.y"
      {
    (yyval.node) = newNodeN("Exp","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2144 "./syntax.tab.c"
    break;

  case 91: /* Exp: FLOAT  */
#line 327 "./syntax.y"
        {
    (yyval.node) = newNodeN("Exp","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2152 "./syntax.tab.c"
    break;

  case 92: /* Exp: LP error RP  */
#line 330 "./syntax.y"
              {

}
#line 2160 "./syntax.tab.c"
    break;

  case 93: /* Exp: ID LP error RP  */
#line 333 "./syntax.y"
                 {

}
#line 2168 "./syntax.tab.c"
    break;

  case 94: /* Exp: Exp LB error RB  */
#line 336 "./syntax.y"
                  {

}
#line 2176 "./syntax.tab.c"
    break;

  case 95: /* Exp: Exp ASSIGNOP error  */
#line 339 "./syntax.y"
                    {

}
#line 2184 "./syntax.tab.c"
    break;

  case 96: /* Exp: Exp AND error  */
#line 342 "./syntax.y"
               {

}
#line 2192 "./syntax.tab.c"
    break;

  case 97: /* Exp: Exp OR error  */
#line 345 "./syntax.y"
              {

}
#line 2200 "./syntax.tab.c"
    break;

  case 98: /* Exp: Exp RELOP error  */
#line 348 "./syntax.y"
                 {

}
#line 2208 "./syntax.tab.c"
    break;

  case 99: /* Exp: Exp PLUS error  */
#line 351 "./syntax.y"
                {

}
#line 2216 "./syntax.tab.c"
    break;

  case 100: /* Exp: Exp MINUS error  */
#line 354 "./syntax.y"
                 {

}
#line 2224 "./syntax.tab.c"
    break;

  case 101: /* Exp: Exp STAR error  */
#line 357 "./syntax.y"
                {

}
#line 2232 "./syntax.tab.c"
    break;

  case 102: /* Exp: Exp DIV error  */
#line 360 "./syntax.y"
               {

}
#line 2240 "./syntax.tab.c"
    break;

  case 103: /* Exp: MINUS error  */
#line 363 "./syntax.y"
             {

}
#line 2248 "./syntax.tab.c"
    break;

  case 104: /* Exp: NOT error  */
#line 366 "./syntax.y"
           {
    
}
#line 2256 "./syntax.tab.c"
    break;

  case 105: /* Args: Exp COMMA Args  */
#line 371 "./syntax.y"
                      {
    (yyval.node) = newNodeN("Args","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2264 "./syntax.tab.c"
    break;

  case 106: /* Args: Exp  */
#line 374 "./syntax.y"
      {
    (yyval.node) = newNodeN("Args","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2272 "./syntax.tab.c"
    break;


#line 2276 "./syntax.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 378 "./syntax.y"



void yyerror(const char *msg) {
    if (yylineno != last_error_line) {
        last_error_line = yylineno;
        lab1_sign = 0;
        fprintf(stderr, "Error type B at Line %d: %s\n", yylineno, msg);
    }
}
