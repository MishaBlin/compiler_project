#include "program_node.hpp"

#include <iostream>

#include "constants.hpp"

ProgramNode::ProgramNode() : Node() {}

void ProgramNode::Add(Node* child) {
  children.push_back(child);
}

void ProgramNode::Execute(Context* context, const bool dry_run) {
  auto main_context = new Context();
  for (const auto child : children) {
    child->Execute(main_context, dry_run);
  }
}

void ProgramNode::Optimize() {
  for (const auto child : children) {
    child->Optimize();
  }
}

void ProgramNode::Print(int indent) {
  std::cout << "Program" << std::endl;
  for (int i = 0; i < indent; i++) {
    std::cout << constants::kIndent;
  }
  for (const auto child : children) {
    child->Print(indent + 1);
  }
}

ProgramNode::~ProgramNode() {
  for (auto child : children) {
    delete child;
  }
}