#ifndef __REVIEWSTATE__
#define __REVIEWSTATE__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"

class ReviewState : public BaseState
{
    private:
    /* data */
    public:
    ReviewState();
    byte HandleCommand(byte command);
};

ReviewState::ReviewState(/* args */)
{
}

byte ReviewState::HandleCommand(byte command);
{
    byte returnValue = ReviewStateIndex;

    if (command == ConfirmCommand)
    {
        returnValue = DataEntryStateIndex;
    }
    
    return returnValue;

    
}

#endif