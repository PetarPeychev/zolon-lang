#ifndef SYNTAXTREE_LOGICALOEPRATION_H
#define SYNTAXTREE_LOGICALOEPRATION_H

#include "Expression.hpp"

namespace syntax_tree {

enum LogicalOperator
{
    Conjunction,
    Disjunction,
    LogicalNegation
};

class LogicalOperation : public Expression
{
private:
    LogicalOperator op;
    Expression* left;
    Expression* right;
public:
    LogicalOperation(LogicalOperator op, Expression* left, Expression* right);
    LogicalOperation(LogicalOperator op, Expression* right);
    void print();
    evaluation::Value *evaluate(evaluation::Environment *environment);
};
}

#endif
