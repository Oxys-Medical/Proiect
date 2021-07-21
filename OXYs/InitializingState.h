#ifndef __INITIALIZINGSTATE_H__
#define __INITIALIZINGSTATE_H__

#include "BaseState.h"
#include "Constants.h"

class InitializingState : public BaseState
{
     private:
     /* data */
     public:
     InitializingState();
     byte HandleCommand(byte command);
};

byte InitializingState::HandleCommand(byte command)
{
    return DataEntryStateIndex;
}

#endif