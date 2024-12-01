#include "expression_node.hpp"
#include "arithmetic_operation.hpp"
#include "constant_node.hpp"

ExpressionNode::ExpressionNode() : Node() {
}

Value ExpressionNode::GetValue(Context *context) {
    return Value();
}

void ExpressionNode::Optimize() {
    if (auto it = dynamic_cast<ArithmeticOperation *>(this)) {
        if (auto leftConst = dynamic_cast<ConstantNode *>(it->left)) {
            if (auto rightConst = dynamic_cast<ConstantNode *>(it->right)) {
                ExpressionNode *optimized = OptimizeNode(this);
                if (optimized != this) {
                    if (auto constNode = dynamic_cast<ConstantNode *>(optimized)) {
                        this->~ExpressionNode();
                        new(this) ConstantNode(*constNode);
                    } else {
                        this->~ExpressionNode();
                        new(this) ExpressionNode(*optimized);
                    }
                    delete optimized;
                }
            }
        }
    }

}

ExpressionNode *OptimizeNode(ExpressionNode *node) {
    if (auto it = dynamic_cast<ArithmeticOperation *>(node)) {
        if (auto leftConst = dynamic_cast<ConstantNode *>(it->left)) {
            if (auto rightConst = dynamic_cast<ConstantNode *>(it->right)) {
                Value left = leftConst->GetValue(nullptr);
                Value right = rightConst->GetValue(nullptr);
                if (left.ivalue && right.ivalue) {
                    int result = 0;
                    switch (it->operation) {
                        case '+':
                            result = *left.ivalue + *right.ivalue;
                            break;
                        case '-':
                            result = *left.ivalue - *right.ivalue;
                            break;
                        case '*':
                            result = *left.ivalue * *right.ivalue;
                            break;
                        case '/':
                            result = *left.ivalue / *right.ivalue;
                            break;
                    }
                    return new ConstantNode(result);
                }
            }
        }
    }
//    return node;
}

ExpressionNode::~ExpressionNode() {}