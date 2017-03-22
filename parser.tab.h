/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
