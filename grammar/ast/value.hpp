#pragma once

#include <string>

struct ArrayNode;
struct TupleNode;
struct FunctionNode;

struct Value {
  int *ivalue;
  double *dvalue;
  std::string *svalue;
  bool *bvalue;
  ArrayNode *array;
  TupleNode *tuple;
  FunctionNode *function;

  Value();

  void Print() const;

  Value operator+(const Value &other);
  Value operator*(const Value &other);
  Value operator-(const Value &other);
  Value operator/(const Value &other);
  Value operator%(const Value &other);
};