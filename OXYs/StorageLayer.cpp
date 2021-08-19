#include "StorageLayer.h"
#include "Constants.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card
#include <stdlib.h>
#include "PatientData.h"

// cod pentru SD in arduino

void StorageLayer::AddPatientData(char* CNP)
{
    setup();
    CNPFile = SD.open("CNP.txt", FILE_WRITE); 
    
    CNPFile.println(CNP);
    CNPFile.close();
}
void StorageLayer::AddMeasurement(char* CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    char* f;
    setup();
    strcpy(f,CNP);
    strcat(f, ".txt"); 
    XFile = SD.open(f, FILE_WRITE);
    XFile.println(currentDataTime);
    XFile.println(actualPulse);
    XFile.println(actualSaturation);
}
// int StorageLayer::PatientData()
// {

// }

// https://learn.sparkfun.com/tutorials/microsd-shield-and-sd-breakout-hookup-guide