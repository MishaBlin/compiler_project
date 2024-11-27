#include "assignment.hpp"

#include <iostream>

#include "constants.hpp"

AssignmentNode::AssignmentNode(ReferenceNode *ref, ExpressionNode *new_value) : Node() {
  this->ref = ref;
  this->new_value = new_value;
}

void AssignmentNode::Execute(Context *context) {
  // std::cout << "AssignmentNode::Execute" << std::endl;
  this->ref->SetValue(context, this->new_value);
}

void AssignmentNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Assignment" << std::endl;
  this->ref->Print(indent + 1);
  this->new_value->Print(indent + 1);
}
