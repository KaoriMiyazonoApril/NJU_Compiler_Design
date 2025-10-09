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
#define YYLAST   709

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

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
       0,    48,    48,    51,    56,    59,    62,    65,    67,    70,
      73,    76,    79,    82,    86,    89,    93,    96,   100,   103,
     107,   110,   112,   116,   119,   122,   125,   129,   132,   135,
     138,   142,   145,   149,   153,   156,   159,   162,   166,   169,
     170,   174,   177,   180,   183,   186,   189,   192,   195,   198,
     201,   204,   207,   211,   214,   215,   219,   223,   226,   229,
     234,   237,   241,   244,   247,   250,   253,   256,   259,   262,
     265,   268,   271,   274,   277,   280,   283,   286,   289,   292,
     295,   298,   301,   304,   307,   311,   314
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

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,    20,    10,   -71,    56,   -71,    24,   124,   -71,    20,
      24,   -71,    44,    47,   -71,   -71,   -71,    46,    59,   -71,
      95,    87,    54,   -71,   -71,    49,   -71,   -71,    69,   -71,
      62,     5,    79,    57,   -71,    86,    94,    83,    86,    98,
     -71,    62,   108,   106,   -71,   -71,   -71,   107,   110,   -71,
     115,   196,   -71,   129,    76,   136,   139,   -71,   -71,   -71,
     131,   -71,   -19,   -71,   -71,   -71,   144,   -71,   -71,   145,
     640,   640,   645,   663,   147,   150,   -71,   154,   222,   521,
      94,   640,   -71,    94,   -71,   170,   -71,    30,   -71,   605,
     -71,   297,   313,   172,   537,   183,   553,   668,   686,   -71,
     -71,   640,   -71,   640,   640,   640,   640,   640,   640,   640,
     640,   189,   691,   -71,   489,   -71,   185,   -71,   505,   186,
     -71,   -71,   -71,   -71,   187,   569,   190,   585,   329,   345,
     457,   361,   377,   393,   409,   425,   441,   -71,   181,   473,
     -71,   640,   -71,   248,   274,   248,   248,   -71,   -71,   -71,
      41,   188,   619,   193,   -71,   -71,   248,   248,   -71,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    21,    16,     0,     3,     0,     0,    17,     0,
       0,     2,    22,     0,    19,     1,     6,    25,    23,    12,
       0,    14,     0,     5,     4,     0,     9,    29,     0,    11,
       0,     0,    10,     0,    13,     0,     0,     0,     0,     0,
      28,     0,     0,    32,    25,    23,    15,     0,     0,    35,
       0,     0,    55,    25,    60,     0,    57,    18,    53,    30,
      33,    27,     0,    26,    24,    36,     0,    78,    79,    77,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,    56,     0,    31,     0,    47,    35,    40,     0,
      80,     0,     0,    80,     0,    80,     0,     0,     0,    34,
      38,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,    58,    80,    74,     0,     0,
      82,    70,    48,    43,    80,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    80,     0,
      83,     0,    73,     0,     0,     0,     0,    84,    75,    85,
      80,    49,    50,    44,    52,    46,     0,     0,    51,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   202,   -71,   180,   -21,   -71,   -71,   -71,     2,
     -71,   155,   -71,   194,   -33,   -22,    67,   -71,   -67,   -71,
     -70,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    20,     7,     8,    13,    14,    54,
      22,    42,    43,    76,    88,    78,    52,    38,    55,    56,
      79,   119
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    92,    94,    96,    36,     2,    47,    41,    48,    21,
       3,   114,    36,   113,    36,    12,   115,    36,    77,   118,
      -7,     9,    -7,     1,    -7,     9,    10,   125,   127,    36,
     -37,   128,    21,   129,   130,   131,   132,   133,   134,   135,
     136,    41,   139,    60,     2,   100,     2,    86,     2,     3,
      35,     3,    26,     3,   -37,    32,    15,   -37,    50,   -37,
     -54,   -54,   -54,    44,    49,    27,   -20,    45,   -54,    25,
      39,   118,   -54,     2,   -54,   -54,    33,    28,     3,   -54,
     -54,     2,   -54,   -54,    81,   -54,     3,    35,    40,   -54,
     -54,   -54,    37,     2,    30,    53,    31,   -54,     3,    45,
      51,    29,    49,   -54,   -54,    58,    57,    31,   -54,   -54,
       2,   -54,   -54,    62,   -54,     3,    35,    59,   -54,   -54,
     -54,   151,   153,   154,   155,    17,   -54,    61,    63,    18,
      19,    64,   -54,   -54,   158,   159,    80,   -54,    65,     2,
     -54,   -54,    82,   -54,     3,    85,    83,    67,    68,    69,
      86,    31,   -80,   -80,   -80,    70,   -80,   -80,   -80,   -80,
     -80,    71,    72,    89,   -80,    97,    33,    87,    98,    73,
      74,    85,    75,    67,    68,    69,    86,    99,   -80,   -80,
     -80,    70,   -80,   -80,   -80,   -80,   -80,    71,    72,   122,
     -80,   120,    33,    49,   137,    73,    74,    66,    75,    67,
      68,    69,   147,    11,   140,   142,   143,    70,    16,   145,
      46,    23,    24,    71,    72,   156,    34,    84,    33,   -39,
     157,    73,    74,    85,    75,    67,    68,    69,     0,   149,
       0,     0,     0,    70,     0,     0,     0,     0,     0,    71,
      72,     0,     0,     0,    33,   -39,     0,    73,    74,   150,
      75,    67,    68,    69,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,    71,    72,     0,     0,     0,
      33,     0,     0,    73,    74,   152,    75,    67,    68,    69,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
       0,    71,    72,     0,     0,     0,    33,     0,   101,    73,
      74,     0,    75,   -71,   -71,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   101,     0,   -71,   112,   -71,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   111,
     101,     0,   -72,   112,   -72,   -81,   -81,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   101,     0,   -81,   112,
     -81,   -62,   -62,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   101,     0,   -62,   112,   -62,   -66,   -66,   -66,
     -66,   -66,   -66,   107,   108,   -66,   -66,   111,   101,     0,
     -66,   112,   -66,   -67,   -67,   -67,   -67,   -67,   -67,   107,
     108,   -67,   -67,   111,   101,     0,   -67,   112,   -67,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   111,
     101,     0,   -68,   112,   -68,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   111,   101,     0,   -69,   112,
     -69,   -63,   -63,   -63,   104,   105,   106,   107,   108,   -63,
     -63,   111,   101,     0,   -63,   112,   -63,   -64,   -64,   -64,
     104,   105,   106,   107,   108,   109,   -64,   111,   101,     0,
     -64,   112,   -64,   -65,   -65,   -65,     0,   105,   106,   107,
     108,   -65,   -65,   111,   101,     0,   -65,   112,   -65,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     101,     0,     0,   112,   148,   -61,   -61,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   101,     0,     0,   112,
       0,     0,   141,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   101,     0,   -86,   112,     0,   102,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   101,     0,
       0,   112,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   101,     0,   121,   112,     0,   123,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     101,     0,     0,   112,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   101,     0,   144,   112,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,   146,   112,   116,     0,    67,    68,
      69,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,     0,    71,    72,   117,    86,     0,   -80,   -80,   -80,
       0,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,   -80,
       0,    90,    49,    67,    68,    69,    93,     0,    67,    68,
      69,    70,     0,     0,     0,     0,    70,    71,    72,     0,
       0,     0,    71,    72,    95,     0,    67,    68,    69,   124,
       0,    67,    68,    69,    70,     0,     0,     0,     0,    70,
      71,    72,     0,     0,     0,    71,    72,   126,     0,    67,
      68,    69,   138,     0,    67,    68,    69,    70,     0,     0,
       0,     0,    70,    71,    72,     0,     0,     0,    71,    72
};

static const yytype_int16 yycheck[] =
{
      70,    71,    72,    73,    25,    24,     1,    28,     3,     7,
      29,    81,    33,    80,    35,     5,    83,    38,    51,    89,
       0,     1,     0,     1,     0,     1,     6,    97,    98,    50,
       0,   101,    30,   103,   104,   105,   106,   107,   108,   109,
     110,    62,   112,    41,    24,    78,    24,     6,    24,    29,
       1,    29,     6,    29,    24,     1,     0,    27,     1,    29,
       3,     4,     5,     1,    23,    19,    22,     5,    11,    22,
       1,   141,    23,    24,    17,    18,    22,    18,    29,    22,
      23,    24,    25,    26,     8,    28,    29,     1,    19,     3,
       4,     5,    25,    24,     7,     1,    20,    11,    29,     5,
      33,     6,    23,    17,    18,    38,    23,    20,    22,    23,
      24,    25,    26,     7,    28,    29,     1,    19,     3,     4,
       5,   143,   144,   145,   146,     1,    11,    19,    21,     5,
       6,    21,    17,    18,   156,   157,     7,    22,    23,    24,
      25,    26,     6,    28,    29,     1,     7,     3,     4,     5,
       6,    20,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    18,    20,    18,    22,    23,    18,    25,
      26,     1,    28,     3,     4,     5,     6,    23,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     6,
      20,    19,    22,    23,     5,    25,    26,     1,    28,     3,
       4,     5,    21,     1,    19,    19,    19,    11,     6,    19,
      30,     9,    10,    17,    18,    27,    22,    62,    22,    23,
      27,    25,    26,     1,    28,     3,     4,     5,    -1,   141,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    23,    -1,    25,    26,     1,
      28,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    26,     1,    28,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,     1,    25,
      26,    -1,    28,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     1,    -1,    19,    20,    21,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,    -1,    19,    20,    21,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     1,    -1,    19,    20,
      21,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     1,    -1,    19,    20,    21,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     1,    -1,
      19,    20,    21,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     1,    -1,    19,    20,    21,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,    -1,    19,    20,    21,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     1,    -1,    19,    20,
      21,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     1,    -1,    19,    20,    21,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     1,    -1,
      19,    20,    21,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,     1,    -1,    19,    20,    21,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,    -1,    -1,    20,    21,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     1,    -1,    -1,    20,
      -1,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     1,    -1,    19,    20,    -1,     6,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     1,    -1,
      -1,    20,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     1,    -1,    19,    20,    -1,     6,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,    -1,    -1,    20,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     1,    -1,    19,    20,
      -1,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,     1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,     6,    -1,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,     1,    23,     3,     4,     5,     1,    -1,     3,     4,
       5,    11,    -1,    -1,    -1,    -1,    11,    17,    18,    -1,
      -1,    -1,    17,    18,     1,    -1,     3,     4,     5,     1,
      -1,     3,     4,     5,    11,    -1,    -1,    -1,    -1,    11,
      17,    18,    -1,    -1,    -1,    17,    18,     1,    -1,     3,
       4,     5,     1,    -1,     3,     4,     5,    11,    -1,    -1,
      -1,    -1,    11,    17,    18,    -1,    -1,    -1,    17,    18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    24,    29,    33,    34,    35,    37,    38,     1,
       6,    34,     5,    39,    40,     0,    34,     1,     5,     6,
      36,    41,    42,    34,    34,    22,     6,    19,    18,     6,
       7,    20,     1,    22,    45,     1,    37,    48,    49,     1,
      19,    37,    43,    44,     1,     5,    36,     1,     3,    23,
       1,    48,    48,     1,    41,    50,    51,    23,    48,    19,
      41,    19,     7,    21,    21,    23,     1,     3,     4,     5,
      11,    17,    18,    25,    26,    28,    45,    46,    47,    52,
       7,     8,     6,     7,    43,     1,     6,    23,    46,    18,
       1,    52,    52,     1,    52,     1,    52,    18,    18,    23,
      46,     1,     6,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    20,    50,    52,    50,     1,    19,    52,    53,
      19,    19,     6,     6,     1,    52,     1,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,     5,     1,    52,
      19,     7,    19,    19,    19,    19,    19,    21,    21,    53,
       1,    47,     1,    47,    47,    47,    27,    27,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    35,    35,
      35,    35,    35,    35,    36,    36,    37,    37,    38,    38,
      39,    39,    40,    41,    41,    41,    41,    42,    42,    42,
      42,    43,    43,    44,    45,    45,    45,    45,    46,    46,
      46,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    49,    50,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     0,     2,     3,
       3,     3,     2,     3,     1,     3,     1,     1,     5,     2,
       1,     0,     1,     1,     4,     1,     4,     4,     3,     2,
       4,     3,     1,     2,     4,     2,     3,     4,     2,     0,
       2,     2,     1,     3,     5,     7,     5,     2,     3,     5,
       5,     7,     5,     2,     0,     2,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     3,     4,     3,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     1
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
  case 2: /* Program: error ExtDefList  */
#line 48 "./syntax.y"
                           {

}
#line 1446 "./syntax.tab.c"
    break;

  case 3: /* Program: ExtDefList  */
#line 51 "./syntax.y"
             {
    (yyval.node) = newNodeN("Program","", (yyvsp[0].node) ? (yyvsp[0].node)->lineNo : (yyloc).first_line, 1, (yyvsp[0].node));
    root = (yyval.node);
}
#line 1455 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: error SEMI ExtDefList  */
#line 56 "./syntax.y"
                                   {

}
#line 1463 "./syntax.tab.c"
    break;

  case 5: /* ExtDefList: error ExtDefList  */
#line 59 "./syntax.y"
                   {

}
#line 1471 "./syntax.tab.c"
    break;

  case 6: /* ExtDefList: ExtDef ExtDefList  */
#line 62 "./syntax.y"
                    {
    (yyval.node) = newNodeN("ExtDefList","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1479 "./syntax.tab.c"
    break;

  case 7: /* ExtDefList: %empty  */
#line 65 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1485 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: error SEMI  */
#line 67 "./syntax.y"
                    {

}
#line 1493 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier error SEMI  */
#line 70 "./syntax.y"
                       {

}
#line 1501 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: Specifier FunDec error  */
#line 73 "./syntax.y"
                         {

}
#line 1509 "./syntax.tab.c"
    break;

  case 11: /* ExtDef: Specifier ExtDecList SEMI  */
#line 76 "./syntax.y"
                            {
    (yyval.node) = newNodeN("ExtDef","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1517 "./syntax.tab.c"
    break;

  case 12: /* ExtDef: Specifier SEMI  */
#line 79 "./syntax.y"
                 {
    (yyval.node) = newNodeN("ExtDef","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1525 "./syntax.tab.c"
    break;

  case 13: /* ExtDef: Specifier FunDec CompSt  */
#line 82 "./syntax.y"
                          {
    (yyval.node) = newNodeN("ExtDef","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1533 "./syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec  */
#line 86 "./syntax.y"
                    {
    (yyval.node) = newNodeN("ExtDecList","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1541 "./syntax.tab.c"
    break;

  case 15: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 89 "./syntax.y"
                          {
    (yyval.node) = newNodeN("ExtDecList","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1549 "./syntax.tab.c"
    break;

  case 16: /* Specifier: TYPE  */
#line 93 "./syntax.y"
                 {
    (yyval.node) = newNodeN("Specifier","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1557 "./syntax.tab.c"
    break;

  case 17: /* Specifier: StructSpecifier  */
#line 96 "./syntax.y"
                  {
    (yyval.node) = newNodeN("Specifier","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1565 "./syntax.tab.c"
    break;

  case 18: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 100 "./syntax.y"
                                              {
    (yyval.node) = newNodeN("StructSpecifier","", (yyvsp[-4].node)->lineNo, 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1573 "./syntax.tab.c"
    break;

  case 19: /* StructSpecifier: STRUCT Tag  */
#line 103 "./syntax.y"
             {
    (yyval.node) = newNodeN("StructSpecifier","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1581 "./syntax.tab.c"
    break;

  case 20: /* OptTag: ID  */
#line 107 "./syntax.y"
            {
    (yyval.node) = newNodeN("OptTag","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1589 "./syntax.tab.c"
    break;

  case 21: /* OptTag: %empty  */
#line 110 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1595 "./syntax.tab.c"
    break;

  case 22: /* Tag: ID  */
#line 112 "./syntax.y"
         {
    (yyval.node) = newNodeN("Tag","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1603 "./syntax.tab.c"
    break;

  case 23: /* VarDec: ID  */
#line 116 "./syntax.y"
            {
    (yyval.node) = newNodeN("VarDec","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1611 "./syntax.tab.c"
    break;

  case 24: /* VarDec: VarDec LB INT RB  */
#line 119 "./syntax.y"
                   {
    (yyval.node) = newNodeN("VarDec","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1619 "./syntax.tab.c"
    break;

  case 25: /* VarDec: error  */
#line 122 "./syntax.y"
        {

}
#line 1627 "./syntax.tab.c"
    break;

  case 26: /* VarDec: VarDec LB error RB  */
#line 125 "./syntax.y"
                     {

}
#line 1635 "./syntax.tab.c"
    break;

  case 27: /* FunDec: ID LP VarList RP  */
#line 129 "./syntax.y"
                          {
    (yyval.node) = newNodeN("FunDec","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1643 "./syntax.tab.c"
    break;

  case 28: /* FunDec: ID LP RP  */
#line 132 "./syntax.y"
           {
    (yyval.node) = newNodeN("FunDec","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1651 "./syntax.tab.c"
    break;

  case 29: /* FunDec: error RP  */
#line 135 "./syntax.y"
           {

}
#line 1659 "./syntax.tab.c"
    break;

  case 30: /* FunDec: ID LP error RP  */
#line 138 "./syntax.y"
                 {

}
#line 1667 "./syntax.tab.c"
    break;

  case 31: /* VarList: ParamDec COMMA VarList  */
#line 142 "./syntax.y"
                                 {
    (yyval.node) = newNodeN("VarList","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1675 "./syntax.tab.c"
    break;

  case 32: /* VarList: ParamDec  */
#line 145 "./syntax.y"
           {
    (yyval.node) = newNodeN("VarList","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1683 "./syntax.tab.c"
    break;

  case 33: /* ParamDec: Specifier VarDec  */
#line 149 "./syntax.y"
                            {
    (yyval.node) = newNodeN("ParamDec","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1691 "./syntax.tab.c"
    break;

  case 34: /* CompSt: LC DefList StmtList RC  */
#line 153 "./syntax.y"
                                {
    (yyval.node) = newNodeN("CompSt","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1699 "./syntax.tab.c"
    break;

  case 35: /* CompSt: error RC  */
#line 156 "./syntax.y"
           {

}
#line 1707 "./syntax.tab.c"
    break;

  case 36: /* CompSt: LC error RC  */
#line 159 "./syntax.y"
              {

}
#line 1715 "./syntax.tab.c"
    break;

  case 37: /* CompSt: LC DefList error RC  */
#line 162 "./syntax.y"
                      {

}
#line 1723 "./syntax.tab.c"
    break;

  case 38: /* StmtList: Stmt StmtList  */
#line 166 "./syntax.y"
                         {
    (yyval.node) = newNodeN("StmtList","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1731 "./syntax.tab.c"
    break;

  case 39: /* StmtList: %empty  */
#line 169 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1737 "./syntax.tab.c"
    break;

  case 40: /* StmtList: error StmtList  */
#line 170 "./syntax.y"
                 {

}
#line 1745 "./syntax.tab.c"
    break;

  case 41: /* Stmt: Exp SEMI  */
#line 174 "./syntax.y"
                {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1753 "./syntax.tab.c"
    break;

  case 42: /* Stmt: CompSt  */
#line 177 "./syntax.y"
         {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1761 "./syntax.tab.c"
    break;

  case 43: /* Stmt: RETURN Exp SEMI  */
#line 180 "./syntax.y"
                  {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1769 "./syntax.tab.c"
    break;

  case 44: /* Stmt: IF LP Exp RP Stmt  */
#line 183 "./syntax.y"
                                          {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-4].node)->lineNo, 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1777 "./syntax.tab.c"
    break;

  case 45: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 186 "./syntax.y"
                              {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-6].node)->lineNo, 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1785 "./syntax.tab.c"
    break;

  case 46: /* Stmt: WHILE LP Exp RP Stmt  */
#line 189 "./syntax.y"
                       {
    (yyval.node) = newNodeN("Stmt","", (yyvsp[-4].node)->lineNo, 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1793 "./syntax.tab.c"
    break;

  case 47: /* Stmt: error SEMI  */
#line 192 "./syntax.y"
             {

}
#line 1801 "./syntax.tab.c"
    break;

  case 48: /* Stmt: RETURN error SEMI  */
#line 195 "./syntax.y"
                    {

}
#line 1809 "./syntax.tab.c"
    break;

  case 49: /* Stmt: IF LP error RP Stmt  */
#line 198 "./syntax.y"
                                            {

}
#line 1817 "./syntax.tab.c"
    break;

  case 50: /* Stmt: IF LP Exp RP error  */
#line 201 "./syntax.y"
                                           {

}
#line 1825 "./syntax.tab.c"
    break;

  case 51: /* Stmt: IF LP error RP Stmt ELSE Stmt  */
#line 204 "./syntax.y"
                                {

}
#line 1833 "./syntax.tab.c"
    break;

  case 52: /* Stmt: WHILE LP error RP Stmt  */
#line 207 "./syntax.y"
                         {

}
#line 1841 "./syntax.tab.c"
    break;

  case 53: /* DefList: Def DefList  */
#line 211 "./syntax.y"
                      {
    (yyval.node) = newNodeN("DefList","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1849 "./syntax.tab.c"
    break;

  case 54: /* DefList: %empty  */
#line 214 "./syntax.y"
            { (yyval.node) = NULL; }
#line 1855 "./syntax.tab.c"
    break;

  case 55: /* DefList: error DefList  */
#line 215 "./syntax.y"
                {

}
#line 1863 "./syntax.tab.c"
    break;

  case 56: /* Def: Specifier DecList SEMI  */
#line 219 "./syntax.y"
                             {
    (yyval.node) = newNodeN("Def","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1871 "./syntax.tab.c"
    break;

  case 57: /* DecList: Dec  */
#line 223 "./syntax.y"
              {
    (yyval.node) = newNodeN("DecList","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1879 "./syntax.tab.c"
    break;

  case 58: /* DecList: Dec COMMA DecList  */
#line 226 "./syntax.y"
                    {
    (yyval.node) = newNodeN("DecList","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1887 "./syntax.tab.c"
    break;

  case 59: /* DecList: error COMMA DecList  */
#line 229 "./syntax.y"
                      {
    Node* error_node = newNodeN("Error","", (yyloc).first_line, 0);
    (yyval.node) = newNodeN("DecList","", (yyloc).first_line, 3, error_node, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1896 "./syntax.tab.c"
    break;

  case 60: /* Dec: VarDec  */
#line 234 "./syntax.y"
             {
    (yyval.node) = newNodeN("Dec","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 1904 "./syntax.tab.c"
    break;

  case 61: /* Dec: VarDec ASSIGNOP Exp  */
#line 237 "./syntax.y"
                      {
    (yyval.node) = newNodeN("Dec","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1912 "./syntax.tab.c"
    break;

  case 62: /* Exp: Exp ASSIGNOP Exp  */
#line 241 "./syntax.y"
                       {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1920 "./syntax.tab.c"
    break;

  case 63: /* Exp: Exp AND Exp  */
#line 244 "./syntax.y"
              {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1928 "./syntax.tab.c"
    break;

  case 64: /* Exp: Exp OR Exp  */
#line 247 "./syntax.y"
             {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1936 "./syntax.tab.c"
    break;

  case 65: /* Exp: Exp RELOP Exp  */
#line 250 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1944 "./syntax.tab.c"
    break;

  case 66: /* Exp: Exp PLUS Exp  */
#line 253 "./syntax.y"
               {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1952 "./syntax.tab.c"
    break;

  case 67: /* Exp: Exp MINUS Exp  */
#line 256 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1960 "./syntax.tab.c"
    break;

  case 68: /* Exp: Exp STAR Exp  */
#line 259 "./syntax.y"
               {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1968 "./syntax.tab.c"
    break;

  case 69: /* Exp: Exp DIV Exp  */
#line 262 "./syntax.y"
              {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1976 "./syntax.tab.c"
    break;

  case 70: /* Exp: LP Exp RP  */
#line 265 "./syntax.y"
            {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-1].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1984 "./syntax.tab.c"
    break;

  case 71: /* Exp: MINUS Exp  */
#line 268 "./syntax.y"
                         {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 1992 "./syntax.tab.c"
    break;

  case 72: /* Exp: NOT Exp  */
#line 271 "./syntax.y"
          {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-1].node)->lineNo, 2, (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2000 "./syntax.tab.c"
    break;

  case 73: /* Exp: ID LP Args RP  */
#line 274 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2008 "./syntax.tab.c"
    break;

  case 74: /* Exp: ID LP RP  */
#line 277 "./syntax.y"
           {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2016 "./syntax.tab.c"
    break;

  case 75: /* Exp: Exp LB Exp RB  */
#line 280 "./syntax.y"
                {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-3].node)->lineNo, 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2024 "./syntax.tab.c"
    break;

  case 76: /* Exp: Exp DOT ID  */
#line 283 "./syntax.y"
             {
    (yyval.node) = newNodeN("Exp","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2032 "./syntax.tab.c"
    break;

  case 77: /* Exp: ID  */
#line 286 "./syntax.y"
     {
    (yyval.node) = newNodeN("Exp","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2040 "./syntax.tab.c"
    break;

  case 78: /* Exp: INT  */
#line 289 "./syntax.y"
      {
    (yyval.node) = newNodeN("Exp","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2048 "./syntax.tab.c"
    break;

  case 79: /* Exp: FLOAT  */
#line 292 "./syntax.y"
        {
    (yyval.node) = newNodeN("Exp","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2056 "./syntax.tab.c"
    break;

  case 80: /* Exp: error  */
#line 295 "./syntax.y"
        {

}
#line 2064 "./syntax.tab.c"
    break;

  case 81: /* Exp: Exp error Exp  */
#line 298 "./syntax.y"
                {

}
#line 2072 "./syntax.tab.c"
    break;

  case 82: /* Exp: LP error RP  */
#line 301 "./syntax.y"
              {

}
#line 2080 "./syntax.tab.c"
    break;

  case 83: /* Exp: ID LP error RP  */
#line 304 "./syntax.y"
                 {

}
#line 2088 "./syntax.tab.c"
    break;

  case 84: /* Exp: Exp LB error RB  */
#line 307 "./syntax.y"
                  {

}
#line 2096 "./syntax.tab.c"
    break;

  case 85: /* Args: Exp COMMA Args  */
#line 311 "./syntax.y"
                      {
    (yyval.node) = newNodeN("Args","", (yyvsp[-2].node)->lineNo, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2104 "./syntax.tab.c"
    break;

  case 86: /* Args: Exp  */
#line 314 "./syntax.y"
      {
    (yyval.node) = newNodeN("Args","", (yyvsp[0].node)->lineNo, 1, (yyvsp[0].node));
}
#line 2112 "./syntax.tab.c"
    break;


#line 2116 "./syntax.tab.c"

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

#line 317 "./syntax.y"



void yyerror(const char *msg) {
    if (yylineno != last_error_line) {
        last_error_line = yylineno;
        lab1_sign = 0;
        fprintf(stderr, "Error type B at Line %d: %s\n", yylineno, msg);
    }
}
