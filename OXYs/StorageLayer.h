#ifndef __STORAGELAYER_H__
#define __STORAGELAYER_H__

#include "PatientData.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card

class StorageLayer
{
private:
   void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  }
  // see more https://learn.sparkfun.com/tutorials/microsd-shield-and-sd-breakout-hookup-guide

public:
    StorageLayer();

    void AddPatientData(long CNP)
    {

        CNPFile = SD.open("CNP.txt", FILE_WRITE);
        CNPFile.println(CNP);
        //CNPFile.println(adresa); //ce adresa?
        file.close();
    }
    void AddMeasurement(int actualPulse, int actualSaturation, char *currentDataTime)
    {
        //Cum facem cu denumirea fiecarui fisier
        XFile = SD.open("ceva.txt", FILE_WRITE);
        XFile.println(currentDataTime);
        XFile.println(actualPulse);
        XFile.println(ActualSaturation);
        file.close();
    }
    PatientData *FetchPatientData(); //returneaza un array de obiecte care au proprietetile CNP, puls, etc.
};

#endif