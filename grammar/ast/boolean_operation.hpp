#pragma once

#include <string>

#include "expression_node.hpp"

struct BooleanOperation : public ExpressionNode {
  ExpressionNode *left;
  ExpressionNode *right;
  std::string operation;

  BooleanOperation(ExpressionNode *l, ExpressionNode *r, const std::string &operation);
  void Print(int indent) override;
  Value GetValue(Context *context) override;
};