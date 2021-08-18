#ifndef __DATALAYER_H__
#define __DATALAYER_H__

#include "StorageLayer.h"
#include "PatientData.h"

class DataLayer
{
private:
    StorageLayer _storageLayer;


public:
    DataLayer();
    void AddPatientData(long CNP, int actualPulse, int actualSaturation, char *currentDataTime);
    void AddMeasurement(int actualPulse, int actualSaturation, char *currentDataTime);
    void AppendDigit(String currentCNP, int Digit);
    void DeleteDigit(String currentCNP); //parametrii nu stiu
    String ConfirmCNP(String currentCNP);

    PatientData charFetchPatientData(); // ar trebui sa returneze un array si fiecare element al array-ului sa contina un triplet (actualPulse, actualSaturation, time)? sau un array de obiecte?
};

#endif
