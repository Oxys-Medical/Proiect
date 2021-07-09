#ifndef __BASESTATE_H__
#define __BASESTATE_H__

class BaseState
{
    public:
    virtual byte HandleCommand(byte command);
};

#endif