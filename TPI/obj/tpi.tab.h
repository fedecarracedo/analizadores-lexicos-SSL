
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     DEC_CONST = 259,
     OCT_CONST = 260,
     HEX_CONST = 261,
     REAL_CONST = 262,
     CHAR_CONST = 263,
     STR_LIT = 264,
     MUL_ASSIGN = 265,
     DIV_ASSIGN = 266,
     MOD_ASSIGN = 267,
     ADD_ASSIGN = 268,
     SUB_ASSIGN = 269,
     RIGHT_ASSIGN = 270,
     LEFT_ASSIGN = 271,
     AND_ASSIGN = 272,
     XOR_ASSIGN = 273,
     OR_ASSIGN = 274,
     OR_OP = 275,
     AND_OP = 276,
     EQ_OP = 277,
     NE_OP = 278,
     LE_OP = 279,
     GE_OP = 280,
     LEFT_OP = 281,
     RIGHT_OP = 282,
     INC_OP = 283,
     DEC_OP = 284,
     PTR_OP = 285,
     SIZEOF = 286,
     TYPEDEF = 287,
     STATIC = 288,
     AUTO = 289,
     REGISTER = 290,
     EXTERN = 291,
     VOID = 292,
     CHAR = 293,
     SHORT = 294,
     INT = 295,
     LONG = 296,
     FLOAT = 297,
     DOUBLE = 298,
     SIGNED = 299,
     UNSIGNED = 300,
     CONST = 301,
     VOLATILE = 302,
     STRUCT = 303,
     UNION = 304,
     ELLIPSIS = 305,
     ENUM = 306,
     IF = 307,
     ELSE = 308,
     SWITCH = 309,
     WHILE = 310,
     DO = 311,
     FOR = 312,
     CASE = 313,
     DEFAULT = 314,
     CONTINUE = 315,
     BREAK = 316,
     RETURN = 317,
     GOTO = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 19 "../src/tpi.y"

    char* cadena;
    int entero;
    float real;



/* Line 1676 of yacc.c  */
#line 123 "tpi.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


