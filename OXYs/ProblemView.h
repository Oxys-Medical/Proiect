#ifndef __PROBLEMVIEW_H__
#define __PROBLEMVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

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

ProblemView::ProblemView(/* args */)
{
}

#endif
