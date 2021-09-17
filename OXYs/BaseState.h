#ifndef __BASESTATE_H__
#define __BASESTATE_H__

#include <Arduino.h>

class BaseState
{
    public:
    BaseState()
    {  
    };
    ~BaseState()
    {};
    virtual byte HandleCommand(byte command);
    virtual byte* Measure();
    virtual unsigned long GetCNP();
};

#endif
