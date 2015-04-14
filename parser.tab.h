/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C

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
	PERCENT = 279,
	DSTAR = 280,
	BAND = 281,
	BOR = 282,
	BXOR = 283,
	BNOT = 284,
	LAND = 285,
	LOR = 286,
	LNOT = 287,
	ASSIGN = 288,
	ASSIGNPLUS = 289,
	ASSIGNMINUS = 290,
	ASSIGNSTAR = 291,
	ASSIGNSLASH = 292,
	ASSIGNDSTAR = 293,
	ASSIGNBAND = 294,
	ASSIGNBOR = 295,
	ASSIGNBXOR = 296,
	EQUAL = 297,
	LESS = 298,
	GREATER = 299,
	LESSEQ = 300,
	GREATEREQ = 301,
	RSHIFT = 302,
	LSHIFT = 303,
	LBRACE = 304,
	RBRACE = 305,
	LPAREN = 306,
	RPAREN = 307,
	LBRACKET = 308,
	RBRACKET = 309,
	DOT = 310,
	COLON = 311,
	SEMICOLON = 312,
	COMMA = 313,
	POUND = 314
};
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE {
	int first_line;
	int first_column;
	int last_line;
	int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


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
