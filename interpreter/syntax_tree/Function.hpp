#ifndef SYNTAXTREE_FUNCTION_H
#define SYNTAXTREE_FUNCTION_H

#include "Expression.hpp"
#include <string>

namespace syntax_tree {

class Function : public Expression
{
private:
    std::string argument;
    Expression* value;
public:
    Function(std::string argument, Expression* value);
    void print();
};
}

#endif
