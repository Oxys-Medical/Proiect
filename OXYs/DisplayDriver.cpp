#include "DisplayDriver.h"
#include "Constants.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"
#include "Adafruit_STMPE610.h"
#include <SPI.h>
#include <SD.h>

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
   if (!_adafruitTouchscreen.bufferEmpty() && !_adafruitTouchscreen.touched())
   {       TS_Point p = _adafruitTouchscreen.getPoint();
       int y = map(p.x, TS_MINX, TS_MAXX, 0, _displayDriver.height());
       int x = map(p.y, TS_MINY, TS_MAXY, 0, _displayDriver.width());       
       returnArray[0] = x;
       returnArray[1] = y;
       returnArray[2] = p.z;
     }
    return returnArray;
}
// void DisplayDriver::bmpDraw(char *filename, uint8_t x, uint16_t y)
// {
//   File     bmpFile;
//   int      bmpWidth, bmpHeight;   // W+H in pixels
//   uint8_t  bmpDepth;              // Bit depth (currently must be 24)
//   uint32_t bmpImageoffset;        // Start of image data in file
//   uint32_t rowSize;               // Not always = bmpWidth; may have padding
//   uint8_t  sdbuffer[3*BUFFPIXEL]; // pixel buffer (R+G+B per pixel)
//   uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
//   boolean  goodBmp = false;       // Set to true on valid header parse
//   boolean  flip    = true;        // BMP is stored bottom-to-top
//   int      w, h, row, col;
//   uint8_t  r, g, b;
//   uint32_t pos = 0, startTime = millis();

//   if((x >= tft.width()) || (y >= tft.height())) return;

//   // Open requested file on SD card
//   if ((bmpFile = SD.open(filename)) == NULL) {
//     Serial.print(F("File not found"));
//     return;
//   }

//   if(read16(bmpFile) == 0x4D42) { // BMP signature
//     Serial.print(F("File size: ")); Serial.println(read32(bmpFile));
//     (void)read32(bmpFile); // Read & ignore creator bytes
//     bmpImageoffset = read32(bmpFile); // Start of image data
//     Serial.print(F("Image Offset: ")); Serial.println(bmpImageoffset, DEC);
//     // Read DIB header
//     Serial.print(F("Header size: ")); Serial.println(read32(bmpFile));
//     bmpWidth  = read32(bmpFile);
//     bmpHeight = read32(bmpFile);
//     if(read16(bmpFile) == 1) { // # planes -- must be '1'
//       bmpDepth = read16(bmpFile); // bits per pixel
//       Serial.print(F("Bit Depth: ")); Serial.println(bmpDepth);
//       if((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

//         goodBmp = true; // Supported BMP format -- proceed!
//         Serial.print(F("Image size: "));
//         Serial.print(bmpWidth);
//         Serial.print('x');
//         Serial.println(bmpHeight);

//         // BMP rows are padded (if needed) to 4-byte boundary
//         rowSize = (bmpWidth * 3 + 3) & ~3;

//         // If bmpHeight is negative, image is in top-down order.
//         // This is not canon but has been observed in the wild.
//         if(bmpHeight < 0) {
//           bmpHeight = -bmpHeight;
//           flip      = false;
//         }

//         // Crop area to be loaded
//         w = bmpWidth;
//         h = bmpHeight;
//         if((x+w-1) >= tft.width())  w = tft.width()  - x;
//         if((y+h-1) >= tft.height()) h = tft.height() - y;

//         // Set TFT address window to clipped image bounds
//         tft.startWrite(); // Start TFT transaction
//         tft.setAddrWindow(x, y, w, h);

//         for (row=0; row<h; row++) { // For each scanline...

//             pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
//           else     // Bitmap is stored top-to-bottom
//             pos = bmpImageoffset + row * rowSize;
//           if(bmpFile.position() != pos) { // Need seek?
//             tft.endWrite(); // End TFT transaction
//             bmpFile.seek(pos);
//             buffidx = sizeof(sdbuffer); // Force buffer reload
//             tft.startWrite(); // Start new TFT transaction
//           }

//           for (col=0; col<w; col++) { // For each pixel...
//             // Time to read more pixel data?
//             if (buffidx >= sizeof(sdbuffer)) { // Indeed
//               tft.endWrite(); // End TFT transaction
//               bmpFile.read(sdbuffer, sizeof(sdbuffer));
//               buffidx = 0; // Set index to beginning
//               tft.startWrite(); // Start new TFT transaction
//             }

//             // Convert pixel from BMP to TFT format, push to display
//             b = sdbuffer[buffidx++];
//             g = sdbuffer[buffidx++];
//             r = sdbuffer[buffidx++];
//             tft.pushColor(tft.color565(r,g,b));
//           } // end pixel
//         } // end scanline
//         tft.endWrite(); // End last TFT transaction
//         Serial.print(F("Loaded in "));
//         Serial.print(millis() - startTime);
//         Serial.println(" ms");
//       } // end goodBmp
//     }
//   }
// }
void DisplayDriver::BlankScreen()
{
  _displayDriver.fillScreen(HX8357_BLACK);
}
