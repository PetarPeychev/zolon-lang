/*-------------------------------------------------------

The root of the statement syntax tree. Can currently
either contain a binding statement or an expression.

The evaluate function recursively triggers evaluation
of the whole tree structure using the Gang of Four pattern.

A visitor pattern would be preferable for encapsulation
of logic, but due to time contraints, I opted for GoF.

---------------------------------------------------------*/

#ifndef SYNTAXTREE_STATEMENT_H
#define SYNTAXTREE_STATEMENT_H

#include "Binding.hpp"
#include "Expression.hpp"
#include "../evaluation/Environment.hpp"

namespace syntax_tree {

enum StatementType
{
    BindingStatement,
    ExpressionStatement
};

class Statement
{
private:
    StatementType type;
    Binding* binding;
    Expression* expression;
public:
    Statement(Binding*);
    Statement(Expression*);
    ~Statement();
    void print();
    void evaluate(evaluation::Environment *);
};
}

#endif
