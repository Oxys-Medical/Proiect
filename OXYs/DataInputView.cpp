#ifndef __DATAINPUTVIEW__
#define __DATAINPUTVIEW__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

class DataInputView : public BaseView
{
private:
    /* data */
public:
    DataInputView(/* args */);
    byte HandleCommand(byte command);
};

DataInputView::DataInputView(/* args */)
{
}

byte DataInputView::HandleCommand(byte command)
{
    byte returnValue = DataInputViewIndex;
    
    if (command == ConfirmCommand)
    {
        returnValue = MeasurementViewIndex;
    }
    
    return returnValue;
}

#endif