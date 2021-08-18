#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#include <Arduino.h>
#include "UiElement.h"
#include "DisplayDriver.h"
#include "Commands.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"

/// A simple drawn button UI element
class UiButton : public UiElement
{

public:
  UiButton(DisplayDriver displayDriver, short x, short y, short w, short h, short r, uint16_t outlinecolor, uint16_t fillcolor, uint16_t textcolor, byte textSize ,char label, byte command);

  void Display()
  {
    _displayDriver.setCursor(_x, _y);
    _displayDriver.drawRoundRect(_x, _y, _w, _h, _r, _outlinecolor);
    _displayDriver.fillRoundRect(_x, _y, _w, _h, _r, _fillcolor);
    _displayDriver.setCursor(_x+10, _y+10); //date de test
    _displayDriver.setTextSize(_textSize);
    _displayDriver.setTextColor(_textcolor);
    _displayDriver.print(_label);
  };

  void Animate()
  {
    _displayDriver.setCursor(_x+10, _y+10); // date de test
    _displayDriver.setTextSize(_textSize);
    _displayDriver.setTextColor(_textcolor);
    _displayDriver.fillRoundRect(_x, _y, _w, _h, _r, _fillcolor);
    _displayDriver.print(_label);
  }

private:
  DisplayDriver displayDriver;
  short _x, _y; // Coordinates of top-left corner
  short _w, _h, _r;
  byte _textSize;
  uint16_t _outlinecolor, _fillcolor, _textcolor;
  char _label[10];
  byte _command;
};

UiButton::UiButton(DisplayDriver displayDriver, short x, short y, short w, short h, short r, uint16_t outlinecolor, uint16_t fillcolor, uint16_t textcolor, byte textSize, char label, byte command)
{
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  _r = r;
  _outlinecolor = outlinecolor;
  _fillcolor = fillcolor;
  _textcolor = textcolor;
  _textSize = textSize;
  _label = label;
  _command = command;
}

byte UiButton::HandleContactPoint(int *contactPoint)
{
  if ( x>_x && x<_x+_w && y>_y && y<_y+_h )
    {
      return _command;
    }
  else
  {
    return NoCommand;
  }
}

#endif