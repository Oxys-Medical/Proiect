#ifndef __REVIEWVIEW_H__
#define __REVIEWVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

class ReviewView : public BaseView
{
    private:
    /* data */
    public:
    ReviewView();
    byte HandleCommand(byte command)
    {
      byte returnValue = ReviewViewIndex;

      //if (command == ConfirmCommand)
      //{
        //  returnValue = DataInputViewIndex;
      //} 
    
      return returnValue;  
    } 
};

byte ReviewView::HandleCommand(int* contactPoint)
{
    byte returnValue = ReviewViewIndex;
    
      byte command = _sendDataButton.HandleContactPoint(contactPoint);
      if (command != NoCommand)
      {
        byte nextState = _stateMachine.HandleCommand(command);
        switch (nextState)
        {
          case DataEntryState:
          {
            BaseView::HandleCommand(contactPoint);
            return DataInputViewIndex;
          }
            break;
        }
      }

    BaseView::HandleCommand(contactPoint);
    return returnValue;
}

ReviewView::ReviewView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;
}
 
#endif
