#ifndef __VIEWCONTROLLER_H__
#define __VIEWCONTROLLER_H__

//#include "StateMachine.h"
//#include "DisplayDriver.h"
//#include "BaseView.h"
#include <Arduino.h>


class ViewController
{
    private:
//    DisplayDriver _displayDriver;
//    StateMachine _stateMachine; 
//    BaseView _currentView;
//    BaseView* _viewArray;
//    byte _currentViewIndex;

    public:
    ViewController();
    void HandleCommand(); 
    void UpdateView(byte viewIndex); 
    
};


#endif
