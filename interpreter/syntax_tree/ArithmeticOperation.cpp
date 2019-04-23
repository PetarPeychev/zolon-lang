#include "ArithmeticOperation.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

ArithmeticOperation::ArithmeticOperation(ArithmeticOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}

ArithmeticOperation::ArithmeticOperation(ArithmeticOperator op, Expression* right)
{
    this->op = op;
    this->left = NULL;
    this->right = right;
}

void ArithmeticOperation::print()
{
    std::cout << "(";
    if(this->left != NULL)
    {
        this->left->print();
    }
    switch(this->op)
    {
        case Addition: std::cout << " + "; break;
        case Subtraction: std::cout << " - "; break;
        case Multiplication: std::cout << " * "; break;
        case Division: std::cout << " / "; break;
        case ArithmeticNegation: std::cout << " -"; break;
    }
    this->right->print();
    std::cout << ")";
}

Value *ArithmeticOperation::evaluate(Environment *environment)
{
    Value *lval;
    if(this->left != NULL)
    {
        lval = this->left->evaluate(environment);
    }
    Value *rval = this->right->evaluate(environment);
    switch(this->op)
    {
        case Addition: return new Value(NUMBER, lval->valueNval() + rval->valueNval()); break;
        case Subtraction: return new Value(NUMBER, lval->valueNval() - rval->valueNval()); break;
        case Multiplication: return new Value(NUMBER, lval->valueNval() * rval->valueNval()); break;
        case Division: return new Value(NUMBER, lval->valueNval() / rval->valueNval()); break;
        case ArithmeticNegation: return new Value(NUMBER, -rval->valueNval()); break;
        default: /* Logically Impossible */ return NULL; break;
    }
}
