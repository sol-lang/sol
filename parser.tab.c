/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "sol.h"
#include "ast.h"

#include <string.h>

#define YYSTYPE void *


#line 76 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    THEN = 259,
    ELSE = 260,
    WHILE = 261,
    FOR = 262,
    IN = 263,
    DO = 264,
    FUNC = 265,
    RETURN = 266,
    BREAK = 267,
    CONTINUE = 268,
    END = 269,
    NONE = 270,
    IDENT = 271,
    INT = 272,
    FLOAT = 273,
    STRING = 274,
    PLUS = 275,
    MINUS = 276,
    STAR = 277,
    SLASH = 278,
    DSTAR = 279,
    BAND = 280,
    BOR = 281,
    BXOR = 282,
    BNOT = 283,
    LAND = 284,
    LOR = 285,
    LNOT = 286,
    ASSIGN = 287,
    ASSIGNPLUS = 288,
    ASSIGNMINUS = 289,
    ASSIGNSTAR = 290,
    ASSIGNSLASH = 291,
    ASSIGNDSTAR = 292,
    ASSIGNBAND = 293,
    ASSIGNBOR = 294,
    ASSIGNBXOR = 295,
    EQUAL = 296,
    LESS = 297,
    GREATER = 298,
    LESSEQ = 299,
    GREATEREQ = 300,
    RSHIFT = 301,
    LSHIFT = 302,
    LBRACE = 303,
    RBRACE = 304,
    LPAREN = 305,
    RPAREN = 306,
    LBRACKET = 307,
    RBRACKET = 308,
    DOT = 309,
    COLON = 310,
    SEMICOLON = 311,
    COMMA = 312,
    POUND = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (stmt_node **program);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   650

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    35,    46,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    69,    70,    77,    84,    91,
      98,   105,   112,   119,   126,   139,   152,   165,   178,   191,
     204,   217,   230,   243,   247,   248,   249,   253,   254,   258,
     259,   260,   261,   262,   263,   267,   268,   269,   273,   274,
     275,   279,   280,   284,   285,   286,   287,   288,   289,   293,
     294,   298,   299,   303,   304,   321,   325,   333,   341,   345,
     346,   357,   361,   362,   376,   377,   381,   382,   383,   384,
     385,   386,   390,   391,   392,   396,   400,   401,   406,   407,
     419,   420,   425,   426,   438,   439,   444,   445,   457,   462
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "WHILE", "FOR",
  "IN", "DO", "FUNC", "RETURN", "BREAK", "CONTINUE", "END", "NONE",
  "IDENT", "INT", "FLOAT", "STRING", "PLUS", "MINUS", "STAR", "SLASH",
  "DSTAR", "BAND", "BOR", "BXOR", "BNOT", "LAND", "LOR", "LNOT", "ASSIGN",
  "ASSIGNPLUS", "ASSIGNMINUS", "ASSIGNSTAR", "ASSIGNSLASH", "ASSIGNDSTAR",
  "ASSIGNBAND", "ASSIGNBOR", "ASSIGNBXOR", "EQUAL", "LESS", "GREATER",
  "LESSEQ", "GREATEREQ", "RSHIFT", "LSHIFT", "LBRACE", "RBRACE", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "DOT", "COLON", "SEMICOLON", "COMMA",
  "POUND", "$accept", "program", "stmt_list", "stmt", "expr", "logic_expr",
  "ulogic_expr", "rel_expr", "term_expr", "factor_expr", "power_expr",
  "binary_expr", "ubinary_expr", "ulen_expr", "call_expr", "funcdecl_expr",
  "index_expr", "ex_index_expr", "ref_expr", "lit_expr", "gen_expr",
  "paren_expr", "expr_list", "ident_list", "assoc_list", "assoc_item", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -97

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -97,    15,   318,   -97,   417,   417,    20,    21,   417,   -97,
     -97,   -97,   272,   -97,   -97,   -97,    23,   417,   417,    -8,
     417,   417,   417,    32,    26,    -7,   -97,   190,    65,    76,
      77,   192,   -97,   -97,   -41,   -97,   -97,   419,   -97,   -97,
     -97,   -97,     3,     4,    75,    53,    89,    26,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   -97,    26,   456,
      52,    97,   417,    27,   -97,   -13,    26,   341,   491,   -97,
     417,    91,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
      93,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     -97,   -97,   417,    89,   -97,    18,    26,    26,    26,    26,
      26,    26,    26,    26,    26,   417,   -42,   -97,   -97,   -97,
     -97,   -97,   -97,    26,    96,   455,    81,    81,   102,   102,
     102,   102,   102,   596,   596,   566,   566,   561,   526,   526,
     526,   526,   526,   364,    84,    26,    26,    26,    26,    26,
      26,    26,    26,    26,   109,    14,     7,    51,   -97,   -97,
     -97,    26,   104,   490,   -97,   417,   -97,   -97,   -97,   -97,
     -97,   172,   417,   392,   195,   245,   268,   -97,    26,   -97,
     -97,   -97,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,    11,    12,
      13,    80,    74,    76,    78,    79,     0,     0,     0,    94,
       0,    86,     0,     3,     5,    33,    36,    38,    44,    47,
      50,    52,    58,    60,    62,    65,    68,     0,    71,    75,
      81,    84,     0,     0,     0,     0,    90,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,    59,
      37,     0,     0,     0,    95,     0,    87,     0,    61,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     4,     0,    90,    91,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,    83,    96,    97,
      85,    82,    88,    89,     0,    70,    34,    35,    39,    40,
      41,    42,    43,    45,    46,    48,    49,    51,    53,    54,
      55,    57,    56,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,     0,     0,     0,    93,     4,
      92,    99,     0,    69,    63,    86,     4,     6,     8,     4,
       4,     0,     0,     0,     0,     0,     0,    67,    98,    64,
       7,     9,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   -96,   -97,    -2,    45,   124,   266,    59,    83,
      68,   376,   138,   136,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -88,    57,   -97,    99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    23,    58,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    67,   105,    63,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   143,    42,    43,   154,   155,    47,   100,    61,    89,
      70,   162,    71,   101,    90,     3,   169,     4,    65,    66,
       5,     6,    72,    73,     7,     8,     9,    10,   168,    11,
      12,    13,    14,    15,   158,    16,    44,    45,   120,    70,
      57,    71,    17,    61,    62,    18,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    70,    70,    71,    71,    70,
     116,    71,    19,   171,    20,   123,    21,   158,   124,   159,
     174,    46,    22,   175,   176,   160,   117,   173,    70,    62,
      71,   -36,   -36,   102,   118,    79,    80,    66,    69,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    81,    82,
     156,    83,   170,   103,   -36,   104,   -36,   125,   160,   144,
      72,    73,     4,   161,   166,     5,     6,   126,   127,     7,
       8,     9,    10,   167,    11,    12,    13,    14,    15,   115,
      16,   -38,   -38,   -33,   165,   -33,   172,    17,   133,   134,
      18,   123,    60,    74,    75,    76,    77,    78,    70,   163,
      71,   137,    24,    24,   -38,    59,   -38,    19,    68,    20,
     157,    21,   119,    66,   135,   136,     0,    22,     0,    24,
     178,   123,    24,    24,    24,     4,     0,     0,     5,     6,
       0,     0,     7,     8,     9,    10,   177,    11,    12,    13,
      14,    15,     0,    16,     0,     0,     0,     0,     4,     0,
      17,     5,     6,    18,     0,     7,     8,     9,    10,   180,
      11,    12,    13,    14,    15,     0,    16,    84,    85,    86,
      19,     0,    20,    17,    21,     0,    18,     0,     0,     0,
      22,    74,    75,    76,    77,    78,     0,     0,    87,    88,
       0,     0,     0,    19,     0,    20,     0,    21,     4,     0,
       0,     5,     6,    22,     0,     7,     8,     9,    10,   181,
      11,    12,    13,    14,    15,     0,    16,     0,     0,     0,
       0,     4,     0,    17,     5,     6,    18,     0,     7,     8,
       9,    10,   182,    11,    12,    13,    14,    15,     0,    16,
       0,     0,     0,    19,     0,    20,    17,    21,     0,    18,
       0,     0,     0,    22,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,    19,     0,    20,     0,
      21,     4,     0,     0,     5,     6,    22,     0,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    16,
     128,   129,   130,   131,   132,     0,    17,     0,     0,    18,
       0,     7,     0,     0,     0,     0,    11,    12,    13,    14,
      15,     0,    16,     0,     0,     0,    19,     0,    20,    17,
      21,     0,    18,     0,     7,     0,    22,     0,     0,    11,
      12,    13,    14,    15,     0,    16,     0,     0,     0,    19,
       0,    20,    17,    21,   121,    18,     0,     0,   122,    22,
       0,     0,     7,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    19,    16,    20,   164,    21,     0,     0,     0,
      17,   122,    22,    18,     0,     0,     0,     7,     0,     0,
       0,     0,    11,    12,    13,    14,    15,     0,    16,     0,
      19,     0,    20,   179,    21,    17,     0,     0,    18,   122,
      22,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     138,   139,   140,   141,   142,    19,     0,    20,     0,    21,
       0,     0,     0,     0,     0,    22,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,     0,   -58,   -58,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,     0,   -58,     0,
     -58,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,     0,
     -60,   -60,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     0,   -60,   -60,   -60,   -60,   -60,   -60,   -60,     0,
       0,     0,     0,   -60,     0,   -60,   -52,   -52,   -52,   -52,
     -52,    84,    85,    86,     0,   -52,   -52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -52,   -52,   -52,
     -52,   -52,    87,    88,     0,     0,     0,     0,   -52,     0,
     -52,   -50,   -50,   -50,   -50,    83,   -47,   -47,    81,    82,
     -50,   -50,     0,     0,     0,   -47,   -47,     0,     0,     0,
       0,     0,   -50,   -50,   -50,   -50,   -50,   -47,   -47,   -47,
     -47,   -47,     0,   -50,     0,   -50,    79,    80,   -47,     0,
     -47,     0,     0,     0,     0,   -44,   -44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -44,   -44,   -44,
     -44,   -44,     0,     0,     0,     0,     0,     0,   -44,     0,
     -44
};

static const yytype_int16 yycheck[] =
{
       2,    89,     4,     5,   100,   101,     8,     4,    16,    50,
      52,    53,    54,     9,    55,     0,     9,     3,    20,    21,
       6,     7,    29,    30,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    16,    21,    16,    16,    51,    52,
      17,    54,    28,    16,    52,    31,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    52,    52,    54,    54,    52,
      62,    54,    48,   159,    50,    67,    52,    16,    70,    51,
     166,    50,    58,   169,   170,    57,    49,   165,    52,    52,
      54,    29,    30,     8,    57,    20,    21,    89,    56,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    22,    23,
     102,    24,    51,    50,    52,    16,    54,    16,    57,    16,
      29,    30,     3,   115,     5,     6,     7,    72,    73,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    32,
      21,    29,    30,    52,    50,    54,    32,    28,    79,    80,
      31,   143,    18,    41,    42,    43,    44,    45,    52,    53,
      54,    83,   154,   155,    52,    17,    54,    48,    22,    50,
     103,    52,    63,   165,    81,    82,    -1,    58,    -1,   171,
     172,   173,   174,   175,   176,     3,    -1,    -1,     6,     7,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    -1,    -1,    -1,    -1,     3,    -1,
      28,     6,     7,    31,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    25,    26,    27,
      48,    -1,    50,    28,    52,    -1,    31,    -1,    -1,    -1,
      58,    41,    42,    43,    44,    45,    -1,    -1,    46,    47,
      -1,    -1,    -1,    48,    -1,    50,    -1,    52,     3,    -1,
      -1,     6,     7,    58,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,     3,    -1,    28,     6,     7,    31,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    -1,    48,    -1,    50,    28,    52,    -1,    31,
      -1,    -1,    -1,    58,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    48,    -1,    50,    -1,
      52,     3,    -1,    -1,     6,     7,    58,    -1,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    -1,    21,
      74,    75,    76,    77,    78,    -1,    28,    -1,    -1,    31,
      -1,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    -1,    48,    -1,    50,    28,
      52,    -1,    31,    -1,    10,    -1,    58,    -1,    -1,    15,
      16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    48,
      -1,    50,    28,    52,    53,    31,    -1,    -1,    57,    58,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    48,    21,    50,    51,    52,    -1,    -1,    -1,
      28,    57,    58,    31,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    -1,    21,    -1,
      48,    -1,    50,    51,    52,    28,    -1,    -1,    31,    57,
      58,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      84,    85,    86,    87,    88,    48,    -1,    50,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    58,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    -1,    54,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    20,    21,    22,    23,    24,    20,    21,    22,    23,
      29,    30,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    41,    42,    43,
      44,    45,    -1,    52,    -1,    54,    20,    21,    52,    -1,
      54,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,     3,     6,     7,    10,    11,    12,
      13,    15,    16,    17,    18,    19,    21,    28,    31,    48,
      50,    52,    58,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    63,    63,    16,    16,    50,    63,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    17,    63,    71,
      65,    16,    52,    83,    84,    63,    63,    81,    72,    56,
      52,    54,    29,    30,    41,    42,    43,    44,    45,    20,
      21,    22,    23,    24,    25,    26,    27,    46,    47,    50,
      55,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       4,     9,     8,    50,    16,    82,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    32,    63,    49,    57,    84,
      51,    53,    57,    63,    63,    16,    64,    64,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    69,    70,    70,
      70,    70,    70,    81,    16,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    61,    61,    63,    82,    16,    51,
      57,    63,    53,    53,    51,    50,     5,    14,    14,     9,
      51,    61,    32,    81,    61,    61,    61,    14,    63,    51,
      14,    14,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    79,    79,    80,    81,    81,    81,    81,
      82,    82,    82,    82,    83,    83,    83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     5,     7,     5,     7,
       2,     1,     1,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     2,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     1,     2,
       1,     2,     1,     4,     6,     1,     7,     6,     1,     4,
       3,     1,     4,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     3,     1,     3,     0,     1,     2,     2,
       0,     1,     2,     2,     0,     1,     2,     2,     5,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (program, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, program); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, stmt_node **program)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (program);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, stmt_node **program)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, program);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, stmt_node **program)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , program);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, program); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, stmt_node **program)
{
  YYUSE (yyvaluep);
  YYUSE (program);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (stmt_node **program)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 31 "parser.y" /* yacc.c:1646  */
    { *program = AS_ST((yyvsp[0])); }
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 35 "parser.y" /* yacc.c:1646  */
    {
	stmtlist_node *cur = AS_ST((yyvsp[-1]))->stmtlist;
	while(cur->next) cur = cur->next;
	if(cur->stmt) {
        cur->next = NEW(stmtlist_node);
        cur = cur->next;
	}
    cur->stmt = (yyvsp[0]);
    cur->next = NULL;
    (yyval) = (yyvsp[-1]);
  }
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 46 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEW_ST();
    AS_ST((yyval))->type = ST_LIST;
    AS_ST((yyval))->stmtlist = NEW(stmtlist_node);
    AS_ST((yyval))->stmtlist->stmt = NULL;
    AS_ST((yyval))->stmtlist->next = NULL;
}
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_EXPR; AS_ST((yyval))->expr = (yyvsp[0]); }
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[-3]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[-1]); AS_ST((yyval))->ifelse->iffalse = NULL; }
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[-5]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[-3]); AS_ST((yyval))->ifelse->iffalse = (yyvsp[-1]); }
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_LOOP; AS_ST((yyval))->loop = NEW(loop_node); AS_ST((yyval))->loop->cond = (yyvsp[-3]); AS_ST((yyval))->loop->loop = (yyvsp[-1]); }
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_ITER; AS_ST((yyval))->iter = NEW(iter_node); AS_ST((yyval))->iter->var = (yyvsp[-5]); AS_ST((yyval))->iter->iter = (yyvsp[-3]); AS_ST((yyval))->iter->loop = (yyvsp[-1]); }
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = (yyvsp[0]); }
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 62 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = NULL; }
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 63 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_BREAK; }
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_CONT; }
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 65 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 69 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_ASSIGN; AS_EX((yyval))->assign = NEW(assign_node); AS_EX((yyval))->assign->ident = (yyvsp[-2]); AS_EX((yyval))->assign->value = (yyvsp[0]); }
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_ADD, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 77 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_SUB, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_MUL, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 91 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
    MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_DIV, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_POW, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 105 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BAND, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 112 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BXOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 126 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    AS_EX((yyval))->setindex->value = (yyvsp[0]);
    //ex_free(AS_EX($1));
}
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 139 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_ADD, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_SUB, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 165 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_MUL, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 178 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_DIV, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 191 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_POW, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 204 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BAND, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 217 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BOR, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 230 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[-2]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[-2]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BXOR, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    //ex_free(AS_EX($1));
}
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1854 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1860 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_EQUAL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESS; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATER; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESSEQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATEREQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 267 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_ADD; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_SUB; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MUL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1938 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_DIV; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1944 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_POW; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1956 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1968 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BXOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1986 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_RSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_BNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LEN; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_CALL; AS_EX((yyval))->call = NEW(call_node); AS_EX((yyval))->call->expr = (yyvsp[-3]); AS_EX((yyval))->call->args = (yyvsp[-1]); }
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 304 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_CALL;
	AS_EX((yyval))->call = NEW(call_node);
	AS_EX((yyval))->call->expr = NEW_EX();
	AS_EX((yyval))->call->expr->type = EX_INDEX;
	AS_EX((yyval))->call->expr->index = NEW(index_node);
	AS_EX((yyval))->call->expr->index->expr = (yyvsp[-5]);
	AS_EX((yyval))->call->expr->index->index = NEW_EX();
	AS_EX((yyval))->call->expr->index->index->type = EX_LIT;
	AS_EX((yyval))->call->expr->index->index->lit = NEW(lit_node);
	AS_EX((yyval))->call->expr->index->index->lit->type = LIT_STRING;
	AS_EX((yyval))->call->expr->index->index->lit->str = (yyvsp[-3]);
	AS_EX((yyval))->call->args = NEW(exprlist_node);
	AS_EX((yyval))->call->args->expr = (yyvsp[-5]);
	AS_EX((yyval))->call->args->next = (yyvsp[-1]);
}
#line 2050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 325 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[-5]);
	AS_EX((yyval))->funcdecl->args = (yyvsp[-3]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2069 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 333 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->args = (yyvsp[-3]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2082 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 341 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2088 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 346 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_INDEX;
    AS_EX((yyval))->index = NEW(index_node);
    AS_EX((yyval))->index->expr = (yyvsp[-2]);
    AS_EX((yyval))->index->index = NEW_EX();
    AS_EX((yyval))->index->index->type = EX_LIT;
    AS_EX((yyval))->index->index->lit = NEW(lit_node);
    AS_EX((yyval))->index->index->lit->type = LIT_STRING;
    AS_EX((yyval))->index->index->lit->str = (yyvsp[0]);
}
#line 2110 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 357 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2116 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 361 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2122 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 362 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_INDEX;
    AS_EX((yyval))->index = NEW(index_node);
    AS_EX((yyval))->index->expr = (yyvsp[-2]);
    AS_EX((yyval))->index->index = NEW_EX();
    AS_EX((yyval))->index->index->type = EX_LIT;
    AS_EX((yyval))->index->index->lit = NEW(lit_node);
    AS_EX((yyval))->index->index->lit->type = LIT_STRING;
    AS_EX((yyval))->index->index->lit->str = (yyvsp[0]);
}
#line 2138 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 376 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_REF; AS_EX((yyval))->ref = NEW(ref_node); AS_EX((yyval))->ref->ident = (yyvsp[0]); }
#line 2144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 377 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2150 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 381 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = *AS((yyvsp[0]), long); free((yyvsp[0])); }
#line 2156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 382 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = -(*AS((yyvsp[0]), long)); free((yyvsp[0])); }
#line 2162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 383 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_FLOAT; AS_EX((yyval))->lit->fval = *AS((yyvsp[0]), double); free((yyvsp[0])); }
#line 2168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 384 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_STRING; AS_EX((yyval))->lit->str = (yyvsp[0]); }
#line 2174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 385 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_NONE; }
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 386 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 390 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LISTGEN; AS_EX((yyval))->listgen = NEW(listgen_node); AS_EX((yyval))->listgen->list = (yyvsp[-1]); }
#line 2192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 391 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_MAPGEN; AS_EX((yyval))->mapgen = NEW(mapgen_node); AS_EX((yyval))->mapgen->map = (yyvsp[-1]); }
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 392 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 396 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 400 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2216 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 401 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(exprlist_node);
	AS((yyval), exprlist_node)->expr = (yyvsp[0]);
	AS((yyval), exprlist_node)->next = NULL;
}
#line 2226 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 406 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2232 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 407 "parser.y" /* yacc.c:1646  */
    {
	exprlist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 419 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2252 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 420 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(identlist_node);
	AS((yyval), identlist_node)->ident = (yyvsp[0]);
	AS((yyval), identlist_node)->next = NULL;
}
#line 2262 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 425 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2268 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 426 "parser.y" /* yacc.c:1646  */
    {
	identlist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 438 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 439 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(assoclist_node);
	AS((yyval), assoclist_node)->item = (yyvsp[0]);
	AS((yyval), assoclist_node)->next = NULL;
}
#line 2298 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 444 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 445 "parser.y" /* yacc.c:1646  */
    {
	assoclist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 457 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = (yyvsp[-3]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2328 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 462 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = NEW_EX();
	AS((yyval), associtem_node)->key->type = EX_LIT;
	AS((yyval), associtem_node)->key->lit = NEW(lit_node);
	AS((yyval), associtem_node)->key->lit->type = LIT_STRING;
	AS((yyval), associtem_node)->key->lit->str = (yyvsp[-2]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2342 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2346 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (program, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (program, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, program);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, program);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (program, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, program);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, program);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 473 "parser.y" /* yacc.c:1906  */


// TODO
