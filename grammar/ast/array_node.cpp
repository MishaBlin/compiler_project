#include "array_node.hpp"

#include <iostream>

#include "constants.hpp"

ArrayNode::ArrayNode(Elements *elements) : ExpressionNode() {
  this->elements = elements;
}

void ArrayNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Array. Elements: " << std::endl;
  for (auto element : elements->elements) {
    element->Print(indent + 1);
  };
}
