/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>
#include <stdlib.h>

File CNPFile;
File XFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(5))
  {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  char *CNP = "6000112303929";
  int actualPulse = 89, actualSaturation = 97;
  char *currentDataTime = "azi";
}
void AddMeasurement(char CNP, int actualPulse, int actualSaturation, char currentDataTime)
{
  char f[64];
  ltoa(CNP, f, 10);
  strcat(f, ".txt"); // din ce librarie luam strcat
  XFile = SD.open(CNP, FILE_WRITE);
  XFile.println(currentDataTime);
  XFile.println(actualPulse);
  XFile.println(actualSaturation);
  XFile.close();
}

void AddPatientData(char CNP)
{
  CNPFile = SD.open("CNP.txt", FILE_WRITE);
  CNPFile.println(CNP);
  CNPFile.close();
}

void loop()
{
  // nothing happens after setup
}
