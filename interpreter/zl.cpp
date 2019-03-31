/*-------------------------------------------------------

Minimal entry point, which runs either the interactive
or file interface, depending on the provided arguments.

---------------------------------------------------------*/

#include "cli/FileInterpreter.hpp"
#include "cli/InteractiveInterface.hpp"

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        auto interactiveInterface = new cli::InteractiveInterface();
        interactiveInterface->initialize();
    }
    else
    {
        auto fileInterpreter = new cli::FileInterpreter();
        fileInterpreter->run(argc, argv);
    }
    return 0;
}
