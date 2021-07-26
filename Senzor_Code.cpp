/*
Copyright (C) 2020 piONE.jp
https://pione.jp/products/PulseOximeter/

POM_v0_1_1.ino
DIY Pulse Oximeter Basic Program
Version 0.1.1

This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
For medical and commercial use, please follow your local laws.
*/

//***Devices***//
//Circuit parameter 
//cred ca trebe
#define CRus 100000 //Time constant[us] of Ct1Rt1
//CRus se calculeaza din Ct1*Rt1*10^6 

//IO pins  nu trebe la noi
//#define BZ 5
//#define SW2 6
//#define SW1 7
//#define PD 8
//#define Charge 9
//#define IRLED 10
//#define REDLED 11

//Maximum number of Tm(time measurement) measurements
// #define MeasureN 16384    //14bit

// //Tm moving average n
// #define TmMAN 3 //1 to 4
// #define CommercialPowerSourceFreq 50  //50 or 60

// //Hysteresis width
// #define SpO2_Hysteresis_width 1
// #define HR_Hysteresis_width 2


// word T_HR_arr[4]; // unsigned? 
// float HR_val;  //ActualPulse
// byte HR_Hysteresis;
// float R;     // ce e asta?
 
// float SpO2_arr[4];
// float SpO2_val; //ActualSaturation
// byte SpO2_Hysteresis;
// unsigned long count=0;      //Count of measurements
// unsigned long countHR=0;    //Count of heart beat
// word countAfterPeriod=0;    //unsigned?
// byte countRangeOver;
// unsigned long Tmi[2];
// float Tm[5][2];
// float Tm_prev;
// float dTm[8];
// float dTm8_ave;
// byte color=0; //0:IR 1:RED
// unsigned long TmStart;
// unsigned long PeakTime[2];
// float beta[2];         //Transmission coefficient
// float beta_history[32][2];  //Hystory of the Transmission coefficient 
// float beta_Ave[2]; // Average Transmission coefficient
// float beta_MinMax[2][2]; //[Min or Max][IR or Red]
// boolean Period;
// char StrBuff16[17];
// byte mode=0;
// unsigned long MeasPeriod=1e6/CommercialPowerSourceFreq; //us
// unsigned long StartTime;
// word Tmi_min=MeasureN*0.05; // unsigned
// word Tmi_max=MeasureN*0.95; //unsigned 

//void setup() {
//  InitialDevices();
//  ResetMinMax();
//  PrintStart();
//  CheckConfigure();
//  PrintFormat();  
//}

// am pus

// void loop() {
//   GetTm();
//   if(Tmi[0]< Tmi_min || Tmi[1]< Tmi_min || Tmi[0] > Tmi_max || Tmi[1] > Tmi_max){ //Tm Range Over

//     }
//   else{
//     countRangeOver=0;
//     Calcbeta(); 
//     CheckdTmPeriod();
//     if(Period==1){
//       CalcHR();
//       CalcSpO2();
//       ++countHR;
//       ResetMinMax();
//     }
//     PrintData(); // modificam
//     ++count;
//   }
// }



//////***Device function***//////
// void LEDState(byte State){
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

void InitialDevices(){
  Serial.begin(38400); 
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, CharHeart);
  pinMode( BZ, OUTPUT );
  pinMode( IRLED, OUTPUT );
  pinMode( REDLED, OUTPUT );
  pinMode( Charge, OUTPUT );
  pinMode( SW1, INPUT_PULLUP);
  pinMode( SW2, INPUT_PULLUP);  
  pinMode( PD, INPUT);  
  digitalWrite(BZ,0);
  LEDState(2);
}
// micros provine din libraria asta ==> LiquidCrystal_I2C.h, dar cred ca ne va trebui alta
// void GetTm(){
//   Tm_prev=Tm[4][0];
//   for(color=0;color<2;++color){
//     WaitPeriod();
//     LEDState(color);
//     TmStart=micros();
//     for(Tmi[color]=0;Tmi[color]<MeasureN;++Tmi[color]){
//       if((PINB & 1)==1){      
//         Tm[count%TmMAN][color]=micros()-TmStart;  
//         break;  
//       }   
//     }
//     LEDState(2);//discharge
//     Tm[4][color]=0;
//     for(byte i=0;i<TmMAN;++i){
//       Tm[4][color]+=Tm[i][color];
//     }
//     Tm[4][color]/=TmMAN;    
//   }
// }

void WaitPeriod(){
  if(KillHumNoize==1){
    if(color==0){
      while(1){
        if(micros()%MeasPeriod<100){ //De aflat cât timp e de fapt
          break;
        }
      }
    }
    else if(color==1){
      while(1){
        if(micros()%MeasPeriod>MeasPeriod*0.3){
          break;
        }
      }
    }
  }
  else{
    delay(1);  
  }
}

//////***Calculate function***//////
// void ResetMinMax(){
//   for(byte i=0;i<2;++i){
//     beta_MinMax[0][i]=1e6;
//     beta_MinMax[1][i]=-1e6;
//   }  
// }

// void Calcbeta(){
//   for(color=0;color<2;++color){
//     beta[color]=1/(1-exp(-Tm[4][color]/CRus));      //Calculate beta aka Transmission coefficient
//     if(beta[color] > beta_MinMax[1][color]){
//       beta_MinMax[1][color]=beta[color];
//     }
//     if(beta[color] < beta_MinMax[0][color]){
//       beta_MinMax[0][color]=beta[color];
//     }    
//   }
//   if(count%2==0){
//     for(byte j=0;j<2;++j){
//       beta_history[count/2%32][j]=beta[j];
//       beta_Ave[j]=0;
//       for(byte i=0;i<32;++i){
//         beta_Ave[j]+=beta_history[i][j];
//       }
//       beta_Ave[j]/=32;
//     }
//   }
// }

// in pulseoxysampler am pus astea 


// void CalcHR(){
//   T_HR_arr[countHR%4]=(PeakTime[0]-PeakTime[1]) & 0xFFFF;
//   HR_val=0;
//   for(byte i=0;i<4;++i){
//    HR_val+=T_HR_arr[i]; 
//   }
//   HR_val=60000*4/HR_val;
//   if(fabs(HR_Hysteresis-HR_val)>HR_Hysteresis_width){
//     HR_Hysteresis=int(HR_val+0.5);
//   }
// }

// void CalcSpO2(){
//   R=(beta_MinMax[1][1]/beta_MinMax[0][1]-1)/(beta_MinMax[1][0]/beta_MinMax[0][0]-1);
//   SpO2_arr[countHR%4]=0.3557*R*R*R-5.1864*R*R-18.342*R+108.381;
//   SpO2_val=0;
//   for(byte i=0;i<4;++i){
//    SpO2_val+=SpO2_arr[i]; 
//   }
//   SpO2_val/=4;
//   if(fabs(SpO2_Hysteresis-SpO2_val)>SpO2_Hysteresis_width){
//     SpO2_Hysteresis=int(SpO2_val+0.5);
//   }
// }

// void CheckdTmPeriod(){
//   Period=0;
//   dTm[count%8]=Tm_prev-Tm[4][0];
//   dTm8_ave=0;
//   for(byte i=0;i<8;++i){
//     dTm8_ave+=dTm[i];
//   }
//   dTm8_ave=dTm8_ave/8;
//   if(dTm8_ave<0 && countAfterPeriod>5){   //period
//     PeakTime[1]=PeakTime[0];
//     PeakTime[0]=millis();
//     Period=1;
//     countAfterPeriod=0;
//   }
//   else if(dTm8_ave>0){
//     ++countAfterPeriod;
//   }
// }
