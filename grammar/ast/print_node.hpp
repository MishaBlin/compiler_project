#pragma once

#include "expression_node.hpp"

struct PrintNode : public Node {
  ExpressionNode *expression;

  PrintNode(ExpressionNode *exp);

  void Print(int indent) override;
  void Execute(Context *context) override;

  ~PrintNode();
};