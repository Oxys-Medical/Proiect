#include "UiElement.h"


UiElement::UiElement(int x, int y, int Height, int Width, uint16_t color)
{
   _adafruitDisplay = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST); 

    this->x = x;
    this->y = y;
    this->Height = Height;
    this->Width = Width;
    this->color = color;

}