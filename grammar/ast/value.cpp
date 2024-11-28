#include "value.hpp"

#include <iostream>
#include <stdexcept>

#include "array_node.hpp"
#include "tuple_node.hpp"

Value::Value() : ivalue(nullptr), dvalue(nullptr), svalue(nullptr), bvalue(nullptr), array(nullptr), tuple(nullptr) {}

Value Value::operator+(const Value &other) {
  Value res;
  if (this->ivalue && other.ivalue) {
    res.ivalue = new int(*(this->ivalue) + *(other.ivalue));
    return res;
  }

  if (this->dvalue && other.dvalue) {
    res.dvalue = new double(*(this->dvalue) + *(other.dvalue));
    return res;
  }

  if (this->dvalue && other.ivalue) {
    res.dvalue = new double(*(this->dvalue) + (double)*(other.ivalue));
    return res;
  }

  if (this->ivalue && other.dvalue) {
    res.dvalue = new double((double)*(this->ivalue) + *(other.dvalue));
    return res;
  }

  if (this->svalue && other.svalue) {
    res.svalue = new std::string(*(this->svalue) + *(other.svalue));
    return res;
  }

  if (this->tuple && other.tuple) {
    TupleNode *right_tuple = other.tuple;

    auto res_tuple_elems = *(this->tuple->elements);

    for (auto other_elem : other.tuple->elements->tuple_elems) {
      res_tuple_elems.Add(other_elem);
    }

    res.tuple = new TupleNode(new TupleElements(std::move(res_tuple_elems)));
    return res;
  }

  if (this->array && other.array) {
    auto new_elements = new Elements();
    for (const auto this_elem : this->array->elements->elements) {
      new_elements->elements.push_back(this_elem);
    }
    for (const auto other_elem : other.array->elements->elements) {
      new_elements->elements.push_back(other_elem);
    }
    res.array = new ArrayNode(new_elements);
    return res;
  }

  throw std::logic_error("not supported");
}

Value Value::operator*(const Value &other) {
  Value res;
  if (this->ivalue && other.ivalue) {
    res.ivalue = new int(*(this->ivalue) * *(other.ivalue));
    return res;
  } else if (this->dvalue && other.dvalue) {
    res.dvalue = new double(*(this->dvalue) * *(other.dvalue));
    return res;
  } else if (this->dvalue && other.ivalue) {
    res.dvalue = new double(*(this->dvalue) * (double)*(other.ivalue));
    return res;
  } else if (this->ivalue && other.dvalue) {
    res.dvalue = new double((double)*(this->ivalue) * *(other.dvalue));
    return res;
  }
  throw std::logic_error("not supported");
}

Value Value::operator-(const Value &other) {
  Value res;
  if (this->ivalue && other.ivalue) {
    res.ivalue = new int(*(this->ivalue) - *(other.ivalue));
    return res;
  } else if (this->dvalue && other.dvalue) {
    res.dvalue = new double(*(this->dvalue) - *(other.dvalue));
    return res;
  } else if (this->dvalue && other.ivalue) {
    res.dvalue = new double(*(this->dvalue) - (double)*(other.ivalue));
    return res;
  } else if (this->ivalue && other.dvalue) {
    res.dvalue = new double((double)*(this->ivalue) - *(other.dvalue));
    return res;
  }
  throw std::logic_error("not supported");
}

Value Value::operator/(const Value &other) {
  Value res;

  if (this->ivalue && other.ivalue) {
    res.ivalue = new int(*(this->ivalue) / *(other.ivalue));
    return res;
  } else if (this->dvalue && other.dvalue) {
    res.dvalue = new double(*(this->dvalue) / *(other.dvalue));
    return res;
  } else if (this->dvalue && other.ivalue) {
    res.dvalue = new double(*(this->dvalue) / (double)*(other.ivalue));
    return res;
  } else if (this->ivalue && other.dvalue) {
    res.dvalue = new double((double)*(this->ivalue) / *(other.dvalue));
    return res;
  }
  throw std::logic_error("not supported");
}

Value Value::operator%(const Value &other) {
  Value res;
  if (this->ivalue && other.ivalue) {
    res.ivalue = new int(*(this->ivalue) % *(other.ivalue));
    return res;
  }
  throw std::logic_error("not supported");
}

void Value::Print() const {
  if (ivalue) {
    std::cout << *(ivalue) << std::endl;
    return;
  }
  if (dvalue) {
    std::cout << *(dvalue) << std::endl;
    return;
  }
  if (svalue) {
    std::cout << *(svalue) << std::endl;
    return;
  }
  if (bvalue) {
    if (*(bvalue)) {
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
    return;
  }
  std::cout << "<nil>" << std::endl;
}

bool Value::IsEmpty() const {
  return !(this->array || this->bvalue || this->dvalue || this->function || this->ivalue || this->svalue || this->tuple);
}
