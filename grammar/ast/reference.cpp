#include "reference.hpp"

#include <iostream>

#include "array_node.hpp"
#include "constant_node.hpp"
#include "constants.hpp"
#include "tuple_node.hpp"

Identifier::Identifier(int index) : index(index) {}

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
    if (this->elements[i].first == "array") {
      // add checking;
      int idx = this->elements[i].second.index.value();
      value = value->array->elements->elements[idx]->GetValue(context);
      continue;
    }
    if (this->elements[i].first == "tuple") {
      auto idx = this->elements[i].second.index;
      if (!idx.has_value()) {
        value = value->tuple->elements->names[this->elements[i].second.name.value()]->GetValue(context);
        continue;
      }
      value = value->tuple->elements->indexes[idx.value()]->GetValue(context);
    }
  }
  return value.value();
}

void ReferenceNode::SetValue(Context* context, ExpressionNode* new_value) {
  // std::cout << "LocationValue::SetValue" << std::endl;
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
    if (this->elements[i].first == "array") {
      // add checking;
      int idx = this->elements[i].second.index.value();
      value = value->array->elements->elements[idx]->GetValue(context);
      continue;
    }
    if (this->elements[i].first == "tuple") {
      auto idx = this->elements[i].second.index;
      if (!idx.has_value()) {
        value = value->tuple->elements->names[this->elements[i].second.name.value()]->GetValue(context);
        continue;
      }
      value = value->tuple->elements->indexes[idx.value()]->GetValue(context);
    }
  }

  if (this->elements.back().first == "array") {
    // add checking;
    int idx = this->elements.back().second.index.value();
    value->array->elements->elements[idx] = new_value;
    return;
  }
  if (this->elements.back().first == "tuple") {
    auto idx = this->elements.back().second.index;
    if (!idx.has_value()) {
      value->tuple->elements->names[this->elements.back().second.name.value()] = new_value;
      return;
    }
    value->tuple->elements->indexes[idx.value()]->GetValue(context);
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
      std::cout << "type: array, idx: " << elements[i].second.index.value() << std::endl;
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
