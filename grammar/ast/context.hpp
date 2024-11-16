#pragma once

#include <string>
#include <unordered_map>

#include "value.hpp"

struct ExpressionNode;

struct Context {
  std::unordered_map<std::string, Value> locals;
  Context* parent;

  Context(Context* parent = nullptr);

  void PrintVars();

  int ScopeIdx();
};
