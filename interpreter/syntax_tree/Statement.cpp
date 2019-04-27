#include "Statement.hpp"

using namespace syntax_tree;
using namespace evaluation;

// constructor for a binding statement
Statement::Statement(Binding *binding)
{
    this->type = BindingStatement;
    this->binding = binding;
}

// constructor for an expression statement
Statement::Statement(Expression *expression)
{
    this->type = ExpressionStatement;
    this->expression = expression;
}

// destructor deletes contained expression or binding
Statement::~Statement()
{
    if(this->type == BindingStatement)
    {
        delete this->binding;
    }
    else
    {
        delete this->expression;
    }
}

// printing the statement means printing its contained expression or binding
void Statement::print()
{
    if(this->type == BindingStatement)
    {
        this->binding->print();
    }
    else
    {
        this->expression->print();
    }
}

// evaluating the statement means either evaluating the binding
// or evaluating the expression and printing the value to the user
void Statement::evaluate(Environment *environment)
{
    if(this->type == BindingStatement)
    {
        this->binding->evaluate(environment);
    }
    else
    {
        Value *value = this->expression->evaluate(environment);
        value->print();
    }
}
