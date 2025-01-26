#ifndef TWO_SIN_H
#define TWO_SIN_H

#include "effects.h"
#include "utilities.h"

/* 
  Two sin effect.
  From Notamesh LED effects.
  Usage: two_sin();
    effectThisPhase
    effectThisDirection
    effectThisHue
    effectThisRotation
    effectThisCutOff
    effectAllFrequency
*/

uint8_t thatHue = 140;          // You can change the starting hue for other wave.
uint8_t thatRotation = 0;       // You can change how quickly the hue rotates for the other wave. Currently 0.
int8_t thatSpeed = 4;           // You can change the speed, and use negative values.
int thatPhase = 0;              // Phase change value gets calculated.
uint8_t thatCutOff = 192;       // You can change the cutoff value to display that wave. Lower value = longer wave.

void two_sin() {
  if (ledCount >= 10) {
    effectThisPhase += effectThisSpeed * effectThisDirection;
    thatPhase += thatSpeed * effectThisDirection;

    effectThisHue = effectThisHue + effectThisRotation;
    thatHue = thatHue + thatRotation;

    uintl k;

    for (k = 0; k < ledCount; k++) {
      int thisbright = qsuba(cubicwave8((k * effectAllFrequency) + effectThisPhase), effectThisCutOff);
      int thatbright = qsuba(cubicwave8((k * effectAllFrequency) + 128 + thatPhase), thatCutOff);

      leds[k] = ColorFromPalette(gCurrentPalette, effectThisHue, thisbright, currentBlending);
      leds[k] += ColorFromPalette(gCurrentPalette, thatHue, thatbright, currentBlending);
    }
  }
} // two_sin()

#endif
