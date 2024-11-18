#include "value.hpp"

#include <iostream>
#include <stdexcept>

Value::Value() : ivalue(nullptr), dvalue(nullptr), svalue(nullptr), bvalue(nullptr), array(nullptr), tuple(nullptr) {}

Value Value::operator+(const Value &other) {
  Value res;
  if (this->ivalue && other.ivalue) {
    res.ivalue = new int(*(this->ivalue) + *(other.ivalue));
    return res;
  } else if (this->dvalue && other.dvalue) {
    res.dvalue = new double(*(this->dvalue) + *(other.dvalue));
    return res;
  } else if (this->dvalue && other.ivalue) {
    res.dvalue = new double(*(this->dvalue) + (double)*(other.ivalue));
    return res;
  } else if (this->ivalue && other.dvalue) {
    res.dvalue = new double((double)*(this->ivalue) + *(other.dvalue));
    return res;
  } else if (this->svalue && other.svalue) {
    res.svalue = new std::string(*(this->svalue) + *(other.svalue));
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