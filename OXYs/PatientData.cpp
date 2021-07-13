#include "PatientData.h"

PatientData::PatientData(long CNP, int actualPulse, int actualSaturation, char* currentDateTime) 
{
    this->CNP = CNP;
    this->actualPulse = actualPulse;
    this->actualSaturation = actualSaturation;
    this->currentDateTime = currentDateTime;
}