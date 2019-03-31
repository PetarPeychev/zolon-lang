#ifndef SYNTAXTREE_NUMBERLITERAL_H
#define SYNTAXTREE_NUMBERLITERAL_H

#include "Expression.hpp"

namespace syntax_tree {

class NumberLiteral : public Expression
{
private:
    double value;
public:
    NumberLiteral(double value);
    void print();
};
}

#endif
