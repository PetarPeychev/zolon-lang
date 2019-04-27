#include "InvalidBinding.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

void InvalidBinding::print()
{
    std::cout << "[Invalid Binding]";
}

// can't evaluate an invalid binding
void InvalidBinding::evaluate(Environment *environment)
{
    throw "Attempt to evaluate an invalid binding.";
}
