#include "print_node.hpp"

#include <iostream>

#include "array_node.hpp"
#include "constants.hpp"
#include "tuple_node.hpp"

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

void PrintNode::Execute(Context* context, const bool dry_run) {
  if (expressions == nullptr) {
    throw std::runtime_error("Nothing to print");
  }
  int i = 0;
  int size = expressions->elements.size();
  for (auto expression : expressions->elements) {
    i++;
    auto val = expression->GetValue(context);
    if (dry_run) {
      continue;
    }
    if (val.ivalue) {
      std::cout << *(val.ivalue);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (val.dvalue) {
      std::cout << *(val.dvalue);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (val.svalue) {
      std::cout << *(val.svalue);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (val.bvalue) {
      if (*(val.bvalue)) {
        std::cout << "true";
      } else {
        std::cout << "false";
      }
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (val.array) {
      std::cout << val.array->ToString(context);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    if (val.tuple) {
      std::cout << val.tuple->ToString(context);
      if (i != size) {
        std::cout << constants::kSpace;
      }
      continue;
    }

    throw std::runtime_error("Not supported type to print");
  }
  if (!dry_run)
    std::cout << std::endl;
}

PrintNode::~PrintNode() {
}

void PrintNode::Optimize() {
  for (auto& elem : this->expressions->elements) {
    elem = elem->OptimizedNode();
  }
}