#include "array_node.hpp"

#include <iostream>

#include "constants.hpp"

ArrayNode::ArrayNode(Elements *elements) : ExpressionNode() {
  this->elements = elements;
}

Value ArrayNode::GetValue(Context *context) {
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
    }

    if (i != values.size() - 1) {
      result += ", ";
    }
  }

  result = "[" + result + "]";

  auto val = new Value();
  val->svalue = new std::string(result);

  return *val;
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
