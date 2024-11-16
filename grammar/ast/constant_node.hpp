#pragma once

#include "expression_node.hpp"
#include "value.hpp"

struct ConstantNode : public ExpressionNode {
  Value value;

  ConstantNode();
  ConstantNode(int value);
  ConstantNode(double value);
  ConstantNode(bool value);
  ConstantNode(const std::string *value);

  void Print(int indent);
  Value GetValue(Context* context) override;
};
