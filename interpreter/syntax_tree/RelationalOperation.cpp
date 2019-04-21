#include "RelationalOperation.hpp"
#include <iostream>

namespace syntax_tree {

RelationalOperation::RelationalOperation(RelationalOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}
void RelationalOperation::print()
{
    this->left->print();
    switch(this->op)
    {
        case Equality: std::cout << " == "; break;
        case Inequality: std::cout << " != "; break;
        case GreaterThan: std::cout << " > "; break;
        case LessThan: std::cout << " < "; break;
        case GreaterOrEqual: std::cout << " >= "; break;
        case LessOrEqual: std::cout << " <= "; break;
    }
    this->right->print();
}
}
