#ifndef __PULSEOXYSAMPLER_H__
#define __PULSEOXYSAMPLER_H__

#include "SamplingLayer.h"

class PulseOxySampler
{
    private:
    SamplingLayer _samplingLayer;
    int ConvertPulseValue(int pulseValue);
    int ConvertSaturationValue(int saturationValue);

    public:
    PulseOxySampler();
    int* MeasureValues();
};

#endif