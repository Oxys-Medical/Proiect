#ifndef __DISPLAYDRIVER_H__
#define __DISPLAYDRIVER_H__

#include <SPI.h>
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"
#include "Adafruit_GFX.h"

#define TS_MINX 150
#define TS_MAXX 3800
#define TS_MINY 150
#define TS_MAXY 3800

#define RefreshTime 40

#ifdef ESP8266
#define STMPE_CS 16
#define TFT_CS 0
#define TFT_DC 15
#define SD_CS 2
#endif
#ifdef ESP32
#define STMPE_CS 32
#define TFT_CS 15
#define TFT_DC 33
#define SD_CS 14
#endif
#ifdef TEENSYDUINO
#define TFT_DC 10
#define TFT_CS 4
#define STMPE_CS 3
#define SD_CS 8
#endif
#ifdef ARDUINO_STM32_FEATHER
#define TFT_DC PB4
#define TFT_CS PA15
#define STMPE_CS PC7
#define SD_CS PC5
#endif
#ifdef ARDUINO_NRF52832_FEATHER
#define STMPE_CS 30
#define TFT_CS 31
#define TFT_DC 11
#define SD_CS 27
#endif
#if defined(ARDUINO_MAX32620FTHR) || defined(ARDUINO_MAX32630FTHR)
#define TFT_DC P5_4
#define TFT_CS P5_3
#define STMPE_CS P3_3
#define SD_CS P3_2
#endif

// Something else!
#if defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAMD_FEATHER_M0) || defined(__AVR_ATmega328P__) || \
    defined(ARDUINO_SAMD_ZERO) || defined(__SAMD51__) || defined(__SAM3X8E__) || defined(ARDUINO_NRF52840_FEATHER)
#define STMPE_CS 6
#define TFT_CS 9
#define TFT_DC 10
#define SD_CS 5

// optional different defaults
#else
#define STMPE_CS 6
#define TFT_CS 9
#define TFT_DC 10
#define SD_CS 5
#endif

#define TFT_RST -1

// Redefine original colors, add additional colors to match those available with the ILI9341 library
#define HX8357_BLACK 0x0000       ///<   0,   0,   0
#define HX8357_NAVY 0x000F        ///<   0,   0, 123
#define HX8357_DARKGREEN 0x03E0   ///<   0, 125,   0
#define HX8357_DARKCYAN 0x03EF    ///<   0, 125, 123
#define HX8357_MAROON 0x7800      ///< 123,   0,   0
#define HX8357_PURPLE 0x780F      ///< 123,   0, 123
#define HX8357_OLIVE 0x7BE0       ///< 123, 125,   0
#define HX8357_LIGHTGREY 0xC618   ///< 198, 195, 198
#define HX8357_DARKGREY 0x7BEF    ///< 123, 125, 123
#define HX8357_BLUE 0x001F        ///<   0,   0, 255
#define HX8357_GREEN 0x07E0       ///<   0, 255,   0
#define HX8357_CYAN 0x07FF        ///<   0, 255, 255
#define HX8357_RED 0xF800         ///< 255,   0,   0
#define HX8357_MAGENTA 0xF81F     ///< 255,   0, 255
#define HX8357_YELLOW 0xFFE0      ///< 255, 255,   0
#define HX8357_WHITE 0xFFFF       ///< 255, 255, 255
#define HX8357_ORANGE 0xFD20      ///< 255, 165,   0
#define HX8357_GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define HX8357_PINK 0xFC18        ///< 255, 130, 198

class DisplayDriver
{
private:
   Adafruit_HX8357 _displayDriver = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
   Adafruit_STMPE610 _adafruitTouchscreen = Adafruit_STMPE610(STMPE_CS);
   int16_t _x;
   int16_t _y;

public:
   void
   BlankScreen();
   DisplayDriver();
   void Initialize();
   int *GetContactPoint();
   void setCursor(int16_t x, int16_t y)
   {
      _x = x;
      _y = y;
   }

   void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
                      int16_t radius, uint16_t color);
   void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
                      int16_t radius, uint16_t color);
   void setTextSize(uint8_t s);
   void setTextColor(uint16_t c);
   void print(char printableText);
   void fillScreen(uint16_t color);
   void drawTriangle();
   void drawTriangle(int16_t A, int16_t B, int16_t C, int16_t a,
                               int16_t b, int16_t c, uint16_t color);
   void fillTriangle(int16_t A, int16_t B, int16_t C, int16_t a,
                               int16_t b, int16_t c, uint16_t color);
};

#endif
