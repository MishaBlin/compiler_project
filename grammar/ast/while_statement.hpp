#pragma once

#include "blocks_node.hpp"
#include "expression_node.hpp"

struct WhileStatement : public Node {
  ExpressionNode *condition;
  BlocksNode *body;

  WhileStatement(ExpressionNode *condition, BlocksNode *body);
  void Execute(Context *context, const bool dry_run) override;
  void Optimize() override;

  void Print(int indent) override;
};