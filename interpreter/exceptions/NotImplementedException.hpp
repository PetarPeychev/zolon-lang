/*-------------------------------------------------------

Exception definition for functions, which have not yet
been implemented.

---------------------------------------------------------*/

#ifndef EXCEPTIONS_NOTIMPLEMENTED_H
#define EXCEPTIONS_NOTIMPLEMENTED_H

#include <stdexcept>

namespace exceptions {

class NotImplemented : public std::logic_error
{
public:
    NotImplemented() : std::logic_error("Function not yet implemented.") { };
};
}

#endif
