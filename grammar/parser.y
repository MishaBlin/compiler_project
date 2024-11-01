%{  
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    

    extern FILE *yyin;
    extern int yylineno;
    extern int yylex();
    void yyerror(const char *s);

    // AST Node structure definition
    typedef enum { NODE_DECLARATION, NODE_STATEMENT, NODE_EXPRESSION } NodeType;

    typedef struct ASTNode {
        NodeType type;
        char* value;
        struct ASTNode* left;
        struct ASTNode* right;
    } ASTNode;

    ASTNode* create_node(NodeType type, char* value, ASTNode* left, ASTNode* right);
    void print_ast(ASTNode* node, int indent);

    // Create a new AST node
    ASTNode* create_node(NodeType type, char* value, ASTNode* left, ASTNode* right) {
        ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
        node->type = type;
        node->value = strdup(value);  // Copy the string value
        node->left = left;
        node->right = right;
        return node;
    }

    // Print the AST in a readable format
    void print_ast(ASTNode* node, int indent) {
        if (!node) return;
        for (int i = 0; i < indent; i++) printf("  ");
        printf("%s\n", node->value);
        print_ast(node->left, indent + 1);
        print_ast(node->right, indent + 1);
    }
%}


%start Program

%union {
    int iconst;       /* For integer constants */
    float fconst;     /* For real constants */
    char* sconst;     /* For string literals */
    char* ident;      /* For identifiers */
    struct ASTNode* node; /* For AST nodes */
}
%type <node> Program DeclarationsAndStatements Declarations Declaration Statements Statement Assignment Expression Relation Factor Term Unary Primary OptAssignment OptTypeIndicator OptExprList Return OptExpression
%type <node> TypeIndicator // Add this line for TypeIndicator
%type <node> Literal // Add this line for Literal
%type <node> AddOp
%type <node> RelOp
%type <node> OptUnary
%type <node> INT_LITERAL, REAL_LITERAL, TRUE, FALSE, STRING_LITERAL



/* Declare tokens from the lexer */

%token STRING_LITERAL PLUS MINUS MULT DIV COMMENT ASSIGNMENT RANGE COLON SEMICOLON
%token EQ NEQ LT LTE GT GTE IMPLICATION AND OR XOR NOT VAR IS THEN EMPTY END
%token FUNCTION IN LOOP FOR WHILE IF ELSE TRUE FALSE RETURN INT REAL BOOL STRING
%token INT_LITERAL REAL_LITERAL IDENTIFIER LEFT_BR RIGHT_BR DOT LEFT_SQ_BR RIGHT_SQ_BR COMMA QUOTE
%token INVALID_CHARACTER PRINT RIGHT_CURL_BR LEFT_CURL_BR
%token <ident> IDENTIFIER

%type  <node> LogicalOp

%left OR XOR AND
%left EQ NEQ LT LTE GT GTE  // Comparison operators
%left PLUS MINUS            // Add/Sub operators
%left MULT DIV              // Mul/Div operators

%%

Program : DeclarationsAndStatements {
    print_ast($1, 0);  // Print the AST after parsing
    $$ = $1;           // Store the root AST node
}
;

DeclarationsAndStatements : Declarations {
    $$ = create_node(NODE_DECLARATION, "DeclarationsAndStatements", $1, NULL);
}
| Statements {
    $$ = create_node(NODE_STATEMENT, "DeclarationsAndStatements", $1, NULL);
}
| Declarations Statements {
    $$ = create_node(NODE_DECLARATION, "DeclarationsAndStatements", $1, $2);
}
| Statements Declarations {
    $$ = create_node(NODE_STATEMENT, "DeclarationsAndStatements", $1, $2);
}
;



Declarations : Declaration { $$ = create_node(NODE_DECLARATION, "Declaration", $1, NULL); }
             | Declarations Declaration { $$ = create_node(NODE_DECLARATION, "Declarations", $1, $2); }
;

Declaration : VAR IDENTIFIER OptAssignment OptSemicolon {
    // Create an AST node for the variable declaration
    $$ = create_node(NODE_DECLARATION, "VarDeclaration", create_node(NODE_EXPRESSION, $2, $3, NULL), NULL);
}
;




OptSemicolon : SEMICOLON
             | /* empty */
             ;

OptAssignment : ASSIGNMENT Expression {
    // Create an AST node for the optional assignment
    $$ = create_node(NODE_EXPRESSION, "OptAssignment", NULL, $2);  // Right side expression
}
| /* empty */ {
    $$ = NULL;  // Representing the absence of an assignment
}
;


Expression : Relation {
    $$ = $1;
}
| Expression LogicalOp Relation {
    $$ = create_node(NODE_EXPRESSION, $2->value, $1, $3);  // Use $2->value to get the operator
}
;


LogicalOp : AND {
    $$ = create_node(NODE_EXPRESSION, "AND", NULL, NULL);
}
| OR {
    $$ = create_node(NODE_EXPRESSION, "OR", NULL, NULL);
}
| XOR {
    $$ = create_node(NODE_EXPRESSION, "XOR", NULL, NULL);
}
;

Relation : Factor {
    $$ = $1;  // Set the relation to the factor node
}
| Relation RelOp Factor {
    // Create a new AST node for the relational operation
    $$ = create_node(NODE_EXPRESSION, $2->value, $1, $3);  // $2 contains the relational operator
}
;

RelOp : LT {
    $$ = create_node(NODE_EXPRESSION, "LT", NULL, NULL);  // Less Than
}
| LTE {
    $$ = create_node(NODE_EXPRESSION, "LTE", NULL, NULL);  // Less Than or Equal
}
| GT {
    $$ = create_node(NODE_EXPRESSION, "GT", NULL, NULL);  // Greater Than
}
| GTE {
    $$ = create_node(NODE_EXPRESSION, "GTE", NULL, NULL);  // Greater Than or Equal
}
| EQ {
    $$ = create_node(NODE_EXPRESSION, "EQ", NULL, NULL);  // Equal
}
| NEQ {
    $$ = create_node(NODE_EXPRESSION, "NEQ", NULL, NULL);  // Not Equal
}
;


Factor : Term {
    // When a factor is just a term, return the term directly
    $$ = $1; 
}
| Factor AddOp Term {
    // When a factor consists of another factor, an operator, and a term,
    // create an AST node for the operation
    $$ = create_node(NODE_EXPRESSION, $2->value, $1, $3); // Use the operator's value and the two terms
}
;

AddOp : PLUS {
    // Create an AST node for the addition operator
    $$ = create_node(NODE_EXPRESSION, "PLUS", NULL, NULL);
}
| MINUS {
    // Create an AST node for the subtraction operator
    $$ = create_node(NODE_EXPRESSION, "MINUS", NULL, NULL);
}
;


Term : Unary
     | Term MulOp Unary
     ;

MulOp : MULT
      | DIV
      ;

Unary : OptUnary Primary OptTypeIndicator {
    // Create a unary AST node based on the optional unary operator
    if ($1) {
        $$ = create_node(NODE_EXPRESSION, $1->value, $2, NULL); // Operator with primary
    } else {
        $$ = $2; // No unary operator, just return the primary
    }
}
| Literal {
    $$ = $1; // Return the literal as an AST node
}
| LEFT_BR Expression RIGHT_BR {
    $$ = $2; // Return the expression inside the parentheses
}
;

OptUnary : PLUS {
    // Create an AST node for the unary plus operator
    $$ = create_node(NODE_EXPRESSION, "PLUS", NULL, NULL);
}
| MINUS {
    // Create an AST node for the unary minus operator
    $$ = create_node(NODE_EXPRESSION, "MINUS", NULL, NULL);
}
| NOT {
    // Create an AST node for the NOT operator
    $$ = create_node(NODE_EXPRESSION, "NOT", NULL, NULL);
}
| /* empty */ {
    $$ = NULL; // No unary operator present
}
;


OptTypeIndicator : IS TypeIndicator {
    // Create an AST node indicating a type indicator
    $$ = create_node(NODE_EXPRESSION, "IS", $2, NULL);  // $2 contains the type indicator AST node
}
| /* empty */ {
    $$ = NULL;  // Return NULL if no type indicator is present
}
;
Primary : IDENTIFIER {
    // Create an AST node for the identifier with its optional tail
    $$ = create_node(NODE_EXPRESSION, $1, NULL, NULL);  // $1 is the identifier, $2 is the tail
}
| TRUE {
    // Create an AST node for the boolean literal TRUE
    $$ = create_node(NODE_EXPRESSION, "TRUE", NULL, NULL);
}
| FALSE {
    // Create an AST node for the boolean literal FALSE
    $$ = create_node(NODE_EXPRESSION, "FALSE", NULL, NULL);
}
| STRING_LITERAL {
    // Create an AST node for the string literal
    $$ = create_node(NODE_EXPRESSION, $1, NULL, NULL);
}
;

OptTail : DOT INT_LITERAL
        | DOT IDENTIFIER
        | LEFT_SQ_BR Expression RIGHT_SQ_BR
        | LEFT_BR OptExprList RIGHT_BR
        | /* empty */
        ;

OptExprList : Expression {
    // Create an AST node for a single expression
    $$ = create_node(NODE_EXPRESSION, "ExpressionList", $1, NULL);  // $1 is the single expression
}
| OptExprList COMMA Expression {
    // Create an AST node for multiple expressions
    $$ = create_node(NODE_EXPRESSION, "ExpressionList", $1, $3);  // $1 is the previous list, $3 is the new expression
}
| /* empty */ {
    $$ = NULL;  // Return NULL if no expressions are present
}
;

Statement : Assignment {
    $$ = $1;  // The assignment node
}

;

// Assignment Rule
Assignment : Primary ASSIGNMENT Expression {
    $$ = create_node(NODE_STATEMENT, "Assignment", create_node(NODE_EXPRESSION, $1->value, NULL, $3), NULL); // Assign the value to the identifier
}
;


Print : PRINT Expression OptPrintList ;

OptPrintList : COMMA Expression
             | /* empty */
             ;

Return : RETURN OptExpression {
    // Create an AST node for the return statement
    $$ = create_node(NODE_STATEMENT, "Return", $2, NULL);  // $2 is the optional expression
}
;

OptExpression : Expression {
    // Create an AST node for the expression being returned
    $$ = $1;  // $1 is the expression
}
| /* empty */ {
    $$ = NULL;  // Return NULL if no expression is present
}
;


If : IF Expression THEN Body OptElse END ;

OptElse : ELSE Body
        | /* empty */
        ;

Loop : WHILE Expression LoopBody
     | FOR IDENTIFIER IN TypeIndicator LoopBody
     ;

LoopBody : LOOP Body END ;

// TypeIndicator Rule
TypeIndicator : INT {
    $$ = create_node(NODE_EXPRESSION, "INT", NULL, NULL);
}
| REAL {
    $$ = create_node(NODE_EXPRESSION, "REAL", NULL, NULL);
}
| BOOL {
    $$ = create_node(NODE_EXPRESSION, "BOOL", NULL, NULL);
}
| STRING {
    $$ = create_node(NODE_EXPRESSION, "STRING", NULL, NULL);
}
| EMPTY {
    $$ = create_node(NODE_EXPRESSION, "EMPTY", NULL, NULL);
}
| LEFT_SQ_BR RIGHT_SQ_BR {
    $$ = create_node(NODE_EXPRESSION, "ArrayType", NULL, NULL); // Represents an empty array
}
| LEFT_BR RIGHT_BR {
    $$ = create_node(NODE_EXPRESSION, "FunctionType", NULL, NULL); // Represents an empty function
}
| FUNCTION {
    $$ = create_node(NODE_EXPRESSION, "FUNCTION", NULL, NULL);
}
| Expression RANGE Expression {
    $$ = create_node(NODE_EXPRESSION, "Range", $1, $3); // Represents a range type
}
;


// Literal Rule
Literal : INT_LITERAL {
    // Create an AST node for integer literals with the actual value
    char buffer[20];  // Buffer to hold the string representation of the integer
    snprintf(buffer, sizeof(buffer), "%d", $1);  // Convert integer to string
    $$ = create_node(NODE_EXPRESSION, strdup(buffer), NULL, NULL);
}
| REAL_LITERAL {
    // Create an AST node for real literals with the actual value
    char buffer[20];  // Buffer to hold the string representation of the real number
    snprintf(buffer, sizeof(buffer), "%.2f", $1);  // Convert float to string with 2 decimal precision
    $$ = create_node(NODE_EXPRESSION, strdup(buffer), NULL, NULL);
}
| TRUE {
    // Create an AST node for the boolean literal TRUE
    $$ = create_node(NODE_EXPRESSION, "TRUE", NULL, NULL);
}
| FALSE {
    // Create an AST node for the boolean literal FALSE
    $$ = create_node(NODE_EXPRESSION, "FALSE", NULL, NULL);
}
| STRING_LITERAL {
    // Create an AST node for string literals with the actual value
    $$ = create_node(NODE_EXPRESSION, $1, NULL, NULL);  // Use the string value directly
}



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

Statements : Statement {
    $$ = create_node(NODE_STATEMENT, "Statement", $1, NULL);
}
| Statements Statement {
    $$ = create_node(NODE_STATEMENT, "Statements", $1, $2);
}
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
