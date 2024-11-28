#include "is_node.hpp"

#include "reference.hpp"

TypeIndicatorNode::TypeIndicatorNode(Types type) : type(type) {
}

bool TypeIndicatorNode::IsInt() {
  return type == Types::INT;
}

bool TypeIndicatorNode::IsReal() {
  return type == Types::REAL;
}

bool TypeIndicatorNode::IsBool() {
  return type == Types::BOOL;
}

bool TypeIndicatorNode::IsString() {
  return type == Types::STRING;
}

bool TypeIndicatorNode::IsNull() {
  return type == Types::EMPTY;
}

bool TypeIndicatorNode::IsArray() {
  return type == Types::ARRAY;
}

bool TypeIndicatorNode::IsTuple() {
  return type == Types::TUPLE;
}

bool TypeIndicatorNode::IsFunction() {
  return type == Types::FUNCTION;
}

IsNode::IsNode(ReferenceNode* reference, TypeIndicatorNode* type) : ExpressionNode() {
  this->reference = reference;
  this->type = type;
}

Value IsNode::GetValue(Context* context) {
  const auto val = this->reference->GetValue(context);
  Value res;
  if (val.array && type->IsArray()) {
    res.bvalue = new bool(true);
    return res;
  }

  if (val.bvalue && type->IsBool()) {
    res.bvalue = new bool(true);
    return res;
  }

  if (val.dvalue && type->IsReal()) {
    res.bvalue = new bool(true);
    return res;
  }

  if (val.function && type->IsFunction()) {
    res.bvalue = new bool(true);
    return res;
  }

  if (val.ivalue && type->IsInt()) {
    res.bvalue = new bool(true);
    return res;
  }

  if (val.svalue && type->IsString()) {
    res.bvalue = new bool(true);
    return res;
  }

  if (val.tuple && type->IsTuple()) {
    res.bvalue = new bool(true);
    return res;
  }

  if (val.IsEmpty() && type->IsNull()) {
    res.bvalue = new bool(true);
    return res;
  }

  res.bvalue = new bool(false);
  return res;
}
