#include "lvalue.hpp"

#include <iostream>

#include "constants.hpp"

LocationValue::LocationValue(const std::string& name) : ExpressionNode() {
  this->name = name;
}

Value LocationValue::GetValue(Context* context) {
  auto it = context;
  while (it != nullptr) {
    if (it->locals.count(this->name)) {
      return it->locals[this->name]->GetValue(it);
    }
    it = it->parent;
  }
  throw std::runtime_error("Variable " + this->name + " not found");
}

void LocationValue::SetValue(Context* context, ExpressionNode* new_value) {
  auto it = context;
  while (it != nullptr) {
    if (it->locals.count(this->name)) {
      it->locals[this->name] = new_value;
      return;
    }
    it = it->parent;
  }
  throw std::runtime_error("Variable " + this->name + " not found");
}

void LocationValue::Print(int indent) {
  for (int i = 0; i < indent + 1; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Variable Name: " << this->name << std::endl;
}
