#ifndef SYNTAXTREE_STATEMENT_H
#define SYNTAXTREE_STATEMENT_H

#include "Binding.hpp"
#include "Expression.hpp"

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
    void print();
};
}

#endif
