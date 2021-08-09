#ifndef __DATAINPUTVIEW_H__
#define __DATAINPUTVIEW_H__

#include "BaseView.h"
#include "CNPFunctions.h"
#include "Commands.h"
#include "Constants.h"
#include "StateMachine.h"
#include "DisplayDriver.h"
#include <Arduino.h>

class DataInputView : public BaseView
{
  private:
    /* data */
  public:
    DataInputView(DisplayDriver, StateMachine );
    byte HandleCommand(int* contactPoint);
};

DataInputView::DataInputView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;
    //aici desenăm butoanele
    //din arduino: examples -> gfxbuttontest featherwing 
}

byte DataInputView::HandleCommand(int* contactPoint)
{
    byte returnValue = DataInputViewIndex;
    for (int i = 0; i < _elementArray.Length(); i++)
    {
      byte command = _elementArray[i].HandleContactPoint(contactPoint);
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
        }
      }
    }

    BaseView::HandleCommand(contactPoint);
    return returnValue;
}

#endif
