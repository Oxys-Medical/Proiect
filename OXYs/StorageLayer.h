#ifndef __STORAGELAYER_H__
#define __STORAGELAYER_H__

#include "PatientData.h"
#include "Constants.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card
#include <stdlib.h>

class StorageLayer
{
private:
  void setup()
  {
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    while (!Serial)
    {
      ; // wait for serial port to connect. Needed for native USB port only
    }
  }
  // see more https://learn.sparkfun.com/tutorials/microsd-shield-and-sd-breakout-hookup-guide

public:
  StorageLayer();

  void AddPatientData(long CNP)
  {
    SD.begin(CSpin);
    CNPFile = SD.open("CNP.txt", FILE_WRITE); //oare trebe append?
    CNPFile.println(CNP);
    file.close();
    SD.close();
  }
  void AddMeasurement(long CNP, int actualPulse, int actualSaturation, char *currentDataTime)
  {
    char f[64];
    ltoa(CNP, f, 10);
    strcat(f, ".txt"); // din ce librarie luam strcat
    XFile = SD.open(f, FILE_WRITE);
    XFile.println(currentDataTime);
    XFile.println(actualPulse);
    XFile.println(ActualSaturation);
    file.close();
    SD.close();
  }
  PatientData *FetchPatientData(); //returneaza un array de obiecte care au proprietetile CNP, puls, etc.
};

#endif