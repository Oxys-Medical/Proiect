#ifndef __STORAGELAYER_H__
#define __STORAGELAYER_H__

#include "PatientData.h"

class StorageLayer
{
    private:
    void SetupSDCard(); // see more https://learn.sparkfun.com/tutorials/microsd-shield-and-sd-breakout-hookup-guide

    public:
    StorageLayer();

    // vor scrie datele pe cardul SD?
    void AddPatientData(long CNP);
    void AddMeasurement(int actualPulse, int actualSaturation, char* currentDataTime);
    PatientData* FetchPatientData(); //returneaza un array de obiecte care au proprietetile CNP, puls, etc.
};

#endif