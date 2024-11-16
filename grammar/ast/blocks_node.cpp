#include "blocks_node.hpp"

BlocksNode::BlocksNode() : Node() {}

void BlocksNode::Add(Node* child) {
  children.push_back(child);
}

void BlocksNode::Execute(Context* context) {
  for (const auto node : children) {
    node->Execute(context);
  }
}

void BlocksNode::Print(int indent) {
  for (const auto child : children) {
    child->Print(indent + 1);
  }
}

BlocksNode::~BlocksNode() {
  for (auto child : children) {
    delete child;
  }
}
