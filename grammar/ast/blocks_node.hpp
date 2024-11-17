#pragma once

#include <vector>

#include "node.hpp"

struct BlocksNode : public Node {
  std::vector<Node *> children;
  BlocksNode();

  void Add(Node *child) override;
  void Execute(Context *context) override;
  void Print(int indent) override;
  ~BlocksNode();
};