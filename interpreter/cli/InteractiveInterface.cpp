#include "InteractiveInterface.hpp"
#include "../Interpreter.hpp"
#include "../evaluation/Environment.hpp"
#include <iostream>

cli::InteractiveInterface::InteractiveInterface()
{
    this->running = true;
}

void cli::InteractiveInterface::addStatement(std::string statement)
{
    this->statements.push_back(statement);
}

std::vector<std::string> cli::InteractiveInterface::getStatements()
{
    return this->statements;
}

void cli::InteractiveInterface::initialize()
{
    evaluation::Environment *environment = new evaluation::Environment();
    Interpreter* interpreter = new Interpreter(environment);
    std::cout << "Zolon Interactive Interface (Dev 0.1)" << std::endl;
    do
    {
        interpreter->hadError = false;
        std::cout << ">> ";
        std::string statement;
        bool statementTerminated = false;
        while(!statementTerminated)
        {
            std::string line;
            std::getline(std::cin, line);
            statement += line;
            if(!line.empty() && line.back() == ';')
            {
                statementTerminated = true;
                if(statement == "quit;")
                {
                    // TODO: Rewrite the statements display into a save function
                    auto statements = this->getStatements();
                    std::cout << "Statements:" << std::endl;
                    for (auto i = statements.begin(); i != statements.end(); ++i)
                        std::cout << *i << std::endl;
                    this->running = false;
                }
                else
                {
                    interpreter->run(statement);
                    if(!interpreter->hadError)
                    {
                        this->addStatement(statement);
                    }
                }
            }
            else
            {
                std::cout << "   ";
                statement += '\n';
            }
        }
    }
    while(this->running);
}
