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
    ELSE = 260,
    WHILE = 261,
    FOR = 262,
    IN = 263,
    DO = 264,
    FUNC = 265,
    LAMBDA = 266,
    RETURN = 267,
    BREAK = 268,
    CONTINUE = 269,
    END = 270,
    NONE = 271,
    IDENT = 272,
    INT = 273,
    FLOAT = 274,
    STRING = 275,
    PLUS = 276,
    MINUS = 277,
    STAR = 278,
    SLASH = 279,
    PERCENT = 280,
    DSTAR = 281,
    BAND = 282,
    BOR = 283,
    BXOR = 284,
    BNOT = 285,
    LAND = 286,
    LOR = 287,
    LNOT = 288,
    ASSIGN = 289,
    ASSIGNPLUS = 290,
    ASSIGNMINUS = 291,
    ASSIGNSTAR = 292,
    ASSIGNSLASH = 293,
    ASSIGNDSTAR = 294,
    ASSIGNBAND = 295,
    ASSIGNBOR = 296,
    ASSIGNBXOR = 297,
    EQUAL = 298,
    NEQUAL = 299,
    LESS = 300,
    GREATER = 301,
    LESSEQ = 302,
    GREATEREQ = 303,
    RSHIFT = 304,
    LSHIFT = 305,
    LBRACE = 306,
    RBRACE = 307,
    LPAREN = 308,
    RPAREN = 309,
    LBRACKET = 310,
    RBRACKET = 311,
    DOT = 312,
    COLON = 313,
    SEMICOLON = 314,
    COMMA = 315,
    POUND = 316,
    TBANG = 317
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
