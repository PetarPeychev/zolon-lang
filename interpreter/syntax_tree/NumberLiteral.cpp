#include "NumberLiteral.hpp"

namespace syntax_tree {

NumberLiteral::NumberLiteral(double value)
{
    this->value = value;
}
void NumberLiteral::print()
{
    std::cout << value;
}
}
