#include "constant_node.hpp"

#include <iostream>

#include "constants.hpp"

ConstantNode::ConstantNode() : ExpressionNode() {
  this->value = Value();
}

ConstantNode::ConstantNode(int value) : ConstantNode() {
  this->value.ivalue = new int(value);
}

ConstantNode::ConstantNode(double value) : ConstantNode() {
  this->value.dvalue = new double(value);
}

ConstantNode::ConstantNode(const std::string* value) : ConstantNode() {
  this->value.svalue = new std::string(*value);
}

ConstantNode::ConstantNode(bool value) : ConstantNode() {
  this->value.bvalue = new bool(value);
}

void ConstantNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "constant ";
  if (this->value.ivalue) {
    std::cout << "integer: " << *(this->value.ivalue) << std::endl;
    return;
  }

  if (this->value.dvalue) {
    std::cout << "double: " << *(this->value.dvalue) << std::endl;
    return;
  }

  if (this->value.svalue) {
    std::cout << "string: " << *(this->value.svalue) << std::endl;
    return;
  }

  if (this->value.bvalue) {
    std::cout << "bool: " << (*(this->value.bvalue) ? "true" : "false") << std::endl;
    return;
  }
}

Value ConstantNode::GetValue(Context* context) {
  return this->value;
}
