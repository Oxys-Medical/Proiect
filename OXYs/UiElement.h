#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

//oare astea le punem in Constants.h?
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


#include <Arduino.h>
#include <Adafruit_HX8357.h>
#include <Adafruit_GFX.h>

class UiElement
{
   private:
   Adafruit_HX8357 _adafruitDisplay = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);

   public:
   UiElement(int x, int y, int Height, int Width, uint16_t color);
   int x;
   int y;
   int Height;
   int Width;
   uint16_t color;
   void Update(); //sau o facem virtual void?
   void Animate();
   //putem folosi clasa Adafruit_GFX_Button ?
};

#endif