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

Value *NumberLiteral::evaluate(Environment *environment)
{
    return new Value(NUMBER, this->value);
}
