#ifndef EFFECT_CONFETTI_PAL_H
#define EFFECT_CONFETTI_PAL_H

#include "effects.h"
#include "utilities.h"

/* This is adapted from the confetti routine created by Mark Kriegsman */

/*  Usage - confetti_pal();

    thisfade
    thisdelay
    currentPalette and targetPalette
    thisdiff
    thisindex
    thisinc
    thisbright
*/

void confetti_pal() {                                                                                               // random colored speckles that blink in and fade smoothly
  if (ledCount >= 10) {
    fadeToBlackBy(leds, ledCount, thisfade);        //Задухание светодиодов на значение thisfade
    uintl pos = randoml(ledCount);
    leds[pos] = ColorFromPalette(gCurrentPalette, thisindex + random8(thisdiff) / 4 , 255, currentBlending);   // Munge the values and pick a colour from the palette
    thisindex = thisindex + thisinc;                                                                                  // base palette counter increments here.
  }
} // confetti_pal()

#endif // EFFECT_CONFETTI_PAL_H
