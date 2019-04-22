/*-------------------------------------------------------

Class representing an evaluation environment. Contains
a map of assigned values in the current frame and a
pointer to the parent frame.

---------------------------------------------------------*/

#ifndef EVALUATION_ENVIRONMENT_H
#define EVALUATION_ENVIRONMENT_H

#include <map>
#include "Value.hpp"

namespace evaluation {

class Environment
{
private:
    std::map<std::string, Value *> *frame;
    Environment *parent;
public:
    Environment();
    Environment(Environment *);
    Value *find(std::string);
    void add(std::string, Value *);
};
}

#endif
