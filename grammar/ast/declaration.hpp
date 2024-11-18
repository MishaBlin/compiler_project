#pragma once

#include "function_node.hpp"

struct Declaration : public Node {
  std::string var_name;
  ExpressionNode* var_value;
  FunctionNode* func_def;

  Declaration(const std::string& name, ExpressionNode* value = nullptr);

  Declaration(const std::string& name, FunctionNode* function);

  void Execute(Context* context) override;
  void Print(int indent) override;
};