#pragma once

#include <vector>

#include "node.hpp"

struct ProgramNode : public Node {
  std::vector<Node *> children;

  ProgramNode();

  void Add(Node *child);
  void Execute(Context *context, const bool dry_run) override;
  void Optimize() override;
  void Print(int indent) override;

  ~ProgramNode();
};