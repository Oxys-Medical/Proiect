#include "StorageLayer.h"
#include "Constants.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card
#include <stdlib.h>
#include "PatientData.h"
//#include <openssl/MD5.h> // hash genereaza un cod mai lung decat cnp-ul in sine

// cod pentru SD in arduino

void StorageLayer::AddPatientData(char* CNP, char *currentDataTime)
{
    setup();
    CNPFile = SD.open("CNP.txt", FILE_WRITE); 
    CNPFile.print(CNP);
    CNPFile.print("/");
    CNPFile.println(currentDataTime);//daca tot e mai mic si stocam o singura masuratoare de la fieacare om ajunge current data time?
    CNPFile.close();
}
void StorageLayer::AddMeasurement(char* CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
    char* f;
    setup();
    strcpy(f,currentDataTime);
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