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
    void print();
};
}

#endif
