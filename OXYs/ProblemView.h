#ifndef __PROBLEMVIEW_H__
#define __PROBLEMVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "DisplayDriver.h"
#include "UiButton.h"
#include "UiElement.h"

#define HX8357_LIGHTGREY   0xC618  ///< 198, 195, 198
#define HX8357_DARKGREY    0x7BEF  ///< 123, 125, 123

// UI Buttondetails
#define BUTTON_X 142
#define BUTTON_Y 265
#define BUTTON_W 120
#define BUTTON_H 40
#define BUTTON_TEXTSIZE 2
#define DISPLAY_XOFFSET 0
#define DISPLAY_TEXTOFFSET 0
#define DISPLAY_YOFFSET 0

enum ButtonName {
  BTN_DA,
  BTN_NU,
  
};

#define btn_CNT 2
UiButton YES_Buttons[btn_CNT];
char btnLabels[btn_CNT][3] = {"DA", "NU"};
uint16_t btnColors[btn_CNT] = {HX8357_YELLOW, HX8357_YELLOW};

bool initializeButtons(
            UiButton menuButtons[], 
            uint16_t menuColors[], 
            char menuLabels[][3], 
            int menuButtonCount) {
     _displayDriver.fillScreen(HX8357_BLACK);

    for (uint8_t col=0; col<menuButtonCount; col++) 
    {
        menuButtons[col].initButton(&displayDriver, 
            BUTTON_X + col *(BUTTON_W+87), 
            BUTTON_Y ,   
            BUTTON_W, 
            BUTTON_H, 
            HX8357_BLACK, 
            menuColors[col], 
            HX8357_DARKGREY,
            menuLabels[col], BUTTON_TEXTSIZE);    
        menuButtons[col].drawButton();
    }
    return true;
}               

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

ProblemView::ProblemView(DisplayDriver displayDriver, StateMachine stateMachine)
{       
   initializeButtons(YES_Buttons, btnColors, btnLabels, btn_CNT);
    
    _displayDriver.setTextSize(6);
    _displayDriver.setTextColor(HX8357_BLACK);
    _displayDriver.drawTriangle(240,30,180,110,300,110,HX8357_RED);
    _displayDriver.fillTriangle(240,30,180,110,300,110,HX8357_RED);
    _displayDriver.setCursor(225,60);
    _displayDriver.print("!");

    _displayDriver.setTextSize(4);
    _displayDriver.setTextColor(HX8357_WHITE);
    _displayDriver.setCursor(60, 190);
    _displayDriver.print("Va simtiti bine?");

/*
    _displayDriver.setTextSize(2);
    _displayDriver.setTextColor(HX8357_DARKGREY);
    _displayDriver.setCursor(90, 145);
    _displayDriver.print("Valoarea SpO2 este critica");

*/
    _displayDriver.setTextSize(2);
    _displayDriver.setTextColor(HX8357_DARKGREY);
    _displayDriver.setCursor(60, 145);
    _displayDriver.print("Pulsul este sub limita normala");

}

#endif
