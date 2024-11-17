#include "function_node.hpp"

#include <iostream>

#include "constants.hpp"

Parameters::Parameters() : Node() {}

void Parameters::Add(std::string&& parameter) {
  parameters.emplace_back(std::move(parameter));
}

FunctionNode::FunctionNode(BlocksNode* body, Parameters* parameters) : ExpressionNode() {
  this->body = body;
  this->parameters = std::move(parameters->parameters);
}

void FunctionNode::Execute(Context* context) {
  for (auto statement : this->body->children) {
    statement->Execute(context);
  }
}

void FunctionNode::Print(int indent) {
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Parameters:" << std::endl;
  for (int i = 0; i < indent + 1; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "[";
  for (int i = 0; i < parameters.size(); i++) {
    std::cout << parameters[i];
    if (i != parameters.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  std::cout << "Body:" << std::endl;
  for (auto block : this->body->children) {
    block->Print(indent + 1);
  }
}
