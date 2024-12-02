#include <iostream>

#include "grammar/ast/ast.hpp"
#include "grammar/parser.tab.h"

Node *root = nullptr;

extern FILE *yyin;
extern int yylineno;
extern int yylex();

void yyerror(const char *s) {
  fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
  exit(1);
}

void PrintMessage(const std::string &message) {
  for (int i = 0; i < 10; i++) {
    std::cout << "==";
  }
  std::cout << ' ' << message << ' ';
  for (int i = 0; i < 10; i++) {
    std::cout << "==";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  yyin = fopen(argv[1], "r");
  if (!yyin) {
    perror(argv[1]);
    return 1;
  }

  if (argv[2] == "lexer") {
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
      PrintMessage("Optimized AST Tree");
      root->Optimize();
      root->Print(0);

      PrintMessage("Program Start");
      root->Execute(nullptr, false);
      PrintMessage("Program Finish");
    }
  }
  fclose(yyin);

  return 0;
}