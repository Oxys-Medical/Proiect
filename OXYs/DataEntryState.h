#ifndef __DATAENTRYSTATE__
#define __DATAENTRYSTATE__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"

class DataEntryState : public BaseState
{
private:
    /* data */
public:
    DataEntryState(/* args */);
    byte HandleCommand(byte command);
};

DataEntryState::DataEntryState(/* args */)
{
}

byte DataEntryState::HandleCommand(byte command)
{
    byte returnValue = DataEntryStateIndex;
    //dacă este comandă numerică, adăugăm la CNP și returnăm tot starea de DataEntry;
    if (command == ConfirmCommand)
    {
        returnValue = MeasuringStateIndex;
    }
    
    return returnValue;
}

#endif