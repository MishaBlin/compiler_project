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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING_LITERAL = 258,          /* STRING_LITERAL  */
    PLUS = 259,                    /* PLUS  */
    MINUS = 260,                   /* MINUS  */
    MULT = 261,                    /* MULT  */
    DIV = 262,                     /* DIV  */
    COMMENT = 263,                 /* COMMENT  */
    ASSIGNMENT = 264,              /* ASSIGNMENT  */
    RANGE = 265,                   /* RANGE  */
    COLON = 266,                   /* COLON  */
    SEMICOLON = 267,               /* SEMICOLON  */
    EQ = 268,                      /* EQ  */
    NEQ = 269,                     /* NEQ  */
    LT = 270,                      /* LT  */
    LTE = 271,                     /* LTE  */
    GT = 272,                      /* GT  */
    GTE = 273,                     /* GTE  */
    IMPLICATION = 274,             /* IMPLICATION  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    XOR = 277,                     /* XOR  */
    NOT = 278,                     /* NOT  */
    VAR = 279,                     /* VAR  */
    IS = 280,                      /* IS  */
    THEN = 281,                    /* THEN  */
    EMPTY = 282,                   /* EMPTY  */
    END = 283,                     /* END  */
    FUNCTION = 284,                /* FUNCTION  */
    IN = 285,                      /* IN  */
    LOOP = 286,                    /* LOOP  */
    FOR = 287,                     /* FOR  */
    WHILE = 288,                   /* WHILE  */
    IF = 289,                      /* IF  */
    ELSE = 290,                    /* ELSE  */
    TRUE = 291,                    /* TRUE  */
    FALSE = 292,                   /* FALSE  */
    RETURN = 293,                  /* RETURN  */
    INT = 294,                     /* INT  */
    REAL = 295,                    /* REAL  */
    BOOL = 296,                    /* BOOL  */
    STRING = 297,                  /* STRING  */
    INT_LITERAL = 298,             /* INT_LITERAL  */
    REAL_LITERAL = 299,            /* REAL_LITERAL  */
    IDENTIFIER = 300,              /* IDENTIFIER  */
    LEFT_BR = 301,                 /* LEFT_BR  */
    RIGHT_BR = 302,                /* RIGHT_BR  */
    DOT = 303,                     /* DOT  */
    LEFT_SQ_BR = 304,              /* LEFT_SQ_BR  */
    RIGHT_SQ_BR = 305,             /* RIGHT_SQ_BR  */
    COMMA = 306,                   /* COMMA  */
    QUOTE = 307,                   /* QUOTE  */
    INVALID_CHARACTER = 308,       /* INVALID_CHARACTER  */
    PRINT = 309,                   /* PRINT  */
    RIGHT_CURL_BR = 310,           /* RIGHT_CURL_BR  */
    LEFT_CURL_BR = 311             /* LEFT_CURL_BR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "parser.y"

    int iconst;       /* For integer constants */
    float fconst;     /* For real constants */
    char* sconst;     /* For string literals */
    char* ident;      /* For identifiers */
    struct ASTNode* node; /* For AST nodes */

#line 128 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
