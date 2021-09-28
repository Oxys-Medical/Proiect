#ifndef __INITIALIZINGVIEW_H__
#define __INITIALIZINGVIEW_H__

#include "BaseView.h"
#include "Constants.h"

class InitializingView : public BaseView
{
private:


public:
    InitializingView();
    byte HandleCommand(byte command);
    void Display()
    {
    
    }
};

byte InitializingView :: HandleCommand(byte command)
{
    return DataInputViewIndex;
    Serial.println("Hanne a fost aici");
}
InitializingView::InitializingView()
{

}
#endif
