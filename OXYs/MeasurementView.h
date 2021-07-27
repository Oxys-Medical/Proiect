#ifndef __MEASUREMENTVIEW_H__
#define __MEASUREMENTVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

class MeasurementView : public BaseView
{
    private:
    /* data */
    public:
    MeasurementView();
    
    byte HandleCommand(byte command)
    {
        byte returnValue = MeasurementViewIndex;
    
       // if (command == ConfirmCommand)
        //{
        //    returnValue = ReviewViewIndex;
        //}
        //else 
        //{
          //  returnValue = ProblemViewIndex;
        //}
        
        return returnValue;
    
    }
};

byte MeasurementView::HandleCommand(int* contactPoint)
{
    byte returnValue = MeasurementViewIndex;
    
      byte command = _reviewButton.HandleContactPoint(contactPoint);
      if (command != NoCommand)
      {
        byte nextState = _stateMachine.HandleCommand(command);
        switch (nextState)
        {
          case ReviewState:
          {
            BaseView::HandleCommand(contactPoint);
            return ReviewViewIndex;
          }
            break;
        }
      }

//la error view trece singur cand da peste o valoare limita?? ca nu este buton pentru a trece la error

    BaseView::HandleCommand(contactPoint);
    return returnValue;
}

MeasurementView::MeasurementView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;
}

#endif
