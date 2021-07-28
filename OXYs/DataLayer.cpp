#include "StorageLayer.h"
#include "DataLayer.h"
#include "PulseOxySampler.h"
#include "PulseOxyFunctions.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card

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
    
    //se intoarce in data entrystate?
}

void DataLayer::AddMeasurement(int actualPulse, int actualSaturation)
{
    //RTC()
    //definim currentDataTime
    //_storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime);
}
