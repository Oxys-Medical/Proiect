#ifndef __DISPLAYDRIVER_H__
#define __DISPLAYDRIVER_H__

#include <SPI.h>
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"
#include "Adafruit_GFX.h"
#include "UiElement.h"

class DisplayDriver //: public Adafruit_GFX
{
    private:
    Adafruit_HX8357 _displayDriver ;
    Adafruit_STMPE610 _adafruitTouchscreen;

   public:
   void BlankScreen();
   DisplayDriver();
   void Initialize();
   int* GetContactPoint();
   void setCursor();
};

#endif
