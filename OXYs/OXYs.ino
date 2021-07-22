#include "ViewController.h"

ViewController _viewController;
unsigned long _previousMillis;

void setup() 
{
  // put your setup code here, to run once:
  _previousMillis = 0;
  _viewController = ViewController();
}

void loop() 
{
  if (millis() - _previousMillis >= CycleTime)
  {
    _previousMillis = millis();
    _viewController.HandleCommand();
  }
}