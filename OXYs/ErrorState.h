#ifndef __ERRORSTATE_H__
#define __ERRORSTATE_H__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"
#include <Arduino.h>

class ErrorState : public BaseState
{
    private:
    /* data */
    public:
    ErrorState();
    
    byte HandleCommand(byte command)
    {
      byte returnValue = ErrorStateIndex;

      if (command == UserHasAProblemCommand)
      {
          returnValue = ReviewStateIndex;
      }
      else if (command == UserIsOkCommand)
      {
          returnValue = MeasuringStateIndex;
      }
    
      return returnValue;
 
  }
};

ErrorState::ErrorState(/* args */)
{
}

#endif
