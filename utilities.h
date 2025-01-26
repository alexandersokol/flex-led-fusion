#ifndef UTILITIES_H
#define UTILITIES_H

#define qsubd(x, b) ((x > b) ? 255 : 0)
#define qsuba(x, b) ((x > b) ? x - b : 0)

#if MAX_LEDS < 255
  #define uintl uint8_t
#else 
  #define uintl uint16_t
#endif

#if MAX_LEDS < 255
  #define randoml(...) random8(__VA_ARGS__)
#else
  #define randoml(...) random16(__VA_ARGS__)
#endif

#if MAX_LEDS < 255
  #define beatsinl(...) beatsin8(__VA_ARGS__)
#else
  #define beatsinl(...) beatsin16(__VA_ARGS__)
#endif

#endif // UTILITIES_H
