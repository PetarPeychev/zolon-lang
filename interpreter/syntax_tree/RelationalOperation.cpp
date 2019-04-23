#include "RelationalOperation.hpp"
#include "../Interpreter.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

RelationalOperation::RelationalOperation(RelationalOperator op, Expression* left, Expression* right)
{
    this->op = op;
    this->left = left;
    this->right = right;
}
void RelationalOperation::print()
{
    std::cout << "(";
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
    std::cout << ")";
}

Value *RelationalOperation::evaluate(Environment *environment)
{
    Value *lval = this->left->evaluate(environment);
    Value *rval = this->right->evaluate(environment);
    if(lval->valueType() == NUMBER && rval->valueType() == NUMBER)
    {
        switch(this->op)
        {
            case Equality: return new Value(BOOLEAN, lval->valueNval() == rval->valueNval()); break;
            case Inequality: return new Value(BOOLEAN, lval->valueNval() != rval->valueNval()); break;
            case GreaterThan: return new Value(BOOLEAN, lval->valueNval() > rval->valueNval()); break;
            case LessThan: return new Value(BOOLEAN, lval->valueNval() < rval->valueNval()); break;
            case GreaterOrEqual: return new Value(BOOLEAN, lval->valueNval() >= rval->valueNval()); break;
            case LessOrEqual: return new Value(BOOLEAN, lval->valueNval() <= rval->valueNval()); break;
            default: /* Logically Impossible */ return NULL; break;
        }
    }
    else
    {
        Interpreter::exception("Relational operation attempted on invalid value types.");
        return new Value();
    }
}
