#pragma once

#include "elements.hpp"

struct PrintNode : public Node {
  Elements *expressions;

  PrintNode(Elements *exp);

  void Print(int indent) override;
  void Execute(Context *context, const bool dry_run) override;
  void Optimize() override;

  ~PrintNode();
};