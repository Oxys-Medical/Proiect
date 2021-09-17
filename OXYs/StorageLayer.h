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


public:
  StorageLayer();
  int PatientNumber;
  File CNPFile;
  File XFile;
  void AddPatientData(char* CNP, char* currentDateTime);
  void AddMeasurement(char* CNP, int actualPulse, int actualSaturation, char* currentDataTime);
//  PatientData *GetPatientData(); //returneaza un array de obiecte care au proprietetile CNP, puls, etc.
};

#endif