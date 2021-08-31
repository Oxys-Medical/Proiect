#include "DisplayDriver.h"
#include "Constants.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"
#include <SPI.h>

DisplayDriver::DisplayDriver()
{
}

void DisplayDriver::Initialize()
{
    _displayDriver.begin();
    _displayDriver.setRotation(1);
    _displayDriver.setCursor(0, 0);
    _displayDriver.fillScreen(HX8357_BLACK);
    _adafruitTouchscreen.begin();
}

int* DisplayDriver::GetContactPoint()
{
    int* returnArray = new int[NumberOfPhysicalDimensions];
   if (!_displayDriver.bufferEmpty() && !_displayDriver.touched())
   {       TS_Point p = _displayDriver.getPoint();
       int y = map(p.x, TS_MINX, TS_MAXX, 0, _displayDriver.height());
       int x = map(p.y, TS_MINY, TS_MAXY, 0, _displayDriver.width());       
       returnArray[0] = x;
       returnArray[1] = y;
       returnArray[2] = p.z;
     }
    return returnArray;
}

void DisplayDriver::BlankScreen()
{
  _displayDriver.fillScreen(HX8357_BLACK);
}
