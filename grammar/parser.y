%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern FILE *yyin;
    extern int yylineno;
    extern int yylex();
    void yyerror(const char *s);
%}

%start Program

%union {
    int iconst;       /* For integer constants */
    float fconst;     /* For real constants */
    char* sconst;     /* For string literals */
    char* ident;      /* For identifiers */
}

/* Declare tokens from the lexer */

%token STRING_LITERAL PLUS MINUS MULT DIV COMMENT ASSIGNMENT RANGE COLON SEMICOLON
%token EQ NEQ LT LTE GT GTE IMPLICATION AND OR XOR NOT VAR IS THEN EMPTY END
%token FUNCTION IN LOOP FOR WHILE IF ELSE TRUE FALSE RETURN INT REAL BOOL STRING
%token INT_LITERAL REAL_LITERAL IDENTIFIER LEFT_BR RIGHT_BR DOT LEFT_SQ_BR RIGHT_SQ_BR COMMA QUOTE
%token INVALID_CHARACTER PRINT RIGHT_CURL_BR LEFT_CURL_BR

%left OR XOR AND
%left EQ NEQ LT LTE GT GTE  // Comparison operators
%left PLUS MINUS            // Add/Sub operators
%left MULT DIV              // Mul/Div operators

%%

Program : DeclarationsAndStatements ;

DeclarationsAndStatements : Declarations
                          | Statements
                          | Declarations Statements
                          | Statements Declarations
                          ;

Declarations : Declaration
             | Declarations Declaration
             ;

Declaration : VAR IDENTIFIER OptAssignment OptSemicolon
            ;

OptSemicolon : SEMICOLON
             | /* empty */
             ;

OptAssignment : ASSIGNMENT Expression
              | /* empty */
              ;

Expression : Relation
           | Expression LogicalOp Relation
           ;

LogicalOp : AND
          | OR
          | XOR
          ;

Relation : Factor
         | Relation RelOp Factor
         ;

RelOp : LT
      | LTE
      | GT
      | GTE
      | EQ
      | NEQ
      ;

Factor : Term
       | Factor AddOp Term
       ;

AddOp : PLUS
      | MINUS
      ;

Term : Unary
     | Term MulOp Unary
     ;

MulOp : MULT
      | DIV
      ;

Unary : OptUnary Primary OptTypeIndicator
      | Literal
      | LEFT_BR Expression RIGHT_BR
      ;

OptUnary : PLUS
         | MINUS
         | NOT
         | /* empty */
         ;

OptTypeIndicator : IS TypeIndicator
                 | /* empty */
                 ;

Primary : IDENTIFIER OptTail
        | TRUE
        | FALSE
        | STRING_LITERAL
        ;

OptTail : DOT INT_LITERAL
        | DOT IDENTIFIER
        | LEFT_SQ_BR Expression RIGHT_SQ_BR
        | LEFT_BR OptExprList RIGHT_BR
        | /* empty */
        ;

OptExprList : Expression
            | OptExprList COMMA Expression
            | /* empty */
            ;

Statement : Assignment
          | Print
          | Return
          | If
          | Loop
          ;

Assignment : Primary ASSIGNMENT Expression ;

Print : PRINT Expression OptPrintList ;

OptPrintList : COMMA Expression
             | /* empty */
             ;

Return : RETURN OptExpression ;

OptExpression : Expression
              | /* empty */
              ;

If : IF Expression THEN Body OptElse END ;

OptElse : ELSE Body
        | /* empty */
        ;

Loop : WHILE Expression LoopBody
     | FOR IDENTIFIER IN TypeIndicator LoopBody
     ;

LoopBody : LOOP Body END ;

TypeIndicator : INT
              | REAL
              | BOOL
              | STRING
              | EMPTY
              | LEFT_SQ_BR RIGHT_SQ_BR
              | LEFT_BR RIGHT_BR
              | FUNCTION
              | Expression RANGE Expression
              ;

Literal : INT_LITERAL
        | REAL_LITERAL
        | TRUE
        | FALSE
        | STRING_LITERAL
        | ArrayLiteral
        | TupleLiteral
        | FunctionLiteral
        ;

ArrayLiteral : LEFT_SQ_BR OptExprList RIGHT_SQ_BR ;

TupleLiteral : LEFT_CURL_BR OptTupleExprList RIGHT_CURL_BR ;

OptTupleExprList : TupleElement
                 | OptTupleExprList COMMA TupleElement
                 | /* empty */
                 ;

TupleElement : OptIdentifierAssignment Expression ;

OptIdentifierAssignment : IDENTIFIER ASSIGNMENT
                        | /* empty */
                        ;

FunctionLiteral : FUNCTION LEFT_BR OptIdentifierList RIGHT_BR FunBody ;

OptIdentifierList : IDENTIFIER
                  | OptIdentifierList COMMA IDENTIFIER
                  | /* empty */
                  ;

FunBody : IS Body END
        | IMPLICATION Expression
        ;

Body : DeclarationsAndStatements
     ;

Statements : Statement
           | Statements Statement
           ;

%%

void yyerror(const char *s)
{
  fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
  exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }

    if (strcmp(argv[2], "lexer") == 0) {
      int token;
      while ((token = yylex())) {
          // printf("Token: %d\n", token);
      }
    } else {
      int flag = yyparse();
      fprintf(stderr, "Flag %d\n", flag);
    }
    fclose(yyin);

    return 0;
}
