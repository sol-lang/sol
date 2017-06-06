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
    LAMBDA = 267,
    RETURN = 268,
    BREAK = 269,
    CONTINUE = 270,
    END = 271,
    NONE = 272,
    IDENT = 273,
    INT = 274,
    FLOAT = 275,
    STRING = 276,
    PLUS = 277,
    MINUS = 278,
    STAR = 279,
    SLASH = 280,
    PERCENT = 281,
    DSTAR = 282,
    BAND = 283,
    BOR = 284,
    BXOR = 285,
    BNOT = 286,
    LAND = 287,
    LOR = 288,
    LNOT = 289,
    ASSIGN = 290,
    ASSIGNPLUS = 291,
    ASSIGNMINUS = 292,
    ASSIGNSTAR = 293,
    ASSIGNSLASH = 294,
    ASSIGNDSTAR = 295,
    ASSIGNBAND = 296,
    ASSIGNBOR = 297,
    ASSIGNBXOR = 298,
    EQUAL = 299,
    NEQUAL = 300,
    LESS = 301,
    GREATER = 302,
    LESSEQ = 303,
    GREATEREQ = 304,
    RSHIFT = 305,
    LSHIFT = 306,
    LBRACE = 307,
    RBRACE = 308,
    BLPAREN = 309,
    LPAREN = 310,
    RPAREN = 311,
    LBRACKET = 312,
    RBRACKET = 313,
    DOT = 314,
    COLON = 315,
    SEMICOLON = 316,
    COMMA = 317,
    POUND = 318,
    TBANG = 319
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

#line 215 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   812

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    48,    59,    69,    70,    71,    72,    73,
      74,    75,    76,    80,    84,    92,    99,   107,   111,   121,
     124,   128,   129,   136,   143,   150,   157,   164,   171,   178,
     185,   198,   211,   224,   237,   250,   263,   276,   289,   302,
     306,   307,   308,   312,   313,   317,   318,   319,   320,   321,
     322,   323,   327,   328,   329,   333,   334,   335,   336,   340,
     341,   345,   346,   351,   352,   353,   354,   355,   356,   360,
     361,   365,   366,   370,   371,   379,   383,   392,   401,   413,
     417,   418,   429,   433,   434,   448,   449,   453,   454,   455,
     456,   457,   458,   462,   463,   464,   468,   472,   473,   478,
     479,   524,   525,   560,   573,   608,   612,   613,   618,   619,
     638,   643,   655,   656,   660,   661
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSEIF", "ELSE", "WHILE",
  "FOR", "IN", "DO", "FUNC", "LAMBDA", "RETURN", "BREAK", "CONTINUE",
  "END", "NONE", "IDENT", "INT", "FLOAT", "STRING", "PLUS", "MINUS",
  "STAR", "SLASH", "PERCENT", "DSTAR", "BAND", "BOR", "BXOR", "BNOT",
  "LAND", "LOR", "LNOT", "ASSIGN", "ASSIGNPLUS", "ASSIGNMINUS",
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
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -158,    13,   442,  -158,   554,   554,    -1,    61,   -21,   554,
     554,   554,  -158,   123,  -158,  -158,  -158,    16,   554,   554,
      -4,  -158,  -158,   554,   554,   -22,    37,  -158,  -158,    10,
    -158,  -158,   235,     1,  -158,     3,   106,  -158,  -158,   -31,
    -158,  -158,   315,  -158,  -158,  -158,  -158,   554,    11,    18,
      42,   -21,  -158,  -158,    37,    37,    37,   554,   554,   554,
     554,   554,   554,   554,   554,   554,  -158,    37,   596,   -10,
      29,   554,    28,  -158,    37,   120,   639,  -158,   554,    53,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     554,    64,   554,   554,   554,   554,   554,   554,   554,   554,
     554,    32,  -158,  -158,   554,  -158,   -12,    -8,    37,    37,
      37,    37,    37,    37,    37,    37,    37,   554,    63,  -158,
    -158,  -158,  -158,  -158,    37,   133,   393,  -158,  -158,     1,
       1,    85,    85,    85,    85,    85,    85,  -158,  -158,  -158,
     753,   682,   682,   682,   682,   682,   725,   467,    44,    37,
      37,    37,    37,    37,    37,    37,    37,    37,  -158,   208,
     233,    21,    68,   -24,    69,    50,  -158,    50,    37,    62,
     471,  -158,   554,   554,  -158,  -158,  -158,  -158,  -158,    50,
     554,   554,  -158,  -158,  -158,   554,   554,   524,    15,   286,
     311,  -158,    37,    37,   364,    36,    37,  -158,  -158,  -158,
    -158,   389,  -158,  -158,   208,  -158,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     7,
       8,    10,    91,    85,    87,    89,    90,     0,     0,     0,
     106,   113,   112,    97,     0,     3,     5,    13,    17,    39,
      42,    44,    51,    54,    58,    60,    62,    68,    70,    72,
      75,    79,     0,    82,    86,    92,    95,     0,     0,     0,
       0,     0,   101,   101,     6,     9,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,    69,    43,
       0,     0,     0,   107,    98,     0,    71,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     4,     0,   101,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,     0,    94,
     108,   109,    93,    99,   100,     0,    81,    40,    41,    52,
      53,    45,    46,    47,    48,    49,    50,    55,    56,    57,
      59,    63,    64,    65,    67,    66,    61,     0,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    96,     0,
       0,     0,     0,   115,     0,   115,   105,   115,   111,     0,
      80,    73,    97,     0,     4,    20,    14,    15,     4,   115,
       0,     0,   104,   103,     4,     0,     0,     0,     0,     0,
       0,     4,   102,   114,     0,     0,   110,    74,     4,    19,
      16,     0,    77,    78,     0,    76,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   -75,  -158,    -2,  -158,  -103,  -158,  -158,   -15,
     119,  -158,    70,    94,    30,    51,    96,   126,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,   -99,   -48,  -158,    97,
      33,  -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    67,    27,   186,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    75,   116,    72,    73,
      47,   192
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   157,    48,    49,    69,   117,   173,    54,    55,    56,
     173,   190,   174,     3,    70,   112,   174,    50,   194,   208,
     195,    74,   -42,   -42,   100,    90,    91,    92,   113,   101,
      93,   188,   201,    21,    22,    66,   191,   169,   170,    77,
      52,    53,    80,    81,   175,   111,    70,   -42,   177,   -42,
     176,   114,   213,    71,   176,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   137,   138,   172,    78,   128,
      79,   136,    78,   134,    79,    78,   135,    79,    78,    51,
      79,   129,   158,   197,   115,    71,   173,   193,   168,    78,
     130,    79,   174,    78,    78,    79,    79,   196,    74,   182,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   199,
     191,   216,   171,   200,    68,    21,    22,   -44,   -44,   204,
      78,   179,    79,     4,   189,   178,   211,     5,     6,   156,
     176,     7,     8,   214,    94,    95,    96,    12,    13,    14,
      15,    16,   -44,    17,   -44,   151,   152,   153,   154,   155,
      76,    18,   139,   140,    19,   134,    97,    98,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    26,    26,   131,
      99,     0,    20,     0,    21,    22,     0,    23,   132,     0,
      74,   198,   133,    24,   147,   148,   149,   150,   202,   203,
      78,   180,    79,   205,   206,   134,     0,    26,    26,     0,
       0,     0,    26,   141,   142,   143,   144,   145,   146,    26,
       0,     4,    26,   183,   184,     5,     6,     0,     0,     7,
       8,     9,    10,    11,   185,    12,    13,    14,    15,    16,
       0,    17,     0,     0,     0,     0,     4,     0,     0,    18,
       5,     6,    19,     0,     7,     8,     9,    10,    11,   187,
      12,    13,    14,    15,    16,     0,    17,    82,    83,     0,
      20,     0,    21,    22,    18,    23,     0,    19,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    20,     0,    21,    22,     4,
      23,     0,     0,     5,     6,     0,    24,     7,     8,     9,
      10,    11,   209,    12,    13,    14,    15,    16,     0,    17,
       0,     0,     0,     0,     4,     0,     0,    18,     5,     6,
      19,     0,     7,     8,     9,    10,    11,   210,    12,    13,
      14,    15,    16,     0,    17,     0,     0,     0,    20,     0,
      21,    22,    18,    23,     0,    19,     0,     0,     0,    24,
     102,   103,   104,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,    20,     0,    21,    22,     4,    23,     0,
       0,     5,     6,     0,    24,     7,     8,     9,    10,    11,
     212,    12,    13,    14,    15,    16,     0,    17,     0,     0,
       0,     0,     4,     0,     0,    18,     5,     6,    19,     0,
       7,     8,     9,    10,    11,   215,    12,    13,    14,    15,
      16,     0,    17,     0,     0,     0,    20,     0,    21,    22,
      18,    23,     0,    19,     0,     0,     0,    24,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,     0,     0,     0,
       0,    20,     0,    21,    22,     4,    23,     0,     0,     5,
       6,     0,    24,     7,     8,     9,    10,    11,     0,    12,
      13,    14,    15,    16,     0,    17,     0,     0,     0,     0,
       4,     0,     0,    18,     5,     6,    19,     0,     7,     8,
       0,     0,     0,     0,    12,    13,    14,    15,    16,     0,
      17,     0,     0,     0,    20,     0,    21,    22,    18,    23,
       0,    19,     0,     0,     0,    24,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,     0,     0,     0,     0,    20,
       0,    21,    22,   181,    23,     0,     0,     4,     0,   133,
      24,     5,     6,     0,     0,     7,     8,     0,     0,     0,
       0,    12,    13,    14,    15,    16,     0,    17,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     4,    19,     0,
       0,     5,     6,     0,     0,     7,     8,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    20,    17,    21,    22,
     207,    23,     0,     0,     0,    18,   133,    24,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    21,    22,
       0,    23,     0,     0,     0,     0,     0,    24,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,     0,   -68,   -68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,
       0,     0,     0,   -68,     0,   -68,     0,     0,     0,     0,
     -68,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
       0,   -70,   -70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,     0,     0,     0,     0,     0,   -70,     0,   -70,     0,
       0,     0,     0,   -70,   -62,   -62,   -62,   -62,   -62,   -62,
      94,    95,    96,     0,   -62,   -62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -62,   -62,   -62,   -62,
     -62,   -62,    97,    98,     0,     0,     0,     0,     0,   -62,
       0,   -62,     0,     0,     0,     0,    99,   -60,   -60,   -60,
     -60,   -60,    93,     0,     0,     0,     0,   -60,   -60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -60,
     -60,   -60,   -60,   -60,   -60,   -58,   -58,   -58,   -58,   -58,
       0,     0,   -60,     0,   -60,   -58,   -58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,     0,     0,     0,     0,
     -58,     0,   -58
};

static const yytype_int16 yycheck[] =
{
       2,   100,     4,     5,    19,    53,    18,     9,    10,    11,
      18,    35,    24,     0,    18,     4,    24,    18,   175,     4,
     177,    23,    32,    33,    55,    24,    25,    26,    10,    60,
      27,    10,   189,    54,    55,    19,    60,   112,   113,    61,
       7,     8,    32,    33,    56,    47,    18,    57,    56,    59,
      62,     9,    16,    57,    62,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    35,    80,    81,   115,    57,    71,
      59,    18,    57,    75,    59,    57,    78,    59,    57,    18,
      59,    53,    18,   182,    51,    57,    18,    18,    56,    57,
      62,    59,    24,    57,    57,    59,    59,    35,   100,    55,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   184,
      60,   214,   114,   188,    18,    54,    55,    32,    33,   194,
      57,    58,    59,     3,    56,   127,   201,     7,     8,    99,
      62,    11,    12,   208,    28,    29,    30,    17,    18,    19,
      20,    21,    57,    23,    59,    94,    95,    96,    97,    98,
      24,    31,    82,    83,    34,   157,    50,    51,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   169,   170,    72,
      64,    -1,    52,    -1,    54,    55,    -1,    57,    58,    -1,
     182,   183,    62,    63,    90,    91,    92,    93,   190,   191,
      57,    58,    59,   195,   196,   197,    -1,   199,   200,    -1,
      -1,    -1,   204,    84,    85,    86,    87,    88,    89,   211,
      -1,     3,   214,     5,     6,     7,     8,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    -1,    -1,    -1,    -1,     3,    -1,    -1,    31,
       7,     8,    34,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    22,    23,    -1,
      52,    -1,    54,    55,    31,    57,    -1,    34,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    52,    -1,    54,    55,     3,
      57,    -1,    -1,     7,     8,    -1,    63,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    31,     7,     8,
      34,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    -1,    -1,    -1,    52,    -1,
      54,    55,    31,    57,    -1,    34,    -1,    -1,    -1,    63,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,     3,    57,    -1,
      -1,     7,     8,    -1,    63,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    31,     7,     8,    34,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    -1,    52,    -1,    54,    55,
      31,    57,    -1,    34,    -1,    -1,    -1,    63,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,     3,    57,    -1,    -1,     7,
       8,    -1,    63,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    31,     7,     8,    34,    -1,    11,    12,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,    -1,    52,    -1,    54,    55,    31,    57,
      -1,    34,    -1,    -1,    -1,    63,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    -1,    -1,     3,    -1,    62,
      63,     7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,     3,    34,    -1,
      -1,     7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    52,    23,    54,    55,
      56,    57,    -1,    -1,    -1,    31,    62,    63,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    63,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      64,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    64,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    64,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    22,    23,    24,    25,    26,
      -1,    -1,    57,    -1,    59,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     3,     7,     8,    11,    12,    13,
      14,    15,    17,    18,    19,    20,    21,    23,    31,    34,
      52,    54,    55,    57,    63,    68,    69,    70,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    95,    69,    69,
      18,    18,    95,    95,    69,    69,    69,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    19,    69,    81,    74,
      18,    57,    93,    94,    69,    91,    82,    61,    57,    59,
      32,    33,    22,    23,    44,    45,    46,    47,    48,    49,
      24,    25,    26,    27,    28,    29,    30,    50,    51,    64,
      55,    60,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    69,     4,    10,     9,    95,    92,    92,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    35,    69,    53,
      62,    94,    58,    62,    69,    69,    18,    74,    74,    77,
      77,    75,    75,    75,    75,    75,    75,    78,    78,    78,
      78,    80,    80,    80,    80,    80,    79,    91,    18,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    56,    67,
      67,    69,    92,    18,    24,    56,    62,    56,    69,    58,
      58,    56,    55,     5,     6,    16,    71,    16,    10,    56,
      35,    60,    96,    18,    96,    96,    35,    91,    69,    67,
      67,    96,    69,    69,    67,    69,    69,    56,     4,    16,
      16,    67,    16,    16,    67,    16,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    70,    70,    70,    70,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    90,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96
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
       1,     2,     1,     4,     6,     1,     8,     7,     7,     1,
       4,     3,     1,     4,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     3,     3,     1,     3,     0,     1,     2,
       2,     0,     4,     3,     3,     2,     0,     1,     2,     2,
       5,     3,     1,     1,     2,     0
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
#line 44 "parser.y" /* yacc.c:1646  */
    { *program = AS_ST((yyvsp[0])); }
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 48 "parser.y" /* yacc.c:1646  */
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
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 59 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = NEW_ST();
    AS_ST((yyval))->type = ST_LIST;
    AS_ST((yyval))->stmtlist = NEW(stmtlist_node);
    AS_ST((yyval))->stmtlist->stmt = NULL;
    AS_ST((yyval))->stmtlist->next = NULL;
}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_EXPR; AS_ST((yyval))->expr = (yyvsp[0]); }
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 70 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = (yyvsp[0]); }
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 71 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = NULL; }
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 72 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_BREAK; AS_ST((yyval))->brk = NEW(break_node); AS_ST((yyval))->brk->val = NULL;}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 73 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_BREAK; AS_ST((yyval))->brk = NEW(break_node); AS_ST((yyval))->brk->val = (yyvsp[0]); }
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 74 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_CONT; AS_ST((yyval))->cont = NEW(cont_node); AS_ST((yyval))->cont->val = NULL; }
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 75 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); SET_LOC(AS_ST((yyval)), (yyloc)); AS_ST((yyval))->type = ST_CONT; AS_ST((yyval))->cont = NEW(cont_node); AS_ST((yyval))->cont->val = (yyvsp[0]); }
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_IFELSE;
	AS_EX((yyval))->ifelse = NEW(ifelse_node);
	AS_EX((yyval))->ifelse->cond = (yyvsp[-3]);
	AS_EX((yyval))->ifelse->iftrue = (yyvsp[-1]);
	AS_EX((yyval))->ifelse->iffalse = (yyvsp[0]);
}
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 92 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_LOOP;
	AS_EX((yyval))->loop = NEW(loop_node);
	AS_EX((yyval))->loop->cond = (yyvsp[-3]);
	AS_EX((yyval))->loop->loop = (yyvsp[-1]);
}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 99 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ITER;
	AS_EX((yyval))->iter = NEW(iter_node);
	AS_EX((yyval))->iter->var = (yyvsp[-5]);
	AS_EX((yyval))->iter->iter = (yyvsp[-3]);
	AS_EX((yyval))->iter->loop = (yyvsp[-1]);
}
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "parser.y" /* yacc.c:1646  */
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
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "parser.y" /* yacc.c:1646  */
    {
		(yyval) = (yyvsp[-1]);
	}
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_ASSIGN; AS_EX((yyval))->assign = NEW(assign_node); AS_EX((yyval))->assign->ident = (yyvsp[-2]); AS_EX((yyval))->assign->value = (yyvsp[0]); }
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 129 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_ADD, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 136 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_SUB, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_MUL, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
    MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_DIV, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_POW, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 164 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BAND, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 171 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 178 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BXOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 185 "parser.y" /* yacc.c:1646  */
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
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 198 "parser.y" /* yacc.c:1646  */
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
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 211 "parser.y" /* yacc.c:1646  */
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
#line 1984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "parser.y" /* yacc.c:1646  */
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
#line 2002 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 237 "parser.y" /* yacc.c:1646  */
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
#line 2020 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "parser.y" /* yacc.c:1646  */
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
#line 2038 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 263 "parser.y" /* yacc.c:1646  */
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
#line 2056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 276 "parser.y" /* yacc.c:1646  */
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
#line 2074 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 289 "parser.y" /* yacc.c:1646  */
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
#line 2092 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 302 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2098 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2104 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2110 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 308 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2116 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2122 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 313 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2128 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_EQUAL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2134 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_NEQUAL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2140 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESS; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2146 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 320 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATER; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2152 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESSEQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2158 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATEREQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 323 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2170 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_ADD; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2176 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 328 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_SUB; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2182 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 329 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MUL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2194 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_DIV; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2200 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 335 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MOD; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2206 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_POW; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2218 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 341 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_TBANG; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2230 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2236 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 351 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2242 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 352 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 353 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BXOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2254 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2260 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 355 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_RSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2266 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 356 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2272 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_BNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2278 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 361 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2284 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LEN; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2290 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2296 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 370 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_CALL; AS_EX((yyval))->call = NEW(call_node); AS_EX((yyval))->call->expr = (yyvsp[-3]); AS_EX((yyval))->call->args = (yyvsp[-1]); AS_EX((yyval))->call->method = NULL; }
#line 2302 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 371 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_CALL;
	AS_EX((yyval))->call = NEW(call_node);
	AS_EX((yyval))->call->expr = (yyvsp[-5]);
	AS_EX((yyval))->call->args = (yyvsp[-1]);
	AS_EX((yyval))->call->method = (yyvsp[-3]);
}
#line 2315 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 379 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2321 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 383 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[-6]);
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2335 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 392 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->params = (yyvsp[-4]);
	AS_EX((yyval))->funcdecl->anno = (yyvsp[-2]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2349 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 401 "parser.y" /* yacc.c:1646  */
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
}
#line 2366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 413 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 417 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 418 "parser.y" /* yacc.c:1646  */
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
#line 2394 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 429 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 433 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2406 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 434 "parser.y" /* yacc.c:1646  */
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
#line 2422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 448 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_REF; AS_EX((yyval))->ref = NEW(ref_node); AS_EX((yyval))->ref->ident = (yyvsp[0]); }
#line 2428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 449 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 453 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = *AS((yyvsp[0]), long); free((yyvsp[0])); }
#line 2440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 454 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = -(*AS((yyvsp[0]), long)); free((yyvsp[0])); }
#line 2446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 455 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_FLOAT; AS_EX((yyval))->lit->fval = *AS((yyvsp[0]), double); free((yyvsp[0])); }
#line 2452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 456 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_BUFFER; AS_EX((yyval))->lit->buf = (yyvsp[0]); }
#line 2458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 457 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_NONE; }
#line 2464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 458 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 462 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LISTGEN; AS_EX((yyval))->listgen = NEW(listgen_node); AS_EX((yyval))->listgen->list = (yyvsp[-1]); }
#line 2476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 463 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_MAPGEN; AS_EX((yyval))->mapgen = NEW(mapgen_node); AS_EX((yyval))->mapgen->map = (yyvsp[-1]); }
#line 2482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 464 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 468 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 472 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 473 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(exprlist_node);
	AS((yyval), exprlist_node)->expr = (yyvsp[0]);
	AS((yyval), exprlist_node)->next = NULL;
}
#line 2510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 478 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 479 "parser.y" /* yacc.c:1646  */
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
#line 2537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 524 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 525 "parser.y" /* yacc.c:1646  */
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
#line 2583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 560 "parser.y" /* yacc.c:1646  */
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
#line 2601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 573 "parser.y" /* yacc.c:1646  */
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
#line 2641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 608 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 612 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 613 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(assoclist_node);
	AS((yyval), assoclist_node)->item = (yyvsp[0]);
	AS((yyval), assoclist_node)->next = NULL;
}
#line 2663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 618 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 619 "parser.y" /* yacc.c:1646  */
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
#line 2690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 638 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = (yyvsp[-3]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 643 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = NEW_EX();
	AS((yyval), associtem_node)->key->type = EX_LIT;
	AS((yyval), associtem_node)->key->lit = NEW(lit_node);
	AS((yyval), associtem_node)->key->lit->type = LIT_STRING;
	AS((yyval), associtem_node)->key->lit->str = (yyvsp[-2]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 660 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 661 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2726 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2730 "parser.tab.c" /* yacc.c:1646  */
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
#line 664 "parser.y" /* yacc.c:1906  */


// TODO
