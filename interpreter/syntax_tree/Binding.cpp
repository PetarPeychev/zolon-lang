#include "Binding.hpp"
#include "InvalidExpression.hpp"
#include "../Interpreter.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

Binding::Binding()
{
    this->identifier = "";
    this->expression = new InvalidExpression();
}

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

void Binding::evaluate(Environment *environment)
{
    Value *rval = this->expression->evaluate(environment);
    if(rval->valueType() != INVALID)
    {
        environment->add(this->identifier, rval);
        rval->print();
    }
    else
    {
        Interpreter::exception("Attempting to bind an invalid value type.");
    }
}
