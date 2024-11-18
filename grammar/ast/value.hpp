#pragma once

#include <string>

struct ArrayNode;
struct TupleNode;

struct Value {
  int *ivalue;
  double *dvalue;
  std::string *svalue;
  bool *bvalue;
  ArrayNode *array;
  TupleNode *tuple;

  Value();

  void Print() const;

  Value operator+(const Value &other);
  Value operator*(const Value &other);
  Value operator-(const Value &other);
  Value operator/(const Value &other);
  Value operator%(const Value &other);
};