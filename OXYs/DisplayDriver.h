#ifndef __DISPLAYDRIVER_H__
#define __DISPLAYDRIVER_H__

#include <SPI.h>
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"
#include "Adafruit_GFX.h"
#include "UiElement.h"

class DisplayDriver//
{
    private:
    Adafruit_HX8357 _displayDriver ;
    Adafruit_STMPE610 _adafruitTouchscreen;

   public:
   void BlankScreen();
   DisplayDriver();
   void Initialize();

//functii din Adafruit GTX
   int* GetContactPoint(int16_t x, int16_t y);
   void setCursor(int16_t x, int16_t y);
   void drawRoundRect();
   void fillRoundRect();
   void setTextSize();
   void setTextColor();
   void print();
//etc....
};

#endif
