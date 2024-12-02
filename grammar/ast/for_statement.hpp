#pragma once

#include <string>

#include "blocks_node.hpp"
#include "expression_node.hpp"

struct ForStatement : public Node {
  ExpressionNode *begin;
  ExpressionNode *end;
  std::string it_name;
  BlocksNode *body;

  ForStatement(const std::string &it_name, ExpressionNode *begin, ExpressionNode *end, BlocksNode *body);
  void Execute(Context *context, const bool dry_run) override;
  void Optimize() override;
  void Print(int indent) override;
};
