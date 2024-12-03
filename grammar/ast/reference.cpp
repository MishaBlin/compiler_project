#include "reference.hpp"

#include <iostream>

#include "array_node.hpp"
#include "constant_node.hpp"
#include "constants.hpp"
#include "tuple_node.hpp"

namespace {

static constexpr const auto kArray = "array";
static constexpr const auto kArrayOutOfRangeError = "Array Error: Out of range";
static constexpr const auto kArrayNoIntIndexError = "Array Error: No integer index";
static constexpr const auto kTuple = "tuple";
static constexpr const auto kTupleNoElementError = "Tuple Error: No such element";
static constexpr const auto kTupleOutOfRangeError = "Tuple Error: Out of range";

}  // namespace

Identifier::Identifier(int index) : index(index) {}

Identifier::Identifier(ExpressionNode* arr_idx) : arr_idx(arr_idx) {}

Identifier::Identifier(const std::string& name) : name(name) {}

ReferenceNode::ReferenceNode() : ExpressionNode() {
}

Value ReferenceNode::GetValue(Context* context) {
  auto it = context;
  const auto variable = this->elements.front().second.name.value_or("unknown");
  std::optional<Value> value;
  while (it != nullptr) {
    if (it->locals.count(variable)) {
      value = it->locals[variable];
      break;
    }
    it = it->parent;
  }
  if (!value.has_value()) {
    throw std::runtime_error("Variable " + variable + " not found");
  }
  for (int i = 1; i < this->elements.size(); i++) {
    if (this->elements[i].first == kArray) {
      const auto idx_expr = this->elements[i].second.arr_idx.value();
      const auto arr_idx = idx_expr->GetValue(context);
      if (arr_idx.ivalue == nullptr) {
        throw std::runtime_error(kArrayNoIntIndexError);
      }
      const int idx = *arr_idx.ivalue;
      if (idx >= value->array->elements->elements.size()) {
        throw std::runtime_error(kArrayOutOfRangeError);
      }
      value = value->array->elements->elements[idx]->GetValue(context);
      continue;
    }
    if (this->elements[i].first == kTuple) {
      auto idx = this->elements[i].second.index;
      if (!idx.has_value()) {
        if (value->tuple->elements->names.count(this->elements[i].second.name.value()) == 0) {
          throw std::runtime_error(kTupleNoElementError);
        }
        value = value->tuple->elements->names[this->elements[i].second.name.value()]->GetValue(context);
        continue;
      }
      if (idx.value() - 1 >= value->tuple->elements->elements.size()) {
        throw std::runtime_error(kTupleOutOfRangeError);
      }
      value = value->tuple->elements->elements[idx.value() - 1]->GetValue(context);
    }
  }
  return value.value();
}

void ReferenceNode::SetValue(Context* context, ExpressionNode* new_value, const bool dry_run) {
  auto it = context;
  const auto variable = this->elements.front().second.name.value();
  std::optional<Value> value;
  while (it != nullptr) {
    if (it->locals.count(variable)) {
      if (this->elements.size() == 1) {
        it->locals[variable] = new_value->GetValue(context);
        return;
      }
      value = it->locals[variable];
    }
    it = it->parent;
  }
  if (!value.has_value()) {
    throw std::runtime_error("Variable " + variable + " not found");
  }
  
  for (int i = 1; i < this->elements.size() - 1; i++) {
    if (this->elements[i].first == kArray) {
      const auto idx_expr = this->elements[i].second.arr_idx.value();
      const auto arr_idx = idx_expr->GetValue(context);
      if (arr_idx.ivalue == nullptr) {
        throw std::runtime_error(kArrayNoIntIndexError);
      }
      const int idx = *arr_idx.ivalue;
      if (idx >= value->array->elements->elements.size()) {
        throw std::runtime_error(kArrayOutOfRangeError);
      }
      value = value->array->elements->elements[idx]->GetValue(context);
      continue;
    }
    if (this->elements[i].first == kTuple) {
      auto idx = this->elements[i].second.index;
      if (!idx.has_value()) {
        if (value->tuple->elements->names.count(this->elements[i].second.name.value()) == 0) {
          throw std::runtime_error(kTupleNoElementError);
        }
        value = value->tuple->elements->names[this->elements[i].second.name.value()]->GetValue(context);
        continue;
      }
      if (idx.value() - 1 >= value->tuple->elements->elements.size()) {
        throw std::runtime_error(kTupleOutOfRangeError);
      }
      value = value->tuple->elements->elements[idx.value() - 1]->GetValue(context);
    }
  }

  if (this->elements.back().first == kArray) {
    const auto idx_expr = this->elements.back().second.arr_idx.value();
    const auto arr_idx = idx_expr->GetValue(context);
    if (arr_idx.ivalue == nullptr) {
      throw std::runtime_error(kArrayNoIntIndexError);
    }
    const int idx = *arr_idx.ivalue;
    if (idx >= value->array->elements->elements.size()) {
      throw std::runtime_error(kArrayOutOfRangeError);
    }
    value->array->elements->elements[idx] = new_value;
    return;
  }

  if (this->elements.back().first == kTuple) {
    auto idx = this->elements.back().second.index;
    if (!idx.has_value()) {
      if (value->tuple->elements->names.count(this->elements.back().second.name.value()) == 0) {
        throw std::runtime_error(kTupleNoElementError);
      }
      value->tuple->elements->names[this->elements.back().second.name.value()] = new_value;
      return;
    }
    if (idx.value() - 1 >= value->tuple->elements->elements.size()) {
      throw std::runtime_error(kTupleOutOfRangeError);
    }
    value->tuple->elements->elements[idx.value() - 1]->GetValue(context);
  }
}

void ReferenceNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Reference: " << std::endl;
  for (int i = 0; i < this->elements.size(); i++) {
    for (int j = 0; j < indent + 1; j++) {
      std::cout << constants::kIndent;
    }
    if (elements[i].first == "lvalue") {
      std::cout << "type: lvalue, name: " << elements[i].second.name.value() << std::endl;
      continue;
    }
    if (elements[i].first == "array") {
      std::cout << "type: array, idx: " << std::endl;
      elements[i].second.arr_idx.value()->Print(indent + 1);
      continue;
    }
    if (elements[i].first == "tuple") {
      std::cout << "type: tuple, ";
      if (elements[i].second.index.has_value()) {
        std::cout << "idx: " << elements[i].second.index.value() << std::endl;
      } else {
        std::cout << "name: " << elements[i].second.name.value() << std::endl;
      }
      continue;
    }
  }
};
