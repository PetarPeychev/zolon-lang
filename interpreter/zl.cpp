/*-------------------------------------------------------

Minimal entry point, which runs either the interactive
interface or file interpreter, depending on the number of
provided arguments. Validation of the arguments is
implemented in the file interpreter.

---------------------------------------------------------*/

#include "cli/FileInterface.hpp"
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
        auto fileInterface = new cli::FileInterface();
        fileInterface->run(argc, argv);
    }
    return 0;
}
