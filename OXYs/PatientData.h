#ifndef __PATIENTDATA_H__
#define __PATIENTDATA_H__

//#include <Arduino.h>

class PatientData
{
    public:
    String CNP;
    byte* ActualPulse;
    byte* ActualSaturation;
    char* CurrentDateTime;
    
    PatientData(String CNP, byte* actualPulse, byte* actualSaturation, char* currentDateTime);
    ~PatientData();
};

#endif
