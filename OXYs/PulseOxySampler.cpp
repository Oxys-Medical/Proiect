#include "PulseOxySampler.h"
#include "SamplingLayer.h"
#include "Constants.h"
#include "NumericalConstants.h"
#include "PulseOxyFunctions.h"

PulseOxySampler::PulseOxySampler()
{
    _samplingLayer = SamplingLayer();
}

int *PulseOxySampler::MeasureValues()
{
    int pulseValue = _samplingLayer.Read();
    //oare asta e logica?

//     void LEDState(byte State){
//   if(State==0){//IR On and charge
//     digitalWrite(IRLED,0);
//     digitalWrite(Charge,0);
//   }
//   else if(State==1){//RED On and charge
//     digitalWrite(REDLED,0);
//     digitalWrite(Charge,0);
//   }
//   else if(State==2){ //LED Off and discharge
//     digitalWrite(REDLED,1);
//     digitalWrite(IRLED,1);
//     digitalWrite(Charge,1);
//   }
// }

    int saturationValue = _samplingLayer.Read();
    //bla bla mai multă logică

    
    int actualPulse = ConvertPulseValue(pulseValue);
    int actualSaturation = ConvertSaturationValue(saturationValue);

    int *returnArray = new int[ArrayLength];
    returnArray[0] = actualPulse;
    returnArray[1] = actualSaturation;

    return returnArray;
}

int PulseOxySampler::ConvertPulseValue(int pulseValue)
{

    HeartRateArray[countHR % 4] = (PeakTime[0] - PeakTime[1]) & 0xFFFF;
    ActualPulse = 0;
    for (byte i = 0; i < 4; ++i)
    {
        ActualPulse += HeartRateArray[i];
    }
    ActualPulse = 60000 * 4 / ActualPulse; // nu stiu de unde e formula
    if (fabs(HR_Hysteresis - ActualPulse) > HR_Hysteresis_width)
    { //nu stiu ce librarie trebuie aici pt fabs
        HR_Hysteresis = int(ActualPulse + 0.5);
    }

    return ActualPulse;
}

int PulseOxySampler::ConvertSaturationValue(int saturationValue)
{

    R = (beta_MinMax[1][1] / beta_MinMax[0][1] - 1) / (beta_MinMax[1][0] / beta_MinMax[0][0] - 1);
    SpO2Array[countHR % 4] = 0.3557 * R * R * R - 5.1864 * R * R - 18.342 * R + 108.381;
    ActualSaturation = 0;
    for (byte i = 0; i < 4; ++i)
    {
        ActualSaturation += SpO2Array[i];
    }
    ActualSaturation /= 4;
    if (fabs(SpO2_Hysteresis - ActualSaturation) > SpO2_Hysteresis_width)
    {
        SpO2_Hysteresis = int(ActualSaturation + 0.5);
    }

    return ActualSaturation;
}
