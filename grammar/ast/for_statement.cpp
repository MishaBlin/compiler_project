#include "for_statement.hpp"

#include <iostream>

#include "constants.hpp"

ForStatement::ForStatement(const std::string &it_name, ExpressionNode *begin, ExpressionNode *end, BlocksNode *body) : Node() {
  this->begin = begin;
  this->end = end;
  this->it_name = it_name;
  this->body = body;
}

void ForStatement::Execute(Context *context) {
  // todo
  // int start = *(this->begin->GetValue().ivalue);
  // int end = *(this->end->GetValue().ivalue);
  // auto for_context = new Context(context);
  // for_context->locals[this->it_name] = this->begin->GetValue();
  // for (int i = start; i <= end; i++) {
  //   auto new_it = Value();
  //   new_it.ivalue = new int(i);
  //   for_context->locals[this->it_name] = new_it;
  //   this->body->Execute(for_context);
  // }
  // delete for_context;
}

void ForStatement::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "ForStatement: Iterator: " << this->it_name << std::endl;

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "  Begin:" << std::endl;
  this->begin->Print(indent + 2);

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "  End:" << std::endl;
  this->end->Print(indent + 2);

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kSpace;
  }
  std::cout << "  Body:" << std::endl;
  body->Print(indent + 2);
}
