#ifndef YY_parse_h_included
#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 15 "parser.y"
typedef union {
    int iconst;       /* For integer constants */
    float fconst;     /* For real constants */
    char* sconst;     /* For string literals */
    char* ident;      /* For identifiers */
} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype
#ifndef YY_USE_CLASS
#define YYSTYPE yy_parse_stype
#endif

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	STRING_LITERAL	258
#define	PLUS	259
#define	MINUS	260
#define	MULT	261
#define	DIV	262
#define	COMMENT	263
#define	ASSIGNMENT	264
#define	RANGE	265
#define	COLON	266
#define	SEMICOLON	267
#define	EQ	268
#define	NEQ	269
#define	LT	270
#define	LTE	271
#define	GT	272
#define	GTE	273
#define	IMPLICATION	274
#define	AND	275
#define	OR	276
#define	XOR	277
#define	NOT	278
#define	VAR	279
#define	IS	280
#define	THEN	281
#define	EMPTY	282
#define	END	283
#define	FUNCTION	284
#define	IN	285
#define	LOOP	286
#define	FOR	287
#define	WHILE	288
#define	IF	289
#define	ELSE	290
#define	TRUE	291
#define	FALSE	292
#define	RETURN	293
#define	INT	294
#define	REAL	295
#define	BOOL	296
#define	STRING	297
#define	INT_LITERAL	298
#define	REAL_LITERAL	299
#define	IDENTIFIER	300
#define	LEFT_BR	301
#define	RIGHT_BR	302
#define	DOT	303
#define	LEFT_SQ_BR	304
#define	RIGHT_SQ_BR	305
#define	COMMA	306
#define	QUOTE	307
#define	INVALID_CHARACTER	308
#define	PRINT	309
#define	RIGHT_CURL_BR	310
#define	LEFT_CURL_BR	311
#define	L_BR	312
#define	R_BR	313


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int STRING_LITERAL;
static const int PLUS;
static const int MINUS;
static const int MULT;
static const int DIV;
static const int COMMENT;
static const int ASSIGNMENT;
static const int RANGE;
static const int COLON;
static const int SEMICOLON;
static const int EQ;
static const int NEQ;
static const int LT;
static const int LTE;
static const int GT;
static const int GTE;
static const int IMPLICATION;
static const int AND;
static const int OR;
static const int XOR;
static const int NOT;
static const int VAR;
static const int IS;
static const int THEN;
static const int EMPTY;
static const int END;
static const int FUNCTION;
static const int IN;
static const int LOOP;
static const int FOR;
static const int WHILE;
static const int IF;
static const int ELSE;
static const int TRUE;
static const int FALSE;
static const int RETURN;
static const int INT;
static const int REAL;
static const int BOOL;
static const int STRING;
static const int INT_LITERAL;
static const int REAL_LITERAL;
static const int IDENTIFIER;
static const int LEFT_BR;
static const int RIGHT_BR;
static const int DOT;
static const int LEFT_SQ_BR;
static const int RIGHT_SQ_BR;
static const int COMMA;
static const int QUOTE;
static const int INVALID_CHARACTER;
static const int PRINT;
static const int RIGHT_CURL_BR;
static const int LEFT_CURL_BR;
static const int L_BR;
static const int R_BR;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,STRING_LITERAL=258
	,PLUS=259
	,MINUS=260
	,MULT=261
	,DIV=262
	,COMMENT=263
	,ASSIGNMENT=264
	,RANGE=265
	,COLON=266
	,SEMICOLON=267
	,EQ=268
	,NEQ=269
	,LT=270
	,LTE=271
	,GT=272
	,GTE=273
	,IMPLICATION=274
	,AND=275
	,OR=276
	,XOR=277
	,NOT=278
	,VAR=279
	,IS=280
	,THEN=281
	,EMPTY=282
	,END=283
	,FUNCTION=284
	,IN=285
	,LOOP=286
	,FOR=287
	,WHILE=288
	,IF=289
	,ELSE=290
	,TRUE=291
	,FALSE=292
	,RETURN=293
	,INT=294
	,REAL=295
	,BOOL=296
	,STRING=297
	,INT_LITERAL=298
	,REAL_LITERAL=299
	,IDENTIFIER=300
	,LEFT_BR=301
	,RIGHT_BR=302
	,DOT=303
	,LEFT_SQ_BR=304
	,RIGHT_SQ_BR=305
	,COMMA=306
	,QUOTE=307
	,INVALID_CHARACTER=308
	,PRINT=309
	,RIGHT_CURL_BR=310
	,LEFT_CURL_BR=311
	,L_BR=312
	,R_BR=313


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
