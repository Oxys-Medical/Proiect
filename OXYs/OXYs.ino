#include "ViewController.h"
#include "Arduino.h"
#include "Constants.h"

ViewController _viewController;
unsigned long _previousMillis;

void setup() 
{
  // put your setup code here, to run once:
  _previousMillis = 0;
  _viewController = ViewController();
  Serial.begin(9600);
  Serial.println("Incepem");
}

void loop() 
{
  Serial.println("face treaba"); 
  delay(3000); 
  if (millis() - _previousMillis >= CycleTime)
  {
    _previousMillis = millis();
    _viewController.HandleCommand();
  }
}
