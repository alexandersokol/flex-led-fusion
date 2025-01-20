#ifndef EFFECT_RAINBOW_MARCH_H
#define EFFECT_RAINBOW_MARCH_H

/* Usage - rainbow_march();

   thisindex
   thisdiff
   thisrot
   thisdir
*/

void rainbow_march() {                                           // The fill_rainbow call doesn't support brightness levels
  if (ledCount >= 10) {
    thisindex += thisrot * thisdir;
    fill_rainbow(leds, ledCount, thisindex, thisdiff);               // I don't change deltahue on the fly as it's too fast near the end of the strip.
  }
} // rainbow_march()

#endif // EFFECT_RAINBOW_MARCH_H
