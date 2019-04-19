#ifndef SYNTAXTREE_INVALIDBINDING_H
#define SYNTAXTREE_INVALIDBINDING_H

#include "Expression.hpp"
#include "Binding.hpp"

namespace syntax_tree {

class InvalidBinding : public Binding
{
public:
    void print();
};
}

#endif
