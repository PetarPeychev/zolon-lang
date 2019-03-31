#ifndef SYNTAXTREE_EXPRESSION_H
#define SYNTAXTREE_EXPRESSION_H

#include <iostream>

namespace syntax_tree {

class Expression
{
public:
    virtual void print() = 0;
};
}

#endif
