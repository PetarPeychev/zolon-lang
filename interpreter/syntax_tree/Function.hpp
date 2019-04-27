/*-------------------------------------------------------

Will represent a lambda function definition.

Is not currently implemented and will produce an
exception if evaluated.

---------------------------------------------------------*/

#ifndef SYNTAXTREE_FUNCTION_H
#define SYNTAXTREE_FUNCTION_H

#include "Expression.hpp"
#include <string>
#include "../exceptions/NotImplementedException.hpp"

namespace syntax_tree {

class Function : public Expression
{
private:
    std::string argument;
    Expression* value;
public:
    Function(std::string argument, Expression* value);
    void print();
    evaluation::Value *evaluate(evaluation::Environment *) { throw exceptions::NotImplementedException(); }
};
}

#endif
