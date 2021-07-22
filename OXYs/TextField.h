#ifndef __TEXTFIELD_H__
#define __TEXTFIELD_H__

#include <Arduino.h>
#include "UiElement.h"
#include "DisplayDriver.h"

class TextField : public UiElement
{
  private:
  long* _cnpAddress;

  public:
  TextField(DisplayDriver displayDriver, long* CNPaddress, short x, short y, short width, short height);

  void Display()
  {
    _displayDriver.SetCursor(_x, _y);
    _displayDriver.DrawRectangle(_x, _y, _width, _height);
    _displayDriver.SetCursor(coordonate magice de text x, coordonate magice de text y);
    _displayDriver.PrintText(*_cnpAddress, dimensiune text, culoare text backround text);
  }

  void Animate()
  {
    _displayDriver.SetCursor(coordonate magice de text x, coordonate magice de text y);
    _displayDriver.PrintText(*_cnpAddress, dimensiune text, culoaretext, culoare background text);
  }
};

 TextField::TextField(DisplayDriver displayDriver, long* CNPaddress, short x, short y, short width, short height)
 {
   _cnpAddress = CNPaddress;
   _x = x;
   _y = y;
   _width = width;
   _height = height;
   _displayDriver = displayDriver;
 }

#endif
