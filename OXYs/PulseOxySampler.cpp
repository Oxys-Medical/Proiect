#include "PulseOxySampler.h"
#include "SamplingLayer.h"
#include "Constants.h"
#include "NumericalConstants.h"


PulseOxySampler::PulseOxySampler()
{
    _samplingLayer = SamplingLayer();
}

int *PulseOxySampler::MeasureValues()
{
    int pulseValue = _samplingLayer.Read();
    int saturationValue = _samplingLayer.Read();
    pox.begin();
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    pox.update();
    int actualPulse = pox.getHeartRate();
    int actualSaturation = pox.getSpO2();
    //int actualPulse = ConvertPulseValue(pulseValue);
    //int actualSaturation = ConvertSaturationValue(saturationValue);

    int *returnArray = new int[ArrayLength];
    returnArray[0] = actualPulse;
    returnArray[1] = actualSaturation;

    return returnArray;

}
int PulseOxySampler::ConvertPulseValue(int pulseValue)
{
    

    return 0;
}

int PulseOxySampler::ConvertSaturationValue(int saturationValue)
{


    return 0;
}
