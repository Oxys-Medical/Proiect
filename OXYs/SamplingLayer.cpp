#include "SamplingLayer.h"
#include "Constants.h"
#include <Arduino.h>

SamplingLayer::SamplingLayer()
{
    pinMode(AnalogReadPin, INPUT);
}

int SamplingLayer::Read()
{
    int readValue = analogRead(AnalogReadPin);
    return readValue;
}

