/*-------------------------------------------------------

The file interface wrapper for the interpreter. Reads
Zolon source files and runs the interpreter on them.

Not yet implemented.

---------------------------------------------------------*/

#ifndef CLI_FILEINTERFACE_H
#define CLI_FILEINTERFACE_H

namespace cli {

class FileInterface
{
private:
public:
    FileInterface();
    void run(int argc, char* argv[]);
};
}

#endif
