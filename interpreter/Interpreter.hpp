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
    void run(std::string statement);
};

#endif
