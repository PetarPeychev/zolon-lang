#include "Environment.hpp"
#include <iostream>

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

bool Environment::check(std::string identifier)
{
    return this->frame->count(identifier);
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
            return new Value();
        }
    }
}

void Environment::add(std::string identifier, Value *value)
{
    if(this->check(identifier))
    {
        this->frame->at(identifier) = value;
    }
    else
    {
        this->frame->insert(std::pair<std::string, Value *>(identifier, value));
    }
}

void Environment::print()
{
    for(auto i = this->frame->begin(); i != this->frame->end(); i++)
    {
        std::cout << i->first << " = ";
        i->second->print();
    }
}
