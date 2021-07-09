#include "InitializingState.cpp"
#include "DataEntryState.cpp"
#include "StateMachine.h"
#include "Constants.h"
#include "BaseState.h"

StateMachine::StateMachine()
{
    _statePointerArray = new BaseState[NumberOfStates];

    InitializingState initializingState = InitializingState();
    _statePointerArray[InitializingStateIndex] = initializingState;
    DataEntryState dataEntryState = DataEntryState();
    _statePointerArray[DataEntryStateIndex] = dataEntryState;
    //celelalte stări intră în array

    _currentState = _statePointerArray[InitializingStateIndex];
}

StateMachine::HandleCommand(byte command)
{
    byte nextStateIndex = _currentState.HandleCommand(command);
    _currentState = _statePointerArray[nextStateIndex];
    //notificare că s-a schimbat starea.
}