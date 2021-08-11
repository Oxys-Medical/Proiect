#ifndef __DATAINPUTVIEW_H__
#define __DATAINPUTVIEW_H__

#include "BaseView.h"
#include "CNPFunctions.h"
#include "Commands.h"
#include "Constants.h"
#include "StateMachine.h"
#include "DisplayDriver.h"
#include "UiButton.h"
#include "UiElement.h"
#include "Adafruit_GFX.h" 


#define HX8357_DARKGREY    0x7BEF  ///< 123, 125, 123
#define HX8357_YELLOW      
#define HX8357_WHITE 

// UI Buttondetails
#define BUTTON_X 115
#define BUTTON_Y 150
#define BUTTON_W 120
#define BUTTON_H 40
#define BUTTON_R 5
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

byte textSize = 3;
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

byte Commands[BTN_CNT] = {
One,
Two,
Three,
Four,
Five,
Six,
Seven,
Eight,
Nine,
DeleteCommand,
Zero,
ConfirmCommand
};


 bool initializeButtons(uint16_t numColors[], char numLabels[][13], int numButtonCount) ;
  {
    _elementArray = new UiElement[12];
     
    for (uint8_t row=0; row<5; row++) 
    {
       for (uint8_t col=0; col<3; col++) 
       {
         _elementArray[col + row*3] = UiButton(&displayDriver, BUTTON_X+col*(BUTTON_W+5), 
                 BUTTON_Y+row*(BUTTON_H+5),    // x, y, w, h,r, outline, fill, text, command
                  BUTTON_W, BUTTON_H, BUTTON_R, HX8357_BLACK, BTN_Colors[col + row*3], textColor[col + row*3],
                  Labels[col + row*3], BUTTON_TEXTSIZE, Commands[col + row*3]); 
       }
    } 
    
    _deleteButton = UiButton(); 
    _confirmBUtton = UiButton();

    _elementArray[9] = _deleteButton;
    _elementArray[11] = _confirmButton;

   return true;
  }

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
    
  
  initializeButtons( BTN_Colors, Labels, BTN_CNT);
  
    
}

void DataInputView::Display()
{
  _displayDriver.fillScreen(HX8357_BLACK);

   for (uint8_t row=0; row<5; row++) 
    {
       for (uint8_t col=0; col<3; col++) 
       {
         _elementArray[col + row*3].Display();
       }
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
