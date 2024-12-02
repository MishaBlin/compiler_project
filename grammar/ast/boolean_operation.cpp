#include "boolean_operation.hpp"

#include <iostream>

#include "constant_node.hpp"
#include "constants.hpp"

namespace {

static constexpr const auto kAnd = "AND";
static constexpr const auto kOr = "OR";
static constexpr const auto kXor = "XOR";
static constexpr const auto kError = "Not supported operands for boolean operator ";

}  // namespace

BooleanOperation::BooleanOperation(ExpressionNode *l, ExpressionNode *r, const std::string &operation) : ExpressionNode() {
  this->left = l;
  this->right = r;
  this->operation = operation;
}

void BooleanOperation::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Operation " << this->operation << std::endl;
  this->left->Print(indent + 1);
  this->right->Print(indent + 1);
}

Value BooleanOperation::GetValue(Context *context) {
  auto l = this->left->GetValue(context);
  auto r = this->right->GetValue(context);
  if (!l.bvalue || !r.bvalue) {
    throw std::runtime_error("Unssupported operands");
  }
  Value res;
  if (this->operation == kAnd) {
    res.bvalue = new bool(*(l.bvalue) && *(r.bvalue));
    return res;
  }

  if (this->operation == kOr) {
    res.bvalue = new bool(*(l.bvalue) || *(r.bvalue));
    return res;
  }

  if (this->operation == kXor) {
    res.bvalue = new bool(*(l.bvalue) ^ *(r.bvalue));
    return res;
  }

  throw std::logic_error(kError + this->operation);
}

ExpressionNode *BooleanOperation::OptimizedNode() {
  this->left = this->left->OptimizedNode();
  this->right = this->right->OptimizedNode();
  if (dynamic_cast<ConstantNode *>(this->left) && dynamic_cast<ConstantNode *>(this->right)) {
    auto left = this->left->GetValue(nullptr);
    auto right = this->right->GetValue(nullptr);
    if (!left.bvalue || !right.bvalue) {
      throw std::logic_error(kError + this->operation);
    }
    if (this->operation == kAnd) {
      return new ConstantNode(*(left.bvalue) && *(right.bvalue));
    }
    if (this->operation == kOr) {
      return new ConstantNode(*(left.bvalue) || *(right.bvalue));
    }
    if (this->operation == kXor) {
      return new ConstantNode(static_cast<bool>(*(left.bvalue) ^ *(right.bvalue)));
    }
  }
  return this;
}
