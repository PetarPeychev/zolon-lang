#include "BooleanLiteral.hpp"
#include <iostream>

namespace syntax_tree {

BooleanLiteral::BooleanLiteral(bool value)
{
    this->value = value;
}
void BooleanLiteral::print()
{
    if(value) std::cout << "True" << ' ';
    else std::cout << "False" << ' ';
}
}
