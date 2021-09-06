#ifndef __DATALAYER_H__
#define __DATALAYER_H__

#include "StorageLayer.h"
#include "PatientData.h"
#include "RTClib.h"
#include "CnpFunctions.h"

class DataLayer
{
private:
    StorageLayer _storageLayer;
    CNPFunctions _cnpFunctions;
    RTCFunction _rtcFunction;

public:
    DataLayer();
    void AddPatientData(char* CNP, int actualPulse, int actualSaturation,char* currentDataTime);
    void AddMeasurement(char* CNP, int actualPulse, int actualSaturation, char* currentDataTime);
    void AppendDigit(char* currentCNP, char* Digit);
    void DeleteDigit(char* currentCNP); 
    char* ConfirmCNP(char* currentCNP);

    PatientData charFetchPatientData(char* CNP, int actualPulse, int actualSaturation, char *currentDataTime); // ar trebui sa returneze un array si fiecare element al array-ului sa contina un triplet (actualPulse, actualSaturation, time)? sau un array de obiecte?
};

#endif
