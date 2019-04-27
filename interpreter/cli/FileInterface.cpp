#include "FileInterface.hpp"
#include "../exceptions/NotImplementedException.hpp"

using namespace cli;

// Throw my user-defined NotImplementedException
FileInterface::FileInterface()
{
    throw exceptions::NotImplementedException();
}

void FileInterface::run(int argc, char *argv[])
{
    throw exceptions::NotImplementedException();
}
