#ifndef __MEASUREMENTVIEW_H__
#define __MEASUREMENTVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

class MeasurementView : public BaseView
{
    private:
    /* data */
    public:
    MeasurementView();
    
    byte HandleCommand(byte command)
    {
        byte returnValue = MeasurementViewIndex;
    
       // if (command == ConfirmCommand)
        //{
        //    returnValue = ReviewViewIndex;
        //}
        //else 
        //{
          //  returnValue = ProblemViewIndex;
        //}
        
        return returnValue;
    
    }
};

MeasurementView::MeasurementView(/* args */)
{
}

#endif
