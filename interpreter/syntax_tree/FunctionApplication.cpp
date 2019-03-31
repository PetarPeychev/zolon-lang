#include "FunctionApplication.hpp"

namespace syntax_tree {

FunctionApplication::FunctionApplication(std::string name, Expression* argument)
{
    this->name = name;
    this->argument = argument;
}
void FunctionApplication::print()
{
    std::cout << name << '(';
    this->argument->print();
    std::cout << ')';
}
}
