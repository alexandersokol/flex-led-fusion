#ifndef EFFECT_ONE_SIN_PAL_H
#define EFFECT_ONE_SIN_PAL_H

#include "effects.h"
#include "utilities.h"

/*
  One sin effect.
  From Notamesh LED effects.
  Usage - one_sin_pal();
    effectAllFrequency - What is the frequency
    effectBackgroundBrightness - The background brightness
    effectBackgroundColor - The background colour
    effectStartIndex  - What foreground colour are we starting with?
    effectThisCutOff - If the brightness is lower than this, then brightness=0
    effectThisSinc - incrementer to change the starting colour after each pass
    effectThisIndex - rotating colours down the strip counter
    effectThisPhase - the counter used in conjunction with the frequency to move down the strip
    effectThisRotation - How quickly to rotate those colours down the strip
    effectThisDirection - Direction.
*/
void one_sin_pal() {
  effectStartIndex += effectThisSinc;
  effectThisIndex = effectStartIndex;
  effectThisPhase += effectThisDirection;

  if (ledCount >= 10) {
    for (uintl k = 0; k < ledCount; k++) {
      int thisBright = qsubd(cubicwave8((k * effectAllFrequency) + effectThisPhase), effectThisCutOff);
      leds[k] = CHSV(effectBackgroundColor, 255, effectBackgroundBrightness);
      leds[k] += ColorFromPalette(gCurrentPalette, effectThisIndex + k * effectThisSinc, thisBright, currentBlending);
      effectThisIndex += effectThisRotation;
    }
  }
} // one_sin()

#endif // EFFECT_ONE_SIN_PAL_H
