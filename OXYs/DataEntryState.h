#ifndef __DATAENTRYSTATE_H__
#define __DATAENTRYSTATE_H__

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

   // if (command == ButtonPressed)
    //{
    //   returnValue = DataEntryStateIndex;
   // }

    //folosim un switch pentru fiecare cifra adaugata la cnp? 
    //cum facem sa afiseze cifra respectiva si sa o si pastreze pe ecran, ramanand in data entry

    switch (command)
    {
    case Zero:
        return 
    
    case One:
        return 

    case Two:
        return

    case Three:
        return 

    case Four:
        return 

    case Five:
        return 

    case Six:
        return 

    case Seven:
        return 

    case Eight:
        return 
        
    case Nine:
        return 

    }

    if (command == ConfirmCommand)
   {
        returnValue = MeasuringStateIndex;
   }
    
    return returnValue;
}

#endif
