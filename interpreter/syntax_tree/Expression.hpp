#ifndef SYNTAXTREE_EXPRESSION_H
#define SYNTAXTREE_EXPRESSION_H

#include "../evaluation/Environment.hpp"

namespace syntax_tree {

class Expression
{
public:
    virtual ~Expression() {}
    virtual void print() = 0;
    virtual evaluation::Value *evaluate(evaluation::Environment *) = 0;
};
}

#endif
