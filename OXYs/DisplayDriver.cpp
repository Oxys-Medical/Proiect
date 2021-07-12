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
    }

    return returnArray;
}