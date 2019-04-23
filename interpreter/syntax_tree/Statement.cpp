#include "Statement.hpp"

using namespace syntax_tree;
using namespace evaluation;

Statement::Statement(Binding *binding)
{
    this->type = BindingStatement;
    this->binding = binding;
}

Statement::Statement(Expression *expression)
{
    this->type = ExpressionStatement;
    this->expression = expression;
}

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
