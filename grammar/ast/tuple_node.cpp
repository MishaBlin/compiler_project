#include "tuple_node.hpp"

#include <iostream>
#include <optional>
#include <string>

#include "array_node.hpp"
#include "constants.hpp"

TupleElements::TupleElements() : ExpressionNode() {}

TupleNode::TupleNode(TupleElements *elements) {
  this->elements = elements;
}

void TupleElements::Add(TupleElement *element) {
  int n = this->indexes.size();
  this->indexes[n + 1] = element->elem;

  if (element->name) {
    this->names[*(element->name)] = element->elem;
    this->idxToName[n + 1] = *(element->name);
  }
}

void TupleNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Tuple. Elements: " << std::endl;
  int size = this->elements->indexes.size();
  for (int i = 1; i <= size; i++) {
    for (int i = 0; i < indent + 1; i++) {
      std::cout << constants::kIndent;
    }
    std::cout << "idx: " << i << std::endl;
    std::optional<std::string> member;
    if (this->elements->idxToName.count(i)) {
      member = this->elements->idxToName[i];
    }
    for (int i = 0; i < indent + 1; i++) {
      std::cout << constants::kIndent;
    }
    std::cout << "member: " << member.value_or("<nil>") << std::endl;
    for (int i = 0; i < indent + 1; i++) {
      std::cout << constants::kIndent;
    }
    std::cout << "value: " << std::endl;
    this->elements->indexes[i]->Print(indent + 2);
  }
}

TupleElement::TupleElement(ExpressionNode *elem, std::string *name) : Node() {
  this->elem = elem;
  this->name = name;
}

std::string TupleNode::ToString(Context *context) {
  std::string result = "";

  for (int i = 1; i <= this->elements->indexes.size(); i++) {
    Value value = this->elements->indexes[i]->GetValue(context);
    std::string name;

    if (this->elements->idxToName.count(i) != 0) {
      name = this->elements->idxToName[i] += " = ";
    }

    result += name;

    if (value.svalue) {
      result += *(value.svalue);
    } else if (value.ivalue) {
      result += std::to_string(*(value.ivalue));
    } else if (value.bvalue) {
      result += std::to_string(*(value.dvalue));
    } else if (value.array) {
      result += value.array->ToString(context);
    } else if (value.tuple) {
      result += value.tuple->ToString(context);
    }

    if (i != this->elements->indexes.size()) {
      result += ", ";
    }
  }

  result = "{" + result + "}";

  return result;
}

Value TupleNode::GetValue(Context *context) {
  Value val;
  val.tuple = this;
  return val;
}