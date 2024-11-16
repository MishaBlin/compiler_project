#include "tuple_node.hpp"
#include <string>
#include <iostream>

#include "constants.hpp"

TupleElements::TupleElements() : ExpressionNode() {}

TupleNode::TupleNode(TupleElements *elements)
{
    this->elements = elements;
}

void TupleElements::Add(TupleElement *element)
{
    int n = this->indexes.size();
    std::cout << n << std::endl;
    this->indexes[n + 1] = element->elem;

    if (element->name)
    {
        this->names[*(element->name)] = element->elem;
    }
    std::cout << this->indexes.size() << std::endl;
}

void TupleNode::Print(int indent)
{
    for (int i = 0; i < indent; i++)
    {
        std::cout << constants::kSpace;
    }
    std::cout << "Tuple. Elements: " << std::endl;
    // std::cout << this->elements->indexes.size() << std::endl;
    for (auto [key, value] : this->elements->indexes)
    {
        for (int i = 0; i < indent + 1; i++)
        {
            std::cout << constants::kSpace;
        }
        std::cout << "key " << key << std::endl;
        for (int i = 0; i < indent + 1; i++)
        {
            std::cout << constants::kSpace;
        }
        std::cout << "value " << std::endl;
        value->Print(indent + 1);
    }

    for (auto [key, value] : this->elements->names)
    {
        for (int i = 0; i < indent + 1; i++)
        {
            std::cout << constants::kSpace;
        }
        std::cout << "key " << key << std::endl;
        for (int i = 0; i < indent + 1; i++)
        {
            std::cout << constants::kSpace;
        }
        std::cout << "value " << std::endl;
        value->Print(indent + 1);
    }
}

TupleElement::TupleElement(ExpressionNode *elem, std::string *name) : Node()
{
    this->elem = elem;
    this->name = name;
}
