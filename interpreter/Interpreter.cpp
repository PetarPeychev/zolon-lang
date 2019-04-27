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

// static error flag for the interpreter
bool Interpreter::hadError = false;

// error function displays a message and flips the error flag
// usually used to signal errors during scanning or parsing
void Interpreter::error(int line, std::string message)
{
    std::cout << "[Line " + std::to_string(line) + "] Error: " + message << std::endl;
    hadError = true;
}

// runtime exceptions used to signal errors during evaluation
void Interpreter::exception(std::string message)
{
    std::cout << "Runtime Exception: " + message << std::endl;
    hadError = true;
}

// feed a statement to the interpreter, which runs it through the pipeline
void Interpreter::run(std::string statement, bool debug)
{
    lexical_analysis::Scanner scanner = lexical_analysis::Scanner(statement);
    std::vector<lexical_analysis::Token*> tokens = scanner.scanTokens();
    if(this->hadError)
    {
        tokens.clear(); // free memory of token pointers before exit
        return; // Return if scanner produced any errors
    }
    // Print token vector for debug purposes
    if(debug)
    {
        for(auto token : tokens)
        {
            std::cout << token->toString() << std::endl;
        }
    }
    syntactical_analysis::Parser parser = syntactical_analysis::Parser(tokens, this->environment);
    syntax_tree::Statement *tree = parser.parseStatement();
    if(this->hadError)
    {
        tokens.clear(); // free memory of token pointers
        delete tree; // free memory from the tree
        return; // Return if parser produced an error
    }
    // Print syntax tree for debug purposes
    if(debug)
    {
        tree->print();
        std::cout << std::endl;
    }
    tree->evaluate(this->environment);

    // free heap memory
    tokens.clear();
    delete tree;
}
