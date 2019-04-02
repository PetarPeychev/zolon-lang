/*-------------------------------------------------------

The file interface wrapper for the interpreter. Reads
Zolon source files and runs the interpreter on them.

---------------------------------------------------------*/

#ifndef CLI_FILEINTERFACE_H
#define CLI_FILEINTERFACE_H

#include "../exceptions/NotImplementedException.hpp"

namespace cli {

class FileInterface
{
private:
public:
    FileInterface() { throw exceptions::NotImplementedException(); };
    void run(int argc, char* argv[]) { throw exceptions::NotImplementedException(); };
};
}

#endif
