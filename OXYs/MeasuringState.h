#ifndef __MEASURINGSTATE_H__
#define __MEASURINGSTATE_H__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"
#include "PulseOxyFunctions.h"
#include <Arduino.h>
#include "DataLayer.h"

class MeasuringState : public BaseState
{
private:
    unsigned long _previousMeasurementTime;
    DataLayer _dataLayer;

public:
    MeasuringState(DataLayer dataLayer);
    byte HandleCommand(byte command);
    byte *Measure()
    {
        byte *pulseAndSat = new byte[ArrayLength];
        pulseAndSat[0] = 0;
        pulseAndSat[1] = 0;

        if (millis() - _previousMeasurementTime >= MeasurementTime)
        {
            _previousMeasurementTime = millis();

            //pulseAndSat = _pulseOxySampler.MeasureValues();
            //de aici
            //GetTimeMeasurement();
            //if (Tmi[0] < Tmi_min || Tmi[1] < Tmi_min || Tmi[0] > Tmi_max || Tmi[1] > Tmi_max)
            {
                //daca nu are deget? E foarte bine și așa.
            }
            //else
            {
                //deci cum vom pune pana la urma masuratorile? aici sau mai sus?
                //countRangeOver = 0;
                //Calcbeta();
                //bool isPeriod = CheckdTmPeriod();
                //if (isPeriod == 1)
                {
                    //nu folosim =>
                    //pulseAndSat = _pulseOxySampler.MeasureValues();
                    //in loc de astea?
                    // calcHR();   //PULSEOXYSAMPLER
                    // CalcSpO2(); //PULSEOXYSAMPLER
                    //++countHR;
                    //ResetMinMax();
                }
                //++count;
            }
            //pana aici
            //_dataLayer.AddMeasurement(); //dupa fiecare masuratoare returneaza un array
        }

        return pulseAndSat;
    }
};

MeasuringState::MeasuringState(DataLayer dataLayer)
{
    _dataLayer = dataLayer;
    _previousMeasurementTime = 0;
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