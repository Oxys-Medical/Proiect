#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "PulseOxySampler.h"
#include "BaseState.h"

class StateMachine
{
    private:
    PulseOxySampler _pulseOxySampler;
    BaseState _currentState;
    BaseState* _statePointerArray;

    public:
    StateMachine();
    byte HandleCommand(byte command);
    byte* Measure();
};

#endif
