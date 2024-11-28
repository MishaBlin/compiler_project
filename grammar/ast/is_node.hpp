#pragma once

#include <string>

#include "expression_node.hpp"

struct ReferenceNode;

enum class Types {
  INT,
  REAL,
  BOOL,
  STRING,
  EMPTY,
  ARRAY,
  TUPLE,
  FUNCTION
};

struct TypeIndicatorNode : public Node {
  Types type;

  TypeIndicatorNode(Types type);

  bool IsInt();
  bool IsReal();
  bool IsBool();
  bool IsString();
  bool IsNull();
  bool IsArray();
  bool IsTuple();
  bool IsFunction();
};

struct IsNode : public ExpressionNode {
  ReferenceNode* reference;
  TypeIndicatorNode* type;

  IsNode(ReferenceNode* reference, TypeIndicatorNode* type);

  Value GetValue(Context* context) override;
};