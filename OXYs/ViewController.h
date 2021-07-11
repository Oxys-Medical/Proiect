#ifndef __VIEWCONTROLLER_H__
#define __VIEWCONTROLLER_H__

#include "StateMachine.h"

class ViewController
{
    private:
    StateMachine _stateMachine; // asta trebe?
    BaseView _currentView;
    BaseView* _viewPointerArray;

    public:
    ViewController();
    void HandleCommand(byte command);
};

#endif