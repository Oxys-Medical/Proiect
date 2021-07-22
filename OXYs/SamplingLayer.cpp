#include "SamplingLayer.h"
#include "Constants.h"
#include <Arduino.h>

SamplingLayer::SamplingLayer()
{
    pinMode(AnalogReadPin, INPUT);
}

int SamplingLayer::Read()
{
    int readValue = analogRead(AnalogReadPin);
    return readValue;
}

// UiElement
//{
//  privcate:
//  HZ976235872465912465 _adafrtuiDisplay;
//  public:
//  ElementType Type;
//  int x
//  int Y
//  void Update();
//  void Animate();
//  
//}
//
//TextField:UiElement
//{
//  public:
//  TextField(HX982365 adaDisplay, &long cenepeAddress);
//  void Update();
//  void Animate();
//}
//
//Update()
//{
//  long cenepe = *cenepeAddress;
//  -adadispl.SetCursot(this-X,this->y);
//  adadisply.drawrect(negru)
//  adasipy.println(cenepe);
//}
//}
