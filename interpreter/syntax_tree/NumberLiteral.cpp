#include "NumberLiteral.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

NumberLiteral::NumberLiteral(double value)
{
    this->value = value;
}
void NumberLiteral::print()
{
    std::cout << value;
}

// evaluating a literal means just returning the value
Value *NumberLiteral::evaluate(Environment *environment)
{
    return new Value(NUMBER, this->value);
}
