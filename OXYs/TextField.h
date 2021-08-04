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
  long *_cnpAddress;
  byte _textSize;
  uint16_t _outlinecolor, _fillcolor, _textcolor;
  short _r;

public:
  TextField(DisplayDriver displayDriver, long *CNPaddress, short x, short y, short w, short h, short r, uint16_t outlinecolor, uint16_t fillcolor, uint16_t textcolor, byte textSize);

  void Display()
  {
    _displayDriver.setCursor(_x, _y);
    _displayDriver.drawRoundRect(_x, _y, _w, _h, _r, _outlinecolor);
    _displayDriver.fillRoundRect(_x, _y, _w, _h, _r, _fillcolor);
    _displayDriver.setCursor(_x+10, _y+10); //date de test
    _displayDriver.setTextSize(_textSize);
    _displayDriver.setTextColor(_textcolor);
    _displayDriver.print(*_cnpAddress);
  };

  void Animate()
  {
    _displayDriver.setCursor(_x+10, _y+10); //date de test
    _displayDriver.fillRoundRect(_x, _y, _w, _h, _r, _fillcolor);
    _displayDriver.setTextSize(_textSize);
    _displayDriver.setTextColor(_textcolor);
    _displayDriver.print(*_cnpAddress);
  }
};

TextField::TextField(DisplayDriver displayDriver, long *CNPaddress, short x, short y, short w, short h, short r, uint16_t outlinecolor, uint16_t fillcolor, uint16_t textcolor, byte textSize)
{
  _cnpAddress = CNPaddress;
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  _r = r;
  _outlinecolor = outlinecolor;
  _fillcolor = fillcolor;
  _textcolor = textcolor;
  _textSize = textSize;
  _displayDriver = displayDriver;
}

//HandleContactPoint???

#endif
