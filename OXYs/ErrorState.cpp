#ifndef __ERRORSTATE__
#define __ERRORSTATE__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"

class ErrorState : public BaseState
{
    private:
    /* data */
    public:
    ErrorState();
    byte HandleCommand(byte command);
};

ErrorState::ErrorState(/* args */)
{
}

byte ErrorState::HandleCommand(byte command);
{
    byte returnValue = ErrorStateIndex;

    if (command == ConfirmCommand)
    {
        returnValue = ReviewStateIndex;
    }
    else 
    {
        returnValue = MeasuringStateIndex
    }
    
    return returnValue;

    //cum facem sa trecem inapoi la masurare, review cu butoanele 
    
}

#endif