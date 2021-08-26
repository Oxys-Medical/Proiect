#ifndef __STORAGELAYER_H__
#define __STORAGELAYER_H__

#include "PatientData.h"
#include "Constants.h"
#include "SD.h"
#include "RTCFunction.h"

class StorageLayer
{
private:
  PatientData _patientData;
  RTCFunction _rtcFunction;
  void setup()
  {
    Serial.begin(9600);
    while (!Serial)
    {
      ; // wait for serial port to connect. Needed for native USB port only
    }

  Serial.print("Initializing SD card...");

  if (!SD.begin(CSpin)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  }
  

public:
  StorageLayer();
  int PatientNumber;
  File CNPFile;
  File XFile;
  void AddPatientData(char* CNP, char *currentDataTime);
  void AddMeasurement(char* CNP, int actualPulse, int actualSaturation, char *currentDataTime);
  PatientData *PatientData(); //returneaza un array de obiecte care au proprietetile CNP, puls, etc.
};

#endif