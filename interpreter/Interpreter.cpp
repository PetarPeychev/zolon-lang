#include "Interpreter.hpp"
#include "lexical_analysis/Scanner.hpp"
#include "lexical_analysis/Token.hpp"
#include <iostream>

Interpreter::Interpreter(){}

bool Interpreter::hadError = false;

void Interpreter::error(int line, std::string message)
{
    std::cout << "[Line " + std::to_string(line) + "] Error: " + message << std::endl;
    hadError = true;
}

void Interpreter::run(std::string statement)
{
    lexical_analysis::Scanner* scanner = new lexical_analysis::Scanner(statement);
    std::vector<lexical_analysis::Token*> tokens = scanner->scanTokens();
}
