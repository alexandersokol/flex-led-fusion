#ifndef EFFECT_NOISE16_PAL_H
#define EFFECT_NOISE16_PAL_H

#include "effects.h"
#include "utilities.h"

/*
  Noise16 effect.
  From Notamesh LED effects.
  Usage: noise16_pal();
    effectThisDirection
*/

uint32_t x, hueTime;                                          // x & hueTime values
uint8_t octaves = 2;     //2                                  // how many octaves to use for the brightness
uint8_t hueOctaves = 3;  //3                                  // how many octaves to use for the hue
int xScale = 57771;      //57771                              // the 'distance' between points on the x axis
uint32_t hxy = 43213;    //43213                              // not sure about this
int hueScale = 20;       //1                                  // the 'distance' between points for the hue noise
int hueSpeed = 1;        //31                                 // how fast we move through hue noise
uint8_t xSpeed = 0;      //331                                // adjust this value to move along the x axis between frames
int8_t hXYinc = 3;       //3

void noise16_pal() {
  if (ledCount >= 10) {
    fill_noise16(leds, ledCount, octaves, x, xScale, hueOctaves, hxy, hueScale, hueTime);

    hxy += hXYinc * effectThisDirection;
    x += xSpeed * effectThisDirection;
    hueTime += hueSpeed * effectThisDirection;
  }
} // noise16_pal()

#endif // EFFECT_NOISE16_PAL_H
