#ifndef __PULSEOXYSAMPLER_H__
#define __PULSEOXYSAMPLER_H__

#include "SamplingLayer.h"
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

class PulseOxySampler
{
    private:
    SamplingLayer _samplingLayer;


    public:
    PulseOxySampler();
    PulseOximeter pox;
    uint32_t tsLastReport = 0;
    int* MeasureValues();
    int ConvertPulseValue(int pulseValue);
    int ConvertSaturationValue(int saturationValue);

};

#endif