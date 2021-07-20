#ifndef __INITIALIZINGVIEW__
#define __INITIALIZINGVIEW__

#include "BaseView.h"
#include "Constants.h"

class InitializingView : public BaseView
{
private:
    /* data */
public:
    InitializingView();
    byte HandleCommand(byte command);
};

byte InitializingView::HandleCommand(byte command)
{
    return DataInputViewIndex;
}
BaseView::HandleCommand(contactPoint);
#endif