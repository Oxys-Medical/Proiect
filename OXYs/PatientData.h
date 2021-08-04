#ifndef __PATIENTDATA_H__
#define __PATIENTDATA_H__

//#include <Arduino.h>

class PatientData
{
    public:
    long CNP;
    byte* ActualPulse;
    byte* ActualSaturation;
    char* CurrentDateTime;
    PatientData(long CNP, byte* actualPulse, byte* actualSaturation, char* currentDateTime);
    ~PatientData();
};

#endif
