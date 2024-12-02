#include "array_node.hpp"

#include <iostream>

#include "constants.hpp"
#include "tuple_node.hpp"

ArrayNode::ArrayNode(Elements *elements) : ExpressionNode() {
  this->elements = elements;
}

std::string ArrayNode::ToString(Context *context) {
  std::vector<Value> values;

  for (auto element : this->elements->elements) {
    values.push_back(((ExpressionNode *)element)->GetValue(context));
  }

  std::string result = "";

  for (int i = 0; i < values.size(); i++) {
    Value value = values[i];
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

    if (i != values.size() - 1) {
      result += ", ";
    }
  }

  result = "[" + result + "]";

  return result;
}

void ArrayNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Array. Elements: " << std::endl;
  for (auto element : elements->elements) {
    element->Print(indent + 1);
  };
}

Value ArrayNode::GetValue(Context *context) {
  Value val;
  val.array = this;
  return val;
};

void ArrayNode::Optimize() {
  this->elements->Optimize();
}
