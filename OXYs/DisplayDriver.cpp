#include "DisplayDriver.h"
#include "Constants.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"
#include <SPI.h>

#define TS_MINX 150
#define TS_MAXX 3800
#define TS_MINY 150
#define TS_MAXY 3800

#define RefreshTime 40

#ifdef ESP8266
   #define STMPE_CS 16
   #define TFT_CS   0
   #define TFT_DC   15
   #define SD_CS    2
#endif
#ifdef ESP32
   #define STMPE_CS 32
   #define TFT_CS   15
   #define TFT_DC   33
   #define SD_CS    14
#endif
#ifdef TEENSYDUINO
   #define TFT_DC   10
   #define TFT_CS   4
   #define STMPE_CS 3
   #define SD_CS    8
#endif
#ifdef ARDUINO_STM32_FEATHER
   #define TFT_DC   PB4
   #define TFT_CS   PA15
   #define STMPE_CS PC7
   #define SD_CS    PC5
#endif
#ifdef ARDUINO_NRF52832_FEATHER
   #define STMPE_CS 30
   #define TFT_CS   31
   #define TFT_DC   11
   #define SD_CS    27
#endif
#if defined(ARDUINO_MAX32620FTHR) || defined(ARDUINO_MAX32630FTHR)
   #define TFT_DC   P5_4
   #define TFT_CS   P5_3
   #define STMPE_CS P3_3
   #define SD_CS    P3_2
#endif

// Anything else!
#if defined (__AVR_ATmega32U4__) || defined(ARDUINO_SAMD_FEATHER_M0) || defined (__AVR_ATmega328P__) || \
defined(ARDUINO_SAMD_ZERO) || defined(__SAMD51__) || defined(__SAM3X8E__) || defined(ARDUINO_NRF52840_FEATHER)
   #define STMPE_CS 6
   #define TFT_CS   9
   #define TFT_DC   10
   #define SD_CS    5
#endif

#define TFT_RST -1

DisplayDriver::DisplayDriver()
{
    //_adafruitDisplay = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
    //_adafruitTouchscreen = Adafruit_STMPE610(STMPE_CS);
}

void DisplayDriver::Initialize()
{
    //_adafruitDisplay.begin();
    //_adafruitDisplay.setRotation(1);
    //_adafruitDisplay.setCursor(0, 0);
    //_adafruitDisplay.fillScreen(HX8357_BLACK);
    //_adafruitTouchscreen.begin();
}

int* DisplayDriver::GetContactPoint()
{
    int* returnArray = new int[NumberOfPhysicalDimensions];
//    if (!_adafruitDisplay.bufferEmpty() && !_adafruitDisplay.touched())
//    {
//        TS_Point point = _adafruitDisplay.getPoint();
//        int y = map(p.x, TS_MINX, TS_MAXX, 0, tft.height());
//        int x = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
//        returnArray[0] = x;
//        returnArray[1] = y;
//        returnArray[2] = point.z;
//     }
    return returnArray;
}

void DisplayDriver::BlankScreen()
{
   //_adafruitDisplay.fillScreen(HX8357_BLACK);
}
