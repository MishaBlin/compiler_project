#pragma once

#include "expression_node.hpp"
#include "reference.hpp"

struct AssignmentNode : public Node {
  ReferenceNode *ref;
  ExpressionNode *new_value;

  AssignmentNode(ReferenceNode *ref, ExpressionNode *new_value);

  void Execute(Context *context) override;

  void Print(int indent) override;
};