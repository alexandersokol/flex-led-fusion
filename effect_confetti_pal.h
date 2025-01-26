#ifndef EFFECT_CONFETTI_PAL_H
#define EFFECT_CONFETTI_PAL_H

#include "effects.h"
#include "utilities.h"

/* 
  This is adapted from the confetti routine created by Mark Kriegsman.
  From Notamesh LED effects.
  Random colored speckles that blink in and fade smoothly.
  Usage: confetti_pal();
    effectThisFade
    currentPalette and targetPalette
    effectThisDiff
    effectThisIndex
    effectThisSinc
*/
void confetti_pal() {
  if (ledCount >= 10) {
    fadeToBlackBy(leds, ledCount, effectThisFade);
    uintl pos = randoml(ledCount);
    leds[pos] = ColorFromPalette(gCurrentPalette, effectThisIndex + random8(effectThisDiff) / 4 , 255, currentBlending);
    effectThisIndex = effectThisIndex + effectThisSinc;
  }
} // confetti_pal()

#endif // EFFECT_CONFETTI_PAL_H
