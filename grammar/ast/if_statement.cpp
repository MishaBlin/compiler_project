#include "if_statement.hpp"

#include <iostream>

#include "constants.hpp"

IfStatement::IfStatement(ExpressionNode *condition, BlocksNode *body, BlocksNode *elsebody) : Node() {
  this->condition = condition;
  this->body = body;
  this->elsebody = elsebody;
}

void IfStatement::Execute(Context *context) {
  if (*(condition->GetValue(context).bvalue)) {
    auto if_context = new Context(context);
    body->Execute(if_context);
    // if_context->PrintVars();
    delete if_context;
  } else {
    if (elsebody == nullptr) {
      return;
    }
    auto else_context = new Context(context);
    elsebody->Execute(else_context);
    // else_context->PrintVars();
    delete else_context;
  }
}

void IfStatement::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "IfStatement:" << std::endl;

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

  if (elsebody) {
    for (int i = 0; i < indent; i++) {
      std::cout << constants::kSpace;
    }
    std::cout << "  ElseBody:" << std::endl;
    elsebody->Print(indent + 2);
  }
}
