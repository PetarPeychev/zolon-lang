#include "InvalidExpression.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

void InvalidExpression::print()
{
    std::cout << "[Invalid Expression]";
}

Value *InvalidExpression::evaluate(Environment *environment)
{
    throw "Attempt to evaluate an invalid expression.";
}
