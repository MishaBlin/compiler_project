#include "elements.hpp"

Elements::Elements() : ExpressionNode() {
}

void Elements::Add(ExpressionNode *elem) {
  this->elements.push_back(elem);
}

void Elements::Execute(Context *context, const bool dry_run) {}

void Elements::Optimize() {
  for (auto& elem : this->elements) {
    elem = elem->OptimizedNode();
  }
}