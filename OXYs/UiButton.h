#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#include <Arduino.h>
#include "UiElement.h"
#include "DisplayDriver.h"

/// A simple drawn button UI element
class UiButton : UiElement {

public:
  UiButton(void);
  // "Classic" initButton() uses center & size
  void initButton(DisplayDriver displayDriver, int16_t x, int16_t y, uint16_t w,
                  uint16_t h, uint16_t outline, uint16_t fill,
                  uint16_t textcolor, char *label, uint8_t textsize);
  void initButton(DisplayDriver displayDriver, int16_t x, int16_t y, uint16_t w,
                  uint16_t h, uint16_t outline, uint16_t fill,
                  uint16_t textcolor, char *label, uint8_t textsize_x,
                  uint8_t textsize_y);
  void drawButton(bool inverted = false);
  bool contains(int16_t x, int16_t y);

  /**********************************************************************/
  /*!
    @brief    Sets button state, should be done by some touch function
    @param    p  True for pressed, false for not.
  */
  /**********************************************************************/
  void press(bool p) {
    laststate = currstate;
    currstate = p;
  }

  bool justPressed();
  bool justReleased();

  /**********************************************************************/
  /*!
    @brief    Query whether the button is currently pressed
    @returns  True if pressed
  */
  /**********************************************************************/
  bool isPressed(void) { return currstate; };

private:
  DisplayDriver displayDriver;
  int16_t _x1, _y1; // Coordinates of top-left corner
  uint16_t _w, _h;
  uint8_t _textsize_x;
  uint8_t _textsize_y;
  uint16_t _outlinecolor, _fillcolor, _textcolor;
  char _label[10];
  comanda
  textul de pe button

  bool currstate, laststate;
};

byte UiButton::HandleContactPoint(int* contactPoint)
{
  if x intre margini și y intre marginile butonului
  {
    return _comanda primita in constructor
  }
  else
  {
    return NoCommand;
  }
}

#endif