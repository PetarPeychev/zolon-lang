#include "Environment.hpp"

using namespace evaluation;

Environment::Environment()
{
    this->frame = new std::map<std::string, Value *>;
    this->parent = NULL;
}

Environment::Environment(Environment *parent)
{
    this->frame = new std::map<std::string, Value *>;
    this->parent = parent;
}

Value *Environment::find(std::string identifier)
{
    try
    {
        return this->frame->at(identifier);
    }
    catch(std::out_of_range)
    {
        if(this->parent != NULL)
        {
            return this->parent->find(identifier);
        }
        else
        {
            return NULL;
        }
    }
}

void Environment::add(std::string identifier, Value *value)
{
    this->frame->insert(std::pair<std::string, Value *>(identifier, value));
}
