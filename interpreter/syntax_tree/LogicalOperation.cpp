#include "LogicalOperation.hpp"

LogicalOperation::LogicalOperation(LogicalOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}
void LogicalOperation::print()
{
    this->left->print();
    switch(this->op)
    {
        case Conjunction: std::cout << " and "; break;
        case Disjunction: std::cout << " or "; break;
        case LogicalNegation: std::cout << " not "; break;
    }
    this->right->print();
}
