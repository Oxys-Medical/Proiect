#ifndef __TEXTFIELD_H__
#define __TEXTFIELD_H__

#include <Arduino.h>
#include "UiElement.h"
#include "DisplayDriver.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"


class TextField : public UiElement
{
  private:
  long* _cnpAddress;

  public:
  TextField(DisplayDriver displayDriver, long* CNPaddress, short x, short y, short w, short h);

  void Display()
  {
    _displayDriver.setCursor(_x, _y);
    _displayDriver.drawRect(_x, _y, _w, _h);
    _displayDriver.setCursor(coordonate magice de text x, coordonate magice de text y);
    _displayDriver.PrintText(*_cnpAddress, 2, culoare text backround text);
  };

  void Animate()
  {
    _displayDriver.setCursor(coordonate magice de text x, coordonate magice de text y);
    _displayDriver.PrintText(*_cnpAddress, dimensiune text, culoaretext, culoare background text);
  }
};

 TextField::TextField(DisplayDriver displayDriver, long* CNPaddress, short x, short y, short w, short h)
 {
   _cnpAddress = CNPaddress;
   _x = x;
   _y = y;
   _w = w;
   _h = h;
   _displayDriver = displayDriver;
 }


#endif
