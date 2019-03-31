#ifndef SYNTAXTREE_FUNCTIONAPPLICATION_H
#define SYNTAXTREE_FUNCTIONAPPLICATION_H

#include "Expression.hpp"
#include <string>

namespace syntax_tree {

class FunctionApplication : public Expression
{
private:
    std::string name;
    Expression* argument;
public:
    FunctionApplication(std::string name, Expression* argument);
    void print();
};
}

#endif
