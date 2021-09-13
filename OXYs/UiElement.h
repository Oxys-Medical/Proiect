#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include <Arduino.h>
#include "DisplayDriver.h"
#include "Commands.h"

class UiElement 
{
   protected:
   DisplayDriver _displayDriver;
   int _x;
   int _y;
   int _h; //height
   int _w; //width
   uint16_t _color;

   public:
   UiElement();
   virtual void Display();
   virtual void Animate();
   virtual byte HandleContactPoint(int* contactPoint)
   {
      return NoCommand;
   }
};

#endif
