/*-------------------------------------------------------

Represents a binding, which doesn't contain a valid
expression.

---------------------------------------------------------*/

#ifndef SYNTAXTREE_INVALIDBINDING_H
#define SYNTAXTREE_INVALIDBINDING_H

#include "Expression.hpp"
#include "Binding.hpp"

namespace syntax_tree {

class InvalidBinding : public Binding
{
public:
    void print();
    void evaluate(evaluation::Environment *);
};
}

#endif
