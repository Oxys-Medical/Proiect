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
   void setCursor(int16_t x, int16_t y){
    cursor_x = x;
    cursor_y = y;
  }

   void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
                     int16_t radius, uint16_t color);
   void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
                     int16_t radius, uint16_t color);
   void setTextSize(uint8_t s);
   void setTextColor(uint16_t c);
   void print();
   void fillScreen(uint16_t color);
};

#endif
