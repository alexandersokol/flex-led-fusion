#ifndef UTILITIES_H
#define UTILITIES_H

#if MAX_LEDS < 255
  #define UINT_LED uint8_t
#else 
  #define UINT_LED uint16_t
#endif

#if MAX_LEDS < 255
  #define RANDOM_LED(...) random8(__VA_ARGS__)
#else
  #define RANDOM_LED(...) random16(__VA_ARGS__)
#endif

#if MAX_LEDS < 255
  #define BEATSIN_LED(...) beatsin8(__VA_ARGS__)
#else
  #define BEATSIN_LED(...) beatsin16(__VA_ARGS__)
#endif

#endif // UTILITIES_H
