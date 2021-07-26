#ifndef __PULSEOXYFUNCTIONS_H__
#define __PULSEOXYFUNCTIONS_H__

#include "NumericalConstants.h"

//pin define

// global variables???

word T_HR_arr[4]; // Heart Rate Array 
float HR_val;  //ActualPulse
byte HR_Hysteresis; //Pulse with Hysteresis
float R;      // Resistor
float SpO2_arr[4]; //Spo2 Array
float SpO2_val; //Actual Saturation
byte SpO2_Hysteresis; //Saturation with Hysteresis
unsigned long count=0;      //Count of measurements
unsigned long countHR=0;    //Count of heart beat
word countAfterPeriod=0;    //unsigned?
byte countRangeOver;      //cand sa fie in range
unsigned long Tmi[2];      //Time measurement index???
float TimeMeasurement[5][2];     //Time measurement
float Previous_TimeMeasurement;      //Previous Time measurement
float Delta_TimeMeasurement[8];   // Array cu delta Time measurement 
float Average_TimeMeasurement;   //Average of the 8 delta TM
byte color=0;       //0:IR 1:RED
unsigned long TimeMeasurementStart;      //The start of the time measurement
unsigned long PeakTime[2];      //??
float beta[2];         //Transmission coefficient
float beta_history[32][2];  //History of the Transmission coefficient 
float Average_beta[2];      // Average Transmission coefficient
float beta_MinMax[2][2]; //[Min or Max][IR or Red]
//boolean Period; cred ca nu trebe aici

//byte mode=0;

unsigned long MeasurePeriod=1e6/CommercialPowerSourceFreq; //microsecunde
unsigned long StartTime; //okay?
word Tmi_min= MaximumMeasurements*0.05;
word Tmi_max=MaximumMeasurements*0.95;







#endif