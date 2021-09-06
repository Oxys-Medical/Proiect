#include "StorageLayer.h"
#include "DataLayer.h"
#include "PulseOxySampler.h"
#include "PulseOxyFunctions.h"
#include "CNPFunctions.h"
#include "RTCFunction.h"

DataLayer::DataLayer()
{
    _storageLayer = StorageLayer();
    _cnpFunctions = CNPFunctions();
    _rtcFunction = RTCFunction();
}

void DataLayer::AddPatientData(char *CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    if (_cnpFunctions.isValid(CNP))
    {
        if (_cnpFunctions.isNew(CNP))
        {
            if (_cnpFunctions.numberOfEntries() == FullCapacity)
            {
                _cnpFunctions.deleteAllPreviousEntries();
            }
            _storageLayer.AddPatientData(CNP, currentDataTime);
        }
        _storageLayer.AddMeasurement(CNP, actualPulse, actualSaturation, currentDataTime);
    }
}
void DataLayer::AppendDigit(char *currentCNP, char *Digit)
{

    strcat(currentCNP, Digit);
}
void DataLayer::DeleteDigit(char *currentCNP)
{
    byte lastChar = strlen(currentCNP) - 1;
    currentCNP[lastChar] = '\0';
}
char *DataLayer::ConfirmCNP(char *currentCNP)
{
    char *CNP = currentCNP;
    return CNP;
}
// void DataLayer::AddMeasurement(char *CNP, int actualPulse, int actualSaturation, char *currentDataTime)
// {

//     //definim currentDataTime
//     _rtcFunction.setup();
//     _storageLayer.AddMeasurement(CNP, actualPulse, actualSaturation, currentDataTime);
// }
PatientData DataLayer::charFetchPatientData(char *CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
}
