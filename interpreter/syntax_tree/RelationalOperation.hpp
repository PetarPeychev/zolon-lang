/*-------------------------------------------------------

Represents a relational operation on numerical values
using one of the relational operators:
    Equality        ( == )
    Inequality      ( != )
    GreaterThan     ( >  )
    LessThan        ( <  )
    GreaterOrEqual  ( >= )
    LessOrEqual     ( <= )

---------------------------------------------------------*/

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
    ~RelationalOperation();
    void print();
    evaluation::Value *evaluate(evaluation::Environment *);
};
}

#endif
