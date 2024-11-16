#pragma once

#include "expression_node.hpp"
#include "lvalue.hpp"

struct AssignmentNode : public Node {
  LocationValue *lvalue;
  ExpressionNode *new_value;

  AssignmentNode(LocationValue *lvalue, ExpressionNode *new_value);

  void Execute(Context *context) override;

  void Print(int indent) override;
};