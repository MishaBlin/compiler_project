#include "relation_operation.hpp"

#include <iostream>

#include "constants.hpp"

RelationOperation::RelationOperation(ExpressionNode *l, ExpressionNode *r, const std::string &operation) : ExpressionNode() {
  this->left = l;
  this->right = r;
  this->operation = operation;
}

void RelationOperation::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "Operation " << this->operation << std::endl;
  this->left->Print(indent + 1);
  this->right->Print(indent + 1);
}

Value RelationOperation::GetValue(Context *context) {
  Value res;
  auto lval = this->left->GetValue(context);
  auto rval = this->right->GetValue(context);

  double left;
  double right;

  if (lval.ivalue) {
    left = *(lval.ivalue);
  } else if (lval.dvalue) {
    left = *(lval.dvalue);
  } else {
    throw std::logic_error("not supported");
  }

  if (rval.ivalue) {
    right = *(rval.ivalue);
  } else if (lval.dvalue) {
    right = *(rval.dvalue);
  } else {
    throw std::logic_error("not supported");
  }

  if (operation == "<") {
    res.bvalue = new bool(left < right);
  } else if (operation == "<=") {
    res.bvalue = new bool(left <= right);
  } else if (operation == ">") {
    res.bvalue = new bool(left > right);
  } else if (operation == ">=") {
    res.bvalue = new bool(left >= right);
  } else if (operation == "=") {
    res.bvalue = new bool(left == right);
  } else if (operation == "/=") {
    res.bvalue = new bool(left != right);
  } else {
    throw std::logic_error("unknown operation");
  }

  return res;
}