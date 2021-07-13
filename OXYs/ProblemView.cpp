#ifndef __PROBLEMVIEW__
#define __PROBLEMVIEW__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

class ProblemView : public BaseView
{
    private:
    /* data */
    public:
    ProblemView();
    byte HandleCommand(byte command);
};

ProblemView::ProblemView(/* args */)
{
}

byte ProblemView::HandleCommand(byte command)
{
    byte returnValue = ProblemViewIndex;

    if (command == ConfirmCommand)
    {
        returnValue = ReviewViewIndex;
    }
    else 
    {
        returnValue = MeasurementViewIndex;
    }
    
    return returnValue;

    //cum facem sa trecem inapoi la masurare, review cu butoanele 
    
}
 BaseView::HandleCommand(contactPoint);

#endif