#include "expression_node.hpp"

ExpressionNode::ExpressionNode() : Node() {
}

Value ExpressionNode::GetValue(Context* context) {
  return Value();
}

ExpressionNode::~ExpressionNode() {}
