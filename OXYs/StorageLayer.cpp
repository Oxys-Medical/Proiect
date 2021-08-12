#include "StorageLayer.h"
#include "Constants.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card
#include <stdlib.h>
#include "PatientData.h"
// cod pentru SD in arduino

void StorageLayer::AddPatientData(long CNP)
{
    setup();
    CNPFile = SD.open("CNP.txt", FILE_WRITE); //oare trebe append?
    CNPFile.println(CNP);
    CNPFile.close();
    SD.close();
}
void StorageLayer::AddMeasurement(long CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    char f[64];
    ltoa(CNP, f, 10);
    setup();
    strcat(f, ".txt"); // din ce librarie luam strcat
    XFile = SD.open(f, FILE_WRITE);
    XFile.println(currentDataTime);
    XFile.println(actualPulse);
    XFile.println(actualSaturation);
    SD.close();
}
int StorageLayer::FetchPatientData()
{

}

// https://learn.sparkfun.com/tutorials/microsd-shield-and-sd-breakout-hookup-guide