#include "for_statement.hpp"

#include <iostream>

#include "constant_node.hpp"
#include "constants.hpp"

ForStatement::ForStatement(const std::string &it_name, ExpressionNode *begin, ExpressionNode *end, BlocksNode *body) : Node() {
  this->begin = begin;
  this->end = end;
  this->it_name = it_name;
  this->body = body;
}

void ForStatement::Execute(Context *context) {
  int start = *(this->begin->GetValue(context).ivalue);
  int end = *(this->end->GetValue(context).ivalue);
  auto for_context = new Context(context);
  auto val = Value();
  val.ivalue = new int(start);
  for_context->locals[this->it_name] = val;
  while (true) {
    int curr = *(for_context->locals[this->it_name].ivalue);
    if (curr > end) {
      break;
    }
    this->body->Execute(for_context);
    int updated = *(for_context->locals[this->it_name].ivalue) + 1;
    auto up_val = Value();
    up_val.ivalue = new int(updated);
    for_context->locals[this->it_name] = up_val;
  }
  delete for_context;
}

void ForStatement::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "ForStatement: Iterator: " << this->it_name << std::endl;

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "  Begin:" << std::endl;
  this->begin->Print(indent + 2);

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "  End:" << std::endl;
  this->end->Print(indent + 2);

  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "  Body:" << std::endl;
  body->Print(indent + 2);
}
