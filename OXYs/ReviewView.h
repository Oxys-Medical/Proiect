#ifndef __REVIEWVIEW_H__
#define __REVIEWVIEW_H__

#include "BaseView.h"
#include "Commands.h"
#include "Constants.h"

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

ReviewView::ReviewView(/* args */)
{
}
 
#endif
