#pragma once

#include "lvalue.hpp"

struct Declaration : public Node {
  std::string var_name;
  ExpressionNode* var_value;

  Declaration(const std::string& name, ExpressionNode* value = nullptr);

  void Execute(Context *context) override;
  void Print(int indent) override;
};