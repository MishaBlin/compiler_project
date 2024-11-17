#include "elements.hpp"

Elements::Elements() : ExpressionNode() {
}

void Elements::Add(ExpressionNode *elem) {
  this->elements.push_back(elem);
}

void Elements::Execute(Context *context) {}