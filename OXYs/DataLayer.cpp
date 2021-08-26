#include "StorageLayer.h"
#include "DataLayer.h"
#include "PulseOxySampler.h"
#include "PulseOxyFunctions.h"
#include "CNPFunctions.h"
#include "RTCFunction.h"

// #include <SPI.h>
// #include <SD.h>    //trebuie pentru card

DataLayer::DataLayer()
{
    _storageLayer = StorageLayer();
    _cnpFunctions = CNPFunctions();
    _rtcFunction = RTCFunction();
}

void DataLayer::AddPatientData(char *CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    if (_cnpFunctions.isValid(CNP))
        if (_cnpFunctions.isNew(CNP))
        {
            if (_cnpFunctions.numberOfEntries() == FullCapacity)
            {
                _cnpFunctions.deleteAllPreviousEntries();
                //delete previous data
            }
            //o sa fie trecut in cnp.txt si apoi se va crea un .txt nou
            _storageLayer.AddPatientData(CNP, currentDataTime);
            _storageLayer.AddMeasurement(CNP, actualPulse, actualSaturation, currentDataTime);
        }
        else
        { //scriem si creaza un txt nou
            _storageLayer.AddMeasurement(CNP, actualPulse, actualSaturation, currentDataTime);
        }
    //nu face nimic
}
void DataLayer::AppendDigit(char *currentCNP, char *Digit)
{
    //currentCNP = currentCNP * 10 + Digit;
    //oare asa aduagam?
    strcat(currentCNP, Digit);
}
void DataLayer::DeleteDigit(char *currentCNP)
{
    //currentCNP = (currentCNP) / 10;
    //asa stergem?
    byte lastChar = strlen(currentCNP) - 1;
    currentCNP[lastChar] = '\0';
}
char *DataLayer::ConfirmCNP(char *currentCNP)
{
    char *CNP = currentCNP;
    return CNP;
}
void DataLayer::AddMeasurement(char *CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{

    //definim currentDataTime
    _storageLayer.AddMeasurement(CNP, actualPulse, actualSaturation, currentDataTime);
}
PatientData DataLayer::charFetchPatientData(char *CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
}
