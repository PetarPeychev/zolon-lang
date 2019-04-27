/*-------------------------------------------------------

Will represent application of a function on a parameter.

Is not currently implemented and trying to evaluate
it will produce an exception.

---------------------------------------------------------*/

#ifndef SYNTAXTREE_FUNCTIONAPPLICATION_H
#define SYNTAXTREE_FUNCTIONAPPLICATION_H

#include "Expression.hpp"
#include <string>
#include "../exceptions/NotImplementedException.hpp"

namespace syntax_tree {

class FunctionApplication : public Expression
{
private:
    std::string name;
    Expression* argument;
public:
    FunctionApplication(std::string name, Expression* argument);
    void print();
    evaluation::Value *evaluate(evaluation::Environment *)
    { throw exceptions::NotImplementedException(); }
};
}

#endif
