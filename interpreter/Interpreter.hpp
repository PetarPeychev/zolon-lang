/*-------------------------------------------------------

The core logic class, which implements the Zolon interpreter
pipeline and evaluates statements.

---------------------------------------------------------*/

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

class Interpreter
{
private:
public:
    Interpreter();
    static bool hadError;
    static void error(int line, std::string message);
    void run(std::string statement);
};

#endif
