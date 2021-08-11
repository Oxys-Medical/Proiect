#ifndef __MEASUREMENTVIEW_H__
#define __MEASUREMENTVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "DisplayDriver.h"
#include "UiButton.h"
#include "UiElement.h"
#include "Adafruit_GFX.h"

#define HX8357_DARKGREY    0x7BEF  ///< 123, 125, 123
#define HX8357_YELLOW

#define BUTTON_X 180
#define BUTTON_Y 300
#define BUTTON_W 120
#define BUTTON_H 40
#define BUTTON_R 5
#define BUTTON_TEXTSIZE 3
#define DISPLAY_XOFFSET 0
#define DISPLAY_TEXTOFFSET 0
#define DISPLAY_YOFFSET 0

class MeasurementView : public BaseView
{
private:
  /* data */
public:
  MeasurementView(DisplayDriver, StateMachine);

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
