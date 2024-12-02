#pragma once

#include <string>

#include "expression_node.hpp"
#include "value.hpp"

struct RelationOperation : public ExpressionNode {
  ExpressionNode *left;
  ExpressionNode *right;
  std::string operation;

  RelationOperation(ExpressionNode *l, ExpressionNode *r, const std::string &operation);
  void Print(int indent);
  Value GetValue(Context *context) override;
  ExpressionNode* OptimizedNode() override;
};
