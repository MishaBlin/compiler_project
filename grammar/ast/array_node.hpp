#pragma once

#include <vector>

#include "expression_node.hpp"
#include "elements.hpp"

struct ArrayNode : public ExpressionNode {
  Elements *elements;

  ArrayNode(Elements *elements);
  Value GetValue(Context *context) override;

  void Print(int indent) override;
};