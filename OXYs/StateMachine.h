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
    BaseState _stateMachine;

    public:
    StateMachine();
    byte HandleCommand(byte command);
};

#endif
