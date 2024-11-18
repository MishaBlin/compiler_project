%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include <cstring>
    #include <vector>
    #include <iostream>

    #include "ast/ast.hpp"

    Node* root = nullptr;

    #define YYDEBUG 1
    extern FILE *yyin;
    extern int yylineno;
    extern int yylex();
    void yyerror(const char *s);

%}

%union {
    int iconst;       /* For integer constants */
    double fconst;     /* For real constants */
    std::string* sconst;     /* For string literals */
    char* ident;      /* For identifiers */
    Node* node;
    char* value;
}

%code requires {
    #include "ast/ast.hpp"
}


/* Declare tokens from the lexer */

%token IDENT INTEGER REAL STRING TRUE FALSE
%token VAR IF THEN ELSE WHILE FOR IN RETURN PRINT
%token AND OR XOR NOT IS
%token ASSIGN PLUS MINUS MUL DIV LT LE GT GE EQ NEQ
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET COMMA SEMICOLON
%token READINT READREAL READSTRING LOOP DOT END
%token INT_TYPE REAL_TYPE BOOL_TYPE STRING_TYPE EMPTY VECTOR TUPLE FUNC
%token INVALID_CHARACTER RANGE IMPLICATION MOD

%start Program


%type<value> IDENT INTEGER
%type<node> Program Declaration Statement VariableDefinition If Loop Return Print Assignment Array Tuple
%type<node> Expression Relation Factor Term Unary Literal Primary Reference Body ExpressionList TupleElementList TupleElement
%type<node> FunBody OptIdentifierList FunctionDeclaration FunctionCall

%%

Program
    : Program Statement {
        $1->Add($2); 
        $$ = $1;
        root = $$;
    }
    | /* empty */ {
        $$ = new ProgramNode(); 
        root = $$; 
    }
    ;

Statement
    : Declaration { $$ = $1; }
    | Assignment { $$ = $1; }
    | If { $$ = $1; }
    | Loop { $$ = $1; }
    | Return { $$ = $1; }
    | Print { $$ = $1; }
    | FunctionCall { $$ = $1; }
    ;

Declaration
    : VAR VariableDefinition {
        $$ = $2;
    }
    ;

FunctionDeclaration
    : FUNC LPAREN OptIdentifierList RPAREN FunBody {
        $$ = new FunctionNode((BlocksNode*)$5, (Parameters*)$3);
    }
    ;

VariableDefinition
    : IDENT {
        $$ = new Declaration(std::string($1)); 
    }
    | IDENT ASSIGN Expression { 
        $$ = new Declaration(std::string($1), (ExpressionNode*)$3);
    }
    | IDENT ASSIGN FunctionDeclaration {
        $$ = new Declaration(std::string($1), (FunctionNode*)$3);
    }
    ;

Assignment
    : Reference ASSIGN Expression {
        $$ = new AssignmentNode((ReferenceNode*)$1, (ExpressionNode*)$3);
    }
    ;

If
    : IF Expression THEN Body END {
        $$ = new IfStatement((ExpressionNode*)$2, (BlocksNode*)$4);
    }
    | IF Expression THEN Body ELSE Body END {
        $$ = new IfStatement((ExpressionNode*)$2, (BlocksNode*)$4, (BlocksNode*)$6);
    }
    ;

Loop
    : WHILE Expression LOOP Body END {
        $$ = new WhileStatement((ExpressionNode*)$2, (BlocksNode*)$4);
    }
    | FOR IDENT IN Expression RANGE Expression LOOP Body END {
        $$ = new ForStatement(std::string($2), (ExpressionNode*)$4, (ExpressionNode*)$6, (BlocksNode*)$8);
    }
    ;

Return
    : RETURN {
        $$ = new ReturnNode();
    }
    | RETURN Expression {
        $$ = new ReturnNode((ExpressionNode*)$2);
    }
    ;

Print
    : PRINT ExpressionList { 
        $$ = new PrintNode((Elements*)$2); 
    }
    ;

Body
    : Body Statement { 
        $1->Add($2); 
        $$ = $1;
    }
    | /* empty */ {
        $$ = new BlocksNode();
    }
    ;

Expression
    : Relation { $$ = $1; }
    | Expression AND Relation { $$ = new BooleanOperation((ExpressionNode*)$1, (ExpressionNode*)$3, "AND"); }
    | Expression OR Relation  { $$ = new BooleanOperation((ExpressionNode*)$1, (ExpressionNode*)$3, "OR"); }
    | Expression XOR Relation { $$ = new BooleanOperation((ExpressionNode*)$1, (ExpressionNode*)$3, "XOR"); }
    ;

Relation
    : Factor { $$ = $1; }
    | Relation LT Factor  { $$ = new RelationOperation((ExpressionNode*)$1, (ExpressionNode*)$3, "<"); }
    | Relation LE Factor  { $$ = new RelationOperation((ExpressionNode*)$1, (ExpressionNode*)$3, "<="); }
    | Relation GT Factor  { $$ = new RelationOperation((ExpressionNode*)$1, (ExpressionNode*)$3, ">"); }
    | Relation GE Factor  { $$ = new RelationOperation((ExpressionNode*)$1, (ExpressionNode*)$3, ">="); }
    | Relation EQ Factor  { $$ = new RelationOperation((ExpressionNode*)$1, (ExpressionNode*)$3, "="); }
    | Relation NEQ Factor { $$ = new RelationOperation((ExpressionNode*)$1, (ExpressionNode*)$3, "/="); }
    ;

Factor
    : Term { $$ = $1; }
    | Factor PLUS Term  { $$ = new ArithmeticOperation((ExpressionNode*)$1, (ExpressionNode*)$3, '+'); }
    | Factor MINUS Term { $$ = new ArithmeticOperation((ExpressionNode*)$1, (ExpressionNode*)$3,'-'); }
    ;

Term
    : Unary { $$ = $1; }
    | Term MUL Unary { $$ = new ArithmeticOperation((ExpressionNode*)$1, (ExpressionNode*)$3, '*'); }
    | Term DIV Unary { $$ = new ArithmeticOperation((ExpressionNode*)$1, (ExpressionNode*)$3, '/'); }
    | Term MOD Unary { $$ = new ArithmeticOperation((ExpressionNode*)$1, (ExpressionNode*)$3, '%'); }
    ;

Unary
    : Reference { $$ = $1; }
    | Reference IS TypeIndicator
    | Primary { $$ = $1; }
    | PLUS Primary
    | MINUS Primary
    | NOT Primary
    ;

FunctionCall
    : IDENT LPAREN ExpressionList RPAREN {
        $$ = new FunctionCall(std::string($1), (Elements*)$3);
    };

Primary
    : Literal { $$ = $1; }
    | LPAREN Expression RPAREN { $$ = $2; }
    | FunctionCall { $$ = $1; }
    ;

Literal
    : INTEGER { $$ = new ConstantNode(yylval.iconst); }
    | REAL { $$ = new ConstantNode(yylval.fconst); }
    | STRING { $$ = new ConstantNode(yylval.sconst); }
    | TRUE { $$ = new ConstantNode(true); }
    | FALSE { $$ = new ConstantNode(false); }
    | Tuple { $$ = $1; }
    | Array { $$ = $1; }
    | EMPTY { $$ = new ConstantNode(); }
    ;

Tuple
    : LBRACE TupleElementList RBRACE {
        $$ = new TupleNode((TupleElements*) $2);
    }
    ;

TupleElement
    : IDENT ASSIGN Expression {
        // std::cout<<"ident assig exp"<<std::endl;
        $$ = new TupleElement((ExpressionNode*) $3, new std::string($1));
        // std::cout<<"!!!!!!!!!"<<std::endl;
    }
    | Expression {
        $$ = new TupleElement((ExpressionNode*) $1);
    }
    ;

TupleElementList
    : TupleElement {
        TupleElements* elems = new TupleElements();
        elems->Add((TupleElement*) $1);
        $$ = elems;
    }
    | TupleElementList COMMA TupleElement {
        ((TupleElements*)$1)->Add((TupleElement*)$3);
        $$ = $1;
    }
    | {
        $$ = new TupleElements();
    }

Array
    : LBRACKET ExpressionList RBRACKET {
        $$ = new ArrayNode((Elements*) $2);
    }
    ;

ExpressionList
    : ExpressionList COMMA Expression {
        ((Elements*)$1)->Add((ExpressionNode*)$3);
        $$ = $1;
    }
    | Expression {
        Elements* e = new Elements();
        e->Add((ExpressionNode*)$1);
        $$ = e;
    }
    |  /* empty */ {
        $$ = new Elements();
    }
    ;

Reference
    : IDENT { 
        auto ref = new ReferenceNode();
        ref->elements.push_back(std::make_pair("lvalue", Identifier(std::string($1))));
        $$ = ref;
    }
    | Reference LBRACKET INTEGER RBRACKET { 
        std::cout << "Got here" << std::endl;
        std::cout << ($1 == nullptr) << std::endl;
        std::cout << yylval.iconst << std::endl;
        std::cout << "Finish here" << std::endl;
        ((ReferenceNode*)$1)->elements.push_back(std::make_pair("array", Identifier(yylval.iconst)));
        $$ = $1;
    };
    | Reference DOT IDENT {
        ((ReferenceNode*)$1)->elements.push_back(std::make_pair("tuple", Identifier(std::string($3))));
        $$ = $1;
    }
    | Reference DOT INTEGER {
        ((ReferenceNode*)$1)->elements.push_back(std::make_pair("tuple", Identifier(yylval.iconst)));
        $$ = $1;
    }
    ;

TypeIndicator
    : INT_TYPE
    | REAL_TYPE
    | BOOL_TYPE
    | STRING_TYPE
    | EMPTY
    | LBRACKET RBRACKET
    | LBRACE RBRACE
    | FUNC
    ;

OptIdentifierList 
    : IDENT {
        auto param = new Parameters();
        param->Add(std::string($1));
        $$ = param;
    }
    | OptIdentifierList COMMA IDENT{
        ((Parameters*)$1)->Add(std::string($3));
        $$ = $1;
    }
    | /* empty */ {
        $$ = new Parameters();
    }
    ; 

FunBody 
    : IS Body END {
        $$ = $2;
    }
    | IMPLICATION Statement {
        auto block = new BlocksNode();
        block->Add($2);
        $$ = block;
    }
    | IMPLICATION Statement SEMICOLON {
        auto block = new BlocksNode();
        block->Add($2);
        $$ = block;
    }
    ;

%%

void yyerror(const char *s)
{
  fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
  exit(1);
}

void PrintMessage(const std::string& message) {
    for (int i = 0; i < 10; i++) {
        std::cout << "==";
    }
    std::cout << ' ' << message << ' ';
    for (int i = 0; i < 10; i++) {
        std::cout << "==";
    }
    std::cout << std::endl;
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
      if (!root) {
        std::cout << "Root is null" << std::endl;
      } else {
        
        std::cout << "Root is not null" << std::endl;
        PrintMessage("AST Tree");
        root->Print(0);
        
        PrintMessage("Program Start");
        root->Execute(nullptr);
        PrintMessage("Program Finish");
      }
      if (flag == 0) {
        std::cout << "Success :)" << std::endl;
      } else {
        std::cout << "Failure :(" << std::endl;
      }
    }
    fclose(yyin);

    return 0;
}
