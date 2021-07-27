#ifndef __MEASURINGSTATE_H__
#define __MEASURINGSTATE_H__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"
#include "PulseOxyFunctions.h"

class MeasuringState : public BaseState
{
    private:
    /* data */
    public:
    MeasuringState();
    byte HandleCommand(byte command);
    void Measure()
    {
        int* pulseAndSat = _pulseOxySampler.MeasureValues();
        //aici se pune void loop????? 
    
        void loop() {
         GetTimeMeasurement();
         if(Tmi[0]< Tmi_min || Tmi[1]< Tmi_min || Tmi[0] > Tmi_max || Tmi[1] > Tmi_max){ 
             //daca nu are deget? 
         }
        else{
        countRangeOver=0;
        Calcbeta(); 
        bool isPeriod = CheckdTmPeriod();
        if(isPeriod == 1){
        calcHR();//PULSEOXYSAMPLER
        CalcSpO2();//PULSEOXYSAMPLER
        ++countHR;
        ResetMinMax();
        }
        PrintData(); // modificam in serial.print?
        ++count;
    }
    }
        _dataLayer.AddPulseAndSat(pulseAndSat);   //dupa fiecare masuratoare returneaza un array
    }
};

MeasuringState::MeasuringState(/* args */)
{
}

byte MeasuringState::HandleCommand(byte command)
{
    byte returnValue = MeasuringStateIndex;

    if (command == StopMeasurementCommand)
    {
        returnValue = ReviewStateIndex;
    }
    else //ce comanda ar fi aici? trece de o limita si trece singur in error??
    {
        returnValue = ErrorStateIndex;
    }
    
    return returnValue;

    
}

#endif