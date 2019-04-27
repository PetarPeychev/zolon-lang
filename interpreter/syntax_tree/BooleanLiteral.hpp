/*-------------------------------------------------------

Represents a literal boolean value of either true or false.

---------------------------------------------------------*/

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
    evaluation::Value *evaluate(evaluation::Environment *);
};
}

#endif
