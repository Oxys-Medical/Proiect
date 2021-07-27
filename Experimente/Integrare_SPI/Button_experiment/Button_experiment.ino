/*
 * gfxbuttontest_featherwing
 */

#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_HX8357.h>
#include <Adafruit_STMPE610.h>



#ifdef ESP8266
   #define STMPE_CS 16
   #define TFT_CS   0
   #define TFT_DC   15
   #define SD_CS    2
 
#elif defined ESP32
   #define STMPE_CS 32
   #define TFT_CS   15
   #define TFT_DC   33
   #define SD_CS    14
 
#elif defined TEENSYDUINO
   #define TFT_DC   10
   #define TFT_CS   4
   #define STMPE_CS 3
   #define SD_CS    8
  
#elif defined ARDUINO_STM32_FEATHER
   #define TFT_DC   PB4
   #define TFT_CS   PA15
   #define STMPE_CS PC7
   #define SD_CS    PC5
  
#elif defined ARDUINO_NRF52832_FEATHER
   #define STMPE_CS 30
   #define TFT_CS   31
   #define TFT_DC   11
   #define SD_CS    27

#elif  defined(ARDUINO_MAX32620FTHR) || defined(ARDUINO_MAX32630FTHR)
   #define TFT_DC   P5_4
   #define TFT_CS   P5_3
   #define STMPE_CS P3_3
   #define SD_CS    P3_2

// Something else!
#elif  defined (__AVR_ATmega32U4__) || defined(ARDUINO_SAMD_FEATHER_M0) || defined (__AVR_ATmega328P__) || \
defined(ARDUINO_SAMD_ZERO) || defined(__SAMD51__) || defined(__SAM3X8E__) || defined(ARDUINO_NRF52840_FEATHER)
   #define STMPE_CS 6
   #define TFT_CS   9
   #define TFT_DC   10
   #define SD_CS    5

 // optional different defaults 
#else
   #define STMPE_CS 6
   #define TFT_CS   9
   #define TFT_DC   10
   #define SD_CS    5
#endif


#define TFT_RST -1


// Use hardware SPI and the above for CS/DC
Adafruit_HX8357  tft = Adafruit_HX8357( TFT_CS,  TFT_DC,  TFT_RST);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);

// This is calibration data for the raw touch data to the screen coordinates
// For rotation 1, these put the buttons at the top of the screen
#define TS_MINX 3800
#define TS_MAXX 150
#define TS_MINY 150
#define TS_MAXY 3800

// Redefine original colors, add additional colors to match those available with the ILI9341 library
#define HX8357_BLACK       0x0000  ///<   0,   0,   0
#define HX8357_NAVY        0x000F  ///<   0,   0, 123
#define HX8357_DARKGREEN   0x03E0  ///<   0, 125,   0
#define HX8357_DARKCYAN    0x03EF  ///<   0, 125, 123
#define HX8357_MAROON      0x7800  ///< 123,   0,   0
#define HX8357_PURPLE      0x780F  ///< 123,   0, 123
#define HX8357_OLIVE       0x7BE0  ///< 123, 125,   0
#define HX8357_LIGHTGREY   0xC618  ///< 198, 195, 198
#define HX8357_DARKGREY    0x7BEF  ///< 123, 125, 123
#define HX8357_BLUE        0x001F  ///<   0,   0, 255
#define HX8357_GREEN       0x07E0  ///<   0, 255,   0
#define HX8357_CYAN        0x07FF  ///<   0, 255, 255
#define HX8357_RED         0xF800  ///< 255,   0,   0
#define HX8357_MAGENTA     0xF81F  ///< 255,   0, 255
#define HX8357_YELLOW      0xFFE0  ///< 255, 255,   0
#define HX8357_WHITE       0xFFFF  ///< 255, 255, 255
#define HX8357_ORANGE      0xFD20  ///< 255, 165,   0
#define HX8357_GREENYELLOW 0xAFE5  ///< 173, 255,  41
#define HX8357_PINK        0xFC18  ///< 255, 130, 198

// UI Buttondetails
#define BUTTON_X 115
#define BUTTON_Y 150
#define BUTTON_W 120
#define BUTTON_H 40
#define BUTTON_TEXTSIZE 3
#define DISPLAY_XOFFSET 0
#define DISPLAY_TEXTOFFSET 0
#define DISPLAY_YOFFSET 0

// text box where numbers go
#define TEXT_X 10
#define TEXT_Y 10
#define TEXT_W 220
#define TEXT_H 50
#define TEXT_TSIZE 3
#define TEXT_TCOLOR HX8357_MAGENTA
// the data (phone #) we store in the textfield
#define TEXT_LEN 12
char textfield[TEXT_LEN+1] = "";
uint8_t textfield_i=0;

enum ButtonName {
  BTN_1,
  BTN_2,
  BTN_3,
  BTN_4,
  BTN_5,
  BTN_6,
  BTN_7,
  BTN_8,
  BTN_9,
  BTN_DELETE,
  BTN_0,
  BTN_OK
};

#define MENU1_BTN_CNT 12
Adafruit_GFX_Button Menu1Buttons[MENU1_BTN_CNT];
char Menu1Labels[MENU1_BTN_CNT][13] = {"1", "2", "3", "4", "5","6", "7", "8", "9","DELETE", "0", "OK"};
uint16_t Menu1Colors[MENU1_BTN_CNT] = {HX8357_DARKGREY, HX8357_DARKGREY, 
                               HX8357_DARKGREY, HX8357_DARKGREY, HX8357_DARKGREY, HX8357_DARKGREY, HX8357_DARKGREY, HX8357_DARKGREY, HX8357_DARKGREY,HX8357_YELLOW, HX8357_DARKGREY,HX8357_YELLOW};

int textSize = 3;
//uint16_t textcolor = HX8357_MAGENTA;
uint16_t textColor[MENU1_BTN_CNT] = {
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_WHITE,
 HX8357_DARKGREY,
 HX8357_WHITE,
 HX8357_DARKGREY
};

bool initializeButtons( Adafruit_GFX_Button menuButtons[], uint16_t menuColors[], char menuLabels[][13],int menuButtonCount) 
{
     tft.fillScreen(HX8357_BLACK);

    for (uint8_t row=0; row<5; row++) 
    {
       for (uint8_t col=0; col<3; col++) 
       {
      menuButtons[col + row*3].initButton(&tft, BUTTON_X+col*(BUTTON_W+5), 
                 BUTTON_Y+row*(BUTTON_H+5),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, HX8357_BLACK, Menu1Colors[col+row*3], textColor[col + row*3],
                  Menu1Labels[col + row*3], BUTTON_TEXTSIZE); 
      menuButtons[col + row*3].drawButton();
       }
    } 
    
    return true;
}

 // void TextField (Adafruit_HX8357  tft, int x, int y, int w, int h, uint16_t color ){
  //  tft.drawRect(100, 150, 160, 40, HX8357_WHITE);
 //   tft.fillRect(100, 150, 160, 40, HX8357_WHITE); 
  //  }

    
/*void tftSetCenterCursor(String str, int16_t xIn, int16_t yIn) {
  int16_t xText, yText;
  uint16_t w, h;  
  
    tft.getTextBounds(str, 0, 0, &xText, &yText, &w, &h);
    tft.setCursor(xIn-w/2, yIn-h/2);  
}
*/
//--------------------------------------------------------------------------------
 /*void tftPrint(String str) {
    int16_t xText, yText;
    uint16_t w, h;  

      tft.getTextBounds(str, 0, 0, &xText, &yText, &w, &h);
      tft.fillRect(  tft.getCursorX(),   tft.getCursorY(), w, h, HX8357_LIGHTGREY);
      tft.print(str);
}
*/
//-------------------------------------------------------------------------

void setup() {
    Serial.begin(115200);
    delay(100);
    Serial.println("");

    // if the touchscreen returns true, assume we have the  tft device
    if (!ts.begin())
        return;
        
    Serial.println("Touchscreen started");
     tft.begin();
     tft.setRotation(1);
     tft.setTextWrap(false);
                           
    initializeButtons(Menu1Buttons, Menu1Colors, Menu1Labels, MENU1_BTN_CNT);

}

//--------------------------------------------------------------------------------
int  tftButtonRelease(Adafruit_GFX_Button menuButtons[], int menuButtonCount) {
    int btn = -1;
    TS_Point p;
    
    if (ts.bufferSize()) 
    {
        p = ts.getPoint(); 
    } 
    else 
    {
        // this is our way of tracking touch 'release'!
        p.x = p.y = p.z = -1;
    }
  
    // Scale from ~0->4000 to  tft.width using the calibration #'s
    if (p.z != -1) 
    {
        int16_t px = p.x;
        int16_t py = p.y;
        p.x = map(py, TS_MINY, TS_MAXY, 0,  tft.width());
        p.y = map(px, TS_MINX, TS_MAXX, 0,  tft.height()); 
    }

    // go thru all the buttons, checking if they were pressed
    for (uint8_t b=0; b<menuButtonCount; b++) 
    {
        if (menuButtons[b].contains(p.x, p.y)) 
        {
          Serial.print("Pressing: "); Serial.println(b);
          menuButtons[b].press(true);  // tell the button it is pressed
        } 
        else 
        {
          menuButtons[b].press(false);  // tell the button it is NOT pressed
        }
    }
    
    // now we can ask the buttons if their state has changed
    for (uint8_t b=0; b<menuButtonCount; b++) 
    {
        if (menuButtons[b].justReleased()) 
        {
          Serial.print("Released: "); Serial.println(b);
          menuButtons[b].drawButton();  // draw normal
          btn = b;
        }

        if (menuButtons[b].justPressed()) 
        {
            menuButtons[b].drawButton(true);  // draw invert!
            delay(100); // UI debouncing
        }
    }
    return btn;
}

void processMenu1() {
    initializeButtons(Menu1Buttons, Menu1Colors, Menu1Labels, MENU1_BTN_CNT);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, HX8357_WHITE);
    int btn =  tftButtonRelease(Menu1Buttons, MENU1_BTN_CNT);
    if (btn >= 0 && btn < MENU1_BTN_CNT)
    {
        Serial.print("btn = "); Serial.println(btn);
    }
    for (uint8_t b=0; b<12; b++) 
    {
     // if a numberpad button, append the relevant # to the textfield
        if (b >= 3) {
          if (textfield_i < TEXT_LEN) {
            textfield[textfield_i] = Menu1Labels[b][0];
            textfield_i++;
      textfield[textfield_i] = 0; // zero terminate
          
          }
        }

        // clr button! delete char
        if (b == 1) {
          
          textfield[textfield_i] = 0;
          if (textfield > 0) {
            textfield_i--;
            textfield[textfield_i] = ' ';
          }
        }

        // update the current text field
        Serial.println(textfield);
        tft.setCursor(TEXT_X + 2, TEXT_Y+10);
        tft.setTextColor(TEXT_TCOLOR, HX8357_BLACK);
        tft.setTextSize(TEXT_TSIZE);
        tft.print(textfield);
    }
}

//--------------------------------------------------------------------------------
void loop(void) {
 processMenu1();
}
