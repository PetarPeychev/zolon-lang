/*-------------------------------------------------------

The REPL (read-eval-print loop) interactive interface
wrapper for the interpreter.

---------------------------------------------------------*/

#ifndef CLI_INTERACTIVEINTERFACE_H
#define CLI_INTERACTIVEINTERFACE_H

#include <vector>
#include <string>

namespace cli {

class InteractiveInterface
{
private:
    bool running;
    bool debug;
    std::vector<std::string> statements;
    void addStatement(std::string statement);
    std::vector<std::string> getStatements();
public:
    InteractiveInterface();
    void run();
};
}

#endif
