/*-------------------------------------------------------

Represents an arithmetic operation over number values
using one of the arithmetic operators:
    Addition        ( + )
    Subtraction     ( - )
    Multiplication  ( * )
    Division        ( / )
    Negation        ( - )

---------------------------------------------------------*/

#ifndef SYNTAXTREE_ARITHMETICOPERATION_H
#define SYNTAXTREE_ARITHMETICOPERATION_H

#include "Expression.hpp"

namespace syntax_tree {

enum ArithmeticOperator
{
    Addition,
    Subtraction,
    Multiplication,
    Division,
    ArithmeticNegation
};

class ArithmeticOperation : public Expression
{
private:
    ArithmeticOperator op;
    Expression* left;
    Expression* right;
public:
    ArithmeticOperation(ArithmeticOperator op, Expression* left, Expression* right);
    ArithmeticOperation(ArithmeticOperator op, Expression* right);
    ~ArithmeticOperation();
    void print();
    evaluation::Value *evaluate(evaluation::Environment *);
};
}

#endif
