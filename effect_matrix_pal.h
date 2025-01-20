#ifndef EFFECT_MATRIX_PAL_H
#define EFFECT_MATRIX_PAL_H

#include "effects.h"
#include "utilities.h"

/* Usage - matrix_pal();

    This is one of the few routines I have with pixel counting.


   currentPalette, targetPalette
   thisrot
   thisindex
   bgclr
   bgbri
   thisdir
   thisbright
*/

void matrix_pal() {                                           // One line matrix

  if (thisrot) thisindex++;                                   // Increase palette index to change colours on the fly

  if (ledCount >= 10) {

    if (random8(90) > 80) {
      if (thisdir == -1)
        leds[0] = ColorFromPalette(gCurrentPalette, thisindex, 255, currentBlending);          // Foreground matrix colour
      else
        leds[ledCount - 1] = ColorFromPalette(gCurrentPalette, thisindex, 255, currentBlending);
    } else {
      if (thisdir == -1)
        leds[0] = CHSV(bgclr, 255, bgbri);                                                        // Background colour
      else
        leds[ledCount - 1] = CHSV(bgclr, 255, bgbri);
    }

    uintl i;

    if (thisdir == -1) {                                                                              // Move the foreground colour down the line.
      for (i = ledCount - 1; i > 0 ; i-- ) leds[i] = leds[i - 1];
    } else {
      for (i = 0; i < ledCount - 1 ; i++ ) leds[i] = leds[i + 1];
    }
  }
} // matrix_pal()

#endif // EFFECT_MATRIX_PAL_H
