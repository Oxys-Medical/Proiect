#ifndef __INITIALIZINGVIEW_H__
#define __INITIALIZINGVIEW_H__

#include "BaseView.h"
#include "Constants.h"

class InitializingView : public BaseView
{
private:
    DisplayDriver _displayDriver;
    StateMachine _stateMachine;

public:
    InitializingView(DisplayDriver displayDriver, StateMachine stateMachine);
    byte HandleCommand(byte command);
    void Display()
    {
    
    }
};

byte InitializingView::HandleCommand(byte command)
{
    return DataInputViewIndex;
}
InitializingView::InitializingView()
{
    _displayDriver.
}
#endif
