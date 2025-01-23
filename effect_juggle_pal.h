#ifndef EFFECT_JUGGLE_PAL_H
#define EFFECT_JUGGLE_PAL_H

#include "effects.h"

/* This is adapted from a routine created by Mark Kriegsman */

/*  Usage - juggle_pal();
    effectThisFade
    numdots
    effectThisBeat
    effectThisDiff
*/

uint8_t numdots;

void juggle_pal() {                                           // Several colored dots, weaving in and out of sync with each other
  if (ledCount >= 10) {
    effectThisIndex = 0;                                              // Reset the hue values.
    fadeToBlackBy(leds, ledCount, effectThisFade);                  //Затухание к черному
    for (uint8_t i = 0; i < numdots; i++) {
      leds[beatsin16(effectThisBeat + i + numdots, 0, ledCount - 1)] += ColorFromPalette(gCurrentPalette, effectThisIndex , 255, currentBlending); // Munge the values and pick a colour from the palette
      effectThisIndex += effectThisDiff;
    }
  }
} // juggle_pal()

#endif // EFFECT_JUGGLE_PAL_H
