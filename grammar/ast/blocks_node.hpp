#pragma once

#include <vector>

#include "node.hpp"

struct BlocksNode : public Node {
  std::vector<Node *> children;
  BlocksNode();

  void Add(Node *child) override;
  void Execute(Context *context, const bool dry_run) override;
  void Print(int indent) override;
  void Optimize() override;
  ~BlocksNode();
};