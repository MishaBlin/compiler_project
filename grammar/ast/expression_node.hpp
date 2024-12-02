#pragma once

#include "node.hpp"
#include "value.hpp"

struct ExpressionNode : public Node {
  ExpressionNode();

  virtual Value GetValue(Context* context);
  virtual ExpressionNode* OptimizedNode();

  ~ExpressionNode();
};