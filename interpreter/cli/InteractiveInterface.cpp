#include "InteractiveInterface.hpp"
#include "../Interpreter.hpp"
#include "../evaluation/Environment.hpp"
#include <iostream>

cli::InteractiveInterface::InteractiveInterface()
{
    // is change to false when the user quits the interface
    this->running = true;

    // can be toggled by the user, displays extra debug info
    this->debug = false;
}

void cli::InteractiveInterface::addStatement(std::string statement)
{
    this->statements.push_back(statement);
}

std::vector<std::string> cli::InteractiveInterface::getStatements()
{
    return this->statements;
}

// start the REPL
void cli::InteractiveInterface::run()
{
    // create new empty environment, new interpreter instance and display start message
    evaluation::Environment *environment = new evaluation::Environment();
    Interpreter *interpreter = new Interpreter(environment);
    std::cout << "Zolon Interactive Interface (Dev 0.1)" << std::endl;

    // the main interface loop
    do
    {
        // reset the interpreter's error status
        interpreter->hadError = false;
        std::cout << ">> ";
        std::string statement;
        bool statementTerminated = false;

        // read a potentially multi-line statement, which is terminated by
        // a semicolon followed by a new line
        while(!statementTerminated)
        {
            std::string line;
            std::getline(std::cin, line);
            statement += line;
            if(!line.empty() && line.back() == ';')
            {
                statementTerminated = true;

                // check the statement for being a reserved command
                if(statement == "quit;")
                {
                    // the quit; command displays some information about the
                    // interactive session and exits
                    auto statements = this->getStatements();
                    std::cout << "Statements:" << std::endl;
                    for (auto i = statements.begin(); i != statements.end(); ++i)
                        std::cout << *i << std::endl;
                    std::cout << "Environment Variables:" << std::endl;
                    environment->print();
                    this->running = false;
                }
                else if(statement == "debug;")
                {
                    // the debug; command toggles the debug flag, which
                    // shows more information during the stages of interpretation
                    this->debug = !this->debug;
                }
                else if(statement == "env;")
                {
                    // the env; command displays all of the bindings in the environment
                    environment->print();
                }
                else // if it's not a command, send it to the interpreter
                {
                    interpreter->run(statement, debug);

                    // only add the statement to the vector if it was valid
                    // don't want to display/save invalid statements when the user quits
                    if(!interpreter->hadError)
                    {
                        this->addStatement(statement);
                    }
                }
            }
            else
            {
                // continue the statement to the next line
                std::cout << "   ";
                statement += '\n';
            }
        }
    }
    while(this->running);

    // free heap memory
    delete environment;
    delete interpreter;
}
