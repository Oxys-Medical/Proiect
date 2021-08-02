#include "UiElement.h"
#include "Adafruit_HX8357.h"
#include "Adafruit_GFX.h"

UiElement::UiElement(DisplayDriver displayDriver, short x, short y, short h, short w)
{
   //_adafruitDisplay = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST); 

    _x = x;
    _y = y;
    _h = h;
    _w = w;

}