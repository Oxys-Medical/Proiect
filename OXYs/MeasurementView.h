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
    
    byte HandleCommand(int* contactPoint)
    {
        byte returnValue = MeasurementViewIndex;
        byte command = reviewButton.HandleContactPoint(int* contactPoint)
    
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

  _displayDriver.fillScreen(HX8357_BLACK);

  //aici am desenat doar butonul care trece la review
     _displayDriver.drawRoundRect(180,264,120,40,5,HX8357_YELLOW);
     _displayDriver.fillRoundRect(180,264,120,40,5,HX8357_YELLOW);
     _displayDriver.setTextSize(2);
     _displayDriver.setTextColor(HX8357_DARKGREY);
     _displayDriver.setCursor(198, 277);
     _displayDriver.print("REZUMAT");

//ce am desenat initial am facut buton acum
     UiButton reviewButton = UiButton(pozitii, dirver-ul de display, textul de pe buton, comanda pe care o executa);

    //  RezBTN.initButton(&displayDriver, 
    //         245, 
    //         275,    
    //         120, 
    //         40, 
    //         HX8357_BLACK, 
    //         HX8357_YELLOW, 
    //         HX8357_DARKGREY,
    //         "REZUMAT", 2);    
        reviewButton.Display();
}

#endif
