#!/bin/bash

flex -o ./grammar/lex.yy.c ./grammar/lexer.l

gcc ./grammar/lex.yy.c -o lexer

./lexer $1

rm -f ./lexer ./grammar/lex.yy.c