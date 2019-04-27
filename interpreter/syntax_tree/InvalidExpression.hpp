/*-------------------------------------------------------

Represents an expression, which can't evaluate to
a valid value.

---------------------------------------------------------*/

#ifndef SYNTAXTREE_INVALIDEXPRESSION_H
#define SYNTAXTREE_INVALIDEXPRESSION_H

#include "Expression.hpp"

namespace syntax_tree {

class InvalidExpression : public Expression
{
public:
    void print();
    evaluation::Value *evaluate(evaluation::Environment *);
};
}

#endif
