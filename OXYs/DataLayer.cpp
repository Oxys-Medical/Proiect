#include "StorageLayer.h"
#include "DataLayer.h"



DataLayer::DataLayer()
{
    _storageLayer = StorageLayer();
}

void DataLayer::AddPatientData(long CNP)
{
    // verificari ca este CNP valid, daca mai exista deja sau nu, etc..
    _storageLayer.AddPatientData(CNP);
}

void DataLayer::AddMeasurement(int actualPulse, int actualSaturation)
{
    //RTC()
    //definim currentDataTime
    _storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime);
}