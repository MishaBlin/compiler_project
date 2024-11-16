#include "declaration.hpp"

#include <iostream>

#include "constants.hpp"

Declaration::Declaration(const std::string& name, ExpressionNode* value) : Node() {
  this->var_name = name;
  this->var_value = value;
}

void Declaration::Execute(Context* context) {
  // std::cout << "Declaration::Execute" << std::endl;
  context->locals[this->var_name] = this->var_value->GetValue(context);
}

void Declaration::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Variable Declaration" << std::endl;
  for (int i = 0; i < indent + 1; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Variable Name: " << this->var_name << std::endl;
  if (this->var_value) {
    this->var_value->Print(indent + 1);
  }
}
