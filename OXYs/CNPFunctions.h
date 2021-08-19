#ifndef __CNPFUNCTIONS_H__
#define __CNPFUNCTIONS_H__

#include <SPI.h>
#include <SD.h> //trebuie pentru card

//ceva initializare card ? ? ?

class CNPFunctions
{

private:
public:
    CNPFunctions();
    int pow(int x, int y);
    bool isValid(char *CNP);
    bool isNew(char *CNP);
    void deleteAllPreviousEntries();
    int numberOfEntries();
};

#endif