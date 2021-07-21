#ifndef __INITIALIZINGVIEW_H__
#define __INITIALIZINGVIEW_H__

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

#endif
