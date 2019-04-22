/*-------------------------------------------------------

Class representing a value, which an expression evaluates
to at runtime.

---------------------------------------------------------*/

#ifndef EVALUATION_VALUE_H
#define EVALUATION_VALUE_H

namespace evaluation {

enum ValueType
{
    NUMBER, BOOLEAN
};

class Value
{
private:
    ValueType type;
    double nval;
    bool bval;
public:
    Value(ValueType, double);
    Value(ValueType, bool);
    ValueType valueType();
    double valueNval();
    bool valueBval();
};
}

#endif
