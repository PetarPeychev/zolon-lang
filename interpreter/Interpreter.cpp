#include "Interpreter.hpp"
#include "lexical_analysis/Scanner.hpp"
#include "lexical_analysis/Token.hpp"

Interpreter::Interpreter(){}

void Interpreter::run(std::string statement)
{
    lexical_analysis::Scanner* scanner = new lexical_analysis::Scanner(statement);
    std::vector<lexical_analysis::Token> tokens = scanner->scanTokens();
}
