/***************************************************
  This is our library for the Adafruit 3.5" TFT (HX8357) FeatherWing
  ----> http://www.adafruit.com/products/3651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <SPI.h>
#include <SD.h>
#include <WiFi101.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"

//When used in landscape mode, the touchscreen senses touches like this:
//_
//|
//|
//|
//|
//X
//|
//|
//|
//|
//-|----------Y----------|
//
//The values returned by the TS controller are in these ranges:
//_
//| 3800
//|
//|
//|
//|
//X          
//|
//|
//|
//|
//|
//| 150
//-
//
//  150                           3800
// |-----------------Y----------------|
//
// To make our lives easier, we'll consider that the screen's horizontal is X and that the screen's vertical is Y (when used in landscape mode).

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

// Use hardware SPI and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
unsigned long _previousMillis;

void setup()
{
  _previousMillis = 0;
  tft.begin();
  tft.setRotation(1);
  tft.setCursor(0, 0);
  tft.fillScreen(HX8357_BLACK);
  //Achtung! Clearing the screen is painfully slow. We're better off having a black backround for the text and/or clearing sections of the screen.
  tft.setTextColor(HX8357_WHITE, HX8357_BLACK);
  tft.setTextSize(1);
  ts.begin();
  WiFi.setPins(8,7,4,2);
  //ReadFromSdCard();
  //PrintWiFiNetworks();
}

void loop(void) 
{
  if (millis() - _previousMillis >= RefreshTime)
  {
    _previousMillis = millis();
    if (!ts.bufferEmpty() && ! ts.touched())
    {
      tft.setCursor(0, 0);
      TS_Point p = ts.getPoint();
      short y = map(p.x, TS_MINX, TS_MAXX, 0, tft.height());
      short x = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
      tft.println("Touched X and Y are:");
      tft.print(x);
      tft.print("  ");
      tft.println();
      tft.print(y);
      tft.println("  ");
    }
  } 
}

void ReadFromSdCard()
{
  SD.begin(SD_CS);
  File textFile = SD.open("testing.txt");
  if (textFile)
  {
    while (textFile.available())
    {
      tft.println(textFile.read());
    }
    textFile.close();
  }
}

void PrintWiFiNetworks()
{
  // scan for nearby networks:
  tft.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1)
  {
    tft.println("Couldn't get a WiFi connection");
    while (true);
  }

  // print the list of networks seen:
  tft.print("number of available networks: ");
  tft.println(numSsid);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    tft.print(thisNet + 1);
    tft.print(") ");
    tft.print("Signal: ");
    tft.print(WiFi.RSSI(thisNet));
    tft.print(" dBm");
    tft.print("\tChannel: ");
    tft.print(WiFi.channel(thisNet));
    tft.print("\t\tSSID: ");
    tft.println(WiFi.SSID(thisNet));
  }
  tft.println();
}
