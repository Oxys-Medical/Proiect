#ifndef __DATALAYER_H__
#define __DATALAYER_H__

#include "StorageLayer.h"
#include "PatientData.h"
#include "RTClib.h"

class DataLayer
{
private:
    StorageLayer _storageLayer;

public:
    DataLayer();
    void AddPatientData(String CNP, int actualPulse, int actualSaturation, char *currentDataTime);
    void AddMeasurement(int actualPulse, int actualSaturation, char *currentDataTime);
    void AppendDigit(String currentCNP, int Digit);
    void DeleteDigit(String currentCNP); 
    String ConfirmCNP(String currentCNP);

    PatientData charFetchPatientData(); // ar trebui sa returneze un array si fiecare element al array-ului sa contina un triplet (actualPulse, actualSaturation, time)? sau un array de obiecte?
};

#endif
