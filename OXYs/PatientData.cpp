#include "PatientData.h"
#include <Arduino.h>

PatientData::PatientData(char* CNP, byte* actualPulse, byte* actualSaturation, char* currentDateTime) 
{
    this->CNP = CNP;
    this->ActualPulse = actualPulse;
    this->ActualSaturation = actualSaturation;
    this->CurrentDateTime = currentDateTime;
}

PatientData::~PatientData()
{
  delete(this->ActualPulse);
  delete(this->ActualSaturation);
  //TODO: Asta s-ar putea să ne facă probleme.
  delete(this->CurrentDateTime);
}
