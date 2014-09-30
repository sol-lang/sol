/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include "sol.h"
#include "ast.h"

#include <string.h>

#define YYSTYPE void *


/* Line 371 of yacc.c  */
#line 78 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     ELSE = 260,
     WHILE = 261,
     FOR = 262,
     IN = 263,
     DO = 264,
     FUNC = 265,
     END = 266,
     IDENT = 267,
     INT = 268,
     FLOAT = 269,
     STRING = 270,
     PLUS = 271,
     MINUS = 272,
     STAR = 273,
     SLASH = 274,
     DSTAR = 275,
     BAND = 276,
     BOR = 277,
     BXOR = 278,
     BNOT = 279,
     LAND = 280,
     LOR = 281,
     LNOT = 282,
     ASSIGN = 283,
     ASSIGNPLUS = 284,
     ASSIGNMINUS = 285,
     ASSIGNSTAR = 286,
     ASSIGNSLASH = 287,
     ASSIGNDSTAR = 288,
     ASSIGNBAND = 289,
     ASSIGNBOR = 290,
     ASSIGNBXOR = 291,
     EQUAL = 292,
     LESS = 293,
     GREATER = 294,
     LESSEQ = 295,
     GREATEREQ = 296,
     LBRACE = 297,
     RBRACE = 298,
     LPAREN = 299,
     RPAREN = 300,
     LBRACKET = 301,
     RBRACKET = 302,
     DOT = 303,
     COLON = 304,
     SEMICOLON = 305,
     COMMA = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (stmt_node **program);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 195 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    13,    21,    27,    35,    38,
      40,    43,    46,    50,    54,    58,    62,    66,    70,    74,
      78,    82,    89,    96,   103,   110,   117,   124,   131,   138,
     145,   147,   151,   155,   157,   160,   162,   166,   170,   174,
     178,   182,   184,   188,   192,   194,   198,   202,   204,   208,
     210,   214,   218,   222,   224,   227,   229,   234,   236,   244,
     251,   253,   255,   257,   262,   264,   266,   268,   270,   272,
     276,   280,   282,   286,   287,   289,   292,   296,   297,   299,
     302,   306,   307,   309,   312,   316,   322
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    56,    -1,     3,    56,     4,
      54,    11,    -1,     3,    56,     4,    54,     5,    54,    11,
      -1,     6,    56,     9,    54,    11,    -1,     7,    12,     8,
      56,     9,    54,    11,    -1,    54,    50,    -1,    55,    -1,
      54,    54,    -1,    55,    54,    -1,    12,    28,    56,    -1,
      12,    29,    56,    -1,    12,    30,    56,    -1,    12,    31,
      56,    -1,    12,    32,    56,    -1,    12,    33,    56,    -1,
      12,    34,    56,    -1,    12,    35,    56,    -1,    12,    36,
      56,    -1,    56,    46,    56,    47,    28,    56,    -1,    56,
      46,    56,    47,    29,    56,    -1,    56,    46,    56,    47,
      30,    56,    -1,    56,    46,    56,    47,    31,    56,    -1,
      56,    46,    56,    47,    32,    56,    -1,    56,    46,    56,
      47,    33,    56,    -1,    56,    46,    56,    47,    34,    56,
      -1,    56,    46,    56,    47,    35,    56,    -1,    56,    46,
      56,    47,    36,    56,    -1,    57,    -1,    57,    25,    57,
      -1,    57,    26,    57,    -1,    58,    -1,    27,    58,    -1,
      59,    -1,    59,    37,    59,    -1,    59,    38,    59,    -1,
      59,    39,    59,    -1,    59,    40,    59,    -1,    59,    41,
      59,    -1,    60,    -1,    60,    16,    60,    -1,    60,    17,
      60,    -1,    61,    -1,    61,    18,    61,    -1,    61,    19,
      61,    -1,    62,    -1,    62,    20,    62,    -1,    63,    -1,
      64,    21,    64,    -1,    64,    22,    64,    -1,    64,    23,
      64,    -1,    64,    -1,    24,    65,    -1,    65,    -1,    65,
      44,    72,    45,    -1,    66,    -1,    10,    12,    44,    73,
      45,    54,    11,    -1,    10,    44,    73,    45,    54,    11,
      -1,    67,    -1,    12,    -1,    68,    -1,    68,    46,    68,
      47,    -1,    69,    -1,    13,    -1,    14,    -1,    15,    -1,
      70,    -1,    46,    72,    47,    -1,    42,    74,    43,    -1,
      71,    -1,    44,    56,    45,    -1,    -1,    56,    -1,    72,
      56,    -1,    72,    51,    56,    -1,    -1,    12,    -1,    73,
      12,    -1,    73,    51,    12,    -1,    -1,    75,    -1,    74,
      75,    -1,    74,    51,    75,    -1,    46,    56,    47,    28,
      56,    -1,    12,    28,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    35,    36,    37,    38,    39,    40,    41,
      45,    54,    66,    67,    74,    81,    88,    95,   102,   109,
     116,   123,   131,   139,   147,   155,   163,   171,   179,   187,
     195,   199,   200,   201,   205,   206,   210,   211,   212,   213,
     214,   215,   219,   220,   221,   225,   226,   227,   231,   232,
     236,   237,   238,   239,   243,   244,   248,   249,   253,   261,
     269,   273,   274,   278,   279,   283,   284,   285,   286,   290,
     291,   292,   296,   300,   301,   306,   315,   327,   328,   333,
     342,   354,   355,   360,   369,   381,   386
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "WHILE", "FOR",
  "IN", "DO", "FUNC", "END", "IDENT", "INT", "FLOAT", "STRING", "PLUS",
  "MINUS", "STAR", "SLASH", "DSTAR", "BAND", "BOR", "BXOR", "BNOT", "LAND",
  "LOR", "LNOT", "ASSIGN", "ASSIGNPLUS", "ASSIGNMINUS", "ASSIGNSTAR",
  "ASSIGNSLASH", "ASSIGNDSTAR", "ASSIGNBAND", "ASSIGNBOR", "ASSIGNBXOR",
  "EQUAL", "LESS", "GREATER", "LESSEQ", "GREATEREQ", "LBRACE", "RBRACE",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "DOT", "COLON", "SEMICOLON",
  "COMMA", "$accept", "program", "stmt", "stmt_list", "expr", "logic_expr",
  "ulogic_expr", "rel_expr", "term_expr", "factor_expr", "power_expr",
  "binary_expr", "ubinary_expr", "call_expr", "funcdecl_expr", "ref_expr",
  "index_expr", "lit_expr", "gen_expr", "paren_expr", "expr_list",
  "ident_list", "assoc_list", "assoc_item", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    69,    70,
      70,    70,    71,    72,    72,    72,    72,    73,    73,    73,
      73,    74,    74,    74,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     5,     7,     5,     7,     2,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       1,     3,     3,     1,     2,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     3,     3,     1,     2,     1,     4,     1,     7,     6,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     0,     1,     2,     3,     0,     1,     2,
       3,     0,     1,     2,     3,     5,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    61,    65,    66,    67,     0,
       0,    81,     0,    73,     0,     2,     9,     3,    30,    33,
      35,    41,    44,    47,    49,    53,    55,    57,    60,    62,
      64,    68,    71,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,    54,    34,
       0,     0,     0,    82,     0,    74,     0,     1,     8,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,    77,    78,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    70,     0,    83,    72,
      69,     0,    75,     0,    31,    32,    36,    37,    38,    39,
      40,    42,    43,    45,    46,    48,    50,    51,    52,     0,
       0,     0,     0,     0,     0,    79,     0,     0,    86,     0,
      84,    76,     0,    56,    63,     0,     4,     6,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    85,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     5,     7,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    59,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      56,    84,    52,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
      59,   299,   299,     4,    -9,   344,   -51,   -51,   -51,   340,
     305,    12,   299,   299,    23,   235,    59,   -19,   -21,   -51,
     139,    65,    14,     9,   -51,   -14,    -8,   -51,   -51,     8,
     -51,   -51,   -51,     2,     6,    62,    24,    63,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   -51,    -8,   -51,
      74,   299,    13,   -51,    39,   -19,   251,   -51,   -51,   235,
     235,   299,   305,   305,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   299,   343,    59,
      59,   299,    63,   -51,    16,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   299,    60,   -51,    12,   -51,   -51,
     -51,   299,   -19,    67,   -21,   -21,   139,   139,   139,   139,
     139,    65,    65,    14,    14,     9,   -51,   -51,   -51,   259,
      91,    84,     7,    17,    80,   -51,    59,    76,   -19,    99,
     -51,   -19,   362,   -51,   -51,    59,   -51,   -51,    59,    59,
     109,   -51,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   160,   185,   210,   -51,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -51,   -51,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,    30,   -51,    -1,    77,    94,   223,    88,    89,
      44,   -51,     3,   120,   -51,   -51,    54,   -51,   -51,   -51,
      58,    70,   -51,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,    34,    98,    36,    62,    63,    79,    74,    75,    76,
       1,    54,    55,     2,     3,    80,    35,     4,   137,     5,
       6,     7,     8,    57,    50,    50,   138,    61,   125,    73,
      15,     9,    71,    72,    10,    37,    77,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    60,   130,    61,    11,
      95,    12,    61,    13,    78,   102,    96,    58,    51,    51,
     103,   126,     1,    61,    97,     2,     3,   127,    82,     4,
      81,     5,     6,     7,     8,    83,    55,   116,   117,   118,
     123,    69,    70,     9,    99,    61,    10,     1,   141,   135,
       2,     3,   125,   128,     4,   136,     5,     6,     7,     8,
     131,    11,    94,    12,    49,    13,    61,   129,     9,   121,
     122,    10,     1,    61,   132,     2,     3,   115,   102,     4,
     155,     5,     6,     7,     8,   139,    11,   142,    12,    48,
      13,   127,   120,     9,    58,   119,    10,    78,   134,   104,
     105,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    11,   124,    12,     0,    13,   140,   111,   112,    58,
     113,   114,     0,     1,     0,   152,     2,     3,   153,   154,
       4,   166,     5,     6,     7,     8,    64,    65,    66,    67,
      68,     0,     0,     0,     9,     0,     0,    10,     1,     0,
       0,     2,     3,     0,     0,     4,   167,     5,     6,     7,
       8,     0,    11,     0,    12,     0,    13,     0,     0,     9,
      58,     0,    10,     1,     0,     0,     2,     3,     0,     0,
       4,   168,     5,     6,     7,     8,     0,    11,     0,    12,
       0,    13,     0,     0,     9,    58,     0,    10,     1,     0,
       0,     2,     3,     0,     0,     4,     0,     5,     6,     7,
       8,     0,    11,     0,    12,     0,    13,     0,     0,     9,
      58,     4,    10,     5,     6,     7,     8,     0,     0,     4,
       0,     5,     6,     7,     8,     9,     0,    11,    10,    12,
       0,    13,     0,     9,     0,    58,    10,   106,   107,   108,
     109,   110,     0,    11,     0,    12,     0,    13,   100,     0,
       0,    11,   101,    12,   133,    13,     0,     0,     0,     4,
     101,     5,     6,     7,     8,     4,     0,    47,     6,     7,
       8,     0,     0,     9,     0,     0,    10,     0,     0,     9,
       0,     0,    10,     0,     4,     0,    47,     6,     7,     8,
       0,    11,     0,    12,     0,    13,     0,    11,     9,    12,
       4,    13,    47,     6,     7,     8,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    12,     0,
      13,     0,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    11,     0,    12,    11,    13,    12,     0,    13,
     143,   144,   145,   146,   147,   148,   149,   150,   151
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     2,    52,    12,    25,    26,     4,    21,    22,    23,
       3,    12,    13,     6,     7,     9,    12,    10,    11,    12,
      13,    14,    15,     0,    12,    12,     9,    46,    12,    20,
       0,    24,    18,    19,    27,    44,    44,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    16,    97,    46,    42,
      51,    44,    46,    46,    46,    56,    43,    50,    46,    46,
      61,    45,     3,    46,    51,     6,     7,    51,    44,    10,
       8,    12,    13,    14,    15,    12,    77,    74,    75,    76,
      81,    16,    17,    24,    45,    46,    27,     3,    12,     5,
       6,     7,    12,    94,    10,    11,    12,    13,    14,    15,
     101,    42,    28,    44,    10,    46,    46,    47,    24,    79,
      80,    27,     3,    46,    47,     6,     7,    73,   119,    10,
      11,    12,    13,    14,    15,    45,    42,    28,    44,     9,
      46,    51,    78,    24,    50,    77,    27,    46,    47,    62,
      63,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    42,    82,    44,    -1,    46,   126,    69,    70,    50,
      71,    72,    -1,     3,    -1,   135,     6,     7,   138,   139,
      10,    11,    12,    13,    14,    15,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    24,    -1,    -1,    27,     3,    -1,
      -1,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    -1,    42,    -1,    44,    -1,    46,    -1,    -1,    24,
      50,    -1,    27,     3,    -1,    -1,     6,     7,    -1,    -1,
      10,    11,    12,    13,    14,    15,    -1,    42,    -1,    44,
      -1,    46,    -1,    -1,    24,    50,    -1,    27,     3,    -1,
      -1,     6,     7,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    42,    -1,    44,    -1,    46,    -1,    -1,    24,
      50,    10,    27,    12,    13,    14,    15,    -1,    -1,    10,
      -1,    12,    13,    14,    15,    24,    -1,    42,    27,    44,
      -1,    46,    -1,    24,    -1,    50,    27,    64,    65,    66,
      67,    68,    -1,    42,    -1,    44,    -1,    46,    47,    -1,
      -1,    42,    51,    44,    45,    46,    -1,    -1,    -1,    10,
      51,    12,    13,    14,    15,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    24,
      -1,    -1,    27,    -1,    10,    -1,    12,    13,    14,    15,
      -1,    42,    -1,    44,    -1,    46,    -1,    42,    24,    44,
      10,    46,    12,    13,    14,    15,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,
      46,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    42,    -1,    44,    42,    46,    44,    -1,    46,
      28,    29,    30,    31,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    10,    12,    13,    14,    15,    24,
      27,    42,    44,    46,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    56,    56,    12,    12,    44,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    12,    65,    58,
      12,    46,    74,    75,    56,    56,    72,     0,    50,    54,
      54,    46,    25,    26,    37,    38,    39,    40,    41,    16,
      17,    18,    19,    20,    21,    22,    23,    44,    46,     4,
       9,     8,    44,    12,    73,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    28,    56,    43,    51,    75,    45,
      47,    51,    56,    56,    57,    57,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    62,    64,    64,    64,    72,
      68,    54,    54,    56,    73,    12,    45,    51,    56,    47,
      75,    56,    47,    45,    47,     5,    11,    11,     9,    45,
      54,    12,    28,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    54,    54,    54,    11,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    11,    11,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, program); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, stmt_node **program)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, program)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    stmt_node **program;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (program);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, stmt_node **program)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, program)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    stmt_node **program;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, program);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, stmt_node **program)
#else
static void
yy_reduce_print (yyvsp, yyrule, program)
    YYSTYPE *yyvsp;
    int yyrule;
    stmt_node **program;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , program);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, program); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, stmt_node **program)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, program)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    stmt_node **program;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (program);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (stmt_node **program)
#else
int
yyparse (program)
    stmt_node **program;
#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1787 of yacc.c  */
#line 31 "parser.y"
    { *program = AS_ST((yyvsp[(1) - (1)])); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 35 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_EXPR; AS_ST((yyval))->expr = (yyvsp[(1) - (1)]); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 36 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[(2) - (5)]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[(4) - (5)]); AS_ST((yyval))->ifelse->iffalse = NULL; }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 37 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_IFELSE; AS_ST((yyval))->ifelse = NEW(ifelse_node); AS_ST((yyval))->ifelse->cond = (yyvsp[(2) - (7)]); AS_ST((yyval))->ifelse->iftrue = (yyvsp[(4) - (7)]); AS_ST((yyval))->ifelse->iffalse = (yyvsp[(6) - (7)]); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 38 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_LOOP; AS_ST((yyval))->loop = NEW(loop_node); AS_ST((yyval))->loop->cond = (yyvsp[(2) - (5)]); AS_ST((yyval))->loop->loop = (yyvsp[(4) - (5)]); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 39 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_ITER; AS_ST((yyval))->iter = NEW(iter_node); AS_ST((yyval))->iter->var = strdup((yyvsp[(2) - (7)])); AS_ST((yyval))->iter->iter = (yyvsp[(4) - (7)]); AS_ST((yyval))->iter->loop = (yyvsp[(6) - (7)]); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 40 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 41 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 45 "parser.y"
    {
	(yyval) = NEW_ST();
	AS_ST((yyval))->type = ST_LIST;
	AS_ST((yyval))->stmtlist = NEW(stmtlist_node);
	AS_ST((yyval))->stmtlist->stmt = (yyvsp[(1) - (2)]);
	AS_ST((yyval))->stmtlist->next = NEW(stmtlist_node);
	AS_ST((yyval))->stmtlist->next->stmt = (yyvsp[(2) - (2)]);
	AS_ST((yyval))->stmtlist->next->next = NULL;
  }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 54 "parser.y"
    {
	stmtlist_node *cur = AS_ST((yyvsp[(1) - (2)]))->stmtlist;
	while(cur->next) cur = cur->next;
	cur->next = NEW(stmtlist_node);
	cur = cur->next;
	cur->stmt = (yyvsp[(2) - (2)]);
	cur->next = NULL;
	(yyval) = (yyvsp[(1) - (2)]);
  }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 66 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_ASSIGN; AS_EX((yyval))->assign = NEW(assign_node); AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]); AS_EX((yyval))->assign->value = (yyvsp[(3) - (3)]); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 67 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_ADD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 74 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_SUB, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 81 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_MUL, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 88 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
    MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_DIV, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 95 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_POW, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 102 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BAND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 109 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BOR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 116 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BXOR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 123 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	AS_EX((yyval))->setindex->value = (yyvsp[(6) - (6)]);
}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 131 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_ADD, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 139 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_SUB, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 147 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_MUL, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 155 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_DIV, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 163 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_POW, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 171 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BAND, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 179 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BOR, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 187 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_SETINDEX;
	AS_EX((yyval))->setindex = NEW(setindex_node);
	AS_EX((yyval))->setindex->expr = (yyvsp[(1) - (6)]);
	AS_EX((yyval))->setindex->index = (yyvsp[(3) - (6)]);
	MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BXOR, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));
}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 195 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 199 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LAND; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 200 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LOR; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 201 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 205 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LNOT; AS_EX((yyval))->unop->expr = (yyvsp[(2) - (2)]); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 206 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 210 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_EQUAL; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 211 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESS; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATER; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 213 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESSEQ; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 214 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATEREQ; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 215 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 219 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_ADD; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 220 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_SUB; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 221 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 225 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MUL; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 226 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_DIV; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 227 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_POW; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 232 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BAND; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 237 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BOR; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BXOR; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 239 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 243 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_BNOT; AS_EX((yyval))->unop->expr = (yyvsp[(2) - (2)]); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 244 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 248 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_CALL; AS_EX((yyval))->call = NEW(call_node); AS_EX((yyval))->call->expr = (yyvsp[(1) - (4)]); AS_EX((yyval))->call->args = (yyvsp[(3) - (4)]); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 249 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 253 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[(2) - (7)]);
	AS_EX((yyval))->funcdecl->args = (yyvsp[(4) - (7)]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[(6) - (7)]);
}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 261 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->args = (yyvsp[(3) - (6)]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[(5) - (6)]);
}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 269 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 273 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_REF; AS_EX((yyval))->ref = NEW(ref_node); AS_EX((yyval))->ref->ident = (yyvsp[(1) - (1)]); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 274 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 278 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[(1) - (4)]); AS_EX((yyval))->index->index = (yyvsp[(3) - (4)]); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 279 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 283 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = *AS((yyvsp[(1) - (1)]), long); free((yyvsp[(1) - (1)])); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 284 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_FLOAT; AS_EX((yyval))->lit->fval = *AS((yyvsp[(1) - (1)]), double); free((yyvsp[(1) - (1)])); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 285 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_STRING; AS_EX((yyval))->lit->str = (yyvsp[(1) - (1)]); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 286 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 290 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LISTGEN; AS_EX((yyval))->listgen = NEW(listgen_node); AS_EX((yyval))->listgen->list = (yyvsp[(2) - (3)]); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 291 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_MAPGEN; AS_EX((yyval))->mapgen = NEW(mapgen_node); AS_EX((yyval))->mapgen->map = (yyvsp[(2) - (3)]); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 292 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 296 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 300 "parser.y"
    { (yyval) = NULL; }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 301 "parser.y"
    {
	(yyval) = NEW(exprlist_node);
	AS((yyval), exprlist_node)->expr = (yyvsp[(1) - (1)]);
	AS((yyval), exprlist_node)->next = NULL;
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 306 "parser.y"
    {
	exprlist_node *cur = (yyvsp[(1) - (2)]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = (yyvsp[(2) - (2)]);
	cur->next = NULL;
	(yyval) = (yyvsp[(1) - (2)]);
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 315 "parser.y"
    {
	exprlist_node *cur = (yyvsp[(1) - (3)]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = (yyvsp[(3) - (3)]);
	cur->next = NULL;
	(yyval) = (yyvsp[(1) - (3)]);
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 327 "parser.y"
    { (yyval) = NULL; }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 328 "parser.y"
    {
	(yyval) = NEW(identlist_node);
	AS((yyval), identlist_node)->ident = (yyvsp[(1) - (1)]);
	AS((yyval), identlist_node)->next = NULL;
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 333 "parser.y"
    {
	identlist_node *cur = (yyvsp[(1) - (2)]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = (yyvsp[(2) - (2)]);
	cur->next = NULL;
	(yyval) = (yyvsp[(1) - (2)]);
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 342 "parser.y"
    {
	identlist_node *cur = (yyvsp[(1) - (3)]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = (yyvsp[(3) - (3)]);
	cur->next = NULL;
	(yyval) = (yyvsp[(1) - (3)]);
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 354 "parser.y"
    { (yyval) = NULL; }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 355 "parser.y"
    {
	(yyval) = NEW(assoclist_node);
	AS((yyval), assoclist_node)->item = (yyvsp[(1) - (1)]);
	AS((yyval), assoclist_node)->next = NULL;
}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 360 "parser.y"
    {
	assoclist_node *cur = (yyvsp[(1) - (2)]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = (yyvsp[(2) - (2)]);
	cur->next = NULL;
	(yyval) = (yyvsp[(1) - (2)]);
}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 369 "parser.y"
    {
	assoclist_node *cur = (yyvsp[(1) - (3)]);
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = (yyvsp[(3) - (3)]);
	cur->next = NULL;
	(yyval) = (yyvsp[(1) - (3)]);
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 381 "parser.y"
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = (yyvsp[(2) - (5)]);
	AS((yyval), associtem_node)->value = (yyvsp[(5) - (5)]);
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 386 "parser.y"
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = NEW_EX();
	AS((yyval), associtem_node)->key->type = EX_LIT;
	AS((yyval), associtem_node)->key->lit = NEW(lit_node);
	AS((yyval), associtem_node)->key->lit->type = LIT_STRING;
	AS((yyval), associtem_node)->key->lit->str = (yyvsp[(1) - (3)]);
	AS((yyval), associtem_node)->value = (yyvsp[(3) - (3)]);
}
    break;


/* Line 1787 of yacc.c  */
#line 2313 "parser.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 397 "parser.y"


// TODO