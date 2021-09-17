#ifndef __PATIENTDATA_H__
#define __PATIENTDATA_H__

#include <Arduino.h>

class PatientData
{
    public:
    char* CNP;
    byte* ActualPulse;
    byte* ActualSaturation;
    char* CurrentDateTime;
    char* cnp;
    byte* actualPulse, *actualSaturation;
    char* currentDateTime;
    PatientData();
    ~PatientData();
};

#endif
