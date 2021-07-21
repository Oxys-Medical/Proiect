#ifndef __TEXTFIELD_H__
#define __TEXTFIELD_H__

#include <Arduino.h>
#include "UiElement.h"

class TextField : public UiElement
{
  public:
  TextField( Adafruit_HX8357 _adafruitDisplay, &long CNPAddress);
  void Update();
  void Animate();


};

 void UiElement::Update()
 {
     long CNP = *CNPAddress;
     _adafruitDisplay.setCursor(this->x, this->y);
     _adafruitDisplay.drawRect(this->x, this->y, this->Width, this->Height, HX8357_BLACK);

 };

#endif
