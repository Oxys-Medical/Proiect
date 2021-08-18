#include "StorageLayer.h"
#include "Constants.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card
#include <stdlib.h>
#include "PatientData.h"
#include <string>
#include <cstring>
// cod pentru SD in arduino

void StorageLayer::AddPatientData(String CNP)
{
    setup();
    CNPFile = SD.open("CNP.txt", FILE_WRITE); 
    CNPFile.println(CNP);
    CNPFile.close();
}
void StorageLayer::AddMeasurement(String CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    char* f;
    setup();
    char CNPpointer[CNP.size() +1];
    strcpy(CNPpointer, CNP.c_str());
    strcpy(f,CNPpointer);
    strcat(f, ".txt"); 
    XFile = SD.open(f, FILE_WRITE);
    XFile.println(currentDataTime);
    XFile.println(actualPulse);
    XFile.println(actualSaturation);
}
int StorageLayer::FetchPatientData()
{
    
}

// https://learn.sparkfun.com/tutorials/microsd-shield-and-sd-breakout-hookup-guide