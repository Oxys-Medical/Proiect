#include "PulseOxySampler.h"
#include "SamplingLayer.h"
#include "Constants.h"
#include "NumericalConstants.h"

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
    void CalcHR()
    {
    T_HR_arr[countHR%4]=(PeakTime[0]-PeakTime[1]) & 0xFFFF;
    HR_val=0;
    for(byte i=0;i<4;++i){
    HR_val+=T_HR_arr[i]; 
    }
    HR_val=60000*4/HR_val; 
    if(fabs(HR_Hysteresis-HR_val)>HR_Hysteresis_width){
        HR_Hysteresis=int(HR_val+0.5);
    }
    }

    return pulseValue;
 }

int PulseOxySampler::ConvertSaturationValue(int saturationValue)
{
    //bla bla conversie
    void CalcSpO2()
    {
    R=(beta_MinMax[1][1]/beta_MinMax[0][1]-1)/(beta_MinMax[1][0]/beta_MinMax[0][0]-1);
    SpO2_arr[countHR%4]=0.3557*R*R*R-5.1864*R*R-18.342*R+108.381;
    SpO2_val=0;
    for(byte i=0;i<4;++i){
    SpO2_val+=SpO2_arr[i]; 
    }
    SpO2_val/=4;
    if(fabs(SpO2_Hysteresis-SpO2_val)>SpO2_Hysteresis_width){
        SpO2_Hysteresis=int(SpO2_val+0.5);
    }
    }

    return saturationValue;
}