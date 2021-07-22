#ifndef __MEASURINGSTATE_H__
#define __MEASURINGSTATE_H__

#include "BaseState.h"
#include "Commands.h"
#include "Constants.h"

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
        _dataLayer.AddPulseAndSat(pulseAndSat);
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
    else //ce comanda ar fi aici?
    {
        returnValue = ErrorStateIndex;
    }
    
    return returnValue;

    
}

#endif