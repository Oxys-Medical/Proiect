#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "PulseOxySampler.h"
#include "BaseState.h"
#include <Arduino.h>

class StateMachine
{
    private:
    PulseOxySampler _pulseOxySampler;
    BaseState _currentState;
    BaseState* _statePointerArray;
    BaseState _stateMachine;

    public:
    StateMachine();
    ~StateMachine(){}
    byte HandleCommand(byte command);
    byte* Measure();
    unsigned long GetCNP();
};

#endif
