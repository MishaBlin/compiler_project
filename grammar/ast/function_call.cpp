#include "function_call.hpp"

#include <iostream>
#include <stdexcept>

#include "constants.hpp"
#include "function_node.hpp"

FunctionCall::FunctionCall(const std::string& func_name, Elements* arguments) : ExpressionNode() {
  this->function_name = func_name;
  this->args = arguments;
  this->return_val = nullptr;
}

Value FunctionCall::GetValue(Context* context) {
  return (this->return_val != nullptr ? *(this->return_val) : Value());
}

void FunctionCall::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Function call:" << std::endl;
  for (int i = 0; i < indent + 1; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Function: " << this->function_name << std::endl;
  for (int i = 0; i < indent + 1; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Function args: " << std::endl;
  if (this->args->elements.empty()) {
    std::cout << "<empty>" << std::endl;
    return;
  }

  for (auto arg : this->args->elements) {
    arg->Print(indent + 2);
  }
}

void FunctionCall::Execute(Context* context) {
  auto it = context;
  FunctionNode* function = nullptr;
  while (it != nullptr) {
    if (auto found = it->functions.find(this->function_name); found != it->functions.end() && found->second->parameters.size() == this->args->elements.size()) {
      function = found->second;
      break;
    }
    it = it->parent;
  }
  if (function == nullptr) {
    throw std::runtime_error("No such function with these arguments set found");
  }
  auto func_context = new Context(context);
  int cnt = 0;
  for (const auto& func_param : function->parameters) {
    func_context->locals[func_param] = this->args->elements[cnt++]->GetValue(context);
    // std::cout << "param: " << func_param << std::endl;
    // std::cout << "val: ";
    // func_context->locals[func_param].Print();
  }
//   func_context->PrintVars();
  try {
    function->Execute(func_context);
  } catch (const Value& value) {
    this->return_val = new Value(value);
  }
}