#ifndef __DATAINPUTVIEW__
#define __DATAINPUTVIEW__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"
#include <Arduino.h>

class DataInputView : public BaseView
{
private:
    /* data */
public:
    DataInputView(/* args */);
    byte HandleCommand(int* contactPoint);
};

DataInputView::DataInputView(/* args */)
{
    //aici desenăm butoanele
}

byte DataInputView::HandleCommand(int* contactPoint)
{
    byte returnValue = DataInputViewIndex;
    
    // if (command == ConfirmCommand)
    // {
    //     returnValue = MeasurementViewIndex;
    // }
    
    BaseView::HandleCommand(contactPoint);
    return returnValue;
}

#endif
