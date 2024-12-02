#pragma once

#include "expression_node.hpp"
#include "reference.hpp"

struct AssignmentNode : public Node {
  ReferenceNode *ref;
  ExpressionNode *new_value;

  AssignmentNode(ReferenceNode *ref, ExpressionNode *new_value);

  void Execute(Context *context, const bool dry_run) override;

  void Optimize() override;

  void Print(int indent) override;
};