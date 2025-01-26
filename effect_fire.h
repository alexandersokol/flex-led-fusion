#ifndef EFFECT_FIRE_H
#define EFFECT_FIRE_H

#include "effects.h"

/*
  Fire effect.
  From AlexGyver repo.
  Usage: fire();
    effectThisDirection
*/
void fire() {
  if (ledCount >= 10) {

  uintl x = ledCount / 10;
  uintl k1 = random8(x * 2);
  uintl k2 = random8(x * 2) + k1;
  uintl k4 = ledCount - 1;

#if MAX_LEDS < 255
    uint8_t k3 = x * 3 + random8(x * 4);
    if ((k4 - k2) < k3) k3 = k4;
    else k3 = k3 + k2;
#else
    uint16_t k3 = x * 3 + random8(x * 4) + k2;
#endif

    if (effectThisDirection == 1) {
      fill_gradient_RGB(leds, 0,  CRGB::White,  k1,       CRGB::Yellow);
      fill_gradient_RGB(leds, k1, CRGB::Yellow, k2,       CRGB::Red);
      fill_gradient_RGB(leds, k2, CRGB::Red, k3, CRGB::Black);
      if ( k3 < k4) {
        fill_gradient_RGB(leds, k3, CRGB::Black, k4, CRGB::Black);
      }
      for (uint8_t y = 0; y < x; y++) {
        leds[random16(k2, ledCount - 1)] = CRGB::Red;
      }
    }
    else {
      k1 = ledCount - 1 - k1;
      k2 = ledCount - 1 - k2;
      
#if MAX_LEDS < 255
      if ((ledCount - 1) < k3) k3 = 0;
      else  k3 = ledCount - 1 - k3;
#else
      k3 = ledCount - 1 - k3;
#endif

      fill_gradient_RGB(leds, k1,  CRGB::White,  k4, CRGB::Yellow);
      fill_gradient_RGB(leds, k2, CRGB::Yellow, k1, CRGB::Red);
      fill_gradient_RGB(leds, k3, CRGB::Red, k2, CRGB::Black);
      if ( k3 > 0) {
        fill_gradient_RGB(leds, 0, CRGB::Black, k3, CRGB::Black);
      }
      for (uint8_t y = 0; y < x; y++) {
        leds[random16(k2)] = CRGB::Red;
      }
    }
  }

} // fire()

#endif // EFFECT_FIRE_H
