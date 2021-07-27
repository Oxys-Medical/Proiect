#ifndef __DATAINPUTVIEW_H__
#define __DATAINPUTVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "StateMachine.h"
#include "DisplayDriver.h"
#include "UiButton.h"
#include <Arduino.h>

#define HX8357_DARKGREY    0x7BEF  ///< 123, 125, 123

// UI Buttondetails
#define BUTTON_X 115
#define BUTTON_Y 150
#define BUTTON_W 120
#define BUTTON_H 40
#define BUTTON_TEXTSIZE 3
#define DISPLAY_XOFFSET 0
#define DISPLAY_TEXTOFFSET 0
#define DISPLAY_YOFFSET 0

enum ButtonName {
  BTN_1,
  BTN_2,
  BTN_3,
  BTN_4,
  BTN_5,
  BTN_6,
  BTN_7,
  BTN_8,
  BTN_9,
  BTN_DELETE,
  BTN_0,
  BTN_OK
};

#define BTN_CNT 12
UiButton _elementArray[BTN_CNT];
char Labels[BTN_CNT][13] = {"1", "2", "3", "4", "5","6", "7", "8", "9","DELETE", "0", "OK"};
uint16_t BTN_Colors[BTN_CNT] = { HX8357_DARKGREY, 
                                        HX8357_DARKGREY, 
                                        HX8357_DARKGREY,
                                        HX8357_DARKGREY, 
                                        HX8357_DARKGREY, 
                                        HX8357_DARKGREY,
                                        HX8357_DARKGREY,
                                        HX8357_DARKGREY, 
                                        HX8357_DARKGREY, 
                                        HX8357_YELLOW,  
                                        HX8357_DARKGREY, 
                                        HX8357_YELLOW
                                      };

int textSize = 3;
uint16_t textColor[BTN_CNT] = {
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_DARKGREY,
 HX8357_WHITE,
 HX8357_DARKGREY
};

class DataInputView : public BaseView
{
  private:
    /* data */
  public:
    DataInputView(/* args */);
    byte HandleCommand(int* contactPoint);
};

DataInputView::DataInputView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;
    
    //aici am desenat butoanele 1,2...etc

   bool initializeButtons( UiButton numButtons[], uint16_t numColors[], char numLabels[][13], int numButtonCount) ;
  {
     _displayDriver.fillScreen(HX8357_BLACK);

    for (uint8_t row=0; row<5; row++) 
    {
       for (uint8_t col=0; col<3; col++) 
       {
      numButtons[col + row*3].initButton(&displayDriver, BUTTON_X+col*(BUTTON_W+5), 
                 BUTTON_Y+row*(BUTTON_H+5),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, HX8357_BLACK, BTN_Colors[col+row*3], textColor[col + row*3],
                  Labels[col + row*3], BUTTON_TEXTSIZE); 
      numButtons[col + row*3].drawButton();
       }
    } 
    
   return true;
  }
    
}

byte DataInputView::HandleCommand(int* contactPoint)
{
    byte returnValue = DataInputViewIndex;
    for (int i = 0; i < BTN_CNT; i++)
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
