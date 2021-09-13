#ifndef __PROBLEMVIEW_H__
#define __PROBLEMVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "DisplayDriver.h"
#include "StateMachine.h"
#include "UiButton.h"
#include "UiElement.h"

#define HX8357_LIGHTGREY 0xC618 ///< 198, 195, 198
#define HX8357_DARKGREY 0x7BEF  ///< 123, 125, 123

class ProblemView : public BaseView
{
private:
  DisplayDriver _displayDriver;
  StateMachine _stateMachine;
  UiButton _yesButton = UiButton(70, 265, 120, 40, 5, HX8357_BLACK, HX8357_YELLOW, HX8357_DARKGREY, 2, "DA", UserIsOkCommand);
  UiButton _noButton = UiButton(289, 265, 120, 40, 5, HX8357_BLACK, HX8357_YELLOW, HX8357_DARKGREY, 2, "NU", UserHasAProblemCommand);

public:
  ProblemView(DisplayDriver displayDriver, StateMachine stateMachine);
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
  void Display()
  {
    _displayDriver.fillScreen(HX8357_BLACK);

    _displayDriver.setTextSize(6);
    _displayDriver.setTextColor(HX8357_BLACK);
    _displayDriver.drawTriangle(240, 30, 180, 110, 300, 110, HX8357_RED);
    _displayDriver.fillTriangle(240, 30, 180, 110, 300, 110, HX8357_RED);
    _displayDriver.setCursor(225, 60);
    _displayDriver.print("!");

    _displayDriver.setTextSize(4);
    _displayDriver.setTextColor(HX8357_WHITE);
    _displayDriver.setCursor(60, 190);
    _displayDriver.print("Va simtiti bine?");

    _displayDriver.setTextSize(2);
    _displayDriver.setTextColor(HX8357_DARKGREY);
    _displayDriver.setCursor(60, 145);
    _displayDriver.print("Pulsul este sub limita normala");

    _yesButton.Display();
    _noButton.Display();
  }
};

ProblemView::ProblemView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;
  _yesButton.Initialize(_displayDriver);
  _noButton.Initialize(_displayDriver);
}

#endif
