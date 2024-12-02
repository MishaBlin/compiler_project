#pragma once

#include "expression_node.hpp"

struct NotOperation : public ExpressionNode {
  ExpressionNode* value;
  
  NotOperation(ExpressionNode* node);

  Value GetValue(Context* context) override;
  void Print(const int indent) override;
};
