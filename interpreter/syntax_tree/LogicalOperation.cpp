#include "LogicalOperation.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

LogicalOperation::LogicalOperation(LogicalOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}

LogicalOperation::LogicalOperation(LogicalOperator op, Expression* right)
{
    this->op = op;
    this->left = NULL;
    this->right = right;
}

void LogicalOperation::print()
{
    std::cout << "(";
    if(this->left != NULL)
    {
        this->left->print();
    }
    switch(this->op)
    {
        case Conjunction: std::cout << " and "; break;
        case Disjunction: std::cout << " or "; break;
        case LogicalNegation: std::cout << " not "; break;
    }
    this->right->print();
    std::cout << ")";
}

Value *LogicalOperation::evaluate(Environment *environment)
{
    Value *lval;
    if(this->left != NULL)
    {
        lval = this->left->evaluate(environment);
    }
    Value *rval = this->right->evaluate(environment);
    switch(this->op)
    {
        case Conjunction: return new Value(BOOLEAN, lval->valueBval() && rval->valueBval()); break;
        case Disjunction: return new Value(BOOLEAN, lval->valueBval() || rval->valueBval()); break;
        case LogicalNegation: return new Value(BOOLEAN, !rval->valueBval()); break;
        default: /* Logically Impossible */ return NULL; break;
    }
}
