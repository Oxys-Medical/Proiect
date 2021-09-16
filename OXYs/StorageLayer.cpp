#include "StorageLayer.h"
#include "Constants.h"
#include <SPI.h>
#include <SD.h> //trebuie pentru card
#include <stdlib.h>
#include "PatientData.h"
//#include <openssl/MD5.h> // hash genereaza un cod mai lung decat cnp-ul in sine

// cod pentru SD in arduino

void StorageLayer::AddPatientData(char *CNP, char *currentDateTime)
{
  SD.begin(CSpin);
  CNPFile = SD.open("CNP.txt", FILE_WRITE);
  CNPFile.println(CNP);
  CNPFile.close();
}
void StorageLayer::AddMeasurement(char *CNP, int actualPulse, int actualSaturation, char *currentDataTime)
{
  SD.begin(CSpin);
   char EndCNP[7];
  for (int i = 0; i < 6; i++)
  {
    EndCNP[i] = CNP[i + 7];
  }
  strcat(EndCNP, ".txt");

  XFile = SD.open(EndCNP, FILE_WRITE);
  XFile.print("Datele pentru pacientul cu CNP-ul:");
  XFile.print(CNP);
  XFile.println(" sunt:");
  XFile.println("Data inregistrarilor:");
  XFile.println(currentDataTime);
  XFile.print("Pulsul pacientului este: ");
  XFile.print(actualPulse);
  XFile.println(" BPM");
  XFile.print("Saturatie de oxigen a pacientuluin este: ");
  XFile.print(actualSaturation);
  XFile.println(" SpO2");
  XFile.close();
}
// int StorageLayer::PatientData()
// {

// }
