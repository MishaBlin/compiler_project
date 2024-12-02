#pragma once

#include "expression_node.hpp"
#include "value.hpp"

struct ArithmeticOperation : public ExpressionNode {
  ExpressionNode *left;
  ExpressionNode *right;
  char operation;

  ArithmeticOperation(ExpressionNode *l, ExpressionNode *r, char op);
  void Print(int indent);
  Value GetValue(Context *context) override;
  ExpressionNode *OptimizedNode() override;
};