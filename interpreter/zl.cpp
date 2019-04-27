/*-------------------------------------------------------

Minimal entry point, which runs either the interactive
interface (REPL) or file interpreter depending on the
number of provided arguments.

The file interpreter is not yet implemented.

---------------------------------------------------------*/

#include "cli/FileInterface.hpp"
#include "cli/InteractiveInterface.hpp"

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        auto interactiveInterface = new cli::InteractiveInterface();
        interactiveInterface->run();
    }
    else
    {
        auto fileInterface = new cli::FileInterface();
        // passing on the arguments to the file interface
        fileInterface->run(argc, argv);
    }
    return 0;
}
