#pragma once

#include <optional>
#include <string>
#include <vector>

#include "expression_node.hpp"

struct Identifier {
  std::optional<int> index{};
  std::optional<std::string> name{};
  std::optional<ExpressionNode*> arr_idx{};

  Identifier(int index);
  Identifier(ExpressionNode* arr_idx);
  Identifier(const std::string& name);
};

struct ReferenceNode : public ExpressionNode {
  std::vector<std::pair<std::string, Identifier>> elements;
  ReferenceNode();

  Value GetValue(Context* context) override;
  void Print(int indent) override;
  void SetValue(Context* context, ExpressionNode* new_value, const bool dry_run);
};