#ifndef SYNTAXTREE_BINDING_H
#define SYNTAXTREE_BINDING_H

#include "Expression.hpp"
#include "../evaluation/Environment.hpp"
#include <string>

namespace syntax_tree {

class Binding
{
private:
    std::string identifier;
    Expression *expression;
public:
    Binding();
    Binding(std::string, Expression *);
    void print();
    void evaluate(evaluation::Environment *);
};
}

#endif
