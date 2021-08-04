#ifndef __BASESTATE_H__
#define __BASESTATE_H__

// #include <Arduino.h>

class BaseState
{
    public:
    virtual byte HandleCommand(byte command);
    virtual void Measure();
};

#endif
