#ifndef __BASEVIEW_H__
#define __BASEVIEW_H__

//#include <Arduino.h>

class BaseView
{
    public:
    virtual byte HandleCommand(int* contactPoint)
    {
        delete(contactPoint);
        return 0;
    };
    // Display;
};

#endif
