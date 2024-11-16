#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "expression_node.hpp"

struct TupleElement : public Node
{
    std::string *name;
    ExpressionNode *elem;

    TupleElement(ExpressionNode *elem, std::string *name = nullptr);
};

struct TupleElements : public ExpressionNode
{
    std::unordered_map<int, ExpressionNode *> indexes;
    std::unordered_map<std::string, ExpressionNode *> names;

    std::vector<ExpressionNode *> elements;

    TupleElements();
    void Add(TupleElement *element);
    // void Execute(Context *context) override;
};

struct TupleNode : public ExpressionNode
{
    TupleElements *elements;

    TupleNode(TupleElements *elements);

    void Print(int indent) override;
};