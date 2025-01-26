#ifndef EFFECT_JUGGLE_PAL_H
#define EFFECT_JUGGLE_PAL_H

#include "effects.h"

/*
  Juggle effect. Several colored dots, weaving in and out of sync with each other.
  This is adapted from a routine created by Mark Kriegsman
  From Notamesh LED effects.
  Usage - juggle_pal();
    numDots
    effectThisFade
    effectThisBeat
    effectThisDiff
*/

uint8_t numDots;

void juggle_pal() {
  if (ledCount >= 10) {
    effectThisIndex = 0;
    fadeToBlackBy(leds, ledCount, effectThisFade);
    for (uint8_t i = 0; i < numDots; i++) {
      leds[beatsin16(effectThisBeat + i + numDots, 0, ledCount - 1)] += ColorFromPalette(gCurrentPalette, effectThisIndex , 255, currentBlending); // Munge the values and pick a colour from the palette
      effectThisIndex += effectThisDiff;
    }
  }
} // juggle_pal()

#endif // EFFECT_JUGGLE_PAL_H
