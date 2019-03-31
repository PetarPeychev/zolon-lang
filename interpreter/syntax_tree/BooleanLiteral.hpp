#ifndef SYNTAXTREE_BOOLEANLITERAL_H
#define SYNTAXTREE_BOOLEANLITERAL_H

#include "Expression.hpp"

namespace syntax_tree {

class BooleanLiteral : public Expression
{
private:
    bool value;
public:
    BooleanLiteral(bool value);
    void print();
};
}

#endif
