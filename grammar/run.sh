bison -d parser.y
flex lexer.l
gcc -o parser lex.yy.c parser.tab.c -ll

## ./parser input.txt [parser|lexer]
