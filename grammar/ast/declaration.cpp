#include "declaration.hpp"

#include <iostream>

#include "constants.hpp"
#include "function_node.hpp"

Declaration::Declaration(const std::string& name, ExpressionNode* value) : Node() {
  this->var_name = name;
  this->var_value = value;
}

Declaration::Declaration(const std::string& name, FunctionNode* function) : Node() {
  this->var_name = name;
  this->func_def = function;
}

void Declaration::Execute(Context* context, const bool dry_run) {
  if (dry_run) {
    return;
  }

  if (this->func_def != nullptr) {
    this->func_def->context = context->Clone();
    context->locals[this->var_name] = this->func_def->GetValue(context);
    return;
  }

  context->locals[this->var_name] = this->var_value ? this->var_value->GetValue(context) : Value();
}

void Declaration::Optimize() {
  if (this->func_def) {
    this->func_def->Optimize();
  }
}

void Declaration::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Variable Declaration" << std::endl;
  for (int i = 0; i < indent + 1; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Variable Name: " << this->var_name << std::endl;
  if (this->func_def) {
    this->func_def->Print(indent + 2);
  }
  if (this->var_value) {
    this->var_value->Print(indent + 2);
  }
}
