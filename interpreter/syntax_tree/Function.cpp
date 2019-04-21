#include "Function.hpp"
#include <iostream>

namespace syntax_tree {

Function::Function(std::string argument, Expression* value)
{
    this->argument = argument;
    this->value = value;
}
void Function::print()
{
    std::cout << "\\" << this->argument << " -> {";
    this->value->print();
    std::cout << "}" << ' ';
}
}
