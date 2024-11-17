#pragma once

#include "expression_node.hpp"

struct ReturnNode : public ExpressionNode {
  ExpressionNode* return_exp;

  ReturnNode(ExpressionNode* return_exp = nullptr);

  Value GetValue(Context* context) override;

  void Print(int indent) override;

  void Execute(Context* context) override;
};