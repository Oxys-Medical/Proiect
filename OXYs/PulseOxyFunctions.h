#ifndef __PULSEOXYFUNCTIONS_H__
#define __PULSEOXYFUNCTIONS_H__

#include "NumericalConstants.h"

//pin define

// global variables???

word HeartRateArray[4]; 
float ActualPulse;  
byte HR_Hysteresis; //Pulse with Hysteresis
float R;      // from Formula (AC/DC (1)/AC/DC (2))
float SpO2Array[4]; 
float ActualSaturation; 
byte SpO2_Hysteresis; //Saturation with Hysteresis
unsigned long count=0;      //Count of measurements
unsigned long countHR=0;    //Count of heart beat
word countAfterPeriod=0;    //unsigned?
byte countRangeOver;      //cand sa fie in range
unsigned long Tmi[2];      //Time measurement index???
float TimeMeasurement[5][2];     //Time measurement
float Previous_TimeMeasurement;      //Previous Time measurement
float Delta_TimeMeasurement[8];   // Array cu delta Time measurement 
float Average_DeltaTimeMeasurement;   //Average of the 8 delta TM
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


//functie GetTm

void LEDState(byte State){
  if(State==0){//IR On and charge
    digitalWrite(IRLED,0); //functii trebe cautate? 
    digitalWrite(Charge,0);
  }
  else if(State==1){//RED On and charge
    digitalWrite(REDLED,0);
    digitalWrite(Charge,0);
  }
  else if(State==2){ //LED Off and discharge
    digitalWrite(REDLED,1);
    digitalWrite(IRLED,1);
    digitalWrite(Charge,1);
  }
}

void GetTimeMeasurement(){
  Previous_TimeMeasurement = TimeMeasurement[4][0];
  for( color = 0; color < 2; ++color ){
    //WaitPeriod();
    LEDState(color);
    TimeMeasurementStart=micros(); //librarie?
    for( Tmi[color] = 0; Tmi[color] < MaximumMeasurements; ++Tmi[color] ){
      if((PINB & 1) == 1){      
        TimeMeasurement[count%TimeMeasurementMovingAverage][color]=micros()-TimeMeasurementStart;  
        break;  
      }   
    }
    LEDState(2);//discharge
    TimeMeasurement[4][color]=0;
    for(byte i = 0; i < TimeMeasurementMovingAverage;++i){
      TimeMeasurement[4][color]+= TimeMeasurement[i][color];
    }
    TimeMeasurement[4][color]/= TimeMeasurementMovingAverage;    
  }
}

//functie BETA

void ResetMinMax(){
  for(byte i=0;i<2;++i){
    beta_MinMax[0][i]=1e6;
    beta_MinMax[1][i]=-1e6;
  }  
}

void Calcbeta(){
  for(color = 0; color < 2; ++color){
    beta[color]=1/(1-exp(-TimeMeasurement[4][color]/TimeConstant));      //Calculate beta aka Transmission coefficient
    if(beta[color] > beta_MinMax[1][color]){
      beta_MinMax[1][color]=beta[color];
    }
    if(beta[color] < beta_MinMax[0][color]){
      beta_MinMax[0][color]=beta[color];
    }    
  }
  if(count%2 == 0){
    for(byte j=0; j<2; ++j){
      beta_history[count/2%32][j]=beta[j];
      Average_beta[j]=0;
      for(byte i = 0; i < 32; ++i){
        Average_beta[j]+=beta_history[i][j];
      }
      Average_beta[j]/=32;
    }
  }
}

bool CheckdTmPeriod(){
  bool isPeriod=0;
  Delta_TimeMeasurement[count%8]=Previous_TimeMeasurement-TimeMeasurement[4][0];
  Average_DeltaTimeMeasurement=0;
  for(byte i = 0; i < 8; ++i){
    Average_DeltaTimeMeasurement+=Delta_TimeMeasurement[i];
  }
  Average_DeltaTimeMeasurement = Average_DeltaTimeMeasurement/8;
  if(Average_DeltaTimeMeasurement < 0 && countAfterPeriod > 5){   //period
    PeakTime[1]=PeakTime[0];
    PeakTime[0]=millis();
    isPeriod=1;
    countAfterPeriod=0;
  }
  else if(Average_DeltaTimeMeasurement > 0){
    ++countAfterPeriod;
  }
  return isPeriod;
}




#endif