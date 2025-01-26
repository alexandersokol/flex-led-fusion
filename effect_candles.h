#ifndef EFFECT_CANDLES_H
#define EFFECT_CANDLES_H

/*
  Candles effect.
  From AlexGyver repo.
  Usage: candles();
*/
void candles() {
  if (ledCount >= 10) {

    uintl x;

    for (x = 0; x < ledCount; x++)
    {
      uint8_t flicker = random8(1, 80);
      leds[x] = CRGB(255 - flicker * 2, 150 - flicker, flicker / 2);
    }
  }
} // candles()

#endif // EFFECT_CANDLES_H
