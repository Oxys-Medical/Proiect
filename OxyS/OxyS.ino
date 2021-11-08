#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include "RTClib.h"
#include <SPI.h>
#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_HX8357.h>
#include <Adafruit_STMPE610.h>
#include <SD.h>

#define REPORTING_PERIOD_MS 1000
#define STMPE_CS 6
#define TFT_CS 9
#define TFT_DC 10
#define SD_CS 5
#define TFT_RST -1
#define CSpin 5

RTC_PCF8523 rtc;
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);

File DataFile, HRFile, Spo2File;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

PulseOximeter pox;
uint32_t tsLastReport = 0;
#define TS_MINX 3800
#define TS_MAXX 100
#define TS_MINY 100
#define TS_MAXY 3750

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

// UI Buttondetails
#define BUTTON_X 100
#define BUTTON_Y 260
#define BUTTON_W 100
#define BUTTON_H 80
#define BUTTON_TEXTSIZE 2
#define DISPLAY_XOFFSET 80
#define DISPLAY_TEXTOFFSET 90
#define DISPLAY_YOFFSET 0

enum ButtonName
{
    BTN_START,
    BTN_STOP
};
enum ButtonName2
{
    BTN_BACK,
    BTN_SEND
};
#define MENU1_BTN_CNT 2
Adafruit_GFX_Button Menu1Buttons[MENU1_BTN_CNT];
char Menu1Labels[MENU1_BTN_CNT][6] = {"START", "STOP"};
uint16_t Menu1Colors[MENU1_BTN_CNT] = {HX8357_YELLOW, HX8357_YELLOW};

#define MENU2_BTN_CNT 2
Adafruit_GFX_Button Menu2Buttons[MENU2_BTN_CNT];
char Menu2Labels[MENU2_BTN_CNT][6] = {"BACK", "SEND"};
uint16_t Menu2Colors[MENU2_BTN_CNT] = {HX8357_YELLOW, HX8357_YELLOW};

int textSize = 2;
int textColorIndex = 0;
uint16_t textColor[1] = {HX8357_DARKGREY};

//-------------------------------------------------------------------------
bool initializeButtons(
    Adafruit_GFX_Button menuButtons[],
    uint16_t menuColors[],
    char menuLabels[][6],
    int menuButtonCount)
{
    tft.fillScreen(HX8357_BLACK);

    for (uint8_t row = 0; row < menuButtonCount; row++)
    {
        menuButtons[row].initButton(&tft,
                                    BUTTON_X + row * (BUTTON_W + 180),
                                    BUTTON_Y,
                                    BUTTON_W,
                                    BUTTON_H,
                                    HX8357_BLACK,
                                    menuColors[row],
                                    HX8357_DARKGREY,
                                    menuLabels[row], BUTTON_TEXTSIZE);
        menuButtons[row].drawButton();
    }
    return true;
}

//-------------------------------------------------------------------------
void tftSetCenterCursor(String str, int16_t xIn, int16_t yIn)
{
    int16_t xText, yText;
    uint16_t w, h;

    tft.getTextBounds(str, 0, 0, &xText, &yText, &w, &h);
    tft.setCursor(xIn - w / 2, yIn - h / 2);
}

//--------------------------------------------------------------------------------
void tftPrint(String str)
{
    int16_t xText, yText;
    uint16_t w, h;

    tft.getTextBounds(str, 0, 0, &xText, &yText, &w, &h);
    tft.fillRect(tft.getCursorX(), tft.getCursorY(), w, h, HX8357_BLACK);
    tft.print(str);
}

void onBeatDetected()
{
    Serial.println("Beat!");
    
}

void setup()
{

    Serial.begin(115200);

    if (!ts.begin())
        return;

    Serial.println("Touchscreen started");
    tft.begin();
    tft.setRotation(1);
    tft.setTextWrap(false);

    initializeButtons(Menu1Buttons, Menu1Colors, Menu1Labels, MENU1_BTN_CNT);

    Serial.print("Initializing pulse oximeter..");
    if (!pox.begin())
    {
        Serial.println("FAILED");
        for (;;)
            ;
    }
    else
    {
        Serial.println("SUCCESS");
    }
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    pox.setOnBeatDetectedCallback(onBeatDetected);

    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
        Serial.flush();
        abort();
    }

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   
    rtc.start();

    float drift = 43;                                     // seconds plus or minus over oservation period - set to 0 to cancel previous calibration.
    float period_sec = (7 * 86400);                       // total obsevation period in seconds (86400 = seconds in 1 day:  7 days = (7 * 86400) seconds )
    float deviation_ppm = (drift / period_sec * 1000000); //  deviation in parts per million (μs)
    float drift_unit = 4.34;                              // use with offset mode PCF8523_TwoHours
    int offset = round(deviation_ppm / drift_unit);
}
int tftButtonRelease(Adafruit_GFX_Button menuButtons[], int menuButtonCount)
{
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
        p.x = map(py, TS_MINY, TS_MAXY, 0, tft.width());
        p.y = map(px, TS_MINX, TS_MAXX, 0, tft.height());
    }

    // go thru all the buttons, checking if they were pressed
    for (uint8_t b = 0; b < menuButtonCount; b++)
    {
        if (menuButtons[b].contains(p.x, p.y))
        {
            Serial.print("Pressing: ");
            Serial.println(b);
            menuButtons[b].press(true); // tell the button it is pressed
        }
        else
        {
            menuButtons[b].press(false); // tell the button it is NOT pressed
        }
    }

    // now we can ask the buttons if their state has changed
    for (uint8_t b = 0; b < menuButtonCount; b++)
    {
        if (menuButtons[b].justReleased())
        {
            Serial.print("Released: ");
            Serial.println(b);
            menuButtons[b].drawButton(); // draw normal
            btn = b;
        }

        if (menuButtons[b].justPressed())
        {
            menuButtons[b].drawButton(true); // draw invert!
            delay(100);                      // UI debouncing
        }
    }
    return btn;
}

void processMenu2()
{
    String msg = "";
    bool exitLoop = false;

    msg = "Am terminat inregistrarile!";
    Serial.println(msg);
    tft.fillScreen(HX8357_BLACK);
    initializeButtons(Menu2Buttons, Menu2Colors, Menu2Labels, MENU2_BTN_CNT);
    while (!exitLoop)
    {
        int btn = tftButtonRelease(Menu2Buttons, MENU2_BTN_CNT);

        if (btn >= 0 && btn < MENU2_BTN_CNT)
        {
            Serial.print("btn = ");
            Serial.println(btn);
        }
        tft.setTextSize(2);
        tft.setTextColor(HX8357_CYAN);
        tft.setCursor(80, 100);
        tft.print(msg);
        DateTime now = rtc.now();
        tft.setTextSize(2);
        tft.setTextColor(HX8357_LIGHTGREY, HX8357_BLACK);
        tft.setCursor(160, 15);
        tft.print(now.day(), DEC);
        tft.print('/');
        tft.print(now.month(), DEC);
        tft.print('/');
        tft.print(now.year(), DEC);
        tft.print(' ');
        tft.print(now.hour(), DEC);
        tft.print(':');
        tft.print(now.minute(), DEC);

        switch (btn)
        {
        case BTN_SEND:
            Serial.println("a intrat send");
            
            DataFile = SD.open("Patient.txt", FILE_WRITE);
            DataFile.println("Data inregistrarii:");
            DataFile.print(now.year(), DEC);
            DataFile.print('/');
            DataFile.print(now.month(), DEC);
            DataFile.print('/');
            DataFile.print(now.day(), DEC);
            DataFile.print(" (");
            DataFile.print(daysOfTheWeek[now.dayOfTheWeek()]);
            DataFile.print(") ");
            DataFile.print(now.hour(), DEC);
            DataFile.print(':');
            DataFile.print(now.minute(), DEC);
            DataFile.print(':');
            DataFile.print(now.second(), DEC);
            DataFile.println();
            DataFile.print("Pulsul pacientului:");
            DataFile.print(pox.getHeartRate());
            DataFile.println("bpm");
            DataFile.print("SpO2-ul pacientului:");
            DataFile.print(pox.getSpO2());
            DataFile.println("%");
            DataFile.close();
            tft.setTextSize(2);
            tft.setTextColor(HX8357_PINK);
            tft.setCursor(80, 130);
            tft.print("Datele au fost inregistrate");
            tft.setCursor(140, 150);
            tft.print("pe cardul SD.");
            break;

        case BTN_BACK:
            pox.shutdown();
            Serial.println("a intrat back");
            exitLoop = true;
            break;

        default:
            break;
        }
    }
}

void processMenu1()
{
    String msg = "";
    int btn = tftButtonRelease(Menu1Buttons, MENU1_BTN_CNT);
    if (btn >= 0 && btn < MENU1_BTN_CNT)
    {
        Serial.print("btn = ");
        Serial.println(btn);
    }

    switch (btn)
    {
    case BTN_START:
        pox.begin();
        break;

    case BTN_STOP:
        processMenu2();
        initializeButtons(Menu1Buttons, Menu1Colors, Menu1Labels, MENU1_BTN_CNT);
        pox.begin();
        break;

    default:
        break;
    }
}
void puls()
{
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        DateTime now = rtc.now();
        if (pox.getHeartRate() != 0 && pox.getSpO2() != 0 && pox.getSpO2() <= 100 && pox.getHeartRate() > 30 && pox.getHeartRate() < 200)
        {
            SD.begin(CSpin);
            
            HRFile = SD.open("Pulse.txt", FILE_WRITE);
            HRFile.print(int(pox.getHeartRate()));
            HRFile.print("   ");
            HRFile.print(pox.getSpO2());            
            HRFile.close();
            
      
            tft.setTextSize(3);
            tft.setTextColor(HX8357_DARKGREY);
            tft.setCursor(50, 80);
            tft.print("PRbpm");
            tft.setTextColor(HX8357_PINK, HX8357_BLACK);
            tft.setCursor(60, 120);
            tft.setTextSize(6);
            tft.print(int(pox.getHeartRate()));
            tft.print("    ");
            tft.setTextSize(3);
            tft.setTextColor(HX8357_DARKGREY);
            tft.setCursor(330, 80);
            tft.print("SpO2% ");
            tft.setTextColor(HX8357_CYAN, HX8357_BLACK);
            tft.setTextSize(5);
            tft.setCursor(340, 120);
            tft.print(pox.getSpO2());

            Serial.print("Data inregistrarii:");
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');
            Serial.print(now.day(), DEC);
            Serial.print(" (");
            Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
            Serial.print(") ");
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);

            Serial.print("Pulsul pacientului:");
            Serial.print(pox.getHeartRate());
            Serial.println("bpm");
            Serial.print("SpO2-ul pacientului:");
            Serial.print(pox.getSpO2());
            Serial.println("%");

        tsLastReport = millis();
    }
}
}

void loop()
{
    DateTime now = rtc.now();
    tft.setTextSize(2);
    tft.setTextColor(HX8357_LIGHTGREY, HX8357_BLACK);
    tft.setCursor(160, 15);
    tft.print(now.day(), DEC);
    tft.print('/');
    tft.print(now.month(), DEC);
    tft.print('/');
    tft.print(now.year(), DEC);
    tft.print(' ');
    tft.print(now.hour(), DEC);
    tft.print(':');
    tft.print(now.minute(), DEC);
    processMenu1();
    puls();
}
