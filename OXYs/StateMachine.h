#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "PulseOxySampler.h"

class StateMachine
{
    private:
    PulseOxySampler _pulseOxySampler;
    BaseState _currentState;
    BaseState* _statePointerArray;

    public:
    StateMachine();
    void HandleCommand(byte command);
};

#endif