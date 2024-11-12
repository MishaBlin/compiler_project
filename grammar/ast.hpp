#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>

namespace {
static const std::string kSpace = "  ";
}


struct Value {
  int* ivalue;
  double* dvalue;
  std::string* svalue;
  bool* bvalue;

  Value() : ivalue(nullptr), dvalue(nullptr), svalue(nullptr), bvalue(nullptr) {}

  Value operator+(const Value& other) {
    Value res;
    if (this->ivalue && other.ivalue) {
      std::cout << "here" << std::endl;
      res.ivalue = new int(*(this->ivalue) + *(other.ivalue));
      return res;
    }
    throw std::logic_error("not supported");
  }

  Value operator*(const Value& other) {
    Value res;
    if (this->ivalue && other.ivalue) {
      res.ivalue = new int(*(this->ivalue) * *(other.ivalue));
      return res;
    }
    throw std::logic_error("not supported");
  }

  Value operator-(const Value& other) {
    Value res;
    if (this->ivalue && other.ivalue) {
      res.ivalue = new int(*(this->ivalue) - *(other.ivalue));
      return res;
    }
    throw std::logic_error("not supported");
  }

  Value operator/(const Value& other) {
    Value res;
    if (this->ivalue && other.ivalue) {
      res.ivalue = new int(*(this->ivalue) / *(other.ivalue));
      return res;
    }
    throw std::logic_error("not supported");
  }

  Value operator%(const Value& other) {
    Value res;
    if (this->ivalue && other.ivalue) {
      res.ivalue = new int(*(this->ivalue) % *(other.ivalue));
      return res;
    }
    throw std::logic_error("not supported");
  }
};

static std::unordered_map<std::string, Value> symbol_table;

struct Node {
  Node() {}

  virtual void Print(int indent) {
  }

  virtual void Execute() {}

  virtual void Add(Node* child) {}
  virtual ~Node() {};
};

struct ProgramNode : public Node {
  std::vector<Node*> children;
  ProgramNode() : Node() {}

  void Add(Node* child) {
    children.push_back(child);
  }

  void Execute() override {
    for (const auto child : children) {
      child->Execute();
    }
  }
 
  void Print(int indent) {
    std::cout << "Program" << std::endl;
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    for (const auto child : children) {
      child->Print(indent + 1);
    }
  }

  ~ProgramNode() {
    for (auto child : children) {
      delete child;
    }
  }
};

struct ExpressionNode : public Node {
  ExpressionNode() : Node() {
  }

  virtual Value GetValue() {
    return Value();
  }

  ~ExpressionNode() {}
};

struct PrintNode : public Node {
  ExpressionNode* expression;
  PrintNode(ExpressionNode* exp) : Node() {
    this->expression = exp;
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "Print" << std::endl;
    expression->Print(indent + 1);
  }

  void Execute() override {
    std::cout << *(expression->GetValue().ivalue) << std::endl;
  }

  ~PrintNode() {
    delete expression;
  }
};

struct RelationNode : public ExpressionNode {
  RelationNode() : ExpressionNode() {}

  ~RelationNode() {}
};

struct FactorNode : public RelationNode {
  FactorNode() : RelationNode() {}

  ~FactorNode() {}
};

struct TermNode : public FactorNode {
  TermNode() : FactorNode() {}

  ~TermNode() {}
};

struct UnaryNode : public TermNode {
  UnaryNode() : TermNode() {}

  ~UnaryNode() {}
};

struct PrimaryNode : public UnaryNode {
  PrimaryNode() : UnaryNode() {}

  ~PrimaryNode() {}
};

struct LiteralNode : public PrimaryNode {
  LiteralNode() : PrimaryNode() {
  }

  ~LiteralNode() {}
};

struct ConstantNode : public LiteralNode {
  Value value;

  ConstantNode() : LiteralNode() {
    this->value = Value();
  }

  ConstantNode(int value) : ConstantNode() {
    this->value.ivalue = new int(value);
  }

  ConstantNode(double value) : ConstantNode() {
    this->value.dvalue = new double(value);
  }

  ConstantNode(const std::string& value) : ConstantNode() {
    this->value.svalue = new std::string(value);
  }

  ConstantNode(bool value) : ConstantNode() {
    this->value.bvalue = new bool(value);
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "constant ";
    if (this->value.ivalue) {
      std::cout << "integer " << *(this->value.ivalue) << std::endl;
      return;
    }

    if (this->value.dvalue) {
      std::cout << "double " << *(this->value.dvalue) << std::endl;
      return;
    }

    if (this->value.svalue) {
      std::cout << "string " << *(this->value.svalue) << std::endl;
      return;
    }

    if (this->value.bvalue) {
      std::cout << "bool " << *(this->value.bvalue) << std::endl;
      return;
    }
  }

  Value GetValue() {
    return this->value;
  }
};

struct BooleanOperation : public Node {
  ExpressionNode* left;
  ExpressionNode* right;
  std::string operation;

  BooleanOperation(ExpressionNode* l, ExpressionNode* r, const std::string& operation) : Node() {
    this->left = l;
    this->right = r;
    this->operation = operation;
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "Operation " << this->operation << std::endl;
    this->left->Print(indent + 1);
    this->right->Print(indent + 1);
  }
};

struct RelationOperation : public ExpressionNode {
  ExpressionNode* left;
  ExpressionNode* right;
  std::string operation;

  RelationOperation(ExpressionNode* l, ExpressionNode* r, const std::string& operation) : ExpressionNode() {
    this->left = l;
    this->right = r;
    this->operation = operation;
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "Operation " << this->operation << std::endl;
    this->left->Print(indent + 1);
    this->right->Print(indent + 1);
  }

  Value GetValue() override {
    Value res;
    auto lval = this->left->GetValue().ivalue;
    auto rval = this->right->GetValue().ivalue;
    res.bvalue = new bool(*lval < *rval);
    return res;
  }
};

struct ArithmeticOperation : public ExpressionNode {
  ExpressionNode* left;
  ExpressionNode* right;
  char operation;

  ArithmeticOperation(ExpressionNode* l, ExpressionNode* r, char op) : ExpressionNode() {
    this->left = l;
    this->right = r;
    this->operation = op;
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "Operation " << this->operation << std::endl;
    this->left->Print(indent + 1);
    this->right->Print(indent + 1);
  }



  Value GetValue() override {
    switch (operation) {
      case '+':
        std::cout << "operation" << std::endl;
        return this->left->GetValue() + this->right->GetValue();
      case '-':
        return this->left->GetValue() - this->right->GetValue();
      case '/':
        return this->left->GetValue() / this->right->GetValue();
      case '%':
        return this->left->GetValue() % this->right->GetValue();
      case '*':
        return this->left->GetValue() * this->right->GetValue();
      default:
        throw std::logic_error("invalid arithmetic operator");
    }
  }
};

struct LocationValue : public ExpressionNode {
  std::string name;
  ExpressionNode* expression;

  LocationValue(const std::string& name, ExpressionNode* value = nullptr) : ExpressionNode() {
    this->name = name;
    this->expression = value;
  }

  Value GetValue() override {
    return symbol_table[this->name];
  }

  void Execute() override {
    symbol_table[this->name] = this->expression->GetValue();
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "Variable Name: " << this->name << std::endl;
    if (this->expression) {
      this->expression->Print(indent + 1);
    }
  }
};

struct Declaration : public Node {
  LocationValue* lvalue;

  Declaration(LocationValue* lvalue) : Node() {
    this->lvalue = lvalue;
  }

  void Execute() override {
    this->lvalue->Execute();
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "Variable Declaration" << std::endl;
    this->lvalue->Print(indent + 1);
  }
};

struct AssignmentNode : public Node {
  LocationValue* lvalue;
  ExpressionNode* new_value;

  AssignmentNode(LocationValue* lvalue, ExpressionNode* new_value) : Node() {
    this->lvalue = lvalue;
    this->new_value = new_value;
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "Assignment" << std::endl;
    this->lvalue->Print(indent + 1);
    this->new_value->Print(indent + 1);
  }
};

struct BlocksNode : public Node {
  std::vector<Node*> children;
  BlocksNode() : Node() {}

  void Add(Node* child) {
    children.push_back(child);
  }

  void Execute() override {
    for (const auto node : children) {
      node->Execute();
    }
  }

  void Print(int indent) {
    for (const auto child : children) {
      child->Print(indent + 1);
    }
  }

  ~BlocksNode() {
    for (auto child : children) {
      delete child;
    }
  }
};

struct IfStatement : public Node {
  ExpressionNode* condition;
  BlocksNode* body;
  BlocksNode* elsebody;

  IfStatement(ExpressionNode* condition, BlocksNode* body, BlocksNode* elsebody = nullptr) : Node() {
    this->condition = condition;
    this->body = body;
    this->elsebody = elsebody;
  }

  void Execute() override {
    if (*(condition->GetValue().bvalue)) {
      body->Execute();
    } else {
      elsebody->Execute();
    }
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "IfStatement:" << std::endl;

    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "  Condition:" << std::endl;
    this->condition->Print(indent + 2);

    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "  Body:" << std::endl;
    body->Print(indent + 2);

    if (elsebody) {
      for (int i = 0; i < indent; i++) {
        std::cout << kSpace;
      }
      std::cout << "  ElseBody:" << std::endl;
      elsebody->Print(indent + 2);
    }
  }
};

struct WhileStatement : public Node {
  ExpressionNode* condition;
  BlocksNode* body;

  WhileStatement(ExpressionNode* condition, BlocksNode* body) : Node() {
    this->condition = condition;
    this->body = body;
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "WhileLoop:" << std::endl;

    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "  Condition:" << std::endl;
    this->condition->Print(indent + 2);

    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "  Body:" << std::endl;
    body->Print(indent + 2);
  }
};

struct ForStatement : public Node {
  ExpressionNode* begin;
  ExpressionNode* end;
  std::string it_name;
  BlocksNode* body;

  ForStatement(const std::string& it_name, ExpressionNode* begin, ExpressionNode* end, BlocksNode* body) : Node() {
    this->begin = begin;
    this->end = end;
    this->it_name = it_name;
    this->body = body;
  }

  void Print(int indent) override {
    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "ForStatement: Iterator: " << this->it_name << std::endl;

    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "  Begin:" << std::endl;
    this->begin->Print(indent + 2);

    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "  End:" << std::endl;
    this->end->Print(indent + 2);

    for (int i = 0; i < indent; i++) {
      std::cout << kSpace;
    }
    std::cout << "  Body:" << std::endl;
    body->Print(indent + 2);
  }
};
