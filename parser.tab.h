/* A Bison parser, made by GNU Bison 3.0.2.  */

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
