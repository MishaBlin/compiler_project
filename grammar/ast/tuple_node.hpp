#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "expression_node.hpp"

struct TupleElement : public Node {
  std::string *name;
  ExpressionNode *elem;

  TupleElement(ExpressionNode *elem, std::string *name = nullptr);
};

struct TupleElements : public ExpressionNode {
  std::unordered_map<std::string, ExpressionNode *> names;
  std::unordered_map<int, std::string> idxToName;

  std::vector<ExpressionNode *> elements;
  std::vector<TupleElement *> tuple_elems;

  TupleElements();
  TupleElements(const TupleElements& other) = default;
  TupleElements(TupleElements&& other) = default;
  void Add(TupleElement *element);
};

struct TupleNode : public ExpressionNode {
  TupleElements *elements;

  TupleNode(TupleElements *elements);

  Value GetValue(Context *context) override;

  void Print(int indent) override;
  std::string ToString(Context *context);
};