#pragma once

#include <string>

#include "expression_node.hpp"

struct LocationValue : public ExpressionNode {
  std::string name;

  LocationValue(const std::string &name);
  Value GetValue(Context *context) override;
  void SetValue(Context *context, ExpressionNode *new_value);
  void Print(int indent) override;
};