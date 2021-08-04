#ifndef __DATAENTRYSTATE_H__
#define __DATAENTRYSTATE_H__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"
#include "PulseOxyFunctions.h"

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

    switch (command)
    {
    case Zero:
        _dataLayer.AppendDigit(0);
    
    case One:
        _dataLayer.AppendDigit(1);

    case Two:
        _dataLayer.AppendDigit(2);

    case Three:
        _dataLayer.AppendDigit(3);

    case Four:
        _dataLayer.AppendDigit(4);

    case Five:
        _dataLayer.AppendDigit(5);

    case Six:
        _dataLayer.AppendDigit(6);

    case Seven:
        _dataLayer.AppendDigit(7);

    case Eight:
        _dataLayer.AppendDigit(8);
        
    case Nine:
        _dataLayer.AppendDigit(9);

    }

    if DeleteCommand _dataLayer.DeleteDigit();

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
