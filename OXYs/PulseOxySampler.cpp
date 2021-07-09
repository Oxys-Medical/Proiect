#include "PulseOxySampler.h"
#include "SamplingLayer.h"
#include "Constants.h"

PulseOxySampler::PulseOxySampler()
{
    _samplingLayer = SamplingLayer();
}

int* PulseOxySampler::MeasureValues()
{
    int pulseValue = _samplingLayer.Read();
    //bla bla logică
    int saturationValue = _samplingLayer.Read();
    //bla bla mai multă logică
    int actualPulse = ConvertPulseValue(pulseValue);
    int actualSaturation = ConvertSaturationValue(saturationValue);

    int* returnArray = new int[ArrayLength];
    returnArray[0] = actualPulse;
    returnArray[1] = actualSaturation;

    return returnArray;
}

int PulseOxySampler::ConvertPulseValue(int pulseValue)
{
    //bla bla conversie
    return pulseValue;
}

int PulseOxySampler::ConvertSaturationValue(int saturationValue)
{
    //bla bla conversie
    return saturationValue;
}