#include "PatientData.h"
#include <Arduino.h>
#include "RTClib.h"

PatientData::PatientData() 
{
    this->CNP = cnp;
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
