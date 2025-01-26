#ifndef EFFECT_MATRIX_PAL_H
#define EFFECT_MATRIX_PAL_H

#include "effects.h"
#include "utilities.h"

/* One line matrix effect.
  From Notamesh LED effects.
  Usage - matrix_pal();
    gCurrentPalette,
    effectThisRotation
    effectThisIndex
    effectBackgroundColor
    effectBackgroundBrightness
    effectThisDirection
*/

void matrix_pal() {

  if (effectThisRotation) effectThisIndex++;

  if (ledCount >= 10) {

    if (random8(90) > 80) {
      if (effectThisDirection == -1)
        leds[0] = ColorFromPalette(gCurrentPalette, effectThisIndex, 255, currentBlending);
      else
        leds[ledCount - 1] = ColorFromPalette(gCurrentPalette, effectThisIndex, 255, currentBlending);
    } else {
      if (effectThisDirection == -1)
        leds[0] = CHSV(effectBackgroundColor, 255, effectBackgroundBrightness);
      else
        leds[ledCount - 1] = CHSV(effectBackgroundColor, 255, effectBackgroundBrightness);
    }

    uintl i;
    if (effectThisDirection == -1) {
      for (i = ledCount - 1; i > 0 ; i-- ) leds[i] = leds[i - 1];
    } else {
      for (i = 0; i < ledCount - 1 ; i++ ) leds[i] = leds[i + 1];
    }
  }
} // matrix_pal()

#endif // EFFECT_MATRIX_PAL_H
