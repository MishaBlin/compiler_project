%option noyywrap
%option yylineno

%{
    #include "parser.tab.h"  // For token definitions

    extern YYSTYPE yylval;  // Declare yylval from Bison
%}

digit      [0-9]
letter     [a-zA-Z]
identifier {letter}({letter}|{digit})*
integer    {digit}+
real       {integer}("."{integer})?("E"("+"|"-")?{integer})?

%%
"//".*           { printf("Eat up comment at line %d\n", yylineno); } 
\".*\"           { 
                    yylval.sconst = strdup(yytext); 
                    printf("STRING_LITERAL: %s\n", yytext);
                    return STRING_LITERAL; 
                 }
"+"              { printf("PLUS: %s\n", yytext); return PLUS; }
"-"              { printf("MINUS: %s\n", yytext); return MINUS; }
"*"              { printf("MULT: %s\n", yytext); return MULT; }
"/"              { printf("DIV: %s\n", yytext); return DIV; }
":="             { printf("ASSIGNMENT: %s\n", yytext); return ASSIGNMENT; }
".."             { printf("RANGE: %s\n", yytext); return RANGE; }
";"              { printf("SEMICOLON: %s\n", yytext); return SEMICOLON; }
"="              { printf("EQ: %s\n", yytext); return EQ; }
"/="             { printf("NEQ: %s\n", yytext); return NEQ; }
"<"              { printf("LT: %s\n", yytext); return LT; }
"<="             { printf("LTE: %s\n", yytext); return LTE; }
">"              { printf("GT: %s\n", yytext); return GT; }
">="             { printf("GTE: %s\n", yytext); return GTE; }
"=>"             { printf("IMPLICATION: %s\n", yytext); return IMPLICATION; }
"and"            { printf("AND: %s\n", yytext); return AND; }
"or"             { printf("OR: %s\n", yytext); return OR; }
"xor"            { printf("XOR: %s\n", yytext); return XOR; }
"not"            { printf("NOT: %s\n", yytext); return NOT; }
"var"            { printf("VAR: %s\n", yytext); return VAR; }
"is"             { printf("IS: %s\n", yytext); return IS; }
"then"           { printf("THEN: %s\n", yytext); return THEN; }
"empty"          { printf("EMPTY: %s\n", yytext); return EMPTY; }
"end"            { printf("END: %s\n", yytext); return END; }
"func"           { printf("FUNCTION: %s\n", yytext); return FUNCTION; }
"in"             { printf("IN: %s\n", yytext); return IN; }
"loop"           { printf("LOOP: %s\n", yytext); return LOOP; }
"for"            { printf("FOR: %s\n", yytext); return FOR; }
"while"          { printf("WHILE: %s\n", yytext); return WHILE; }
"if"             { printf("IF: %s\n", yytext); return IF; }
"else"           { printf("ELSE: %s\n", yytext); return ELSE; }
"true"           { printf("TRUE: %s\n", yytext); return TRUE; }
"false"          { printf("FALSE: %s\n", yytext); return FALSE; }
"return"         { printf("RETURN: %s\n", yytext); return RETURN; }
"int"            { printf("INT: %s\n", yytext); return INT; }
"real"           { printf("REAL: %s\n", yytext); return REAL; }
"bool"           { printf("BOOL: %s\n", yytext); return BOOL; }
"string"         { printf("STRING: %s\n", yytext); return STRING; }
"print"          { printf("PRINT: %s\n", yytext); return PRINT; }
{integer}        { 
                    yylval.iconst = atoi(yytext);
                    printf("INT_LITERAL: %s\n", yytext);
                    return INT_LITERAL;
                 }
{real}           { 
                    yylval.fconst = atof(yytext);
                    printf("REAL_LITERAL: %s\n", yytext);
                    return REAL_LITERAL; 
                 }
{identifier}     { 
                    yylval.ident = strdup(yytext);
                    printf("IDENTIFIER: %s\n", yytext);
                    return IDENTIFIER; 
                 }
"("              { printf("LEFT_BR: %s\n", yytext); return LEFT_BR; }
")"              { printf("RIGHT_BR: %s\n", yytext); return RIGHT_BR; }
"{"              { printf("LEFT_CURL_BR: %s\n", yytext); return LEFT_CURL_BR; }
"}"              { printf("RIGHT_CURL_BR: %s\n", yytext); return RIGHT_CURL_BR; }
"."              { printf("DOT: %s\n", yytext); return DOT; }
"["              { printf("LEFT_SQ_BR: %s\n", yytext); return LEFT_SQ_BR; }
"]"              { printf("RIGHT_SQ_BR: %s\n", yytext); return RIGHT_SQ_BR; }
","              { printf("COMMA: %s\n", yytext); return COMMA; }
[\t\f\r ]+       /* ignore whitespace */
\n               { yylineno++; /* Increment lineno on newline */ }
.                { 
                    printf("INVALID_CHARACTER: %s\n", yytext); 
                    return INVALID_CHARACTER; 
                 }
