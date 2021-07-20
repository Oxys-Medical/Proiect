#ifndef __DISPLAYDRIVER_H__
#define __DISPLAYDRIVER_H__

#include <SPI.h>
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"

class DisplayDriver
{
  private:
//  Adafruit_HX8357 _adafruitDisplay;
//  Adafruit_STMPE610 _adafruitTouchscreen;

  public:
  DisplayDriver();
  void Initialize();
  int* GetContactPoint();
};

#endif
