#include "StorageLayer.h"
#include "DataLayer.h"
#include "PulseOxySampler.h"


DataLayer::DataLayer()
{
    _storageLayer = StorageLayer();
}

void DataLayer::AddPatientData(long CNP)
{
    if(isValid(CNP))
        if(iSNew(CNP))
            //o sa fie trecut in cnp.txt se va crea o adresa la txt nou si apoi se va crea un txt nou
            
              _storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime)
             _storageLayer.AddPatientData(CNP);

        else 
            //scriem in cnp.txt adresa noua si creaza un txt nou 
             _storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime)
             _storageLayer.AddPatientData(CNP);
    else 
        //se intoarce in data entrystate? 

    
}

bool isValid(long CNP)
{
    if((CNP%10^13 == 0)   &&    (CNP%10^12 == 5 || CNP%10^12 == 6 CNP%10^12 == 1 || CNP%10^12 ==2 )
        return 0;
    else 
        return 1;
}
// bool isNew(long CNP)
// {
//
//     if(CNP != memoryCNP)
//         return 0; 
//     else
//         return 1;
// }

void DataLayer::AddMeasurement(int actualPulse, int actualSaturation)
{
    //RTC()
    //definim currentDataTime
    //_storageLayer.AddMeasurement(actualPulse, actualSaturation, currentDataTime);
}
