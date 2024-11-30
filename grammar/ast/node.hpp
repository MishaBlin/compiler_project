#pragma once

#include "context.hpp"

struct Node {
  Node();

  virtual void Print(int indent);

  virtual void Execute(Context* context, const bool dry_run);

  virtual void Optimize();

  virtual void Add(Node* child);

  virtual ~Node();
};