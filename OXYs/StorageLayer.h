#ifndef __STORAGELAYER_H__
#define __STORAGELAYER_H__

class StorageLayer
{
    private:
    void SetupSDCard() // see more https://learn.sparkfun.com/tutorials/microsd-shield-and-sd-breakout-hookup-guide

    public:
    StorageLayer();

    // vor scrie datele pe cardul SD?
    void AddPatientData(long CNP);
    void AddMeasurement(int actualPulse, int actualSaturation, string currentDataTime);
    FetchPatientData(); //ce alegem sa returneze
};

#endif