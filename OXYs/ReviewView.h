#ifndef __REVIEWVIEW_H__
#define __REVIEWVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "UiElement.h"
#include "DisplayDriver.h"
#include "UiButton.h"

#define HX8357_LAVENDER 0x7A7CFF

class ReviewView : public BaseView
{
private:
  DisplayDriver _displayDriver;
  StateMachine _stateMachine;
  UiButton _sendDataButton = UiButton(350, 130, 120, 50, 5, HX8357_BLACK, HX8357_LAVENDER, HX8357_WHITE, 2, "Trimite", SendCommand);

public:
  ReviewView(DisplayDriver displayDriver, StateMachine stateMachine)
  {
    _displayDriver = displayDriver;
    _stateMachine = stateMachine;
    _sendDataButton.Initialize(displayDriver);
  }

  byte HandleCommand(int *contactPoint)
  {
    byte returnValue = ReviewViewIndex;

    byte command = _sendDataButton.HandleContactPoint(contactPoint);
    if (command != NoCommand)
    {
      byte nextState = _stateMachine.HandleCommand(command);
      switch (nextState)
      {
      case DataEntryStateIndex:
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

  void Display()
  {
    _displayDriver.fillScreen(HX8357_BLACK);

    _displayDriver.setTextSize(3);
    _displayDriver.setTextColor(HX8357_WHITE);
    _displayDriver.setCursor(60, 60);
    _displayDriver.print("Rezumatul zilei");

    _displayDriver.setTextSize(2);
    _displayDriver.setTextColor(HX8357_LIGHTGREY);
    _displayDriver.setCursor(70, 90);
    _displayDriver.print("Alerte");

    _sendDataButton.Display();
  }
};

#endif
