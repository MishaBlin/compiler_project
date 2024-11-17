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
    this->indexes[n + 1] = element->elem;

    if (element->name)
    {
        this->names[*(element->name)] = element->elem;
        this->idxToName[n + 1] = *(element->name);
    }
}

void TupleNode::Print(int indent)
{
    for (int i = 0; i < indent; i++)
    {
        std::cout << constants::kSpace;
    }
    std::cout << "Tuple. Elements: " << std::endl;
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

Value TupleNode::GetValue(Context *context)
{
    std::string result = "";

    for (int i = 1; i <= this->elements->indexes.size(); i++)
    {
        Value value = this->elements->indexes[i]->GetValue(context);
        std::string name;

        if (this->elements->idxToName.count(i) != 0)
        {
            name = this->elements->idxToName[i] += " = ";
        }

        result += name;

        if (value.svalue)
        {
            result += *(value.svalue);
        }
        else if (value.ivalue)
        {
            result += std::to_string(*(value.ivalue));
        }
        else if (value.bvalue)
        {
            result += std::to_string(*(value.dvalue));
        }

        if (i != this->elements->indexes.size())
        {
            result += ", ";
        }
    }

    result = "{" + result + "}";

    auto val = new Value();
    val->svalue = new std::string(result);

    return *val;
}
