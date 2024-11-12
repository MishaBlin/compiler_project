/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 30 "parser.y"

    #include "ast.hpp"

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    INTEGER = 259,                 /* INTEGER  */
    REAL = 260,                    /* REAL  */
    STRING = 261,                  /* STRING  */
    TRUE = 262,                    /* TRUE  */
    FALSE = 263,                   /* FALSE  */
    VAR = 264,                     /* VAR  */
    IF = 265,                      /* IF  */
    THEN = 266,                    /* THEN  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    IN = 270,                      /* IN  */
    RETURN = 271,                  /* RETURN  */
    PRINT = 272,                   /* PRINT  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    XOR = 275,                     /* XOR  */
    NOT = 276,                     /* NOT  */
    IS = 277,                      /* IS  */
    ASSIGN = 278,                  /* ASSIGN  */
    PLUS = 279,                    /* PLUS  */
    MINUS = 280,                   /* MINUS  */
    MUL = 281,                     /* MUL  */
    DIV = 282,                     /* DIV  */
    LT = 283,                      /* LT  */
    LE = 284,                      /* LE  */
    GT = 285,                      /* GT  */
    GE = 286,                      /* GE  */
    EQ = 287,                      /* EQ  */
    NEQ = 288,                     /* NEQ  */
    LPAREN = 289,                  /* LPAREN  */
    RPAREN = 290,                  /* RPAREN  */
    LBRACE = 291,                  /* LBRACE  */
    RBRACE = 292,                  /* RBRACE  */
    LBRACKET = 293,                /* LBRACKET  */
    RBRACKET = 294,                /* RBRACKET  */
    COMMA = 295,                   /* COMMA  */
    SEMICOLON = 296,               /* SEMICOLON  */
    READINT = 297,                 /* READINT  */
    READREAL = 298,                /* READREAL  */
    READSTRING = 299,              /* READSTRING  */
    LOOP = 300,                    /* LOOP  */
    DOT = 301,                     /* DOT  */
    END = 302,                     /* END  */
    INT_TYPE = 303,                /* INT_TYPE  */
    REAL_TYPE = 304,               /* REAL_TYPE  */
    BOOL_TYPE = 305,               /* BOOL_TYPE  */
    STRING_TYPE = 306,             /* STRING_TYPE  */
    EMPTY = 307,                   /* EMPTY  */
    VECTOR = 308,                  /* VECTOR  */
    TUPLE = 309,                   /* TUPLE  */
    FUNC = 310,                    /* FUNC  */
    INVALID_CHARACTER = 311,       /* INVALID_CHARACTER  */
    RANGE = 312,                   /* RANGE  */
    IMPLICATION = 313,             /* IMPLICATION  */
    MOD = 314                      /* MOD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

    int iconst;       /* For integer constants */
    double fconst;     /* For real constants */
    char* sconst;     /* For string literals */
    char* ident;      /* For identifiers */
    Node* node;
    char* value;

#line 138 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
