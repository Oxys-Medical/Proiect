#ifndef __DATAINPUTVIEW_H__
#define __DATAINPUTVIEW_H__

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
    //din arduino: examples -> gfxbuttontest featherwing 
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
