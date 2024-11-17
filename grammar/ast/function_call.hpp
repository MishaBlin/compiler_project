#pragma once

#include <string>

#include "elements.hpp"
#include "expression_node.hpp"

struct FunctionCall : public ExpressionNode {
  std::string function_name;
  Elements* args;
  Value* return_val;

  FunctionCall(const std::string& func_name, Elements* arguments);

  Value GetValue(Context* context) override;

  void Print(int indent) override;

  void Execute(Context* context) override;
};