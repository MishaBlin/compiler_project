#pragma once

#include <vector>

#include "expression_node.hpp"

struct Elements : public ExpressionNode {
  std::vector<Node *> elements;

  Elements();

  void Add(Node *elem) override;
  void Execute(Context *context) override;
};

struct ArrayNode : public ExpressionNode {
  Elements *elements;

  ArrayNode(Elements *elements);

  void Print(int indent) override;
};