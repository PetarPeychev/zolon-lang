#include "Value.hpp"
#include <iostream>

using namespace evaluation;

// construct an invalid value
Value::Value()
{
    this->type = INVALID;
}

// construct types which contain a number
Value::Value(ValueType type, double nval)
{
    this->type = type;
    this->nval = nval;
}

// construct types which contain a bool
Value::Value(ValueType type, bool bval)
{
    this->type = type;
    this->bval = bval;
}

// display the value
void Value::print()
{
    if(this->type == NUMBER)
    {
        std::cout << this->nval << std::endl;
    }
    else if(this->type == BOOLEAN)
    {
        if(this->bval)
        {
            std::cout << "true" << std::endl;
        }
        else
        {
            std::cout << "false" << std::endl;
        }
    }
    else if(this->type == INVALID)
    {
        std::cout << "[Invalid Value]" << std::endl;
    }
}

ValueType Value::valueType()
{
    return this->type;
}

double Value::valueNval()
{
    if(this->type == NUMBER)
    {
        return this->nval;
    }
    else
    {
        throw "Value does not contain a number value.";
    }
}

bool Value::valueBval()
{
    if(this->type == BOOLEAN)
    {
        return this->bval;
    }
    else
    {
        throw "Value does not contain a boolean value.";
    }
}
