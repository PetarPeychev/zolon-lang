#include "LogicalOperation.hpp"
#include "../Interpreter.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

// binary logical operation
LogicalOperation::LogicalOperation(LogicalOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}

// unary logical operation
LogicalOperation::LogicalOperation(LogicalOperator op, Expression* right)
{
    this->op = op;
    this->left = NULL;
    this->right = right;
}

// destruct both operands
LogicalOperation::~LogicalOperation()
{
    delete this->left;
    delete this->right;
}

// print a parenthesized version of the expression
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
    Value *lval = NULL;
    if(this->left != NULL)
    {
        // evaluate the left side if the operation is binary
        lval = this->left->evaluate(environment);
    }
    // evaluate the right side
    Value *rval = this->right->evaluate(environment);

    // if the operation is unary, the right is a boolean and the operatator is negation
    // then it passes a type check for unary negation
    if((lval == NULL && rval->valueType() == BOOLEAN && this->op == LogicalNegation)
    // or if the operation is binary and both sides are booleans it also passes
    || (lval != NULL && lval->valueType() == BOOLEAN && rval->valueType() == BOOLEAN))
    {
        switch(this->op)
        {
            case Conjunction: return new Value(BOOLEAN, lval->valueBval() && rval->valueBval()); break;
            case Disjunction: return new Value(BOOLEAN, lval->valueBval() || rval->valueBval()); break;
            case LogicalNegation: return new Value(BOOLEAN, !rval->valueBval()); break;
            default: /* Logically Impossible */ return NULL; break;
        }
    }
    else
    {
        // if it doesn't pass then throw a type error and return an invalid value
        Interpreter::exception("Logical operation attempted on invalid value types.");
        return new Value();
    }
}
