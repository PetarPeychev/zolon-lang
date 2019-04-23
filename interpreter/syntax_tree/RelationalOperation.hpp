#ifndef SYNTAXTREE_RELATIONALOPERATION_H
#define SYNTAXTREE_RELATIONALOPERATION_H

#include "Expression.hpp"

namespace syntax_tree {

enum RelationalOperator
{
    Equality,
    Inequality,
    GreaterThan,
    LessThan,
    GreaterOrEqual,
    LessOrEqual
};

class RelationalOperation : public Expression
{
private:
    RelationalOperator op;
    Expression* left;
    Expression* right;
public:
    RelationalOperation(RelationalOperator op, Expression* left, Expression* right);
    void print();
    evaluation::Value *evaluate(evaluation::Environment *);
};
}

#endif
