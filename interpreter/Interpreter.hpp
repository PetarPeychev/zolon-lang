/*-------------------------------------------------------

The core logic class, which implements the Zolon interpreter
pipeline and evaluates statements.

---------------------------------------------------------*/

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include "evaluation/Environment.hpp"

class Interpreter
{
private:
    evaluation::Environment *environment;
public:
    Interpreter(evaluation::Environment *);
    static bool hadError;
    static void error(int line, std::string message);
    void run(std::string statement);
};

#endif
