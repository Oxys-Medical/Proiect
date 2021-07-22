#include "InitializingState.h"
#include "DataEntryState.h"
#include "MeasuringState.h"
#include "ErrorState.h"
#include "ReviewState.h"
#include "StateMachine.h"
#include "Constants.h"
#include "BaseState.h"
#include "DataLayer.h"

StateMachine::StateMachine()
{
    _statePointerArray = new BaseState[NumberOfStates];

    InitializingState initializingState = InitializingState();
    _statePointerArray[InitializingStateIndex] = initializingState;
    DataLayer dataLayer = DataLayer();
    DataEntryState dataEntryState = DataEntryState(dataLayer);
    _statePointerArray[DataEntryStateIndex] = dataEntryState;
    MeasuringState measuringState = MeasuringState();
    _statePointerArray[MeasuringStateIndex] = measuringState;
    ErrorState errorState = ErrorState();
    _statePointerArray[ErrorStateIndex] = errorState;
    ReviewState reviewState = ReviewState(dataLayer);
    _statePointerArray[ReviewStateIndex] = reviewState;

    _currentState = _statePointerArray[InitializingStateIndex];
}

byte StateMachine::HandleCommand(byte command)
{
    byte nextStateIndex = _currentState.HandleCommand(command);
    _currentState = _statePointerArray[nextStateIndex];
    return nextStateIndex;
}

unsigned long StateMachine::GetCNP()
{
    return _currentState.GetCNP();
}