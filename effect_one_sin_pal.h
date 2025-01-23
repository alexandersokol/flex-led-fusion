#ifndef EFFECT_ONE_SIN_PAL_H
#define EFFECT_ONE_SIN_PAL_H

#include "effects.h"
#include "utilities.h"

/* There's lots of values to play with here, as well as selecting your own palettes

*/

/*
   Usage - one_sin_pal();

   effectAllFrequency - What is the frequency
   effectBackgroundBrightness - The background brightness
   effectBackgroundColor - The background colour
   effectStartIndex  - What foreground colour are we starting with?
   thisbright - How bright is it?
   effectThisCutOff - If the brightness is lower than this, then brightness=0
   effectThisSinc - incrementer to change the starting colour after each pass
   effectThisIndex - rotating colours down the strip counter
   effectThisPhase - the counter used in conjunction with the frequency to move down the strip
   effectThisRotation - How quickly to rotate those colours down the strip
   thisspeed  - How fast does it whip down the strand
   effectThisDirection - Direction.
*/

void one_sin_pal() {
  effectStartIndex += effectThisSinc;
  effectThisIndex = effectStartIndex;
  effectThisPhase += effectThisDirection;                                                                       // You can change direction and speed individually.

  if (ledCount >= 10) {
    for (uintl k = 0; k < ledCount; k++) {                                                         // For each of the LED's in the strand, set a brightness based on a wave as follows:
      int thisbright = qsubd(cubicwave8((k * effectAllFrequency) + effectThisPhase), effectThisCutOff);                // qsub sets a minimum value called thiscutoff. If < thiscutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
      leds[k] = CHSV(effectBackgroundColor, 255, effectBackgroundBrightness);                                                        // First set a background colour, but fully saturated.
      leds[k] += ColorFromPalette(gCurrentPalette, effectThisIndex + k * effectThisSinc, thisbright, currentBlending);
      effectThisIndex += effectThisRotation;
    }
  }
} // one_sin()

#endif // EFFECT_ONE_SIN_PAL_H
