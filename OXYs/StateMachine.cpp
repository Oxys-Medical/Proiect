#include "InitializingState.cpp"
#include "DataEntryState.cpp"
#include "MeasuringState.cpp"
#include "ErrorState.cpp"
#include "ReviewState.cpp"
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
    MeasuringState measuringState = MeasuringState();
    _statePointerArray[MeasuringStateIndex] = measuringState;
    ErrorState errorState = ErrorState();
    _statePointerArray[ErrorStateIndex] = errorState;
    ReviewState reviewState = ReviewState();
    _statePointerArray[ReviewStateIndex] = reviewState;

    _currentState = _statePointerArray[InitializingStateIndex];
}

StateMachine::HandleCommand(byte command)
{
    byte nextStateIndex = _currentState.HandleCommand(command);
    _currentState = _statePointerArray[nextStateIndex];
    //notificare că s-a schimbat starea.
}