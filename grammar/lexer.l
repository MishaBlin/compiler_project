%option noyywrap

%{
    #include <stdio.h>

    #include "tokens.hpp"

    const char* lexeme = NULL;
%}

digit      [0-9]
letter     [a-zA-Z]
identifier {letter}({letter}|{digit})*
integer    {digit}+
real       {integer}("."{integer})?("E"("+"|"-")?{integer})?

%%
"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return MULT; }
"//"             { return COMMENT; }
"/"              { return DIV; }
":="             { return ASSIGNMENT; }
".."             { return RANGE; }
":"              { return COLON; }
";"              { return SEMICOLON; }
"="              { return EQ; }
"/="             { return NEQ; }
"<"              { return LT; }
"<="             { return LTE; }
">"              { return GT; }
">="             { return GTE; }
"=>"             { return IMPLICATION; }
"and"            { return AND; }
"or"             { return OR; }
"xor"            { return XOR; }
"not"            { return NOT; }
"var"            { return VAR; }
"is"             { return IS; }
"then"           { return THEN; }
"empty"          { return EMPTY; }
"end"            { return END; }
"func"           { return FUNCTION; }
"in"             { return IN; }
"loop"           { return LOOP; }
"for"            { return FOR; }
"while"          { return WHILE; }
"if"             { return IF; }
"else"           { return ELSE; }
"true"           { return TRUE; }
"false"          { return FALSE; }
"return"         { return RETURN; }
"int"            { return INT; }
"real"           { return REAL; }
"bool"           { return BOOL; }
"string"         { return STRING; }
{integer}        { lexeme = yytext; return INT_LITERAL; }
{real}           { lexeme = yytext; return REAL_LITERAL; }
{identifier}     { lexeme = yytext; return IDENTIFIER; }
"("              { return LEFT_BR; }
")"              { return RIGHT_BR; }
"."              { return DOT; }
"["              { return LEFT_SQ_BR; }
"]"              { return RIGHT_SQ_BR; }
","              { return COMMA; }
"\""             { return QUOTE; }
[\t\f\r ]+        /* ignore whitespace */
\n                /* ignore newlines */
.                { return INVALID_CHARACTER; }
%%


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file;
    enum yytokentype token;
    while ((token = yylex()) != YYEOF) {
        printf("Token: %s [%d], Value: %s\n", tokenToString(token), token, yytext);
    }

    fclose(file);
    return 0;
}