#ifndef __PATIENTDATA_H__
#define __PATIENTDATA_H__

class PatientData
{
    private:
    long CNP;
    int actualPulse;
    int actualSaturation;
    char* currentDateTime;

    public:
    PatientData(long CNP, int actualPulse, int actualSaturation, char* currentDateTime);
};

#endif