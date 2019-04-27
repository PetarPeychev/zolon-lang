#include "ArithmeticOperation.hpp"
#include "../Interpreter.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

// constructor for binary arithmetic operation
ArithmeticOperation::ArithmeticOperation(ArithmeticOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}

// constructor for unary arithmetic operation
ArithmeticOperation::ArithmeticOperation(ArithmeticOperator op, Expression* right)
{
    this->op = op;
    this->left = NULL;
    this->right = right;
}

// destructor frees both operands
ArithmeticOperation::~ArithmeticOperation()
{
    delete this->left;
    delete this->right;
}

// print a parenthesized version of the operation
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
    Value *lval = NULL;
    if(this->left != NULL)
    {
        // evaluate the left operand if it exists
        lval = this->left->evaluate(environment);
    }
    // evaluate the right operand
    Value *rval = this->right->evaluate(environment);

    // if it's a unary operation, the right side is a number and the operation is negation
    // then it passes the type check
    if((lval == NULL && rval->valueType() == NUMBER && this->op == ArithmeticNegation)
    // or if it's a binary operation and both sides are numbers
    // then it passes the type check
    || (lval != NULL && lval->valueType() == NUMBER && rval->valueType() == NUMBER))
    {
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
    else
    {
        // if it doesn't type check, throw an error and return invalid value
        Interpreter::exception("Arithmetic operation attempted on invalid value types.");
        return new Value();
    }
}
