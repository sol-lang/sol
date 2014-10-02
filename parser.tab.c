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
    IDENT = 270,
    INT = 271,
    FLOAT = 272,
    STRING = 273,
    PLUS = 274,
    MINUS = 275,
    STAR = 276,
    SLASH = 277,
    DSTAR = 278,
    BAND = 279,
    BOR = 280,
    BXOR = 281,
    BNOT = 282,
    LAND = 283,
    LOR = 284,
    LNOT = 285,
    ASSIGN = 286,
    ASSIGNPLUS = 287,
    ASSIGNMINUS = 288,
    ASSIGNSTAR = 289,
    ASSIGNSLASH = 290,
    ASSIGNDSTAR = 291,
    ASSIGNBAND = 292,
    ASSIGNBOR = 293,
    ASSIGNBXOR = 294,
    EQUAL = 295,
    LESS = 296,
    GREATER = 297,
    LESSEQ = 298,
    GREATEREQ = 299,
    LBRACE = 300,
    RBRACE = 301,
    LPAREN = 302,
    RPAREN = 303,
    LBRACKET = 304,
    RBRACKET = 305,
    DOT = 306,
    COLON = 307,
    SEMICOLON = 308,
    COMMA = 309
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

#line 182 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   562

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    49,    58,    70,    71,    78,    85,
      92,    99,   106,   113,   120,   127,   140,   153,   166,   179,
     192,   205,   218,   231,   244,   248,   249,   250,   254,   255,
     259,   260,   261,   262,   263,   264,   268,   269,   270,   274,
     275,   276,   280,   281,   285,   286,   287,   288,   292,   293,
     297,   298,   302,   310,   318,   322,   323,   334,   338,   339,
     353,   354,   358,   359,   360,   361,   365,   366,   367,   371,
     375,   376,   381,   390,   402,   403,   408,   417,   429,   430,
     435,   444,   456,   461
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "WHILE", "FOR",
  "IN", "DO", "FUNC", "RETURN", "BREAK", "CONTINUE", "END", "IDENT", "INT",
  "FLOAT", "STRING", "PLUS", "MINUS", "STAR", "SLASH", "DSTAR", "BAND",
  "BOR", "BXOR", "BNOT", "LAND", "LOR", "LNOT", "ASSIGN", "ASSIGNPLUS",
  "ASSIGNMINUS", "ASSIGNSTAR", "ASSIGNSLASH", "ASSIGNDSTAR", "ASSIGNBAND",
  "ASSIGNBOR", "ASSIGNBXOR", "EQUAL", "LESS", "GREATER", "LESSEQ",
  "GREATEREQ", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "DOT", "COLON", "SEMICOLON", "COMMA", "$accept", "program",
  "stmt", "stmt_list", "expr", "logic_expr", "ulogic_expr", "rel_expr",
  "term_expr", "factor_expr", "power_expr", "binary_expr", "ubinary_expr",
  "call_expr", "funcdecl_expr", "index_expr", "ex_index_expr", "ref_expr",
  "lit_expr", "gen_expr", "paren_expr", "expr_list", "ident_list",
  "assoc_list", "assoc_item", YY_NULLPTR
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
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -56

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     380,   437,   437,    -5,    -8,   437,   -56,   -56,   196,   -56,
     -56,   -56,   437,   437,   -12,   437,   437,    13,   335,   380,
     -33,    93,   -56,    68,    21,   129,    -3,   -56,   123,   -17,
     -56,   -56,   266,   -56,   -56,   -56,   -56,     2,     8,    30,
       7,    51,   -33,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   -33,   -17,   -20,    61,   437,    47,   -56,   -26,
     -33,   396,   -56,   -56,   335,   335,   437,    80,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   380,   380,   437,    51,   -56,     4,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   437,   -23,
     -56,   -12,   -56,   -56,   -56,   437,   -33,   107,   336,    95,
      95,    76,    76,    76,    76,    76,   502,   502,   485,   485,
     468,   123,   123,   123,   421,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   125,   170,    12,    49,   -56,   380,
      85,   -33,    71,   -56,   -33,   523,   -56,   380,   -56,   -56,
     380,   380,   195,   -56,   437,   240,   265,   310,   -56,   -33,
     -56,   -56,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     9,    10,    11,    70,    72,
      73,    74,     0,     0,    88,     0,    80,     0,     2,    13,
       3,    34,    37,    39,    45,    48,    51,    53,    57,    59,
      61,    64,     0,    67,    71,    75,    78,     0,     0,     0,
       0,    84,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    38,     0,     0,     0,    89,     0,
      81,     0,     1,    12,    15,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
      77,     0,    90,    79,    76,     0,    82,     0,    66,    35,
      36,    40,    41,    42,    43,    44,    46,    47,    49,    50,
      52,    54,    55,    56,     0,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,     0,     0,    86,     0,
       0,    93,     0,    91,    83,    65,    60,     0,     4,     6,
       0,     0,     0,    87,     0,     0,     0,     0,    63,    92,
       5,     7,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,     5,   -56,    -1,    99,   100,   -38,   114,   115,
      27,   -56,    79,   103,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,    43,    33,   -56,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    17,    64,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    61,    98,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    38,   112,    55,    42,    18,    93,    40,   -37,   -37,
      39,    52,    52,    62,    59,    60,    66,    94,    67,   148,
      79,   160,   113,    66,    65,    67,    66,   152,    67,   -37,
      83,   -37,   121,   122,   123,   124,   125,    56,    95,    41,
      75,    76,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    66,   149,    67,    96,   109,   153,    66,   150,    67,
     116,    66,    55,    67,   148,   117,    97,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    60,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   108,   110,   146,   118,    56,   161,   144,   145,
     163,   111,   164,   150,   -39,   -39,   130,   151,    70,    71,
      72,    73,    74,    54,   154,    53,    70,    71,    72,    73,
      74,    68,    69,    68,    69,   -39,   134,   -39,     1,   147,
     157,     2,     3,   116,     0,     4,     5,     6,     7,   158,
       8,     9,    10,    11,   -34,     0,   -34,    80,    81,    82,
      77,    78,    12,     0,   162,    13,    66,   155,    67,   131,
     132,   133,   165,   169,     0,   166,   167,   119,   120,     0,
      14,     0,    15,     1,    16,     0,     2,     3,    63,     0,
       4,     5,     6,     7,   159,     8,     9,    10,    11,   126,
     127,     0,   128,   129,     0,     0,     0,    12,     1,     0,
      13,     2,     3,     0,     0,     4,     5,     6,     7,   168,
       8,     9,    10,    11,     0,    14,     0,    15,     0,    16,
       0,     0,    12,    63,     0,    13,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
      14,     0,    15,     1,    16,     0,     2,     3,    63,     0,
       4,     5,     6,     7,   170,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     1,     0,
      13,     2,     3,     0,     0,     4,     5,     6,     7,   171,
       8,     9,    10,    11,     0,    14,     0,    15,     0,    16,
       0,     0,    12,    63,     0,    13,     0,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,     0,
      14,     0,    15,     1,    16,     0,     2,     3,    63,     0,
       4,     5,     6,     7,   172,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     1,     0,
      13,     2,     3,     0,     0,     4,     5,     6,     7,     0,
       8,     9,    10,    11,     0,    14,     0,    15,     0,    16,
       0,     0,    12,    63,     0,    13,     0,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,
      14,     0,    15,     1,    16,     0,     2,     3,    63,     0,
       4,     5,     6,     7,     0,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     4,    12,     0,     0,
      13,     8,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    14,    13,    15,     0,    16,
       0,     4,     0,     0,     0,     0,     8,     9,    10,    11,
       0,    14,     0,    15,     0,    16,   114,     4,    12,     0,
     115,    13,     8,     9,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    14,    13,    15,   156,
      16,     0,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,    14,     0,    15,     0,    16,   -51,   -51,   -51,
     -51,    79,     0,     0,     0,     0,   -51,   -51,     0,     0,
       0,     0,     0,     0,   -48,   -48,    77,    78,   -51,   -51,
     -51,   -51,   -51,   -48,   -48,     0,     0,   -51,     0,   -51,
       0,    75,    76,     0,     0,   -48,   -48,   -48,   -48,   -48,
     -45,   -45,     0,     0,   -48,     0,   -48,     0,     0,     0,
       0,     0,   -45,   -45,   -45,   -45,   -45,     0,     0,     0,
       0,   -45,     0,   -45,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68
};

static const yytype_int16 yycheck[] =
{
       1,     2,    57,    15,     5,     0,     4,    15,    28,    29,
      15,    12,    13,     0,    15,    16,    49,     9,    51,    15,
      23,     9,    48,    49,    19,    51,    49,    50,    51,    49,
      47,    51,    70,    71,    72,    73,    74,    49,     8,    47,
      19,    20,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    49,    48,    51,    47,    56,   111,    49,    54,    51,
      61,    49,    15,    51,    15,    66,    15,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    31,    46,    95,    15,    49,    48,    93,    94,
      15,    54,    31,    54,    28,    29,    79,   108,    40,    41,
      42,    43,    44,    13,   115,    12,    40,    41,    42,    43,
      44,    28,    29,    28,    29,    49,    83,    51,     3,    96,
       5,     6,     7,   134,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    49,    -1,    51,    24,    25,    26,
      21,    22,    27,    -1,   149,    30,    49,    50,    51,    80,
      81,    82,   157,   164,    -1,   160,   161,    68,    69,    -1,
      45,    -1,    47,     3,    49,    -1,     6,     7,    53,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    75,
      76,    -1,    77,    78,    -1,    -1,    -1,    27,     3,    -1,
      30,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    45,    -1,    47,    -1,    49,
      -1,    -1,    27,    53,    -1,    30,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      45,    -1,    47,     3,    49,    -1,     6,     7,    53,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,     3,    -1,
      30,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    45,    -1,    47,    -1,    49,
      -1,    -1,    27,    53,    -1,    30,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      45,    -1,    47,     3,    49,    -1,     6,     7,    53,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,     3,    -1,
      30,     6,     7,    -1,    -1,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    -1,    45,    -1,    47,    -1,    49,
      -1,    -1,    27,    53,    -1,    30,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      45,    -1,    47,     3,    49,    -1,     6,     7,    53,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    27,    -1,    -1,
      30,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    45,    30,    47,    -1,    49,
      -1,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    45,    -1,    47,    -1,    49,    50,    10,    27,    -1,
      54,    30,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    45,    30,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    -1,    49,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    40,    41,
      42,    43,    44,    28,    29,    -1,    -1,    49,    -1,    51,
      -1,    19,    20,    -1,    -1,    40,    41,    42,    43,    44,
      28,    29,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    31,    32,    33,    34,    35,    36,
      37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    10,    11,    12,    13,    15,    16,
      17,    18,    27,    30,    45,    47,    49,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    59,    59,    15,
      15,    47,    59,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    59,    68,    61,    15,    49,    78,    79,    59,
      59,    76,     0,    53,    57,    57,    49,    51,    28,    29,
      40,    41,    42,    43,    44,    19,    20,    21,    22,    23,
      24,    25,    26,    47,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     4,     9,     8,    47,    15,    77,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    31,    59,
      46,    54,    79,    48,    50,    54,    59,    59,    15,    60,
      60,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    67,    67,    67,    76,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    57,    57,    59,    77,    15,    48,
      54,    59,    50,    79,    59,    50,    48,     5,    14,    14,
       9,    48,    57,    15,    31,    57,    57,    57,    14,    59,
      14,    14,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    64,
      64,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    74,    74,    75,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     5,     7,     5,     7,     2,     1,
       1,     1,     2,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     2,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     3,     1,     2,     1,
       4,     1,     7,     6,     1,     4,     3,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       0,     1,     2,     3,     0,     1,     2,     3,     0,     1,
       2,     3,     5,     3
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
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 35 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_EXPR; AS_ST((yyval))->expr = (yyvsp[0]); }
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 36 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[-3]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[-1]); AS_ST((yyval))->ifelse->iffalse = NULL; }
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 37 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[-5]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[-3]); AS_ST((yyval))->ifelse->iffalse = (yyvsp[-1]); }
#line 1482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 38 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_LOOP; AS_ST((yyval))->loop = NEW(loop_node); AS_ST((yyval))->loop->cond = (yyvsp[-3]); AS_ST((yyval))->loop->loop = (yyvsp[-1]); }
#line 1488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 39 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_ITER; AS_ST((yyval))->iter = NEW(iter_node); AS_ST((yyval))->iter->var = strdup((yyvsp[-5])); AS_ST((yyval))->iter->iter = (yyvsp[-3]); AS_ST((yyval))->iter->loop = (yyvsp[-1]); }
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 40 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = (yyvsp[0]); }
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 41 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = NULL; }
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 42 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_BREAK; }
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 43 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_CONT; }
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 44 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 45 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 49 "parser.y" /* yacc.c:1646  */
    {
	stmtlist_node *cur = AS_ST((yyvsp[-1]))->stmtlist;
	while(cur->next) cur = cur->next;
	cur->next = NEW(stmtlist_node);
	cur = cur->next;
	cur->stmt = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
  }
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_ST();
	AS_ST((yyval))->type = ST_LIST;
	AS_ST((yyval))->stmtlist = NEW(stmtlist_node);
	AS_ST((yyval))->stmtlist->stmt = (yyvsp[-1]);
	AS_ST((yyval))->stmtlist->next = NEW(stmtlist_node);
	AS_ST((yyval))->stmtlist->next->stmt = (yyvsp[0]);
	AS_ST((yyval))->stmtlist->next->next = NULL;
  }
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_ASSIGN; AS_EX((yyval))->assign = NEW(assign_node); AS_EX((yyval))->assign->ident = (yyvsp[-2]); AS_EX((yyval))->assign->value = (yyvsp[0]); }
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_ADD, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 78 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_SUB, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 85 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_MUL, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 92 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
    MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_DIV, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_POW, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BAND, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 113 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[-2]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BXOR, (yyvsp[-2]), (yyvsp[0]));
  }
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 127 "parser.y" /* yacc.c:1646  */
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
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 140 "parser.y" /* yacc.c:1646  */
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
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "parser.y" /* yacc.c:1646  */
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
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 166 "parser.y" /* yacc.c:1646  */
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
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 179 "parser.y" /* yacc.c:1646  */
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
#line 1750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 192 "parser.y" /* yacc.c:1646  */
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
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 205 "parser.y" /* yacc.c:1646  */
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
#line 1786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 218 "parser.y" /* yacc.c:1646  */
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
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 231 "parser.y" /* yacc.c:1646  */
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
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 1852 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_EQUAL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESS; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATER; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESSEQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATEREQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1888 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_ADD; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_SUB; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MUL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_DIV; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_POW; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1942 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1954 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BXOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_BNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 1972 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1978 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_CALL; AS_EX((yyval))->call = NEW(call_node); AS_EX((yyval))->call->expr = (yyvsp[-3]); AS_EX((yyval))->call->args = (yyvsp[-1]); }
#line 1984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 302 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[-5]);
	AS_EX((yyval))->funcdecl->args = (yyvsp[-3]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2003 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 310 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->args = (yyvsp[-3]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 323 "parser.y" /* yacc.c:1646  */
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
#line 2044 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 339 "parser.y" /* yacc.c:1646  */
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
#line 2072 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 353 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_REF; AS_EX((yyval))->ref = NEW(ref_node); AS_EX((yyval))->ref->ident = (yyvsp[0]); }
#line 2078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2084 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = *AS((yyvsp[0]), long); free((yyvsp[0])); }
#line 2090 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 359 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_FLOAT; AS_EX((yyval))->lit->fval = *AS((yyvsp[0]), double); free((yyvsp[0])); }
#line 2096 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_STRING; AS_EX((yyval))->lit->str = (yyvsp[0]); }
#line 2102 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 361 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2108 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LISTGEN; AS_EX((yyval))->listgen = NEW(listgen_node); AS_EX((yyval))->listgen->list = (yyvsp[-1]); }
#line 2114 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_MAPGEN; AS_EX((yyval))->mapgen = NEW(mapgen_node); AS_EX((yyval))->mapgen->map = (yyvsp[-1]); }
#line 2120 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2126 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 371 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2132 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 375 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2138 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 376 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(exprlist_node);
	AS((yyval), exprlist_node)->expr = (yyvsp[0]);
	AS((yyval), exprlist_node)->next = NULL;
}
#line 2148 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 381 "parser.y" /* yacc.c:1646  */
    {
	exprlist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 390 "parser.y" /* yacc.c:1646  */
    {
	exprlist_node *cur = (yyvsp[-2]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-2]);
}
#line 2176 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 402 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2182 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 403 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(identlist_node);
	AS((yyval), identlist_node)->ident = (yyvsp[0]);
	AS((yyval), identlist_node)->next = NULL;
}
#line 2192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 408 "parser.y" /* yacc.c:1646  */
    {
	identlist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2206 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 417 "parser.y" /* yacc.c:1646  */
    {
	identlist_node *cur = (yyvsp[-2]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-2]);
}
#line 2220 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 429 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2226 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 430 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(assoclist_node);
	AS((yyval), assoclist_node)->item = (yyvsp[0]);
	AS((yyval), assoclist_node)->next = NULL;
}
#line 2236 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 435 "parser.y" /* yacc.c:1646  */
    {
	assoclist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2250 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 444 "parser.y" /* yacc.c:1646  */
    {
	assoclist_node *cur = (yyvsp[-2]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-2]);
}
#line 2264 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 456 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = (yyvsp[-3]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2274 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 461 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = NEW_EX();
	AS((yyval), associtem_node)->key->type = EX_LIT;
	AS((yyval), associtem_node)->key->lit = NEW(lit_node);
	AS((yyval), associtem_node)->key->lit->type = LIT_STRING;
	AS((yyval), associtem_node)->key->lit->str = (yyvsp[-2]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2288 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2292 "parser.tab.c" /* yacc.c:1646  */
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
#line 472 "parser.y" /* yacc.c:1906  */


// TODO
