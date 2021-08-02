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
   uint16_t _color;

   public:
   UiElement(DisplayDriver displayDriver, short x, short y, short h, short w);
   virtual void Display();
   virtual void Animate();
   virtual byte HandleContactPoint(int* contactPoint)
   {
      return NoCommand;
   }
};

#endif