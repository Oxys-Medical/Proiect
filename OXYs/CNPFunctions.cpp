#include "CNPFunctions.h"

// int CNPFunctions::pow(int x, int y)
// {
//     int n = x;
//     for (int i = 0; i < y; i++)
//     {
//         n = n * x;
//     }
//     return n;
// }

bool CNPFunctions::isValid(char* CNP)
{ 
    if (strlen(CNP) == 14 && (CNP[0] == "5" || CNP[0] == "6" || CNP[0] == "1" || CNP[0] == "2"))
    
        return 0;
    else
        return 1;
    //daca e long?
    // if ((CNP % pow(10, 13) == 0) && (CNP % pow(10, 12) == 5 || CNP % pow(10, 12) == 6 || CNP % pow(10, 12) == 1 || CNP % pow(10, 12) == 2))
    //     return 0;
    // else
    //     return 1;
}

bool CNPFunctions::isNew(char* CNP)
{
    SD.begin(CSpin);
    CNPFile = SD.open("CNP.txt", FILE_READ);
    while (CNPFile.available())
    {
        char *readCNP = CNPFile.read();
        Serial.write(readCNP);
        if (strcmp(CNP, readCNP) == 0)
        {
            CNPFile.close();
            return 1;
        }
    }
    CNPFile.close();
    return 0;
}

void CNPFunctions::deleteAllPreviousEntries()
{   


    SD.begin(CSpin);
    CNPFile.close();
    return 0;
}

int CNPFunctions::numberOfEntries()
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
