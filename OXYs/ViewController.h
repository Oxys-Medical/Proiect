#ifndef __VIEWCONTROLLER_H__
#define __VIEWCONTROLLER_H__

#include "StateMachine.h"
#include "DisplayDriver.h"

class ViewController
{
    private:
    DisplayDriver _displayDriver;
    StateMachine _stateMachine; // asta trebe? Trăbă, boss.
    BaseView _currentView;
    BaseView* _viewPointerArray;

    public:
    ViewController();
    void HandleCommand(byte command);
};

#endif
