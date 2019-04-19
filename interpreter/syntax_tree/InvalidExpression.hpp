#ifndef SYNTAXTREE_INVALIDEXPRESSION_H
#define SYNTAXTREE_INVALIDEXPRESSION_H

#include "Expression.hpp"

namespace syntax_tree {

class InvalidExpression : public Expression
{
public:
    void print();
};
}

#endif
