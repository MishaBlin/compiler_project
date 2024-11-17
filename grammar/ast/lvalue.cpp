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
      return it->locals[this->name];
    }
    it = it->parent;
  }
  throw std::runtime_error("Variable " + this->name + " not found");
}

void LocationValue::SetValue(Context* context, ExpressionNode* new_value) {
  // std::cout << "LocationValue::SetValue" << std::endl;
  auto it = context;
  while (it != nullptr) {
    if (it->locals.count(this->name)) {
      it->locals[this->name] = new_value->GetValue(context);
      return;
    }
    it = it->parent;
  }
  throw std::runtime_error("Variable " + this->name + " not found");
}

void LocationValue::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Variable Name: " << this->name << std::endl;
}
