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
  long CNP = 6000112303929;
  int actualPulse = 89;
  int actualSaturation = 97;
  char *currentDataTime = "azi";
  CNPFile = SD.open("CNP.txt", FILE_WRITE);
  Serial.println(CNP);
  Serial.println("Datele pentru pacientul cu CNP-ul respectiv sunt:");
  Serial.println(currentDataTime);
  Serial.println(actualPulse);
  Serial.println(actualSaturation);
  CNPFile.println(CNP);
  //  CNPFile.println(currentDataTime);
  //  CNPFile.println(actualPulse);
  //  CNPFile.println(actualSaturation);
  CNPFile.close();
  char *f;
  ltoa(CNP, f, 10);
  strcat(f, ".txt");
  XFile = SD.open(f, FILE_WRITE);
  XFile.println(currentDataTime);
  XFile.println(actualPulse);
  XFile.println(actualSaturation);
  XFile.close();
}
void loop()
{
  // nothing happens after setup
}