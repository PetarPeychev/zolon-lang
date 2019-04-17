#include "Binding.hpp"

#include <iostream>

using namespace syntax_tree;

Binding::Binding(std::string identifier, Expression *expression)
{
    this->identifier = identifier;
    this->expression = expression;
}

void Binding::print()
{
    std::cout << this->identifier << " = ";
    this->expression->print();
}
