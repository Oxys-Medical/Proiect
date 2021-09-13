#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include <Arduino.h>
#include "DisplayDriver.h"
#include "Commands.h"

class UiElement 
{
   protected:
   DisplayDriver _displayDriver;
   short _x;
   short _y;
   short _h; //height
   short _w; //width

   public:
   UiElement();
   UiElement(short x,
             short y,
             short h,
             short w)
   {
      _x = x;
      _y = y;
      _h = h;
      _w = w;
   };
   virtual void Display();
   virtual void Animate();
   virtual byte HandleContactPoint(int* contactPoint)
   {
      return NoCommand;
   }
   void Initialize(DisplayDriver displayDriver)
   {
      _displayDriver = displayDriver;
   }
};

#endif
