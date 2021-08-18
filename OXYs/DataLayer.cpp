#include "StorageLayer.h"
#include "DataLayer.h"
#include "PulseOxySampler.h"
#include "PulseOxyFunctions.h"
#include "CNPFunctions.h"
#include "RTCFunction.h"
//#include <String.h>
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
    //currentCNP = currentCNP * 10 + Digit;
    //oare asa aduagam?
    strcat(currentCNP,Digit);
}
void DataLayer::DeleteDigit(String currentCNP)
{
    currentCNP = (currentCNP) / 10;
    //asa stergem?
    currentCNP.pop_back();
}
String DataLayer::ConfirmCNP(String currentCNP)
{
    String CNP = currentCNP;
    return CNP;
}
void DataLayer::AddMeasurement(int actualPulse, int actualSaturation)
{
    
    //definim currentDataTime
    _storageLayer.AddMeasurement(actualPulse, actualSaturation, char* currentDataTime);
}

