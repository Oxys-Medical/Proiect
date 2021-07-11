#ifndef __MEASUREMENTVIEW__
#define __MEASUREMENTVIEW__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

class MeasurementView : public BaseView
{
    private:
    /* data */
    public:
    MeasurementView();
    byte HandleCommand(byte command);
};

MeasurementView::MeasurementView(/* args */)
{
}

byte MeasurementView::HandleCommand(byte command);
{
    byte returnValue = MeasurementViewIndex;

    if (command == ConfirmCommand)
    {
        returnValue = ReviewViewIndex;
    }
    else 
    {
        returnValue = ProblemViewIndex;
    }
    
    return returnValue;

    //cum facem sa trecem la error state
    
}

#endif