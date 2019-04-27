/*-------------------------------------------------------

Class representing a value, which an expression evaluates
to at runtime.

Currently include Boolean, Number and Invalid, but
will soon support Function as a first-class value.

---------------------------------------------------------*/

#ifndef EVALUATION_VALUE_H
#define EVALUATION_VALUE_H

namespace evaluation {

enum ValueType
{
    NUMBER, BOOLEAN, INVALID
};

class Value
{
private:
    ValueType type;
    double nval;
    bool bval;
public:
    Value();
    Value(ValueType, double);
    Value(ValueType, bool);
    ValueType valueType();
    double valueNval();
    bool valueBval();
    void print();
};
}

#endif
