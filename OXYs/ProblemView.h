#ifndef __PROBLEMVIEW_H__
#define __PROBLEMVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

class ProblemView : public BaseView
{
    private:
    /* data */
    public:
    ProblemView();
    byte HandleCommand(byte command)
    {
      byte returnValue = ProblemViewIndex;

      //if (command == ConfirmCommand)
      //{
        //  returnValue = ReviewViewIndex;
      //}
      //else 
      //{
        //  returnValue = MeasurementViewIndex;
      //}
    
      return returnValue;
}

};

byte ProblemView::HandleCommand(int* contactPoint)
{
    byte returnValue = ProblemViewIndex;
    
      byte command = _elementArray[2].HandleContactPoint(contactPoint);
      if (command != NoCommand)
      {
        byte nextState = _stateMachine.HandleCommand(command);
        switch (nextState)
        {
          case MeasuringState:
          {
            BaseView::HandleCommand(contactPoint);
            return MeasurementViewIndex;
          }
            break;
          
          case ReviewState:
          {
            BaseView::HandleCommand(contactPoint);
            return ReviewStateIndex;
          }
            break;
        }
      }

    BaseView::HandleCommand(contactPoint);
    return returnValue;
}

ProblemView::ProblemView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;
}

#endif
