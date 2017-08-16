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
