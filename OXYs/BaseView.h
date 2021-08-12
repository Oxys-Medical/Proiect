#ifndef __BASEVIEW_H__
#define __BASEVIEW_H__

#include <Arduino.h>
#include "UiElement.h"

class BaseView
{
    protected:
    UiElement* _elementArray;
    public:
    virtual byte HandleCommand(int* contactPoint)
    {
        delete(contactPoint);
        return 0;
    };
    virtual void Display();
};

#endif
