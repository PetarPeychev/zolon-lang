#include "Environment.hpp"
#include <iostream>

using namespace evaluation;

// constructor for the global environment
Environment::Environment()
{
    this->frame = new std::map<std::string, Value *>;
    this->parent = NULL;
}

// constructor for a local environment with a parent
Environment::Environment(Environment *parent)
{
    this->frame = new std::map<std::string, Value *>;
    this->parent = parent;
}

// clear vector and free the memory
Environment::~Environment()
{
    this->frame->clear();
    delete this->frame;
}

// check if a name is bound to the current frame
bool Environment::check(std::string identifier)
{
    return this->frame->count(identifier);
}

// find a value by name in the current and parent frames
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
            // return invalid value
            return new Value();
        }
    }
}

// add a binding to the current frame
void Environment::add(std::string identifier, Value *value)
{
    if(this->check(identifier))
    {
        // can rebind a name in the current frame,
        //but not "assign" to another parent frame
        this->frame->at(identifier) = value;
    }
    else
    {
        this->frame->insert(std::pair<std::string, Value *>(identifier, value));
    }
}

// display the list of bindings in the current frame
void Environment::print()
{
    for(auto i = this->frame->begin(); i != this->frame->end(); i++)
    {
        std::cout << i->first << " = ";
        i->second->print();
    }
}
