/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

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
#define YYLTYPE loc_t

/* Hacks */
#define first_line line
#define last_line line
#define first_column col
#define last_column col

int yylex(YYSTYPE *, loc_t *);
void yyerror(loc_t *, stmt_node **, char *);


#line 86 "parser.tab.c" /* yacc.c:339  */

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
    ELSEIF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    IN = 264,
    DO = 265,
    FUNC = 266,
    MACRO = 267,
    LAMBDA = 268,
    RETURN = 269,
    BREAK = 270,
    CONTINUE = 271,
    END = 272,
    NONE = 273,
    IDENT = 274,
    INT = 275,
    FLOAT = 276,
    STRING = 277,
    PLUS = 278,
    MINUS = 279,
    STAR = 280,
    SLASH = 281,
    PERCENT = 282,
    DSTAR = 283,
    BAND = 284,
    BOR = 285,
    BXOR = 286,
    BNOT = 287,
    LAND = 288,
    LOR = 289,
    LNOT = 290,
    ASSIGN = 291,
    ASSIGNPLUS = 292,
    ASSIGNMINUS = 293,
    ASSIGNSTAR = 294,
    ASSIGNSLASH = 295,
    ASSIGNDSTAR = 296,
    ASSIGNBAND = 297,
    ASSIGNBOR = 298,
    ASSIGNBXOR = 299,
    EQUAL = 300,
    NEQUAL = 301,
    LESS = 302,
    GREATER = 303,
    LESSEQ = 304,
    GREATEREQ = 305,
    RSHIFT = 306,
    LSHIFT = 307,
    LBRACE = 308,
    RBRACE = 309,
    BLPAREN = 310,
    LPAREN = 311,
    RPAREN = 312,
    LBRACKET = 313,
    RBRACKET = 314,
    DOT = 315,
    COLON = 316,
    SEMICOLON = 317,
    COMMA = 318,
    POUND = 319,
    TBANG = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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



int yyparse (stmt_node **program);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "parser.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
#define YYLAST   844

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    52,    63,    73,    74,    75,    76,    77,
      78,    79,    80,    84,    88,    96,   103,   111,   115,   125,
     128,   132,   133,   140,   147,   154,   161,   168,   175,   182,
     189,   202,   215,   228,   241,   254,   267,   280,   293,   306,
     310,   311,   312,   316,   317,   321,   322,   323,   324,   325,
     326,   327,   331,   332,   333,   337,   338,   339,   340,   344,
     345,   349,   350,   355,   356,   357,   358,   359,   360,   364,
     365,   369,   370,   374,   375,   383,   387,   397,   407,   417,
     427,   440,   453,   457,   458,   469,   473,   474,   488,   489,
     493,   494,   495,   496,   497,   498,   502,   503,   504,   508,
     512,   513,   518,   519,   564,   565,   600,   613,   648,   652,
     653,   658,   659,   678,   683,   695,   696,   700,   701
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSEIF", "ELSE", "WHILE",
  "FOR", "IN", "DO", "FUNC", "MACRO", "LAMBDA", "RETURN", "BREAK",
  "CONTINUE", "END", "NONE", "IDENT", "INT", "FLOAT", "STRING", "PLUS",
  "MINUS", "STAR", "SLASH", "PERCENT", "DSTAR", "BAND", "BOR", "BXOR",
  "BNOT", "LAND", "LOR", "LNOT", "ASSIGN", "ASSIGNPLUS", "ASSIGNMINUS",
  "ASSIGNSTAR", "ASSIGNSLASH", "ASSIGNDSTAR", "ASSIGNBAND", "ASSIGNBOR",
  "ASSIGNBXOR", "EQUAL", "NEQUAL", "LESS", "GREATER", "LESSEQ",
  "GREATEREQ", "RSHIFT", "LSHIFT", "LBRACE", "RBRACE", "BLPAREN", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "DOT", "COLON", "SEMICOLON", "COMMA",
  "POUND", "TBANG", "$accept", "program", "stmt_list", "stmt", "expr",
  "control_expr", "if_termin", "assign_expr", "logic_expr", "ulogic_expr",
  "rel_expr", "term_expr", "factor_expr", "power_expr", "tbang_expr",
  "binary_expr", "ubinary_expr", "ulen_expr", "call_expr", "funcdecl_expr",
  "index_expr", "ex_index_expr", "ref_expr", "lit_expr", "gen_expr",
  "paren_expr", "expr_list", "param_list", "assoc_list", "assoc_item",
  "any_lparen", "maybe_anno", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -88

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -116,    13,   467,  -116,   128,   128,     5,    64,   157,    32,
     128,   128,   128,  -116,   -10,  -116,  -116,  -116,    25,   128,
     128,    -5,  -116,  -116,   128,   128,   -45,    37,  -116,  -116,
     111,  -116,  -116,   518,   129,  -116,    50,   149,  -116,  -116,
     -13,  -116,  -116,   533,  -116,  -116,  -116,  -116,   128,    14,
      -6,    40,    32,  -116,    32,    32,  -116,  -116,    37,    37,
      37,   128,   128,   128,   128,   128,   128,   128,   128,   128,
    -116,    37,   627,   -18,    58,   128,    -7,  -116,    37,   497,
     670,  -116,   128,    22,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,    79,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   -37,  -116,  -116,   128,  -116,
      67,  -116,  -116,    71,    96,    37,    37,    37,    37,    37,
      37,    37,    37,    37,   128,   228,  -116,  -116,  -116,  -116,
    -116,    37,   258,   586,  -116,  -116,   129,   129,   203,   203,
     203,   203,   203,   203,  -116,  -116,  -116,   784,   713,   713,
     713,   713,   713,   756,   527,    44,    37,    37,    37,    37,
      37,    37,    37,    37,    37,  -116,   227,   257,    -3,   132,
     -17,    84,     8,  -116,   139,   146,     8,     8,    37,    78,
     626,  -116,   128,   128,  -116,  -116,  -116,  -116,  -116,     8,
     128,   128,  -116,  -116,  -116,     8,     8,  -116,   128,   128,
     585,    21,   287,   317,  -116,    37,    37,   347,   128,  -116,
     377,    33,    37,  -116,  -116,  -116,  -116,   407,  -116,    41,
     437,  -116,  -116,   227,  -116,  -116,  -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       7,     8,    10,    94,    88,    90,    92,    93,     0,     0,
       0,   109,   116,   115,   100,     0,     3,     5,    13,    17,
      39,    42,    44,    51,    54,    58,    60,    62,    68,    70,
      72,    75,    82,     0,    85,    89,    95,    98,     0,     0,
       0,     0,     0,   104,     0,     0,   104,   104,     6,     9,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,    69,    43,     0,     0,     0,   110,   101,     0,
      71,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     4,     0,   104,
       0,   104,   104,     0,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,    97,   111,   112,    96,
     102,   103,     0,    84,    40,    41,    52,    53,    45,    46,
      47,    48,    49,    50,    55,    56,    57,    59,    63,    64,
      65,    67,    66,    61,     0,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    99,     0,     0,     0,     0,
     118,     0,   118,   108,     0,     0,   118,   118,   114,     0,
      83,    73,   100,     0,     4,    20,    14,    15,     4,   118,
       0,     0,   107,   106,     4,   118,   118,     4,     0,     0,
       0,     0,     0,     0,     4,   105,   117,     0,     0,     4,
       0,     0,   113,    74,     4,    19,    16,     0,    77,     0,
       0,    79,    80,     0,    76,    81,    78,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   -81,  -116,    -2,  -116,  -115,  -116,  -116,    -9,
     131,  -116,    86,    72,    19,   154,   106,   102,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -103,   -51,  -116,    53,
      30,   413
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    26,    71,    28,   196,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    79,   120,    76,    77,
      48,   202
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   164,    49,    50,   117,   123,   124,   198,    58,    59,
      60,    73,    74,     3,    74,   -42,   -42,    81,   116,   200,
     175,    82,    78,    83,    51,   224,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   176,   177,    53,    56,    57,
     -42,   143,   -42,   104,   201,    70,   115,   136,   105,   118,
     232,    75,    82,    75,    83,    82,   137,    83,   235,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   179,   201,
     184,   185,    82,   135,    83,   144,   145,   141,    97,    82,
     142,    83,   119,    52,   121,   122,   180,    22,    23,   210,
     180,    82,   181,    83,   134,    82,   181,    83,   165,    82,
     192,    83,    78,   203,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   212,   209,   180,   178,   213,   237,    22,
      23,   181,   163,   217,   182,    72,   220,    80,   186,   138,
     183,     4,   188,   227,   183,     5,     6,     0,   230,     7,
       8,     9,     0,   233,    84,    85,    13,    14,    15,    16,
      17,   180,    18,   187,    94,    95,    96,   181,   180,   183,
      19,     0,   141,    20,   181,   180,   154,   155,   156,   157,
      54,   181,   146,   147,    27,    27,    55,     0,    98,    99,
     100,    21,     0,    22,    23,     0,    24,     0,     0,   199,
      78,   211,    25,     0,     0,   183,   205,     0,   215,   216,
     101,   102,   183,   206,     0,     0,   221,   222,   141,   183,
      27,    27,    22,    23,   103,    27,   229,     0,    27,   148,
     149,   150,   151,   152,   153,    27,     0,     0,    27,     0,
       4,    27,   193,   194,     5,     6,   -44,   -44,     7,     8,
       9,    10,    11,    12,   195,    13,    14,    15,    16,    17,
       0,    18,   158,   159,   160,   161,   162,     0,     0,    19,
       4,   -44,    20,   -44,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,   197,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,    82,   189,    83,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,   225,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,    82,   190,    83,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,   226,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,     0,     0,     0,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,   228,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,     0,     0,     0,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,   231,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,     0,     0,     0,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,   234,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,     0,     0,     0,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,   236,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,     0,     0,     0,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    10,    11,    12,     0,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,     0,     0,     0,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,     0,     0,     0,    19,
       4,    25,    20,     0,     5,     6,     0,     0,     7,     8,
       9,    86,    87,     0,     0,    13,    14,    15,    16,    17,
      21,    18,    22,    23,     0,    24,   139,     0,     0,    19,
     140,    25,    20,    88,    89,    90,    91,    92,    93,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
      21,     0,    22,    23,   191,    24,     0,     0,     4,     0,
     140,    25,     5,     6,     0,   204,     7,     8,     9,   207,
     208,     0,     0,    13,    14,    15,    16,    17,     0,    18,
       0,     0,   214,     0,     0,     0,     0,    19,   218,   219,
      20,     0,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      22,    23,   223,    24,     0,     0,     0,     0,   140,    25,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,     0,
     -68,   -68,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,     0,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
       0,     0,     0,     0,     0,   -68,     0,   -68,     0,     0,
       0,     0,   -68,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,     0,   -70,   -70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,     0,     0,     0,     0,     0,   -70,     0,
     -70,     0,     0,     0,     0,   -70,   -62,   -62,   -62,   -62,
     -62,   -62,    98,    99,   100,     0,   -62,   -62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -62,   -62,
     -62,   -62,   -62,   -62,   101,   102,     0,     0,     0,     0,
       0,   -62,     0,   -62,     0,     0,     0,     0,   103,   -60,
     -60,   -60,   -60,   -60,    97,     0,     0,     0,     0,   -60,
     -60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -60,   -60,   -60,   -60,   -60,   -60,   -58,   -58,   -58,
     -58,   -58,     0,     0,   -60,     0,   -60,   -58,   -58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
       0,     0,   -58,     0,   -58
};

static const yytype_int16 yycheck[] =
{
       2,   104,     4,     5,    10,    56,    57,    10,    10,    11,
      12,    20,    19,     0,    19,    33,    34,    62,     4,    36,
      57,    58,    24,    60,    19,     4,    36,    37,    38,    39,
      40,    41,    42,    43,    44,   116,   117,     7,     8,     9,
      58,    19,    60,    56,    61,    20,    48,    54,    61,     9,
      17,    58,    58,    58,    60,    58,    63,    60,    17,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   119,    61,
     121,   122,    58,    75,    60,    84,    85,    79,    28,    58,
      82,    60,    52,    19,    54,    55,    19,    55,    56,   192,
      19,    58,    25,    60,    36,    58,    25,    60,    19,    58,
      56,    60,   104,    19,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   194,    36,    19,   118,   198,   233,    55,
      56,    25,   103,   204,    57,    19,   207,    25,    57,    76,
      63,     3,   134,   214,    63,     7,     8,    -1,   219,    11,
      12,    13,    -1,   224,    33,    34,    18,    19,    20,    21,
      22,    19,    24,    57,    25,    26,    27,    25,    19,    63,
      32,    -1,   164,    35,    25,    19,    94,    95,    96,    97,
      13,    25,    86,    87,   176,   177,    19,    -1,    29,    30,
      31,    53,    -1,    55,    56,    -1,    58,    -1,    -1,    57,
     192,   193,    64,    -1,    -1,    63,    57,    -1,   200,   201,
      51,    52,    63,    57,    -1,    -1,   208,   209,   210,    63,
     212,   213,    55,    56,    65,   217,   218,    -1,   220,    88,
      89,    90,    91,    92,    93,   227,    -1,    -1,   230,    -1,
       3,   233,     5,     6,     7,     8,    33,    34,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    98,    99,   100,   101,   102,    -1,    -1,    32,
       3,    58,    35,    60,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    58,    59,    60,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    58,    59,    60,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    -1,    -1,    -1,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    -1,    -1,    -1,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    -1,    -1,    -1,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    -1,    -1,    -1,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    -1,    -1,    -1,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    -1,    -1,    -1,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    -1,    -1,    -1,    32,
       3,    64,    35,    -1,     7,     8,    -1,    -1,    11,    12,
      13,    23,    24,    -1,    -1,    18,    19,    20,    21,    22,
      53,    24,    55,    56,    -1,    58,    59,    -1,    -1,    32,
      63,    64,    35,    45,    46,    47,    48,    49,    50,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      53,    -1,    55,    56,    57,    58,    -1,    -1,     3,    -1,
      63,    64,     7,     8,    -1,   182,    11,    12,    13,   186,
     187,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    32,   205,   206,
      35,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,
      -1,    -1,    65,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      60,    -1,    -1,    -1,    -1,    65,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    65,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    23,    24,    25,
      26,    27,    -1,    -1,    58,    -1,    60,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     3,     7,     8,    11,    12,    13,
      14,    15,    16,    18,    19,    20,    21,    22,    24,    32,
      35,    53,    55,    56,    58,    64,    69,    70,    71,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    96,    70,
      70,    19,    19,    96,    13,    19,    96,    96,    70,    70,
      70,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      20,    70,    82,    75,    19,    58,    94,    95,    70,    92,
      83,    62,    58,    60,    33,    34,    23,    24,    45,    46,
      47,    48,    49,    50,    25,    26,    27,    28,    29,    30,
      31,    51,    52,    65,    56,    61,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    70,     4,    10,     9,    96,
      93,    96,    96,    93,    93,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    36,    70,    54,    63,    95,    59,
      63,    70,    70,    19,    75,    75,    78,    78,    76,    76,
      76,    76,    76,    76,    79,    79,    79,    79,    81,    81,
      81,    81,    81,    80,    92,    19,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    57,    68,    68,    70,    93,
      19,    25,    57,    63,    93,    93,    57,    57,    70,    59,
      59,    57,    56,     5,     6,    17,    72,    17,    10,    57,
      36,    61,    97,    19,    97,    57,    57,    97,    97,    36,
      92,    70,    68,    68,    97,    70,    70,    68,    97,    97,
      68,    70,    70,    57,     4,    17,    17,    68,    17,    70,
      68,    17,    17,    68,    17,    17,    17,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    71,    71,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    90,    90,    90,    91,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     1,     1,     2,
       1,     2,     2,     1,     5,     5,     7,     1,     5,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     2,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     1,     2,
       1,     2,     1,     4,     6,     1,     8,     7,     8,     7,
       7,     8,     1,     4,     3,     1,     4,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     3,     1,     3,
       0,     1,     2,     2,     0,     4,     3,     3,     2,     0,
       1,     2,     2,     5,     3,     1,     1,     2,     0
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
      yyerror (&yylloc, program, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, program); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, stmt_node **program)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, stmt_node **program)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, program);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, stmt_node **program)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , program);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, program); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, stmt_node **program)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (program);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (stmt_node **program)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 40 "parser.y" /* yacc.c:1429  */
{
	yylloc.first_line = 1; yylloc.first_column = 0;
	yylloc.last_line = 1; yylloc.last_column = 1;
}

#line 1507 "parser.tab.c" /* yacc.c:1429  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 48 "parser.y" /* yacc.c:1646  */
    { *program = AS_ST((yyvsp[0])); }
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "parser.y" /* yacc.c:1646  */
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
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 63 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEW_ST();
    AS_ST((yyval))->type = ST_LIST;
    AS_ST((yyval))->stmtlist = NEW(stmtlist_node);
    AS_ST((yyval))->stmtlist->stmt = NULL;
    AS_ST((yyval))->stmtlist->next = NULL;
}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 73 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_EXPR; AS_ST((yyval))->expr = (yyvsp[0]); }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = (yyvsp[0]); }
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 75 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = NULL; }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_BREAK; AS_ST((yyval))->brk = NEW(break_node); AS_ST((yyval))->brk->val = NULL;}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_BREAK; AS_ST((yyval))->brk = NEW(break_node); AS_ST((yyval))->brk->val = (yyvsp[0]); }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_CONT; AS_ST((yyval))->cont = NEW(cont_node); AS_ST((yyval))->cont->val = NULL; }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 79 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_CONT; AS_ST((yyval))->cont = NEW(cont_node); AS_ST((yyval))->cont->val = (yyvsp[0]); }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 88 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_IFELSE;
	AS_EX((yyval))->ifelse = NEW(ifelse_node);
	AS_EX((yyval))->ifelse->cond = (yyvsp[-3]);
	AS_EX((yyval))->ifelse->iftrue = (yyvsp[-1]);
	AS_EX((yyval))->ifelse->iffalse = (yyvsp[0]);
}
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_LOOP;
	AS_EX((yyval))->loop = NEW(loop_node);
	AS_EX((yyval))->loop->cond = (yyvsp[-3]);
	AS_EX((yyval))->loop->loop = (yyvsp[-1]);
}
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 103 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ITER;
	AS_EX((yyval))->iter = NEW(iter_node);
	AS_EX((yyval))->iter->var = (yyvsp[-5]);
	AS_EX((yyval))->iter->iter = (yyvsp[-3]);
	AS_EX((yyval))->iter->loop = (yyvsp[-1]);
}
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 115 "parser.y" /* yacc.c:1646  */
    {
		(yyval) = NEW_ST();
		AS_ST((yyval))->type = ST_EXPR;
		AS_ST((yyval))->expr = NEW_EX();
		AS_ST((yyval))->expr->type = EX_IFELSE;
		AS_ST((yyval))->expr->ifelse = NEW(ifelse_node);
		AS_ST((yyval))->expr->ifelse->cond = (yyvsp[-3]);
		AS_ST((yyval))->expr->ifelse->iftrue = (yyvsp[-1]);
		AS_ST((yyval))->expr->ifelse->iffalse = (yyvsp[0]);
	}
#line 1837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 125 "parser.y" /* yacc.c:1646  */
    {
		(yyval) = (yyvsp[-1]);
	}
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_ASSIGN; AS_EX((yyval))->assign = NEW(assign_node); AS_EX((yyval))->assign->ident = (yyvsp[-2]); AS_EX((yyval))->assign->value = (yyvsp[0]); }
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_ADD, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 140 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_SUB, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_MUL, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 154 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
    MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_DIV, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_POW, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 168 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BAND, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 175 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 182 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BXOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 189 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    AS_EX((yyval))->setindex->value = (yyvsp[0]);
    ex_free(AS_EX((yyvsp[-2])));
}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 202 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_ADD, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 215 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_SUB, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 228 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_MUL, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 241 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_DIV, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 254 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_POW, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 267 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BAND, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 280 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BOR, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 293 "parser.y" /* yacc.c:1646  */
    {
    if(AS_EX((yyvsp[-2]))->type != EX_INDEX) {
        yyerror(&(yyloc), NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = ex_copy(AS_EX((yyvsp[-2]))->index->expr);
    AS_EX((yyval))->setindex->index = ex_copy(AS_EX((yyvsp[-2]))->index->index);
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BXOR, AS_EX((yyvsp[-2]))->index->expr, AS_EX((yyvsp[-2]))->index->index, (yyvsp[0]));
    ex_free(AS_EX((yyvsp[-2])));
}
#line 2115 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 310 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 311 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2133 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_EQUAL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_NEQUAL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 323 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESS; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2169 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATER; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESSEQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATEREQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 331 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_ADD; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2199 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_SUB; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2205 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 337 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MUL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_DIV; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2223 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MOD; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2229 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2235 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_POW; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2241 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2247 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 349 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_TBANG; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2253 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 355 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2265 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 356 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2271 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 357 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BXOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2283 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 359 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_RSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2289 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2295 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_BNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2307 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 369 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LEN; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2313 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 370 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2319 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 374 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_CALL; AS_EX((yyval))->call = NEW(call_node); AS_EX((yyval))->call->expr = (yyvsp[-3]); AS_EX((yyval))->call->args = (yyvsp[-1]); AS_EX((yyval))->call->method = NULL; }
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 375 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_CALL;
	AS_EX((yyval))->call = NEW(call_node);
	AS_EX((yyval))->call->expr = (yyvsp[-5]);
	AS_EX((yyval))->call->args = (yyvsp[-1]);
	AS_EX((yyval))->call->method = (yyvsp[-3]);
}
#line 2338 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 383 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2344 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 387 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[-6]);
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
	AS_EX((yyval))->funcdecl->flags = 0;
}
#line 2359 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 397 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
	AS_EX((yyval))->funcdecl->flags = 0;
}
#line 2374 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 407 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[-6]);
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
	AS_EX((yyval))->funcdecl->flags = FUNC_IS_MACRO;
}
#line 2389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 417 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
	AS_EX((yyval))->funcdecl->flags = FUNC_IS_MACRO;
}
#line 2404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 427 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = NEW_ST();
	AS_EX((yyval))->funcdecl->body->type = ST_RET;
	AS_EX((yyval))->funcdecl->body->ret = NEW(ret_node);
	AS_EX((yyval))->funcdecl->body->ret->ret = (yyvsp[-1]);
	AS_EX((yyval))->funcdecl->flags = 0;
}
#line 2422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 440 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = NEW_ST();
	AS_EX((yyval))->funcdecl->body->type = ST_RET;
	AS_EX((yyval))->funcdecl->body->ret = NEW(ret_node);
	AS_EX((yyval))->funcdecl->body->ret->ret = (yyvsp[-1]);
	AS_EX((yyval))->funcdecl->flags = FUNC_IS_MACRO;
}
#line 2440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 453 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 457 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 458 "parser.y" /* yacc.c:1646  */
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
#line 2468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 473 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 474 "parser.y" /* yacc.c:1646  */
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
#line 2496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 488 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_REF; AS_EX((yyval))->ref = NEW(ref_node); AS_EX((yyval))->ref->ident = (yyvsp[0]); }
#line 2502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 489 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 493 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = *AS((yyvsp[0]), long); free((yyvsp[0])); }
#line 2514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 494 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = -(*AS((yyvsp[0]), long)); free((yyvsp[0])); }
#line 2520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 495 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_FLOAT; AS_EX((yyval))->lit->fval = *AS((yyvsp[0]), double); free((yyvsp[0])); }
#line 2526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 496 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_BUFFER; AS_EX((yyval))->lit->buf = (yyvsp[0]); }
#line 2532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 497 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_NONE; }
#line 2538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 498 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 502 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LISTGEN; AS_EX((yyval))->listgen = NEW(listgen_node); AS_EX((yyval))->listgen->list = (yyvsp[-1]); }
#line 2550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 503 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_MAPGEN; AS_EX((yyval))->mapgen = NEW(mapgen_node); AS_EX((yyval))->mapgen->map = (yyvsp[-1]); }
#line 2556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 504 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 508 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 512 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 513 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(exprlist_node);
	AS((yyval), exprlist_node)->expr = (yyvsp[0]);
	AS((yyval), exprlist_node)->next = NULL;
}
#line 2584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 518 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 519 "parser.y" /* yacc.c:1646  */
    {
	exprlist_node *cur = (yyvsp[-1]);
	if(!cur) {
		cur = NEW(exprlist_node);
		cur->expr = (yyvsp[0]);
		cur->next = NULL;
		(yyval) = cur;
	} else {
		while(cur->next) cur = cur->next;
		cur->next = NEW(exprlist_node);
		cur = cur->next;
		cur->expr = (yyvsp[0]);
		cur->next = NULL;
		(yyval) = (yyvsp[-1]);
	}
}
#line 2611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 564 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 565 "parser.y" /* yacc.c:1646  */
    {
	paramlist_node *pl = (yyvsp[-3]);
	identlist_node *curk;
	exprlist_node *curv;
	if(!pl) {
		pl = NEW(paramlist_node);
		pl->args = NULL;
		pl->annos = NULL;
		pl->clkeys = NULL;
		pl->clvalues = NULL;
		pl->rest = NULL;
	}
	if(!pl->clkeys) {
		pl->clkeys = NEW(identlist_node);
		curk = pl->clkeys;
		pl->clvalues = NEW(exprlist_node);
		curv = pl->clvalues;
	} else {
		curk = pl->clkeys;
		curv = pl->clvalues;
		while(curk->next) {
			curk = curk->next;
			curv = curv->next;
		}
		curk->next = NEW(identlist_node);
		curk = curk->next;
		curv->next = NEW(exprlist_node);
		curv = curv->next;
	}
	curk->ident = (yyvsp[-2]);
	curk->next = NULL;
	curv->expr = (yyvsp[0]);
	curv->next = NULL;
	(yyval) = pl;
}
#line 2657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 600 "parser.y" /* yacc.c:1646  */
    {
	paramlist_node *pl = (yyvsp[-2]);
	if(!pl) {
		pl = NEW(paramlist_node);
		pl->args = NULL;
		pl->annos = NULL;
		pl->clkeys = NULL;
		pl->clvalues = NULL;
		pl->rest = NULL;
	}
	pl-> rest = (yyvsp[0]);
	(yyval) = pl;
}
#line 2675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 613 "parser.y" /* yacc.c:1646  */
    {
	paramlist_node *pl = (yyvsp[-2]);
	identlist_node *cura;
	exprlist_node *curn;
	if(!pl) {
		pl = NEW(paramlist_node);
		pl->args = NULL;
		pl->annos = NULL;
		pl->clkeys = NULL;
		pl->clvalues = NULL;
		pl->rest = NULL;
	}
	if(!pl->args) {
		pl->args = NEW(identlist_node);
		cura = pl->args;
		pl->annos = NEW(exprlist_node);
		curn = pl->annos;
	} else {
		cura = pl->args;
		curn = pl->annos;
		while(cura->next) {
			cura = cura->next;
			curn = curn->next;
		}
		cura->next = NEW(identlist_node);
		cura = cura->next;
		curn->next = NEW(exprlist_node);
		curn = curn->next;
	}
	cura->ident = (yyvsp[-1]);
	cura->next = NULL;
	curn->expr = (yyvsp[0]);
	curn->next = NULL;
	(yyval) = pl;
}
#line 2715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 648 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 652 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 653 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(assoclist_node);
	AS((yyval), assoclist_node)->item = (yyvsp[0]);
	AS((yyval), assoclist_node)->next = NULL;
}
#line 2737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 658 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 659 "parser.y" /* yacc.c:1646  */
    {
	assoclist_node *cur = (yyvsp[-1]);
	if(!cur) {
		cur = NEW(assoclist_node);
		cur->item = (yyvsp[0]);
		cur->next = NULL;
		(yyval) = cur;
	} else {
		while(cur->next) cur = cur->next;
		cur->next = NEW(assoclist_node);
		cur = cur->next;
		cur->item = (yyvsp[0]);
		cur->next = NULL;
		(yyval) = (yyvsp[-1]);
	}
}
#line 2764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 678 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = (yyvsp[-3]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 683 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = NEW_EX();
	AS((yyval), associtem_node)->key->type = EX_LIT;
	AS((yyval), associtem_node)->key->lit = NEW(lit_node);
	AS((yyval), associtem_node)->key->lit->type = LIT_STRING;
	AS((yyval), associtem_node)->key->lit->str = (yyvsp[-2]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 700 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 701 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2800 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2804 "parser.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, program, YY_("syntax error"));
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
        yyerror (&yylloc, program, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, &yylloc, program);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, program);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, program, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, program);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, program);
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
#line 704 "parser.y" /* yacc.c:1906  */


// TODO
