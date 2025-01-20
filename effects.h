#ifndef EFFECTS_H
#define EFFECTS_H

#include "FastLED.h"
#include "utilities.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

UINT_LED ledCount = MAX_LEDS;

struct CRGB leds[MAX_LEDS];

uint8_t thisdiff = 1;
uint8_t thisinc = 1;
uint8_t thisfade = 224;
uint8_t thisindex = 0;

CRGBPalette16 gCurrentPalette;

TBlendType currentBlending = LINEARBLEND;

// LEDS.setBrightness(max_bright);
//FastLED.setBrightness(0);

#endif // EFFECTS_H
