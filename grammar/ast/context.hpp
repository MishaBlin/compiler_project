#pragma once

#include <string>
#include <unordered_map>

#include "value.hpp"

struct ExpressionNode;
struct FunctionNode;

struct Context {
  std::unordered_map<std::string, Value> locals;
  std::unordered_map<std::string, FunctionNode*> functions;
  Context* parent;

  Context(Context* parent = nullptr);

  void PrintVars();

  int ScopeIdx();
};
