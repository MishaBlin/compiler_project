#include "print_node.hpp"

#include <iostream>

#include "constants.hpp"

PrintNode::PrintNode(ExpressionNode* exp) : Node() {
  this->expression = exp;
}

void PrintNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Print" << std::endl;
  expression->Print(indent + 1);
}

void PrintNode::Execute(Context* context) {
  // std::cout << "PrintNode::Execute" << std::endl;
  auto ivalue = expression->GetValue(context).ivalue;
  auto dvalue = expression->GetValue(context).dvalue;
  auto svalue = expression->GetValue(context).svalue;
  auto bvalue = expression->GetValue(context).bvalue;
  if (ivalue) {
    std::cout << *(ivalue) << std::endl;
    return;
  }
  if (dvalue) {
    std::cout << *(dvalue) << std::endl;
    return;
  }
  if (svalue) {
    std::cout << *(svalue) << std::endl;
    return;
  }
  if (bvalue) {
    if (*(bvalue)) {
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
    return;
  }
  throw std::runtime_error("nothing to print");
}

PrintNode::~PrintNode() {
  delete expression;
}
