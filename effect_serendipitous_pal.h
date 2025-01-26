#ifndef EFFECT_SERENDIPITOUS_PAL_H
#define EFFECT_SERENDIPITOUS_PAL_H

#include "effects.h"
#include "utilities.h"

/*
  This is from Serendipitous Circles from the August 1977 and April 1978 issues of Byte Magazine.
   I didn't do a very good job of it, but am at least getting some animation and the routine is very short.
  From Notamesh LED effects.
  Usage - serendipitous_pal();
    effectThisIndex
*/
uint16_t xOrig = 0x013;
uint16_t yOrig = 0x021;
uint16_t X = xOrig;
uint16_t Y = yOrig;
uint16_t xN;
uint16_t yN;

void serendipitous_pal() {
  EVERY_N_SECONDS(5) {
    X = xOrig;
    Y = yOrig;
  }

  xN = X - (Y / 2); yN = Y + (xN / 2);
  //  xN = X-Y/2;   yN = Y+xN/2;
  //  xN = X-(Y/2); yN = Y+(X/2.1);
  //  xN = X-(Y/3); yN = Y+(X/1.5);
  //  xN = X-(2*Y); yN = Y+(X/1.1);

  X = xN;
  Y = yN;
  if (ledCount >= 10) {
    effectThisIndex = (sin8(X) + cos8(Y)) / 2;
    leds[X % (ledCount)] = ColorFromPalette(gCurrentPalette, effectThisIndex, 255, currentBlending);
    fadeToBlackBy(leds, ledCount, 16);  // 8 bit, 1 = slow, 255 = fast
  }
} // serendipitous_pal()

#endif // EFFECT_SERENDIPITOUS_PAL_H
