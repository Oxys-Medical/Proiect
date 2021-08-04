#ifndef __MEASUREMENTVIEW_H__
#define __MEASUREMENTVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "DisplayDriver.h"
#include "UiButton.h"
#include "UiElement.h"

class MeasurementView : public BaseView
{
private:
  /* data */
public:
  MeasurementView();

  byte HandleCommand(int *contactPoint)
  {
    byte returnValue = MeasurementViewIndex;
    byte command = reviewButton.HandleContactPoint(int *contactPoint)

                   // if (command == ConfirmCommand)
                   //{
                   //    returnValue = ReviewViewIndex;
                   //}
                   //else
                   //{
                   //  returnValue = ProblemViewIndex;
                   //}
                   BaseView.HandleContactPoint(contactPoint);
    return returnValue;
  }
};

MeasurementView::MeasurementView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;


  UiButton reviewButton = UiButton(&displayDriver, 180, 264, 120, 40, 5, HX8357_BLACK, HX8357_YELLOW, HX8357_DARKGREY, 2, "REZUMAT", StopMeasurementCommand);
  
}
void MeasurementView::Display()
{
  _displayDriver.fillScreen(HX8357_BLACK);
  reviewButton.Display();
}


#endif
