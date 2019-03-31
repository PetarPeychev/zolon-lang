#include "syntax_tree.hpp"

using namespace syntax_tree;

int main()
{
    Expression* expression = new Function(
        "x",
        new RelationalOperation(
            Equality,
            new NumberLiteral(5),
            new ArithmeticOperation(
                Multiplication,
                new NumberLiteral(7),
                new FunctionApplication(
                    "factorial",
                    new NumberLiteral(3))
            )
        ));
    expression->print();
    std::cout << std::endl;
}
