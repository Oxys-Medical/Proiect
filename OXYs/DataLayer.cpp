#include "StorageLayer.h"
#include "DataLayer.h"

#include <ctime>

DataLayer::DataLayer()
{
    _storageLayer = StorageLayer();
}

void DataLayer::AddPatientData(long CNP);
{
    // verificari ca este CNP valid, daca mai exista deja sau nu, etc..
    _storageLayer.AddPatientData(CNP);
}

void DataLayer::AddMeasurement(int actualPulse, int actualSaturation)
{
    // current date/time based on current system       (https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm)
    time_t now = time(0);

    // convert now to string form
    char* dateTime = ctime(&now);

    _storageLayer.AddMeasurament(actualPulse, actualSaturation, dateTime);
}