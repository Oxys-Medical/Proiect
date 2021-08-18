
#ifndef __RTCFUNCTION_H__
#define __RTCFUNCTION_H__

// Date and time functions using a PCF8523 RTC connected via I2C and Wire lib
#include "RTClib.h" //trebe instalata

class RTCFunction
{

private:
  RTC_PCF8523 rtc;

  char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  void setup()
  {
    Serial.begin(57600);

#ifndef ESP8266
    while (!Serial)
      ; // wait for serial port to connect. Needed for native USB
#endif

    if (!rtc.begin())
    {
      Serial.println("Couldn't find RTC");
      Serial.flush();
      abort();
    }

    if (!rtc.initialized() || rtc.lostPower())
    {
      Serial.println("RTC is NOT initialized, let's set the time!");

      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    rtc.start();

    float drift = 43;                                     // seconds plus or minus over oservation period - set to 0 to cancel previous calibration.
    float period_sec = (7 * 86400);                       // total obsevation period in seconds (86400 = seconds in 1 day:  7 days = (7 * 86400) seconds )
    float deviation_ppm = (drift / period_sec * 1000000); //  deviation in parts per million (μs)
    float drift_unit = 4.34;                              // use with offset mode PCF8523_TwoHours
    // float drift_unit = 4.069; //For corrections every min the drift_unit is 4.069 ppm (use with offset mode PCF8523_OneMinute)
    int offset = round(deviation_ppm / drift_unit);

    Serial.print("Offset is ");
    Serial.println(offset); // Print to control offset
  }

  void loop()
  {
    DateTime now = rtc.now();

  }
};
#endif
