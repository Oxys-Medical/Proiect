#ifndef __DATAENTRYSTATE_H__
#define __DATAENTRYSTATE_H__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"
#include "PulseOxyFunctions.h"

class DataEntryState : public BaseState
{
private:
    DataLayer _dataLayer
public:
    DataEntryState(/* args */);
    byte HandleCommand(byte command);
};

DataEntryState::DataEntryState(/* args */)
{
}

long DataEntryState::Measure()
{
    return _dataLayer.GetCnp();
}

byte DataEntryState::HandleCommand(byte command)
{
    byte returnValue = DataEntryStateIndex;
    //dacă este comandă numerică, adăugăm la CNP și returnăm tot starea de DataEntry;

    // if (command == ButtonPressed)
    //{
    //   returnValue = DataEntryStateIndex;
    // }

    //folosim un switch pentru fiecare cifra adaugata la cnp?
    //cum facem sa afiseze cifra respectiva si sa o si pastreze pe ecran, ramanand in data entry

    if (command == DeleteCommand)
    {
        _dataLayer.DeleteDigit();
    }

    if (command == ConfirmCommand)
    {
        bool isCNPValid = _dataLayer.ConfirmCNP();
        if (isCNPValid)
        {
            returnValue = MeasuringStateIndex;
        }
        else
        {
            returnValue = DataEntryStateIndex;
        }
    }

    return returnValue;
}

#endif
