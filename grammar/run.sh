bison -d -v parser.y
flex lexer.l
g++ -o parser lex.yy.c parser.tab.c -lfl
## ./parser input.txt [parser|lexer]
