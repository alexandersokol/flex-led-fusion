#ifndef EFFECT_RAINBOW_MARCH_H
#define EFFECT_RAINBOW_MARCH_H

#include "effects.h"

/* 
  Rainbow march effect.
  From Notamesh LED effects.
  Usage - rainbow_march();
    effectThisIndex
    effectThisDiff
    effectThisRotation
    effectThisDirection
*/
void rainbow_march() {
  if (ledCount >= 10) {
    effectThisIndex += effectThisRotation * effectThisDirection;
    fill_rainbow(leds, ledCount, effectThisIndex, effectThisDiff);
  }
} // rainbow_march()

#endif // EFFECT_RAINBOW_MARCH_H
