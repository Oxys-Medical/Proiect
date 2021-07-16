#ifndef __ERRORSTATE__
#define __ERRORSTATE__

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

    //cum facem sa trecem inapoi la masurare, review cu butoanele 
  }
};

ErrorState::ErrorState(/* args */)
{
}

#endif
