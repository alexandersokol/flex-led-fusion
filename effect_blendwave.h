#ifndef EFFECT_BLENDWARE_H
#define EFFECT_BLENDWARE_H

#include "utilities.h"

void blendwave() {
  CRGB clr1;
  CRGB clr2;
  uint8_t speed;
  uint8_t loc1;

  if (ledCount >= 10) {

    speed = beatsin8(6, 0, 255);

    clr1 = blend(CHSV(beatsin8(3, 0, 255), 255, 255), CHSV(beatsin8(4, 0, 255), 255, 255), speed);
    clr2 = blend(CHSV(beatsin8(4, 0, 255), 255, 255), CHSV(beatsin8(3, 0, 255), 255, 255), speed);

    loc1 = beatsinl(10, 0, ledCount - 1);

    fill_gradient_RGB(leds, 0, clr2, loc1, clr1);
    fill_gradient_RGB(leds, loc1, clr2, ledCount - 1, clr1);
  }
}

#endif // EFFECT_BLENDWARE_H
