#pragma once

#include <string>

struct Value {
  int *ivalue;
  double *dvalue;
  std::string *svalue;
  bool *bvalue;

  Value();

  void Print() const;

  Value operator+(const Value &other);
  Value operator*(const Value &other);
  Value operator-(const Value &other);
  Value operator/(const Value &other);
  Value operator%(const Value &other);
};