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
}

void DataLayer::AddPatientData(string CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    if (isValid(CNP))
        if (isNew(CNP))
        { 
            if(numberOfEntries() == FullCapacity)
            {
                deleteAllPreviousEntries();
                //delete previous data 

            }
          //o sa fie trecut in cnp.txt si apoi se va crea un .txt nou
            _storageLayer.AddPatientData(CNP);
            _storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime)
        }
        else
        { //scriem in creaza un txt nou
            _storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime)
        }
    else
    //nu face nimic
}
void DataLayer::AppendDigit(String currentCNP, int Digit)
{
    currentCNP = currentCNP * 10 + Digit;
    //oare asa aduagam?
}
void DataLayer::DeleteDigit(String currentCNP)
{
    currentCNP = (currentCNP) / 10;
    //asa stergem?
}
void DataLayer::ConfirmCNP( String currentCNP)
{
    long CNP = currentCNP;
    //ii stocat undeva in memoria interna
}
void DataLayer::AddMeasurement(int actualPulse, int actualSaturation)
{
    
    //definim currentDataTime
    _storageLayer.AddMeasurement(actualPulse, actualSaturation, char* currentDataTime);
}
