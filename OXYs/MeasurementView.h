#ifndef __MEASUREMENTVIEW_H__
#define __MEASUREMENTVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "DisplayDriver.h"
#include "UiButton.h"
#include "UiElement.h"
#include "Adafruit_GFX.h"

class MeasurementView : public BaseView
{
private:
  DisplayDriver _displayDriver;
  StateMachine _stateMachine;
  UiElement _reviewButton;

public:
  MeasurementView(DisplayDriver displayDriver, StateMachine stateMachine);
  byte HandleCommand(int *contactPoint)
  {
    byte returnValue = MeasurementViewIndex;
    byte command = _reviewButton.HandleContactPoint(contactPoint);

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

  void Display()
  {
    _displayDriver.fillScreen(HX8357_BLACK);
    _reviewButton.Display();
  }
};

MeasurementView::MeasurementView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;
  _reviewButton = UiButton(180, 264, 120, 40, 5, HX8357_BLACK, HX8357_YELLOW, HX8357_DARKGREY, 2, "REZUMAT", StopMeasurementCommand);
  _reviewButton.Initialize(_displayDriver);
}

#endif
