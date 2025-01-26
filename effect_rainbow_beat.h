#ifndef EFFECT_RAINBOW_BEAT_H
#define EFFECT_RAINBOW_BEAT_H

/*
  Rainbow beat effect.
  From Notamesh LED effects.
  Usage: rainbow_beat();
*/
void rainbow_beat() {
  if (ledCount >= 10) {
    uint8_t beatA = beatsin8(17, 0, 255);
    uint8_t beatB = beatsin8(13, 0, 255);
    fill_rainbow(leds, ledCount, (beatA + beatB) / 2, 8);
  }
} // rainbow_beat()

#endif // EFFECT_RAINBOW_BEAT_H
