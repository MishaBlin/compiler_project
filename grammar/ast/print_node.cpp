#include "print_node.hpp"

#include <iostream>

#include "constants.hpp"

PrintNode::PrintNode(Elements* exp) : Node() {
  this->expressions = exp;
}

void PrintNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Print" << std::endl;
  for (auto expression : this->expressions->elements) {
    expression->Print(indent + 1);
  }
}

void PrintNode::Execute(Context* context) {
  // std::cout << "PrintNode::Execute" << std::endl;
  if (expressions == nullptr) {
    throw std::runtime_error("Nothing to print");
  }
  int i = 0;
  int size = expressions->elements.size();
  for (auto expression : expressions->elements) {
    i++;
    // std::cout << "i = " << i << std::endl;
    auto ivalue = expression->GetValue(context).ivalue;
    auto dvalue = expression->GetValue(context).dvalue;
    auto svalue = expression->GetValue(context).svalue;
    auto bvalue = expression->GetValue(context).bvalue;
    if (ivalue) {
      std::cout << *(ivalue);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (dvalue) {
      std::cout << *(dvalue);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (svalue) {
      std::cout << *(svalue);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (bvalue) {
      if (*(bvalue)) {
        std::cout << "true";
      } else {
        std::cout << "false";
      }
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    throw std::runtime_error("Not supported type to print");
  }
  std::cout << std::endl;
}

PrintNode::~PrintNode() {
}
