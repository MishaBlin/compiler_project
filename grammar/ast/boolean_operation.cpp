#include "boolean_operation.hpp"

#include <iostream>

#include "constants.hpp"

BooleanOperation::BooleanOperation(ExpressionNode *l, ExpressionNode *r, const std::string &operation) : Node() {
  this->left = l;
  this->right = r;
  this->operation = operation;
}

void BooleanOperation::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Operation " << this->operation << std::endl;
  this->left->Print(indent + 1);
  this->right->Print(indent + 1);
}
