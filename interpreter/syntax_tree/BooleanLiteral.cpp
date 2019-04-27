#include "BooleanLiteral.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

BooleanLiteral::BooleanLiteral(bool value)
{
    this->value = value;
}

void BooleanLiteral::print()
{
    if(value) std::cout << "True";
    else std::cout << "False";
}

// evaluating a literal means just returning the value
Value *BooleanLiteral::evaluate(Environment *environment)
{
    return new Value(BOOLEAN, this->value);
}
