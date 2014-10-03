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
     LBRACE = 301,
     RBRACE = 302,
     LPAREN = 303,
     RPAREN = 304,
     LBRACKET = 305,
     RBRACKET = 306,
     DOT = 307,
     COLON = 308,
     SEMICOLON = 309,
     COMMA = 310,
     POUND = 311
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
#line 200 "parser.tab.c"

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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   682

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    13,    21,    27,    35,    38,
      40,    42,    44,    47,    49,    52,    55,    59,    63,    67,
      71,    75,    79,    83,    87,    91,    95,    99,   103,   107,
     111,   115,   119,   123,   127,   129,   133,   137,   139,   142,
     144,   148,   152,   156,   160,   164,   166,   170,   174,   176,
     180,   184,   186,   190,   192,   196,   200,   204,   206,   209,
     211,   214,   216,   221,   223,   231,   238,   240,   242,   243,
     248,   252,   254,   259,   263,   265,   267,   269,   272,   274,
     276,   278,   280,   284,   288,   290,   294,   295,   297,   300,
     304,   305,   307,   310,   314,   315,   317,   320,   324,   330
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    61,    -1,     3,    61,     4,
      59,    14,    -1,     3,    61,     4,    59,     5,    59,    14,
      -1,     6,    61,     9,    59,    14,    -1,     7,    16,     8,
      61,     9,    59,    14,    -1,    11,    61,    -1,    11,    -1,
      12,    -1,    13,    -1,    59,    54,    -1,    60,    -1,    60,
      59,    -1,    59,    59,    -1,    16,    32,    61,    -1,    16,
      33,    61,    -1,    16,    34,    61,    -1,    16,    35,    61,
      -1,    16,    36,    61,    -1,    16,    37,    61,    -1,    16,
      38,    61,    -1,    16,    39,    61,    -1,    16,    40,    61,
      -1,    75,    32,    61,    -1,    75,    33,    61,    -1,    75,
      34,    61,    -1,    75,    35,    61,    -1,    75,    36,    61,
      -1,    75,    37,    61,    -1,    75,    38,    61,    -1,    75,
      39,    61,    -1,    75,    40,    61,    -1,    62,    -1,    62,
      29,    62,    -1,    62,    30,    62,    -1,    63,    -1,    31,
      63,    -1,    64,    -1,    64,    41,    64,    -1,    64,    42,
      64,    -1,    64,    43,    64,    -1,    64,    44,    64,    -1,
      64,    45,    64,    -1,    65,    -1,    65,    20,    65,    -1,
      65,    21,    65,    -1,    66,    -1,    66,    22,    66,    -1,
      66,    23,    66,    -1,    67,    -1,    67,    24,    67,    -1,
      68,    -1,    69,    25,    69,    -1,    69,    26,    69,    -1,
      69,    27,    69,    -1,    69,    -1,    28,    69,    -1,    70,
      -1,    56,    70,    -1,    71,    -1,    71,    48,    80,    49,
      -1,    72,    -1,    10,    16,    48,    81,    49,    73,    14,
      -1,    10,    48,    81,    49,    73,    14,    -1,    74,    -1,
      59,    -1,    -1,    61,    50,    61,    51,    -1,    61,    52,
      16,    -1,    76,    -1,    61,    50,    61,    51,    -1,    61,
      52,    16,    -1,    16,    -1,    77,    -1,    17,    -1,    21,
      17,    -1,    18,    -1,    19,    -1,    15,    -1,    78,    -1,
      50,    80,    51,    -1,    46,    82,    47,    -1,    79,    -1,
      48,    61,    49,    -1,    -1,    61,    -1,    80,    61,    -1,
      80,    55,    61,    -1,    -1,    16,    -1,    81,    16,    -1,
      81,    55,    16,    -1,    -1,    83,    -1,    82,    83,    -1,
      82,    55,    83,    -1,    50,    61,    51,    32,    61,    -1,
      16,    32,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    49,    58,    70,    71,    78,    85,
      92,    99,   106,   113,   120,   127,   140,   153,   166,   179,
     192,   205,   218,   231,   244,   248,   249,   250,   254,   255,
     259,   260,   261,   262,   263,   264,   268,   269,   270,   274,
     275,   276,   280,   281,   285,   286,   287,   288,   292,   293,
     297,   298,   302,   303,   307,   315,   323,   327,   328,   332,
     333,   344,   348,   349,   363,   364,   368,   369,   370,   371,
     372,   373,   377,   378,   379,   383,   387,   388,   393,   402,
     414,   415,   420,   429,   441,   442,   447,   456,   468,   473
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
  "LESSEQ", "GREATEREQ", "LBRACE", "RBRACE", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "DOT", "COLON", "SEMICOLON", "COMMA", "POUND",
  "$accept", "program", "stmt", "stmt_list", "expr", "logic_expr",
  "ulogic_expr", "rel_expr", "term_expr", "factor_expr", "power_expr",
  "binary_expr", "ubinary_expr", "ulen_expr", "call_expr", "funcdecl_expr",
  "opt_stmt", "index_expr", "ex_index_expr", "ref_expr", "lit_expr",
  "gen_expr", "paren_expr", "expr_list", "ident_list", "assoc_list",
  "assoc_item", YY_NULL
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    79,    80,    80,    80,    80,
      81,    81,    81,    81,    82,    82,    82,    82,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     5,     7,     5,     7,     2,     1,
       1,     1,     2,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     2,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     3,     1,     2,     1,
       2,     1,     4,     1,     7,     6,     1,     1,     0,     4,
       3,     1,     4,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     3,     1,     3,     0,     1,     2,     3,
       0,     1,     2,     3,     0,     1,     2,     3,     5,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     9,    10,    11,    80,    74,
      76,    78,    79,     0,     0,     0,    94,     0,    86,     0,
       0,     2,    13,     3,    34,    37,    39,    45,    48,    51,
      53,    57,    59,    61,    63,    66,     0,    71,    75,    81,
      84,     0,     0,     0,     0,    90,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,    58,    38,
       0,     0,     0,    95,     0,    87,     0,    60,     1,    12,
      15,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,    83,     0,    96,    85,
      82,     0,    88,     0,    70,    35,    36,    40,    41,    42,
      43,    44,    46,    47,    49,    50,    52,    54,    55,    56,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     0,     0,     0,    92,    68,     0,    99,     0,    97,
      89,    69,    62,     0,     4,     6,     0,    68,    67,     0,
      93,     0,     0,     0,     0,    65,    98,     5,     7,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    70,    22,    57,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   169,    35,    36,    37,
      38,    39,    40,    66,   104,    62,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int16 yypact[] =
{
     444,   493,   493,    -7,    -5,   493,   -59,   -59,   -59,    70,
     -59,   -59,   -59,    -3,   493,   493,    -8,   493,   493,   493,
      20,   392,   444,    12,    44,   -59,    40,    95,   100,    -1,
     -59,     5,   -59,   -21,   -59,   -59,   237,   -59,   -59,   -59,
     -59,     6,    15,    26,    -4,    41,    12,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   -59,    12,   530,   -17,
      37,   493,    13,   -59,   -24,    12,   114,   563,   -59,   -59,
     392,   392,   493,    63,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   444,
     444,   493,    41,   -59,   -10,    12,    12,    12,    12,    12,
      12,    12,    12,    12,   493,    36,   -59,    -8,   -59,   -59,
     -59,   493,    12,    61,   289,   -14,   -14,   177,   177,   177,
     177,   177,   630,   630,   613,   613,   596,     5,     5,     5,
     467,    12,    12,    12,    12,    12,    12,    12,    12,    12,
     184,   236,    28,    -9,   -59,   444,   101,    12,    88,   -59,
      12,   341,   -59,   444,   -59,   -59,   444,   444,   392,   120,
     -59,   493,   288,   340,   124,   -59,    12,   -59,   -59,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,    19,   -59,     0,    51,   126,    99,    46,    53,
      54,   -59,   -11,   125,   -59,   -59,   -20,   -59,   -59,   -59,
     -59,   -59,   -59,    57,    47,   -59,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -74
static const yytype_int16 yytable[] =
{
      23,    41,    42,    58,   118,    46,   154,   154,    60,    43,
      99,    44,   -37,   -37,    56,    74,    75,    64,    65,    21,
      68,    23,    23,    85,   100,   119,    72,    89,    73,    60,
      86,    87,    88,   -37,   101,   -37,   -34,   166,   -34,   155,
     167,    71,    61,    45,   102,   156,   156,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    72,   103,    73,   159,
     116,   115,    72,    61,    73,    72,   122,    73,   117,   114,
      23,    23,   123,    74,    75,   137,   138,   139,    72,   124,
      73,    76,    77,    78,    79,    80,    72,   158,    73,    65,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    23,
      23,   152,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    72,   161,    73,   157,    81,    82,   170,   150,   151,
     171,   160,    83,    84,     4,   125,   126,   132,   133,     8,
       9,    10,    11,    12,   175,    13,   134,   135,   179,   136,
     122,    59,    14,     0,    67,    15,   140,   174,     0,   153,
      23,    23,     0,     0,     0,    23,     0,     0,     0,     0,
      16,     0,    17,    23,    18,   120,    23,    23,    23,   121,
      19,   176,    23,    23,   168,   127,   128,   129,   130,   131,
       0,     0,   172,     0,     0,   173,   168,     1,     0,   163,
       2,     3,     0,     0,     4,     5,     6,     7,   164,     8,
       9,    10,    11,    12,     0,    13,   -39,   -39,     0,     0,
       0,     0,    14,     0,     0,    15,     0,     0,    76,    77,
      78,    79,    80,     0,     0,     0,     0,   -39,     0,   -39,
      16,     0,    17,     0,    18,     0,     0,     0,    69,     1,
      19,     0,     2,     3,     0,     0,     4,     5,     6,     7,
     165,     8,     9,    10,    11,    12,     0,    13,     0,     0,
       0,     0,     0,     0,    14,     0,     0,    15,     0,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,    16,     0,    17,     0,    18,     0,     0,     0,
      69,     1,    19,     0,     2,     3,     0,     0,     4,     5,
       6,     7,   177,     8,     9,    10,    11,    12,     0,    13,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    15,
       0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
       0,     0,     0,     0,    16,     0,    17,     0,    18,     0,
       0,     0,    69,     1,    19,     0,     2,     3,     0,     0,
       4,     5,     6,     7,   178,     8,     9,    10,    11,    12,
       0,    13,     0,     0,     0,     0,     0,     0,    14,     0,
       0,    15,     0,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,     0,     0,     0,     0,    16,     0,    17,     0,
      18,     0,     0,     0,    69,     1,    19,     0,     2,     3,
       0,     0,     4,     5,     6,     7,     0,     8,     9,    10,
      11,    12,     0,    13,     0,     0,     0,     0,     0,     0,
      14,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
      17,     0,    18,     0,     0,     0,    69,     1,    19,     0,
       2,     3,     0,     0,     4,     5,     6,     7,     0,     8,
       9,    10,    11,    12,     0,    13,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    15,     0,     4,     0,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,     0,
      16,     0,    17,     0,    18,    14,     0,     0,    15,     0,
      19,     0,     0,     4,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    16,    13,    17,   162,    18,     0,     0,
       0,    14,   121,    19,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,    17,     0,    18,     0,     0,     0,     0,     0,    19,
     -57,   -57,   -57,   -57,   -57,    86,    87,    88,     0,   -57,
     -57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,
     -57,     0,   -57,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,     0,   -59,   -59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -59,   -59,   -59,   -59,   -59,     0,
       0,     0,     0,   -59,     0,   -59,   -51,   -51,   -51,   -51,
      85,     0,     0,     0,     0,   -51,   -51,     0,     0,     0,
       0,     0,     0,   -48,   -48,    83,    84,   -51,   -51,   -51,
     -51,   -51,   -48,   -48,     0,     0,   -51,     0,   -51,     0,
      81,    82,     0,     0,   -48,   -48,   -48,   -48,   -48,   -45,
     -45,     0,     0,   -48,     0,   -48,     0,     0,     0,     0,
       0,   -45,   -45,   -45,   -45,   -45,     0,     0,     0,     0,
     -45,     0,   -45
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,     1,     2,    14,    62,     5,    16,    16,    16,    16,
       4,    16,    29,    30,    17,    29,    30,    17,    18,     0,
       0,    21,    22,    24,     9,    49,    50,    48,    52,    16,
      25,    26,    27,    50,     8,    52,    50,     9,    52,    49,
      49,    22,    50,    48,    48,    55,    55,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    50,    16,    52,   117,
      47,    61,    50,    50,    52,    50,    66,    52,    55,    32,
      70,    71,    72,    29,    30,    86,    87,    88,    50,    16,
      52,    41,    42,    43,    44,    45,    50,    51,    52,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    50,    51,    52,   114,    20,    21,    16,    99,   100,
      32,   121,    22,    23,    10,    74,    75,    81,    82,    15,
      16,    17,    18,    19,    14,    21,    83,    84,    14,    85,
     140,    15,    28,    -1,    19,    31,    89,   167,    -1,   102,
     150,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,
      46,    -1,    48,   163,    50,    51,   166,   167,   168,    55,
      56,   171,   172,   173,   155,    76,    77,    78,    79,    80,
      -1,    -1,   163,    -1,    -1,   166,   167,     3,    -1,     5,
       6,     7,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    29,    30,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    31,    -1,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,    52,
      46,    -1,    48,    -1,    50,    -1,    -1,    -1,    54,     3,
      56,    -1,     6,     7,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    46,    -1,    48,    -1,    50,    -1,    -1,    -1,
      54,     3,    56,    -1,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    31,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,    -1,
      -1,    -1,    54,     3,    56,    -1,     6,     7,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,
      50,    -1,    -1,    -1,    54,     3,    56,    -1,     6,     7,
      -1,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      48,    -1,    50,    -1,    -1,    -1,    54,     3,    56,    -1,
       6,     7,    -1,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    31,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    -1,    21,    -1,
      46,    -1,    48,    -1,    50,    28,    -1,    -1,    31,    -1,
      56,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    46,    21,    48,    49,    50,    -1,    -1,
      -1,    28,    55,    56,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    52,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    41,    42,    43,
      44,    45,    29,    30,    -1,    -1,    50,    -1,    52,    -1,
      20,    21,    -1,    -1,    41,    42,    43,    44,    45,    29,
      30,    -1,    -1,    50,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    10,    11,    12,    13,    15,    16,
      17,    18,    19,    21,    28,    31,    46,    48,    50,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    74,    75,    76,    77,    78,
      79,    61,    61,    16,    16,    48,    61,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    17,    61,    69,    63,
      16,    50,    82,    83,    61,    61,    80,    70,     0,    54,
      59,    59,    50,    52,    29,    30,    41,    42,    43,    44,
      45,    20,    21,    22,    23,    24,    25,    26,    27,    48,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     4,
       9,     8,    48,    16,    81,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    32,    61,    47,    55,    83,    49,
      51,    55,    61,    61,    16,    62,    62,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    69,    69,    69,
      80,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      59,    59,    61,    81,    16,    49,    55,    61,    51,    83,
      61,    51,    49,     5,    14,    14,     9,    49,    59,    73,
      16,    32,    59,    59,    73,    14,    61,    14,    14,    14
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
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = (yyvsp[(2) - (2)]); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 41 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_RET; AS_ST((yyval))->ret = NEW(ret_node); AS_ST((yyval))->ret->ret = NULL; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 42 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_BREAK; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 43 "parser.y"
    { (yyval) = NEW_ST(); AS_ST((yyval))->type = ST_CONT; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 44 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 45 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 49 "parser.y"
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

  case 15:
/* Line 1787 of yacc.c  */
#line 58 "parser.y"
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

  case 16:
/* Line 1787 of yacc.c  */
#line 70 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_ASSIGN; AS_EX((yyval))->assign = NEW(assign_node); AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]); AS_EX((yyval))->assign->value = (yyvsp[(3) - (3)]); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 71 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_ADD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 78 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_SUB, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 85 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_MUL, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 92 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
    MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_DIV, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 99 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_POW, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 106 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BAND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 113 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BOR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_ASSIGN;
	AS_EX((yyval))->assign = NEW(assign_node);
	AS_EX((yyval))->assign->ident = (yyvsp[(1) - (3)]);
	MAKE_REF_BINOP(AS_EX((yyval))->assign->value, OP_BXOR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
  }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 127 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    AS_EX((yyval))->setindex->value = (yyvsp[(3) - (3)]);
    //ex_free(AS_EX($1));
}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 140 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_ADD, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 153 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_SUB, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 166 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_MUL, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 179 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_DIV, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 192 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_POW, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 205 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BAND, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 218 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BOR, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    {
    if(AS_EX((yyvsp[(1) - (3)]))->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_SETINDEX;
    AS_EX((yyval))->setindex = NEW(setindex_node);
    AS_EX((yyval))->setindex->expr = AS_EX((yyvsp[(1) - (3)]))->index->expr;
    AS_EX((yyval))->setindex->index = AS_EX((yyvsp[(1) - (3)]))->index->index;
    MAKE_IDX_BINOP(AS_EX((yyval))->setindex->value, OP_BXOR, AS_EX((yyvsp[(1) - (3)]))->index->expr, AS_EX((yyvsp[(1) - (3)]))->index->index, (yyvsp[(3) - (3)]));
    //ex_free(AS_EX($1));
}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 244 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 248 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LAND; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 249 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LOR; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 250 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 254 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LNOT; AS_EX((yyval))->unop->expr = (yyvsp[(2) - (2)]); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 255 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 259 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_EQUAL; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 260 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESS; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 261 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATER; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 262 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_LESSEQ; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 263 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_GREATEREQ; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 264 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 268 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_ADD; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 269 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_SUB; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 270 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 274 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_MUL; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 275 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_DIV; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 276 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 280 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_POW; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 281 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 285 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BAND; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 286 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BOR; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 287 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_BINOP; AS_EX((yyval))->binop = NEW(binop_node); AS_EX((yyval))->binop->type = OP_BXOR; AS_EX((yyval))->binop->left = (yyvsp[(1) - (3)]); AS_EX((yyval))->binop->right = (yyvsp[(3) - (3)]); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 288 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 292 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_BNOT; AS_EX((yyval))->unop->expr = (yyvsp[(2) - (2)]); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 293 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 297 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_UNOP; AS_EX((yyval))->unop = NEW(unop_node); AS_EX((yyval))->unop->type = OP_LEN; AS_EX((yyval))->unop->expr = (yyvsp[(2) - (2)]); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 298 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 302 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_CALL; AS_EX((yyval))->call = NEW(call_node); AS_EX((yyval))->call->expr = (yyvsp[(1) - (4)]); AS_EX((yyval))->call->args = (yyvsp[(3) - (4)]); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 303 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 307 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = (yyvsp[(2) - (7)]);
	AS_EX((yyval))->funcdecl->args = (yyvsp[(4) - (7)]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[(6) - (7)]);
}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 315 "parser.y"
    {
	(yyval) = NEW_EX();
	AS_EX((yyval))->type = EX_FUNCDECL;
	AS_EX((yyval))->funcdecl = NEW(funcdecl_node);
	AS_EX((yyval))->funcdecl->name = NULL;
	AS_EX((yyval))->funcdecl->args = (yyvsp[(3) - (6)]);
	AS_EX((yyval))->funcdecl->body = (yyvsp[(5) - (6)]);
}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 323 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 327 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 328 "parser.y"
    { (yyval) = NULL; }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 332 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[(1) - (4)]); AS_EX((yyval))->index->index = (yyvsp[(3) - (4)]); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 333 "parser.y"
    {
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_INDEX;
    AS_EX((yyval))->index = NEW(index_node);
    AS_EX((yyval))->index->expr = (yyvsp[(1) - (3)]);
    AS_EX((yyval))->index->index = NEW_EX();
    AS_EX((yyval))->index->index->type = EX_LIT;
    AS_EX((yyval))->index->index->lit = NEW(lit_node);
    AS_EX((yyval))->index->index->lit->type = LIT_STRING;
    AS_EX((yyval))->index->index->lit->str = (yyvsp[(3) - (3)]);
}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 344 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 348 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_INDEX; AS_EX((yyval))->index = NEW(index_node); AS_EX((yyval))->index->expr = (yyvsp[(1) - (4)]); AS_EX((yyval))->index->index = (yyvsp[(3) - (4)]); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 349 "parser.y"
    {
    (yyval) = NEW_EX();
    AS_EX((yyval))->type = EX_INDEX;
    AS_EX((yyval))->index = NEW(index_node);
    AS_EX((yyval))->index->expr = (yyvsp[(1) - (3)]);
    AS_EX((yyval))->index->index = NEW_EX();
    AS_EX((yyval))->index->index->type = EX_LIT;
    AS_EX((yyval))->index->index->lit = NEW(lit_node);
    AS_EX((yyval))->index->index->lit->type = LIT_STRING;
    AS_EX((yyval))->index->index->lit->str = (yyvsp[(3) - (3)]);
}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 363 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_REF; AS_EX((yyval))->ref = NEW(ref_node); AS_EX((yyval))->ref->ident = (yyvsp[(1) - (1)]); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 364 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 368 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = *AS((yyvsp[(1) - (1)]), long); free((yyvsp[(1) - (1)])); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 369 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_INT; AS_EX((yyval))->lit->ival = -(*AS((yyvsp[(2) - (2)]), long)); free((yyvsp[(2) - (2)])); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 370 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_FLOAT; AS_EX((yyval))->lit->fval = *AS((yyvsp[(1) - (1)]), double); free((yyvsp[(1) - (1)])); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 371 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_STRING; AS_EX((yyval))->lit->str = (yyvsp[(1) - (1)]); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 372 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LIT; AS_EX((yyval))->lit = NEW(lit_node); AS_EX((yyval))->lit->type = LIT_NONE; }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 373 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 377 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_LISTGEN; AS_EX((yyval))->listgen = NEW(listgen_node); AS_EX((yyval))->listgen->list = (yyvsp[(2) - (3)]); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 378 "parser.y"
    { (yyval) = NEW_EX(); AS_EX((yyval))->type = EX_MAPGEN; AS_EX((yyval))->mapgen = NEW(mapgen_node); AS_EX((yyval))->mapgen->map = (yyvsp[(2) - (3)]); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 379 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 383 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 387 "parser.y"
    { (yyval) = NULL; }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 388 "parser.y"
    {
	(yyval) = NEW(exprlist_node);
	AS((yyval), exprlist_node)->expr = (yyvsp[(1) - (1)]);
	AS((yyval), exprlist_node)->next = NULL;
}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 393 "parser.y"
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

  case 89:
/* Line 1787 of yacc.c  */
#line 402 "parser.y"
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

  case 90:
/* Line 1787 of yacc.c  */
#line 414 "parser.y"
    { (yyval) = NULL; }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 415 "parser.y"
    {
	(yyval) = NEW(identlist_node);
	AS((yyval), identlist_node)->ident = (yyvsp[(1) - (1)]);
	AS((yyval), identlist_node)->next = NULL;
}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 420 "parser.y"
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

  case 93:
/* Line 1787 of yacc.c  */
#line 429 "parser.y"
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

  case 94:
/* Line 1787 of yacc.c  */
#line 441 "parser.y"
    { (yyval) = NULL; }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 442 "parser.y"
    {
	(yyval) = NEW(assoclist_node);
	AS((yyval), assoclist_node)->item = (yyvsp[(1) - (1)]);
	AS((yyval), assoclist_node)->next = NULL;
}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 447 "parser.y"
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

  case 97:
/* Line 1787 of yacc.c  */
#line 456 "parser.y"
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

  case 98:
/* Line 1787 of yacc.c  */
#line 468 "parser.y"
    {
	(yyval) = NEW(associtem_node);
	AS((yyval), associtem_node)->key = (yyvsp[(2) - (5)]);
	AS((yyval), associtem_node)->value = (yyvsp[(5) - (5)]);
}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 473 "parser.y"
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
#line 2530 "parser.tab.c"
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
#line 484 "parser.y"


// TODO
