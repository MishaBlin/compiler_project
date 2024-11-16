#include "assignment.hpp"

#include <iostream>

#include "constants.hpp"

AssignmentNode::AssignmentNode(LocationValue *lvalue, ExpressionNode *new_value) : Node() {
  this->lvalue = lvalue;
  this->new_value = new_value;
}

void AssignmentNode::Execute(Context *context) {
  // std::cout << "AssignmentNode::Execute" << std::endl;
  this->lvalue->SetValue(context, this->new_value);
}

void AssignmentNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Assignment" << std::endl;
  for (int i = 0; i < indent + 1; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Variable Name: " << this->lvalue->name << std::endl;
  this->new_value->Print(indent + 1);
}
