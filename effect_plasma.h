#ifndef EFFECT_PLASMA_H
#define EFFECT_PLASMA_H

#include "effects.h"
#include "utilities.h"

/*
  Plasma effect.
  From Notamesh LED effects.
  Usage - plasma(freq1, freq2, phase1, phase2);
*/
void plasma(uint8_t freq1, uint8_t freq2, int8_t phase1, int8_t phase2) {

  int thisPhase = beatsin8(phase1, -64, 64);
  int thatPhase = beatsin8(phase2, -64, 64);

  uintl k;

  if (ledCount >= 10) {

    for (k = 0; k < ledCount; k++) {
      int colorIndex = cubicwave8((k * freq1) + thisPhase) / 2 + cos8((k * freq2) + thatPhase) / 2;
      int thisBright = qsuba(colorIndex, beatsin8(7, 0, 96));
      leds[k] = ColorFromPalette(gCurrentPalette, colorIndex, thisBright, currentBlending);
    }
  }
} // plasma()

#endif // EFFECT_PLASMA_H