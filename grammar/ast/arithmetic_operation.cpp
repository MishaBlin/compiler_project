#include "arithmetic_operation.hpp"

#include <iostream>
#include <stdexcept>

#include "constants.hpp"

ArithmeticOperation::ArithmeticOperation(ExpressionNode *l, ExpressionNode *r, char op) : ExpressionNode() {
  this->left = l;
  this->right = r;
  this->operation = op;
}

void ArithmeticOperation::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Operation " << this->operation << std::endl;
  this->left->Print(indent + 1);
  this->right->Print(indent + 1);
}

Value ArithmeticOperation::GetValue(Context *context) {
  switch (operation) {
    case '+':
      return this->left->GetValue(context) + this->right->GetValue(context);
    case '-':
      return this->left->GetValue(context) - this->right->GetValue(context);
    case '/':
      return this->left->GetValue(context) / this->right->GetValue(context);
    case '%':
      return this->left->GetValue(context) % this->right->GetValue(context);
    case '*':
      return this->left->GetValue(context) * this->right->GetValue(context);
    default:
      throw std::logic_error("invalid arithmetic operator");
  }
}
