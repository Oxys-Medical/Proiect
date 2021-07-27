#ifndef __REVIEWVIEW_H__
#define __REVIEWVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include "UiButton.h"
#include "UiElement.h"
#include "DisplayDriver.h"


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

class ReviewView : public BaseView
{
    private:
    /* data */
    public:
    ReviewView();
    byte HandleCommand(byte command)
    {
      byte returnValue = ReviewViewIndex;

      //if (command == ConfirmCommand)
      //{
        //  returnValue = DataInputViewIndex;
      //} 
    
      return returnValue;  
    } 
};

ReviewView::ReviewView(DisplayDriver displayDriver, StateMachine stateMachine)
{
  _displayDriver = displayDriver;
  _stateMachine = stateMachine;

   bool initializeButtons(
            UiButton menuButtons[], 
            uint16_t menuColors[], 
            char menuLabels[][3], 
            int menuButtonCount) {
    displayDriver.fillScreen(HX8357_BLACK);

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

}
 
#endif
