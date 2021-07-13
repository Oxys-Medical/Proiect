#include "DisplayDriver.h"
#include "Constants.h"

DisplayDriver::DisplayDriver()
{
    _adafruitDisplay = TipDeDisplayDeLaAdafruit();
}

void DisplayDriver::Initialize()
{
    _adafruitDisplay.Initialize();
}

int* DisplayDriver::GetContactPoint()
{
    int* returnArray = new int[NumberOfPhysicalDimensions];
    if (!_adafruitDisplay.bufferEmpty())
    {
        TS_Point point = _adafruitDisplay.getPoint();
        //mapare de aici, limitele display-ului:
        //https://learn.adafruit.com/adafruit-3-5-tft-featherwing/adafruit2-resistive-touch-screen
        returnArray[0] = point.X;
        returnArray[1] = point.Y;
        returnArray[2] = point.Z;
        point.x = map(point.x, 0, 4095, 0, tft.width(480));
        point.y = map(point.y, 0, 4095, 0, tft.height(320));

        point.x = map(point.x, TS_MINX, TS_MAXX, 0, tft.width());
        point.y = map(point.y, TS_MINY, TS_MAXY, 0, tft.height());
    
    }
if (_adafruitDisplay.touched())
{
    
}
    return returnArray;
}