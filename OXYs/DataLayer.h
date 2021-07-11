#ifndef __DATALAYER_H__
#define __DATALAYER_H__

#include "StorageLayer.h"

class DataLayer{
    private:
    StorageLayer _storageLayer;

    public:
    DataLayer();
    void AddPatientData(long CNP);
    void AddMeasurement(int actualPulse, int actualSaturation);
    FetchPatientData();  // ar trebui sa returneze un array si fiecare element al array-ului sa contina un tuplet (actualPulse, actualSaturation, time)? sau un array de obiecte?
};

#endif