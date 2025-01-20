#ifndef EFFECT_RAINBOW_BEAT_H
#define EFFECT_RAINBOW_BEAT_H

// Usage - rainbow_beat();

void rainbow_beat() {                                         // The fill_rainbow call doesn't support brightness levels
  if (ledCount >= 10) {
    uint8_t beatA = beatsin8(17, 0, 255);                        // Starting hue
    uint8_t beatB = beatsin8(13, 0, 255);
    fill_rainbow(leds, ledCount, (beatA + beatB) / 2, 8);        // Use FastLED's fill_rainbow routine.
  }
} // rainbow_beat()

#endif // EFFECT_RAINBOW_BEAT_H
