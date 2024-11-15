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
"//".*           {} 
"+"              { printf("PLUS: %s\n", yytext); return PLUS; }
"-"              { printf("MINUS: %s\n", yytext); return MINUS; }
"*"              { printf("MUL: %s\n", yytext); return MUL; }
"/"              { printf("DIV: %s\n", yytext); return DIV; }
"%"              { printf("MOD: %s\n", yytext); return MOD; }
":="             { printf("ASSIGN: %s\n", yytext); return ASSIGN; }
".."             { printf("RANGE: %s\n", yytext); return RANGE; }
";"              { printf("SEMICOLON: %s\n", yytext); return SEMICOLON; }
"="              { printf("EQ: %s\n", yytext); return EQ; }
"/="             { printf("NEQ: %s\n", yytext); return NEQ; }
"<"              { printf("LT: %s\n", yytext); return LT; }
"<="             { printf("LE: %s\n", yytext); return LE; }
">"              { printf("GT: %s\n", yytext); return GT; }
">="             { printf("GE: %s\n", yytext); return GE; }
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
"func"           { printf("FUNC: %s\n", yytext); return FUNC; }
"in"             { printf("IN: %s\n", yytext); return IN; }
"loop"           { printf("LOOP: %s\n", yytext); return LOOP; }
"for"            { printf("FOR: %s\n", yytext); return FOR; }
"while"          { printf("WHILE: %s\n", yytext); return WHILE; }
"if"             { printf("IF: %s\n", yytext); return IF; }
"else"           { printf("ELSE: %s\n", yytext); return ELSE; }
"true"           { printf("TRUE: %s\n", yytext); return TRUE; }
"false"          { printf("FALSE: %s\n", yytext); return FALSE; }
"return"         { printf("RETURN: %s\n", yytext); return RETURN; }
"int"            { printf("INT_TYPE: %s\n", yytext); return INT_TYPE; }
"real"           { printf("REAL_TYPE: %s\n", yytext); return REAL_TYPE; }
"bool"           { printf("BOOL_TYPE: %s\n", yytext); return BOOL_TYPE; }
"string"         { printf("STRING_TYPE: %s\n", yytext); return STRING_TYPE; }
"print"          { printf("PRINT: %s\n", yytext); return PRINT; }
{integer}        { 
                    yylval.iconst = atoi(yytext);
                    printf("INTEGER: %s\n", yytext);
                    return INTEGER;
                 }
{real}           { 
                    yylval.fconst = atof(yytext);
                    printf("REAL: %s\n", yytext);
                    return REAL; 
                 }
{identifier}     { 
                    yylval.ident = strdup(yytext);
                    printf("IDENTIFIER: %s\n", yytext);
                    return IDENT; 
                 }
\"([^\"]*)\"     { 
                    yylval.sconst = new std::string(yytext, 1, strlen(yytext) - 2); 
                    printf("STRING: %s\n", yytext);
                    return STRING; 
                 }
"("              { printf("LPAREN: %s\n", yytext); return LPAREN; }
")"              { printf("RPAREN: %s\n", yytext); return RPAREN; }
"{"              { printf("LBRACE: %s\n", yytext); return LBRACE; }
"}"              { printf("RBRACE: %s\n", yytext); return RBRACE; }
"."              { printf("DOT: %s\n", yytext); return DOT; }
"["              { printf("LBRACKET: %s\n", yytext); return LBRACKET; }
"]"              { printf("RBRACKET: %s\n", yytext); return RBRACKET; }
","              { printf("COMMA: %s\n", yytext); return COMMA; }
[\t\f\r ]+       /* ignore whitespace */
\n               { yylineno++; /* Increment lineno on newline */ }
.                { 
                    printf("INVALID_CHARACTER: %s\n", yytext); 
                    return INVALID_CHARACTER; 
                 }
