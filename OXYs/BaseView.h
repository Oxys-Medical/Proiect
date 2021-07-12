#ifndef __BASEVIEW_H__
#define __BASEVIEW_H__

class BaseView
{
    public:
    virtual byte HandleCommand(int* contactPoint)
    {
        delete(contactPoint);
        return 0;
    };
};

#endif