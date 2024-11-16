#pragma once

#include "context.hpp"

struct Node {
  Node();

  virtual void Print(int indent);

  virtual void Execute(Context* context);

  virtual void Add(Node* child);

  virtual ~Node();
};