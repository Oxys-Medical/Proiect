#ifndef __MEASURINGSTATE__
#define __MEASURINGSTATE__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"

class MeasuringState : public BaseState
{
    private:
    /* data */
    public:
    MeasuringState();
    byte HandleCommand(byte command);
};

MeasuringState::MeasuringState(/* args */)
{
}

byte MeasuringState::HandleCommand(byte command);
{
    byte returnValue = MeasuringStateIndex;

    if (command == ConfirmCommand)
    {
        returnValue = ReviewStateIndex;
    }
    else 
    {
        returnValue = ErrorStateIndex;
    }
    
    return returnValue;

    //cum facem sa trecem la error state
    
}

#endif