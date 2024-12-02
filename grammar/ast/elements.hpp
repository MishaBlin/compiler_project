#pragma once

#include <vector>

#include "expression_node.hpp"

struct Elements : public ExpressionNode {
  std::vector<ExpressionNode *> elements;

  Elements();

  void Add(ExpressionNode *elem);
  void Execute(Context *context, const bool dry_run) override;
  void Optimize() override;
};