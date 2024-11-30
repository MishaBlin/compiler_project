#!/bin/bash

bison -d -v grammar/parser.y -o grammar/parser.tab.c
flex -o grammar/lex.yy.c grammar/lexer.l 
g++ -o main main.cpp grammar/lex.yy.c grammar/parser.tab.c grammar/ast/*.cpp -lfl