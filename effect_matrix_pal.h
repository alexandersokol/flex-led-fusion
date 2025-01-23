#ifndef EFFECT_MATRIX_PAL_H
#define EFFECT_MATRIX_PAL_H

#include "effects.h"
#include "utilities.h"

/* Usage - matrix_pal();

    This is one of the few routines I have with pixel counting.


   currentPalette, targetPalette
   effectThisRotation
   effectThisIndex
   effectBackgroundColor
   effectBackgroundBrightness
   effectThisDirection
   thisbright
*/

void matrix_pal() {                                           // One line matrix

  if (effectThisRotation) effectThisIndex++;                                   // Increase palette index to change colours on the fly

  if (ledCount >= 10) {

    if (random8(90) > 80) {
      if (effectThisDirection == -1)
        leds[0] = ColorFromPalette(gCurrentPalette, effectThisIndex, 255, currentBlending);          // Foreground matrix colour
      else
        leds[ledCount - 1] = ColorFromPalette(gCurrentPalette, effectThisIndex, 255, currentBlending);
    } else {
      if (effectThisDirection == -1)
        leds[0] = CHSV(effectBackgroundColor, 255, effectBackgroundBrightness);                                                        // Background colour
      else
        leds[ledCount - 1] = CHSV(effectBackgroundColor, 255, effectBackgroundBrightness);
    }

    uintl i;

    if (effectThisDirection == -1) {                                                                              // Move the foreground colour down the line.
      for (i = ledCount - 1; i > 0 ; i-- ) leds[i] = leds[i - 1];
    } else {
      for (i = 0; i < ledCount - 1 ; i++ ) leds[i] = leds[i + 1];
    }
  }
} // matrix_pal()

#endif // EFFECT_MATRIX_PAL_H
