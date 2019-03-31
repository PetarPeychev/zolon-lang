#include "ArithmeticOperation.hpp"

namespace syntax_tree {

ArithmeticOperation::ArithmeticOperation(ArithmeticOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}
void ArithmeticOperation::print()
{
    this->left->print();
    switch(this->op)
    {
        case Addition: std::cout << " + "; break;
        case Subtraction: std::cout << " - "; break;
        case Multiplication: std::cout << " * "; break;
        case Division: std::cout << " / "; break;
        case ArithmeticNegation: std::cout << " -"; break;
    }
    this->right->print();
}
}
