#include "boolean_operation.hpp"

#include <iostream>

#include "constants.hpp"

BooleanOperation::BooleanOperation(ExpressionNode *l, ExpressionNode *r, const std::string &operation) : ExpressionNode() {
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

Value BooleanOperation::GetValue(Context *context) {
  auto l = this->left->GetValue(context);
  auto r = this->right->GetValue(context);
  if (!l.bvalue || !r.bvalue) {
    throw std::runtime_error("Unssupported operands");
  }
  Value res;
  if (this->operation == "AND") {
    res.bvalue = new bool(*(l.bvalue) && *(r.bvalue));
    return res;
  }

  if (this->operation == "OR") {
    res.bvalue = new bool(*(l.bvalue) || *(r.bvalue));
    return res;
  }

  if (this->operation == "XOR") {
    res.bvalue = new bool(*(l.bvalue) ^ *(r.bvalue));
    return res;
  }

  throw std::logic_error("Unsupported operator: " + this->operation);
}
