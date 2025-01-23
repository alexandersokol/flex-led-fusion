#ifndef EFFECT_RAINBOW_MARCH_H
#define EFFECT_RAINBOW_MARCH_H

#include "effects.h"

/* Usage - rainbow_march();

   effectThisIndex
   effectThisDiff
   effectThisRotation
   effectThisDirection
*/

void rainbow_march() {                                           // The fill_rainbow call doesn't support brightness levels
  if (ledCount >= 10) {
    effectThisIndex += effectThisRotation * effectThisDirection;
    fill_rainbow(leds, ledCount, effectThisIndex, effectThisDiff);               // I don't change deltahue on the fly as it's too fast near the end of the strip.
  }
} // rainbow_march()

#endif // EFFECT_RAINBOW_MARCH_H
