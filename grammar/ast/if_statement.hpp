#pragma once

#include "blocks_node.hpp"
#include "expression_node.hpp"

struct IfStatement : public Node {
  ExpressionNode *condition;
  BlocksNode *body;
  BlocksNode *elsebody;

  IfStatement(ExpressionNode *condition, BlocksNode *body, BlocksNode *elsebody = nullptr);
  void Execute(Context *context) override;
  void Print(int indent) override;
};