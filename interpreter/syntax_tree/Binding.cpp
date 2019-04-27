#include "Binding.hpp"
#include "InvalidExpression.hpp"
#include "../Interpreter.hpp"
#include <iostream>

using namespace syntax_tree;
using namespace evaluation;

// constructor for an invalid binding
Binding::Binding()
{
    this->identifier = "";
    this->expression = new InvalidExpression();
}

// constructor for a valid binding
Binding::Binding(std::string identifier, Expression *expression)
{
    this->identifier = identifier;
    this->expression = expression;
}

// desructor deletes the contained expression
Binding::~Binding()
{
    delete this->expression;
}

// printing the identifier, an equals sign and the expression contained
void Binding::print()
{
    std::cout << this->identifier << " = ";
    this->expression->print();
}

// evaluate the binding by evaluating the expression,
// adding the result to the environment
// and printing the value
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
        // if the expression evaluates to InvalidValue,
        // the binding throws an error
        Interpreter::exception("Attempting to bind an invalid value type.");
    }
}
