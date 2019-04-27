/*-------------------------------------------------------

Exception definition for functions, which have not yet
been implemented.

---------------------------------------------------------*/

#ifndef EXCEPTIONS_NOTIMPLEMENTED_H
#define EXCEPTIONS_NOTIMPLEMENTED_H

#include <stdexcept>

namespace exceptions {

// inheriting from the standard logic_error exception
class NotImplementedException : public std::logic_error
{
public:
    // add a custom message to the base class
    NotImplementedException() : std::logic_error("Function not yet implemented.") { };
};
}

#endif
