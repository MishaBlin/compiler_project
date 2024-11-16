#include "while_statement.hpp"

#include <iostream>

#include "constants.hpp"

WhileStatement::WhileStatement(ExpressionNode *condition, BlocksNode *body) : Node() {
  this->condition = condition;
  this->body = body;
}

void WhileStatement::Execute(Context *context) {
  auto while_context = new Context(context);
  while (*(condition->GetValue(context).bvalue)) {
    body->Execute(while_context);
  }
  delete while_context;
}

void WhileStatement::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "WhileLoop:" << std::endl;

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "  Condition:" << std::endl;
  this->condition->Print(indent + 2);

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "  Body:" << std::endl;
  body->Print(indent + 2);
}
