#include "context.hpp"

#include <iostream>

#include "constants.hpp"

Context::Context(Context* parent) : parent(parent) {};

void Context::PrintVars() {
  int indent = this->ScopeIdx();

  for (int i = 0; i < 10; i++) {
    std::cout << "==";
  }
  std::cout << " Scope with depth " << indent << " ";
  for (int i = 0; i < 10; i++) {
    std::cout << "==";
  }
  std::cout << std::endl;

  for (const auto& [key, _] : this->locals) {
    for (int i = 0; i < indent; i++) {
      std::cout << constants::kIndent;
    }
    std::cout << "var: " << key << std::endl;
    for (int i = 0; i < indent; i++) {
      std::cout << constants::kIndent;
    }
    //   std::cout << "value: ";
    //   value.Print();
  }

  auto it = this->parent;
  int step = 1;
  while (it != nullptr) {
    for (int i = 0; i < indent + step; i++) {
      std::cout << constants::kIndent;
    }
    std::cout << step << " parent(s) up vars:" << std::endl;
    for (const auto& [key, _] : it->locals) {
      for (int i = 0; i < indent + step; i++) {
        std::cout << constants::kIndent;
      }
      std::cout << "var: " << key << std::endl;
      for (int i = 0; i < indent + step; i++) {
        std::cout << constants::kIndent;
      }
      //   std::cout << "value: ";
      //   value.Print();
    }
    it = it->parent;
    step++;
  }
  //   if (this->parent != nullptr) {
  //     std::cout << "Parent Context Vars:" << std::endl;
  //     this->parent->PrintVars();
  //   }
}

int Context::ScopeIdx() {
  int res = 0;
  auto it = this;
  while (it->parent) {
    res++;
    it = it->parent;
  }
  return res;
}