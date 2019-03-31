/*-------------------------------------------------------

Exception definition for functions, which have not yet
been implemented.

---------------------------------------------------------*/

#ifndef EXCEPTIONS_NOTIMPLEMENTED_H
#define EXCEPTIONS_NOTIMPLEMENTED_H

#include <stdexcept>

namespace exceptions {

class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException() : std::logic_error("Function not yet implemented.") { };
};
}

#endif
