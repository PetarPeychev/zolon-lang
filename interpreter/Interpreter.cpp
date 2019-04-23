#include "Interpreter.hpp"
#include "lexical_analysis/Scanner.hpp"
#include "lexical_analysis/Token.hpp"
#include "syntactical_analysis/Parser.hpp"
#include "syntax_tree/syntax_tree.hpp"
#include "evaluation/Environment.hpp"
#include <iostream>

Interpreter::Interpreter(evaluation::Environment *environment)
{
    this->environment = environment;
}

bool Interpreter::hadError = false;

void Interpreter::error(int line, std::string message)
{
    std::cout << "[Line " + std::to_string(line) + "] Error: " + message << std::endl;
    hadError = true;
}

void Interpreter::exception(std::string message)
{
    std::cout << "Runtime Exception: " + message << std::endl;
    hadError = true;
}

void Interpreter::run(std::string statement)
{
    lexical_analysis::Scanner *scanner = new lexical_analysis::Scanner(statement);
    std::vector<lexical_analysis::Token*> tokens = scanner->scanTokens();
    if(this->hadError) return; // Return if scanner produced an error
    // Print token vector for debug purposes
    for(auto token : tokens)
    {
        std::cout << token->toString() << std::endl;
    }
    syntactical_analysis::Parser *parser = new syntactical_analysis::Parser(tokens);
    syntax_tree::Statement *tree = parser->parseStatement();
    if(this->hadError) return; // Return if parser produced an error
    // Print syntax tree for debug purposes
    tree->print();
    std::cout << std::endl;
    tree->evaluate(this->environment); // TODO: Runtime exception handling
}
