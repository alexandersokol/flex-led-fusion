#ifndef EFFECT_NOISE8_PAL_H
#define EFFECT_NOISE8_PAL_H

#include "effects.h"
#include "utilities.h"

/*
  Noise8 effect.
  This is adapted from a routine created by Mark Kriegsman.
  From Notamesh LED effects.
  Usage - noise8();
    effectThisDirection
*/

uint16_t dist = 12345;       // A random number for our noise generator.
uint8_t scale = 30;          // Wouldn't recommend changing this on the fly, or the animation will be really blocky.

void noise8_pal() {

  uintl i;
  if (ledCount >= 10) {
    for ( i = 0; i < ledCount; i++) {
      uint8_t index = inoise8(i * scale, dist + i * scale) % 255;
      leds[i] = ColorFromPalette(gCurrentPalette, index, 255, currentBlending);
    }
    dist += beatsin8(10, 1, 4) * effectThisDirection;
  }
} // noise8_pal()

#endif // EFFECT_NOISE8_PAL_H
