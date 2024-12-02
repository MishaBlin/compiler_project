#include "not_operation.hpp"

#include <iostream>
#include <stdexcept>

#include "constants.hpp"

NotOperation::NotOperation(ExpressionNode* node) : ExpressionNode(), value(node) {
}

Value NotOperation::GetValue(Context* context) {
  auto val = this->value->GetValue(context);
  if (!val.bvalue) {
    throw std::runtime_error("No boolean operand to negate");
  }
  Value res;
  res.bvalue = new bool(!*(val.bvalue));
  return res;
}

void NotOperation::Print(const int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }

  std::cout << "Not operation:\n";
  this->value->Print(indent + 1);
}
