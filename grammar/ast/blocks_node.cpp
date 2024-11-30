#include "blocks_node.hpp"

#include <iostream>

#include "return_node.hpp"

BlocksNode::BlocksNode() : Node() {}

void BlocksNode::Add(Node* child) {
  children.push_back(child);
}

void BlocksNode::Execute(Context* context, const bool dry_run) {
  for (const auto node : children) {
    node->Execute(context, dry_run);
  }
}

void BlocksNode::Optimize() {
  int i = 0;
  while (i < this->children.size()) {
    if (dynamic_cast<ReturnNode*>(this->children[i])) {
      break;
    }
    this->children[i]->Optimize();
    i++;
  }
  for (int j = this->children.size() - 1; j > i; j--) {
    this->children.pop_back();
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
