#include "StorageLayer.h"
#include "DataLayer.h"
#include "PulseOxySampler.h"
#include "PulseOxyFunctions.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card
#include <fstream> // trebuie la fisiere

DataLayer::DataLayer()
{
    _storageLayer = StorageLayer();
}

void DataLayer::AddPatientData(long CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    if (isValid(CNP))
        if (iSNew(CNP))
            //o sa fie trecut in cnp.txt se va crea o adresa la txt nou si apoi se va crea un txt nou
         _storageLayer.AddPatientData(CNP);
         _storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime)

        else
        //scriem in cnp.txt adresa noua si creaza un txt nou
         _storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime)
         _storageLayer.AddPatientData(CNP);

    else
    
    //nu face nimic
}
void DataLayer::AppendDigit(long currentCNP, int x)
{
    currentCNP=currentCNP*10+x;
    //oare asa aduagam?
    
}
void DataLayer::DeleteDigit(long currentCNP, int x)
{
    currentCNP = (currentCNP - x)/10;  
    //asa stergem?
}
void DataLayer::ConfirmCNP(long currentCNP)
{
    long CNP = currentCNP;
    //ii stocat undeva in memoria interna

}
void DataLayer::AddMeasurement(int actualPulse, int actualSaturation)
{
    //RTC()
    //definim currentDataTime
    //_storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime);
}
