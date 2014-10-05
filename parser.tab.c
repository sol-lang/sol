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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   649

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       0,    31,    31,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    49,    58,    70,    71,    78,    85,
      92,    99,   106,   113,   120,   127,   140,   153,   166,   179,
     192,   205,   218,   231,   244,   248,   249,   250,   254,   255,
     259,   260,   261,   262,   263,   264,   268,   269,   270,   274,
     275,   276,   280,   281,   285,   286,   287,   288,   289,   290,
     294,   295,   299,   300,   304,   305,   322,   326,   334,   342,
     346,   347,   351,   352,   363,   367,   368,   382,   383,   387,
     388,   389,   390,   391,   392,   396,   397,   398,   402,   406,
     407,   412,   421,   433,   434,   439,   448,   460,   461,   466,
     475,   487,   492
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
  "POUND", "$accept", "program", "stmt", "stmt_list", "expr", "logic_expr",
  "ulogic_expr", "rel_expr", "term_expr", "factor_expr", "power_expr",
  "binary_expr", "ubinary_expr", "ulen_expr", "call_expr", "funcdecl_expr",
  "opt_stmt", "index_expr", "ex_index_expr", "ref_expr", "lit_expr",
  "gen_expr", "paren_expr", "expr_list", "ident_list", "assoc_list",
  "assoc_item", YY_NULLPTR
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

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -77

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     365,   110,   110,    -7,    -9,   110,   -89,   -89,   -89,   215,
     -89,   -89,   -89,    -4,   110,   110,   -10,   110,   110,   110,
      19,   342,   365,   -19,    10,   -89,   -13,    67,   124,    13,
     107,   -89,   -89,   -40,   -89,   -89,   292,   -89,   -89,   -89,
     -89,     4,     5,    38,    14,    44,   -19,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   -89,   -19,   455,    15,
      48,   110,    91,   -89,    31,   -19,    58,   490,   -89,   -89,
     342,   342,   110,    74,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,    76,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   365,   365,   110,    44,   -89,    27,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   110,    69,   -89,
     -10,   -89,   -89,   -89,   110,   -19,   130,   418,    83,    83,
     -18,   -18,   -18,   -18,   -18,   595,   595,   565,   565,   560,
     525,   525,   525,   525,   525,   391,    55,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   188,   211,    11,    93,
     -89,   365,    98,   -19,   117,   -89,   -19,   454,   -89,   110,
     365,   -89,   -89,   365,   365,   342,   116,   -89,   110,   416,
     265,   288,   122,   -89,   -19,   -89,   -89,   -89,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     9,    10,    11,    83,    77,
      79,    81,    82,     0,     0,     0,    97,     0,    89,     0,
       0,     2,    13,     3,    34,    37,    39,    45,    48,    51,
      53,    59,    61,    63,    66,    69,     0,    74,    78,    84,
      87,     0,     0,     0,     0,    93,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,    60,    38,
       0,     0,     0,    98,     0,    90,     0,    62,     1,    12,
      15,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,    86,
       0,    99,    88,    85,     0,    91,     0,    73,    35,    36,
      40,    41,    42,    43,    44,    46,    47,    49,    50,    52,
      54,    55,    56,    58,    57,     0,     0,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,     0,     0,
      95,    71,     0,   102,     0,   100,    92,    72,    64,    89,
       0,     4,     6,     0,    71,    70,     0,    96,     0,     0,
       0,     0,     0,    68,   101,    65,     5,     7,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,    16,   -89,     0,    77,   127,    87,    90,   104,
      54,   373,   141,   140,   -89,   -89,     2,   -89,   -89,   -89,
     -89,   -89,   -89,   -88,    80,   -89,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    70,    22,    57,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   176,    35,    36,    37,
      38,    39,    40,    66,   107,    62,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    41,    42,   145,   121,    46,    60,    44,   102,    43,
      91,   -39,   -39,    56,   103,    92,    21,    64,    65,    68,
     173,    23,    23,    76,    77,    78,    79,    80,    76,    77,
      78,    79,    80,    72,   -39,    73,   -39,    85,    71,    74,
      75,    45,    61,   160,   -37,   -37,   104,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    72,    72,    73,    73,
     106,   118,   165,    72,   105,    73,   125,   -37,     4,   -37,
      23,    23,   126,     8,     9,    10,    11,    12,   161,    13,
     117,   179,   122,    72,   162,    73,    14,    81,    82,    15,
     127,    65,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    23,    23,   158,   169,    16,    60,    17,   160,
      18,   123,    74,    75,   177,   124,    19,   163,   156,   157,
       4,    72,   164,    73,   166,     8,     9,    10,    11,    12,
     183,    13,    86,    87,    88,   -34,   188,   -34,    14,   139,
     119,    15,    59,    61,   174,   125,    83,    84,   120,   178,
     162,   128,   129,    89,    90,    58,    23,    23,    16,    67,
      17,    23,    18,   130,   131,   132,   133,   134,    19,    65,
      23,   135,   136,    23,    23,    23,   182,   175,   184,   125,
      23,    23,    72,   167,    73,   159,   180,   137,   138,   181,
     175,     1,     0,   170,     2,     3,     0,     0,     4,     5,
       6,     7,   171,     8,     9,    10,    11,    12,     0,    13,
       0,     0,     0,     0,     1,     0,    14,     2,     3,    15,
       0,     4,     5,     6,     7,   172,     8,     9,    10,    11,
      12,     0,    13,     0,     0,     0,    16,     0,    17,    14,
      18,     0,    15,     0,    69,     0,    19,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     0,     0,    16,
       0,    17,     0,    18,     0,     0,     0,    69,     1,    19,
       0,     2,     3,     0,     0,     4,     5,     6,     7,   186,
       8,     9,    10,    11,    12,     0,    13,     0,     0,     0,
       0,     1,     0,    14,     2,     3,    15,     0,     4,     5,
       6,     7,   187,     8,     9,    10,    11,    12,     0,    13,
       0,     0,     0,    16,     0,    17,    14,    18,     0,    15,
       0,    69,     0,    19,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,    16,     0,    17,     0,
      18,     0,     0,     0,    69,     1,    19,     0,     2,     3,
       0,     0,     4,     5,     6,     7,     0,     8,     9,    10,
      11,    12,     0,    13,     0,     0,     0,     0,     1,     0,
      14,     2,     3,    15,     0,     4,     5,     6,     7,     0,
       8,     9,    10,    11,    12,     0,    13,     0,     0,     0,
      16,     0,    17,    14,    18,     0,    15,     0,    69,     0,
      19,     4,     0,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    16,     0,    17,     0,    18,     0,    14,
       0,     0,    15,    19,     0,     0,     4,     0,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,     0,    16,
       0,    17,   168,    18,    14,     0,     0,    15,   124,    19,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   140,
     141,   142,   143,   144,    16,     0,    17,   185,    18,     0,
       0,     0,     0,   124,    19,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,     0,   -59,   -59,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,     0,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,     0,     0,     0,     0,   -59,     0,   -59,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,     0,   -61,
     -61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -61,   -61,   -61,   -61,   -61,   -61,   -61,     0,     0,
       0,     0,   -61,     0,   -61,   -53,   -53,   -53,   -53,   -53,
      86,    87,    88,     0,   -53,   -53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -53,   -53,   -53,   -53,
     -53,    89,    90,     0,     0,     0,     0,   -53,     0,   -53,
     -51,   -51,   -51,   -51,    85,   -48,   -48,    83,    84,   -51,
     -51,     0,     0,     0,   -48,   -48,     0,     0,     0,     0,
       0,   -51,   -51,   -51,   -51,   -51,   -48,   -48,   -48,   -48,
     -48,     0,   -51,     0,   -51,    81,    82,   -48,     0,   -48,
       0,     0,     0,     0,   -45,   -45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -45,   -45,   -45,   -45,
     -45,     0,     0,     0,     0,     0,     0,   -45,     0,   -45
};

static const yytype_int16 yycheck[] =
{
       0,     1,     2,    91,    62,     5,    16,    16,     4,    16,
      50,    29,    30,    17,     9,    55,     0,    17,    18,     0,
       9,    21,    22,    41,    42,    43,    44,    45,    41,    42,
      43,    44,    45,    52,    52,    54,    54,    24,    22,    29,
      30,    50,    52,    16,    29,    30,     8,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    52,    52,    54,    54,
      16,    61,   120,    52,    50,    54,    66,    52,    10,    54,
      70,    71,    72,    15,    16,    17,    18,    19,    51,    21,
      32,   169,    51,    52,    57,    54,    28,    20,    21,    31,
      16,    91,    16,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    50,    48,    16,    50,    16,
      52,    53,    29,    30,    16,    57,    58,   117,   102,   103,
      10,    52,    53,    54,   124,    15,    16,    17,    18,    19,
      14,    21,    25,    26,    27,    52,    14,    54,    28,    85,
      49,    31,    15,    52,    51,   145,    22,    23,    57,    32,
      57,    74,    75,    46,    47,    14,   156,   157,    48,    19,
      50,   161,    52,    76,    77,    78,    79,    80,    58,   169,
     170,    81,    82,   173,   174,   175,   174,   161,   178,   179,
     180,   181,    52,    53,    54,   105,   170,    83,    84,   173,
     174,     3,    -1,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    -1,    -1,     3,    -1,    28,     6,     7,    31,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    -1,    48,    -1,    50,    28,
      52,    -1,    31,    -1,    56,    -1,    58,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    48,
      -1,    50,    -1,    52,    -1,    -1,    -1,    56,     3,    58,
      -1,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,     3,    -1,    28,     6,     7,    31,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    -1,    48,    -1,    50,    28,    52,    -1,    31,
      -1,    56,    -1,    58,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    48,    -1,    50,    -1,
      52,    -1,    -1,    -1,    56,     3,    58,    -1,     6,     7,
      -1,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    -1,    21,    -1,    -1,    -1,    -1,     3,    -1,
      28,     6,     7,    31,    -1,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      48,    -1,    50,    28,    52,    -1,    31,    -1,    56,    -1,
      58,    10,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    -1,    21,    48,    -1,    50,    -1,    52,    -1,    28,
      -1,    -1,    31,    58,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    -1,    21,    -1,    48,
      -1,    50,    51,    52,    28,    -1,    -1,    31,    57,    58,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    86,
      87,    88,    89,    90,    48,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    57,    58,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,
      20,    21,    22,    23,    24,    20,    21,    22,    23,    29,
      30,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    41,    42,    43,    44,
      45,    -1,    52,    -1,    54,    20,    21,    52,    -1,    54,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    10,    11,    12,    13,    15,    16,
      17,    18,    19,    21,    28,    31,    48,    50,    52,    58,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    76,    77,    78,    79,    80,
      81,    63,    63,    16,    16,    50,    63,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    17,    63,    71,    65,
      16,    52,    84,    85,    63,    63,    82,    72,     0,    56,
      61,    61,    52,    54,    29,    30,    41,    42,    43,    44,
      45,    20,    21,    22,    23,    24,    25,    26,    27,    46,
      47,    50,    55,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     4,     9,     8,    50,    16,    83,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    32,    63,    49,
      57,    85,    51,    53,    57,    63,    63,    16,    64,    64,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      70,    70,    70,    70,    70,    82,    16,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    61,    61,    63,    83,
      16,    51,    57,    63,    53,    85,    63,    53,    51,    50,
       5,    14,    14,     9,    51,    61,    75,    16,    32,    82,
      61,    61,    75,    14,    63,    51,    14,    14,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    74,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    81,    82,
      82,    82,    82,    83,    83,    83,    83,    84,    84,    84,
      84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     5,     7,     5,     7,     2,     1,
       1,     1,     2,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     2,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     1,
       2,     1,     2,     1,     4,     6,     1,     7,     6,     1,
       1,     0,     4,     3,     1,     4,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     3,     3,     1,     3,     0,
       1,     2,     3,     0,     1,     2,     3,     0,     1,     2,
       3,     5,     3
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
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 35 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_EXPR; AS_ST((yyval))->expr = (yyvsp[0]); }
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 36 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[-3]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[-1]); AS_ST((yyval))->ifelse->iffalse = NULL; }
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 37 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[-5]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[-3]); AS_ST((yyval))->ifelse->iffalse = (yyvsp[-1]); }
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 38 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_LOOP; AS_ST((yyval))->loop = NEW(loop_node); AS_ST((yyval))->loop->cond = (yyvsp[-3]); AS_ST((yyval))->loop->loop = (yyvsp[-1]); }
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 39 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_ITER; AS_ST((yyval))->iter = NEW(iter_node); AS_ST((yyval))->iter->var = (yyvsp[-5]); AS_ST((yyval))->iter->iter = (yyvsp[-3]); AS_ST((yyval))->iter->loop = (yyvsp[-1]); }
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 40 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = (yyvsp[0]); }
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 41 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = NULL; }
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 42 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_BREAK; }
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 43 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_CONT; }
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 44 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 45 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1558 "parser.tab.c" /* yacc.c:1646  */
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
#line 1572 "parser.tab.c" /* yacc.c:1646  */
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
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_ASSIGN; AS_EX((yyval))->assign = NEW(assign_node); AS_EX((yyval))->assign->ident = (yyvsp[-2]); AS_EX((yyval))->assign->value = (yyvsp[0]); }
#line 1592 "parser.tab.c" /* yacc.c:1646  */
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
#line 1604 "parser.tab.c" /* yacc.c:1646  */
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
#line 1616 "parser.tab.c" /* yacc.c:1646  */
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
#line 1628 "parser.tab.c" /* yacc.c:1646  */
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
#line 1640 "parser.tab.c" /* yacc.c:1646  */
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
#line 1652 "parser.tab.c" /* yacc.c:1646  */
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
#line 1664 "parser.tab.c" /* yacc.c:1646  */
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
#line 1676 "parser.tab.c" /* yacc.c:1646  */
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
#line 1688 "parser.tab.c" /* yacc.c:1646  */
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
#line 1706 "parser.tab.c" /* yacc.c:1646  */
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
#line 1724 "parser.tab.c" /* yacc.c:1646  */
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
#line 1742 "parser.tab.c" /* yacc.c:1646  */
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
#line 1760 "parser.tab.c" /* yacc.c:1646  */
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
#line 1778 "parser.tab.c" /* yacc.c:1646  */
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
#line 1796 "parser.tab.c" /* yacc.c:1646  */
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
#line 1814 "parser.tab.c" /* yacc.c:1646  */
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
#line 1832 "parser.tab.c" /* yacc.c:1646  */
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
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_EQUAL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESS; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATER; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESSEQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATEREQ; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_ADD; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_SUB; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MUL; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_DIV; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_POW; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BAND; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BXOR; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_RSHIFT; AS_EX((yyval))->binop->left = (yyvsp[-2]); AS_EX((yyval))->binop->right = (yyvsp[0]); }
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_BNOT; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LEN; AS_EX((yyval))->unop->expr = (yyvsp[0]); }
#line 2024 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 304 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_CALL; AS_EX((yyval))->call = NEW(call_node); AS_EX((yyval))->call->expr = (yyvsp[-3]); AS_EX((yyval))->call->args = (yyvsp[-1]); }
#line 2036 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 305 "parser.y" /* yacc.c:1646  */
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
#line 2058 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2064 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 326 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[-5]);
	AS_EX((yyval))->funcdecl->args = (yyvsp[-3]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 334 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->args = (yyvsp[-3]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[-1]);
}
#line 2090 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 342 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2096 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2102 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2108 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 351 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2114 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 352 "parser.y" /* yacc.c:1646  */
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
#line 2130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[-3]); AS_EX((yyval))->index->index = (yyvsp[-1]); }
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 368 "parser.y" /* yacc.c:1646  */
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
#line 2158 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 382 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_REF; AS_EX((yyval))->ref = NEW(ref_node); AS_EX((yyval))->ref->ident = (yyvsp[0]); }
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 383 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2170 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = *AS((yyvsp[0]), long); free((yyvsp[0])); }
#line 2176 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 388 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = -(*AS((yyvsp[0]), long)); free((yyvsp[0])); }
#line 2182 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 389 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_FLOAT; AS_EX((yyval))->lit->fval = *AS((yyvsp[0]), double); free((yyvsp[0])); }
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 390 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_STRING; AS_EX((yyval))->lit->str = (yyvsp[0]); }
#line 2194 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 391 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_NONE; }
#line 2200 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 392 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2206 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 396 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LISTGEN; AS_EX((yyval))->listgen = NEW(listgen_node); AS_EX((yyval))->listgen->list = (yyvsp[-1]); }
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 397 "parser.y" /* yacc.c:1646  */
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_MAPGEN; AS_EX((yyval))->mapgen = NEW(mapgen_node); AS_EX((yyval))->mapgen->map = (yyvsp[-1]); }
#line 2218 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 398 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 402 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2230 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 406 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2236 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 407 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(exprlist_node);
	AS((yyval), exprlist_node)->expr = (yyvsp[0]);
	AS((yyval), exprlist_node)->next = NULL;
}
#line 2246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 412 "parser.y" /* yacc.c:1646  */
    {
	exprlist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2260 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 421 "parser.y" /* yacc.c:1646  */
    {
	exprlist_node *cur = (yyvsp[-2]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-2]);
}
#line 2274 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 433 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 434 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(identlist_node);
	AS((yyval), identlist_node)->ident = (yyvsp[0]);
	AS((yyval), identlist_node)->next = NULL;
}
#line 2290 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 439 "parser.y" /* yacc.c:1646  */
    {
	identlist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 448 "parser.y" /* yacc.c:1646  */
    {
	identlist_node *cur = (yyvsp[-2]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-2]);
}
#line 2318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 460 "parser.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 461 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(assoclist_node);
	AS((yyval), assoclist_node)->item = (yyvsp[0]);
	AS((yyval), assoclist_node)->next = NULL;
}
#line 2334 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 466 "parser.y" /* yacc.c:1646  */
    {
	assoclist_node *cur = (yyvsp[-1]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-1]);
}
#line 2348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 475 "parser.y" /* yacc.c:1646  */
    {
	assoclist_node *cur = (yyvsp[-2]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = (yyvsp[0]);
	cur->next = NULL;
	(yyval) = (yyvsp[-2]);
}
#line 2362 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 487 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = (yyvsp[-3]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 492 "parser.y" /* yacc.c:1646  */
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = NEW_EX();
	AS((yyval), associtem_node)->key->type = EX_LIT;
	AS((yyval), associtem_node)->key->lit = NEW(lit_node);
	AS((yyval), associtem_node)->key->lit->type = LIT_STRING;
	AS((yyval), associtem_node)->key->lit->str = (yyvsp[-2]);
	AS((yyval), associtem_node)->value = (yyvsp[0]);
}
#line 2386 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2390 "parser.tab.c" /* yacc.c:1646  */
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
#line 503 "parser.y" /* yacc.c:1906  */


// TODO
