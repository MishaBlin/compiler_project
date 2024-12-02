#include "arithmetic_operation.hpp"

#include <iostream>
#include <stdexcept>

#include "constant_node.hpp"
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

ExpressionNode *ArithmeticOperation::OptimizedNode() {
  this->left = this->left->OptimizedNode();
  this->right = this->right->OptimizedNode();
  if (dynamic_cast<ConstantNode *>(this->left) && dynamic_cast<ConstantNode *>(this->right)) {
    auto left = this->left->GetValue(nullptr);
    auto right = this->right->GetValue(nullptr);
    Value res;
    switch (this->operation) {
      case '+':
        res = left + right;
        break;
      case '-':
        res = left - right;
        break;
      case '*':
        res = left * right;
        break;
      case '/':
        res = left / right;
        break;
      case '%':
        res = left % right;
        break;
    }
    if (res.ivalue) {
      return new ConstantNode(*(res.ivalue));
    }
    if (res.dvalue) {
      return new ConstantNode(*(res.dvalue));
    }
    if (res.svalue) {
      return new ConstantNode(res.svalue);
    }
  }
  return this;
}
