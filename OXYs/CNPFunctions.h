#ifndef __CNPFUNCTIONS_H__
#define __CNPFUNCTIONS_H__

#include <SPI.h>
#include <SD.h> //trebuie pentru card

//ceva initializare card ? ? ?

//cnp functii

int pow(int x, int y)
{
    int n = x;
    for (int i = 0; i < y; i++)
    {
        n = n * x;
    }
    return n;
}

bool isValid(long CNP)
{ //ai grija cu functia
    if ((CNP % pow(10, 13) == 0) && (CNP % pow(10, 12) == 5 || CNP % pow(10, 12) == 6 || CNP % pow(10, 12) == 1 || CNP % pow(10, 12) == 2))
        return 0;
    else
        return 1;
}

bool isNew(long CNP)
{
    SD.begin(CSpin);
    CNPFile = SD.open("CNP.txt", FILE_READ);
    while (CNPFile.available())
    {
        char readCNP = CNPFile.read();
        Serial.write(readCNP);
        char bufferCNP[sizeof(long) * 8 + 1];
        ltoa(CNP, bufferCNP, 10);
        if (strcmp(bufferCNP, readCNP) == 0)
        {
            CNPFile.close();
            return 1;
        }
    }
    CNPFile.close();
    return 0;
}

void deleteAllPreviousEntries();
{ // trebuie completat

    SD.begin(CSpin);
    CNPFile.close();
    return 0;
}
int numberOfEntries()
{
    int NumberOfEntries = 0;
    SD.begin(CSpin);
    CNPFile = SD.open("CNP.txt", FILE_READ);
    while (CNPFile.available())
    {
        CNPFile.read();
        NumberOfEntries++;
    }

    CNPFile.close();
    return NumberOfEntries;


}

#endif