#ifndef EFFECTS_H
#define EFFECTS_H

#include "FastLED.h"
#include <EEPROM.h>
#include "utilities.h"
#include "gradient_palettes.h"
#include "logging.h"
#include "config.h"
#include "commands.h"
#include "single_led.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define GENERIC_MODE_NOTAMESH 0
#define GENERIC_MODE_COLORS 1

const uint32_t genericModes[] = { GENERIC_MODE_NOTAMESH, GENERIC_MODE_COLORS };

uintl ledCount = MAX_LEDS;

struct CRGB leds[MAX_LEDS];

uint8_t effectPalleteChange = 3;
uint8_t effectThisDiff = 1;
uint8_t effectThisSinc = 1;
uint8_t effectThisFade = 224;
uint8_t effectThisIndex = 0;
int effectThisPhase = 0;
int8_t effectThisSpeed = 4;
int8_t effectThisDirection = 1;
uint8_t effectThisHue = 0;
uint8_t effectThisRotation = 1;
uint8_t effectThisCutOff = 192;
uint8_t effectAllFrequency = 32;
uint8_t effectStartIndex = 0;
uint8_t effectBackgroundColor = 0;
uint8_t effectBackgroundBrightness = 0;
uint16_t effectThisDelay = 0;
uint8_t effectThisBeat;

CRGBPalette16 gCurrentPalette;
CRGBPalette16 gTargetPalette;

uint8_t gCurrentPaletteNumber = 0;
TBlendType currentBlending = LINEARBLEND;
CRGB solid = CRGB::Black;

uint8_t ledMode = 0;

#include "effect_confetti_pal.h"
#include "effect_blendwave.h"
#include "effect_rainbow_beat.h"
#include "effect_two_sin.h"
#include "effect_one_sin_pal.h"
#include "effect_juggle_pal.h"
#include "effect_matrix_pal.h"
#include "effect_noise8_pal.h"
#include "effect_noise16_pal.h"
#include "effect_plasma.h"
#include "effect_rainbow_march.h"
#include "effect_serendipitous_pal.h"
#include "effect_three_sin_pal.h"
#include "effect_fire.h"
#include "effect_candles.h"
#include "effect_colorwave.h"

#define EFFECT_BLEND_WAVE 0
#define EFFECT_RAINBOW_BEAT 1
#define EFFECT_TWO_SIN_1 2
#define EFFECT_ONE_SIN_1 3
#define EFFECT_NOISE8_1 4
#define EFFECT_TWO_SIN_2 5
#define EFFECT_ONE_SIN_2 6
#define EFFECT_JUGGLE_1 7
#define EFFECT_MATRIX_1 8
#define EFFECT_TWO_SIN_3 9
#define EFFECT_ONE_SIN_3 10
#define EFFECT_THREE_SIN_1 11
#define EFFECT_SERENDIPITOUS 12
#define EFFECT_ONE_SIN_4 13
#define EFFECT_TWO_SIN_4 14
#define EFFECT_MATRIX_2 15
#define EFFECT_NOISE8_2 16
#define EFFECT_PLASMA_1 17
#define EFFECT_TWO_SIN_5 18
#define EFFECT_RAINBOW_MARCH_1 19
#define EFFECT_THREE_SIN_2 20
#define EFFECT_RAINBOW_MARCH_2 21
#define EFFECT_NOISE16_1 22
#define EFFECT_ONE_SIN_5 23
#define EFFECT_PLASMA_2 24
#define EFFECT_CONFETTI_1 25
#define EFFECT_TWO_SIN_6 26
#define EFFECT_MATRIX_3 27
#define EFFECT_ONE_SIN_6 28
#define EFFECT_CONFETTI_2 29
#define EFFECT_PLASMA_3 30
#define EFFECT_JUGGLE_2 31
#define EFFECT_ONE_SIN_7 32
#define EFFECT_THREE_SIN_3 33
#define EFFECT_RAINBOW_MARCH_3 34
#define EFFECT_PLASMA_4 35
#define EFFECT_CONFETTI_3 36
#define EFFECT_NOISE16_2 37
#define EFFECT_NOISE8_3 38
#define EFFECT_FIRE 39
#define EFFECT_CANDLES 40
#define EFFECT_COLORWAVES 41

const PROGMEM uint8_t modes[] = { 
    EFFECT_BLEND_WAVE,
    EFFECT_RAINBOW_BEAT,
    EFFECT_TWO_SIN_1,
    EFFECT_ONE_SIN_1,
    EFFECT_NOISE8_1,
    EFFECT_TWO_SIN_2,
    EFFECT_ONE_SIN_2,
    EFFECT_JUGGLE_1,
    EFFECT_MATRIX_1,
    EFFECT_TWO_SIN_3,
    EFFECT_ONE_SIN_3,
    EFFECT_THREE_SIN_1,
    EFFECT_SERENDIPITOUS,
    EFFECT_ONE_SIN_4,
    EFFECT_TWO_SIN_4,
    EFFECT_MATRIX_2,
    EFFECT_NOISE8_2,
    EFFECT_PLASMA_1,
    EFFECT_TWO_SIN_5,
    EFFECT_RAINBOW_MARCH_1,
    EFFECT_THREE_SIN_2,
    EFFECT_RAINBOW_MARCH_2,
    EFFECT_NOISE16_1,
    EFFECT_ONE_SIN_5,
    EFFECT_PLASMA_2,
    EFFECT_CONFETTI_1,
    EFFECT_TWO_SIN_6,
    EFFECT_MATRIX_3,
    EFFECT_ONE_SIN_6,
    EFFECT_CONFETTI_2,
    EFFECT_PLASMA_3,
    EFFECT_JUGGLE_2,
    EFFECT_ONE_SIN_7,
    EFFECT_THREE_SIN_3,
    EFFECT_RAINBOW_MARCH_3,
    EFFECT_PLASMA_4,
    EFFECT_CONFETTI_3,
    EFFECT_NOISE16_2,
    EFFECT_NOISE8_3,
    EFFECT_FIRE,
    EFFECT_CANDLES,
    EFFECT_COLORWAVES
 };
const uint8_t modesCount = sizeof(modes);

const PROGMEM uint32_t colorModes[] = { 
  CRGB::AliceBlue,
  CRGB::Amethyst,
  CRGB::AntiqueWhite,
  CRGB::Aqua,
  CRGB::Aquamarine,
  CRGB::Azure,
  CRGB::Beige,
  CRGB::Bisque,
  CRGB::BlanchedAlmond,
  CRGB::Blue,
  CRGB::BlueViolet,
  CRGB::Brown,
  CRGB::BurlyWood,
  CRGB::CadetBlue,
  CRGB::Chartreuse,
  CRGB::Chocolate,
  CRGB::Coral,
  CRGB::CornflowerBlue,
  CRGB::Cornsilk,
  CRGB::Crimson,
  CRGB::Cyan,
  CRGB::DarkBlue,
  CRGB::DarkCyan,
  CRGB::DarkGoldenrod,
  CRGB::DarkGray,
  CRGB::DarkGrey,
  CRGB::DarkGreen,
  CRGB::DarkKhaki,
  CRGB::DarkMagenta,
  CRGB::DarkOliveGreen,
  CRGB::DarkOrange,
  CRGB::DarkOrchid,
  CRGB::DarkRed,
  CRGB::DarkSalmon,
  CRGB::DarkSeaGreen,
  CRGB::DarkSlateBlue,
  CRGB::DarkSlateGray,
  CRGB::DarkSlateGrey,
  CRGB::DarkTurquoise,
  CRGB::DarkViolet,
  CRGB::DeepPink,
  CRGB::DeepSkyBlue,
  CRGB::DimGray,
  CRGB::DodgerBlue,
  CRGB::FireBrick,
  CRGB::FloralWhite,
  CRGB::ForestGreen,
  CRGB::Fuchsia,
  CRGB::Gainsboro,
  CRGB::GhostWhite,
  CRGB::Gold,
  CRGB::Goldenrod,
  CRGB::Gray,
  CRGB::Grey,
  CRGB::Green,
  CRGB::GreenYellow,
  CRGB::Honeydew,
  CRGB::HotPink,
  CRGB::IndianRed,
  CRGB::Indigo,
  CRGB::Ivory,
  CRGB::Khaki,
  CRGB::Lavender,
  CRGB::LavenderBlush,
  CRGB::LawnGreen,
  CRGB::LemonChiffon,
  CRGB::LightBlue,
  CRGB::LightCoral,
  CRGB::LightCyan,
  CRGB::LightGoldenrodYellow,
  CRGB::LightGreen,
  CRGB::LightGrey,
  CRGB::LightPink,
  CRGB::LightSalmon,
  CRGB::LightSeaGreen,
  CRGB::LightSkyBlue,
  CRGB::LightSlateGray,
  CRGB::LightSlateGrey,
  CRGB::LightSteelBlue,
  CRGB::LightYellow,
  CRGB::Lime,
  CRGB::LimeGreen,
  CRGB::Linen,
  CRGB::Magenta,
  CRGB::Maroon,
  CRGB::MediumAquamarine,
  CRGB::MediumBlue,
  CRGB::MediumOrchid,
  CRGB::MediumPurple,
  CRGB::MediumSeaGreen,
  CRGB::MediumSlateBlue,
  CRGB::MediumSpringGreen,
  CRGB::MediumTurquoise,
  CRGB::MediumVioletRed,
  CRGB::MidnightBlue,
  CRGB::MintCream,
  CRGB::MistyRose,
  CRGB::Moccasin,
  CRGB::NavajoWhite,
  CRGB::Navy,
  CRGB::OldLace,
  CRGB::Olive,
  CRGB::OliveDrab,
  CRGB::Orange,
  CRGB::OrangeRed,
  CRGB::Orchid,
  CRGB::PaleGoldenrod,
  CRGB::PaleGreen,
  CRGB::PaleTurquoise,
  CRGB::PaleVioletRed,
  CRGB::PapayaWhip,
  CRGB::PeachPuff,
  CRGB::Peru,
  CRGB::Pink,
  CRGB::Plaid,
  CRGB::Plum,
  CRGB::PowderBlue,
  CRGB::Purple,
  CRGB::Red,
  CRGB::RosyBrown,
  CRGB::RoyalBlue,
  CRGB::SaddleBrown,
  CRGB::Salmon,
  CRGB::SandyBrown,
  CRGB::SeaGreen,
  CRGB::Seashell,
  CRGB::Sienna,
  CRGB::Silver,
  CRGB::SkyBlue,
  CRGB::SlateBlue,
  CRGB::SlateGray,
  CRGB::SlateGrey,
  CRGB::Snow,
  CRGB::SpringGreen,
  CRGB::SteelBlue,
  CRGB::Tan,
  CRGB::Teal,
  CRGB::Thistle,
  CRGB::Tomato,
  CRGB::Turquoise,
  CRGB::Violet,
  CRGB::Wheat,
  CRGB::White,
  CRGB::WhiteSmoke,
  CRGB::Yellow,
  CRGB::YellowGreen,
  CRGB::FairyLight
};
const uint8_t colorModesCount = sizeof(colorModes);

// EEPROM addresses for each variable
#define MAGIC_VALUE_ADDR 0
#define LED_BRIGHTNESS_ADDR 1
#define CURRENT_MODE_ADDR 2
#define IS_EFFECT_SWITCH_ADDR 4
#define IS_SPARKS_ENABLED_ADDR 5
#define IS_BACKGROUND_ENABLED_ADDR 6
#define GENERIC_MODE_ADDR 7
#define COLOR_MODE_ADDR 8

#define MAGIC_VALUE 0x42  // A unique value to verify initialization

uint8_t ledBrightness = MAX_BRIGHTNESS;
uint8_t currentModePose = 0;
bool isLedEnabled = true;
bool isEffectSwitchEnabled = false;
bool isSparksEnabled = IS_SPARKS_ENABLED;
bool isBackgroundEnabled = IS_BACKGROUND_ENABLED;

uint8_t genericModePosition = 0;
uint8_t colorModePosition = 0;

// -------------------------------------------------------------------------------------------
void saveToEEPROM() {
  EEPROM.update(MAGIC_VALUE_ADDR, MAGIC_VALUE);  // Write magic value
  EEPROM.update(LED_BRIGHTNESS_ADDR, ledBrightness);
  EEPROM.update(CURRENT_MODE_ADDR, currentModePose);
  EEPROM.update(IS_EFFECT_SWITCH_ADDR, isEffectSwitchEnabled);
  EEPROM.update(IS_SPARKS_ENABLED_ADDR, isSparksEnabled);
  EEPROM.update(IS_BACKGROUND_ENABLED_ADDR, isBackgroundEnabled);
  EEPROM.update(GENERIC_MODE_ADDR, genericModePosition);
  EEPROM.update(COLOR_MODE_ADDR, colorModePosition);
  LOG_PRINTLN("Values saved to EEPROM");
}

// -------------------------------------------------------------------------------------------
void loadFromEEPROM() {
  if (EEPROM.read(MAGIC_VALUE_ADDR) != MAGIC_VALUE) {
    // EEPROM uninitialized, write defaults
    LOG_PRINTLN("EEPROM uninitialized, using defaults...");
  } else {
    // Load values from EEPROM
    ledBrightness = EEPROM.read(LED_BRIGHTNESS_ADDR);
    currentModePose = EEPROM.read(CURRENT_MODE_ADDR);
    isEffectSwitchEnabled = EEPROM.read(IS_EFFECT_SWITCH_ADDR);
    isSparksEnabled = EEPROM.read(IS_SPARKS_ENABLED_ADDR);
    isBackgroundEnabled = EEPROM.read(IS_BACKGROUND_ENABLED_ADDR);
    genericModePosition = EEPROM.read(GENERIC_MODE_ADDR);
    colorModePosition = EEPROM.read(COLOR_MODE_ADDR);

    LOG_PRINTLN("Loaded values from EEPROM");
  }
}

// -------------------------------------------------------------------------------------------
void strobeMode(uint8_t mode, bool modeChange) { // mc stands for 'Mode Change', where mc = 0 is strobe the routine, while mc = 1 is change the routine

  if (modeChange) {
    fill_solid(leds, ledCount, CRGB(0, 0, 0)); // Clean up the array for the first time through. Don't show display though, so you may have a smooth transition.

#if PALETTE_TIME > 0
    if (effectPalleteChange == 0)
      effectPalleteChange = 3;
#else
    if (effectPalleteChange == 0)
      effectPalleteChange = 1;
#endif
  }

  switch (mode) { // First time through a new mode, so let's initialize the variables for a given display.
  case EFFECT_BLEND_WAVE:
    if (modeChange) {
      effectThisDelay = 10;
      effectPalleteChange = 0;
    }
    blendwave();
    break;
  case EFFECT_RAINBOW_BEAT:
    if (modeChange) {
      effectThisDelay = 10;
      effectPalleteChange = 0;
    }
    rainbow_beat();
    break;
  case EFFECT_TWO_SIN_1:
    if (modeChange) {
      effectThisDelay = 10;
      effectAllFrequency = 2;
      effectThisSpeed = 1;
      thatSpeed = 2;
      effectThisHue = 0;
      thatHue = 128;
      effectThisDirection = 1;
      effectThisRotation = 1;
      thatRotation = 1;
      effectThisCutOff = 128;
      thatCutOff = 192;
    }
    two_sin();
    break;
  case EFFECT_ONE_SIN_1:
    if (modeChange) {
      effectThisDelay = 20;
      effectAllFrequency = 4;
      effectBackgroundColor = 0;
      effectBackgroundBrightness = 0;
      effectStartIndex = 64;
      effectThisSinc = 2;
      effectThisCutOff = 224;
      effectThisPhase = 0;
      effectThisCutOff = 224;
      effectThisRotation = 0;
      effectThisSpeed = 4;
    }
    one_sin_pal();
    break;
  case EFFECT_NOISE8_1:
    if (modeChange) {
      effectThisDelay = 10;
    }
    noise8_pal();
    break;
  case EFFECT_TWO_SIN_2:
    if (modeChange) {
      effectThisDelay = 10;
      effectAllFrequency = 4;
      effectThisSpeed = -1;
      thatSpeed = 0;
      effectThisHue = 64;
      thatHue = 192;
      effectThisDirection = 1;
      effectThisRotation = 0;
      thatRotation = 0;
      effectThisCutOff = 64;
      thatCutOff = 192;
    }
    two_sin();
    break;
  case EFFECT_ONE_SIN_2:
    if (modeChange) {
      effectThisDelay = 20;
      effectAllFrequency = 10;
      effectBackgroundColor = 64;
      effectBackgroundBrightness = 4;
      effectStartIndex = 64;
      effectThisSinc = 2;
      effectThisCutOff = 224;
      effectThisPhase = 0;
      effectThisCutOff = 224;
      effectThisRotation = 0;
      effectThisSpeed = 4;
    }
    one_sin_pal();
    break;
  case EFFECT_JUGGLE_1:
    if (modeChange) {
      effectThisDelay = 10;
      numDots = 2;
      effectThisFade = 16;
      effectThisBeat = 8;
      effectThisDiff = 64;
    }
    juggle_pal();
    break;
  case EFFECT_MATRIX_1:
    if (modeChange) {
      effectThisDelay = 40;
      effectThisIndex = 128;
      effectThisDirection = 1;
      effectThisRotation = 0;
      effectBackgroundColor = 200;
      effectBackgroundBrightness = 6;
    }
    matrix_pal();
    break;
  case EFFECT_TWO_SIN_3:
    if (modeChange) {
      effectThisDelay = 10;
      effectAllFrequency = 6;
      effectThisSpeed = 2;
      thatSpeed = 3;
      effectThisHue = 96;
      thatHue = 224;
      effectThisDirection = 1;
      effectThisRotation = 0;
      thatRotation = 0;
      effectThisCutOff = 64;
      thatCutOff = 64;
    }
    two_sin();
    break;
  case EFFECT_ONE_SIN_3:
    if (modeChange) {
      effectThisDelay = 20;
      effectAllFrequency = 16;
      effectBackgroundColor = 0;
      effectBackgroundBrightness = 0;
      effectStartIndex = 64;
      effectThisSinc = 2;
      effectThisCutOff = 224;
      effectThisPhase = 0;
      effectThisCutOff = 224;
      effectThisRotation = 0;
      effectThisSpeed = 4;
    }
    one_sin_pal();
    break;
  case EFFECT_THREE_SIN_1:
    if (modeChange) {
      effectThisDelay = 50;
      mul1 = 5;
      mul2 = 8;
      mul3 = 7;
    }
    three_sin_pal();
    break;
  case EFFECT_SERENDIPITOUS:
    if (modeChange) {
      effectThisDelay = 10;
    }
    serendipitous_pal();
    break;
  case EFFECT_ONE_SIN_4:
    if (modeChange) {
      effectThisDelay = 20;
      effectAllFrequency = 8;
      effectBackgroundColor = 0;
      effectBackgroundBrightness = 4;
      effectStartIndex = 64;
      effectThisSinc = 2;
      effectThisCutOff = 224;
      effectThisPhase = 0;
      effectThisCutOff = 224;
      effectThisRotation = 0;
      effectThisSpeed = 4;
    }
    one_sin_pal();
    break;
  case EFFECT_TWO_SIN_4:
    if (modeChange) {
      effectThisDelay = 10;
      effectAllFrequency = 20;
      effectThisSpeed = 2;
      thatSpeed = -1;
      effectThisHue = 24;
      thatHue = 180;
      effectThisDirection = 1;
      effectThisRotation = 0;
      thatRotation = 1;
      effectThisCutOff = 64;
      thatCutOff = 128;
    }
    two_sin();
    break;
  case EFFECT_MATRIX_2:
    if (modeChange) {
      effectThisDelay = 50;
      effectThisIndex = 64;
      effectThisDirection = -1;
      effectThisRotation = 1;
      effectBackgroundColor = 100;
      effectBackgroundBrightness = 10;
    }
    matrix_pal();
    break;
  case EFFECT_NOISE8_2:
    if (modeChange) {
      effectThisDelay = 10;
    }
    noise8_pal();
    break; // By: Andrew Tuline
  case EFFECT_PLASMA_1:
    if (modeChange) {
      effectThisDelay = 10;
    }
    plasma(11, 23, 4, 18);
    break;
  case EFFECT_TWO_SIN_5:
    if (modeChange) {
      effectThisDelay = 20;
      effectAllFrequency = 10;
      effectThisSpeed = 1;
      thatSpeed = -2;
      effectThisHue = 48;
      thatHue = 160;
      effectThisDirection = -1;
      effectThisRotation = 1;
      thatRotation = -1;
      effectThisCutOff = 128;
      thatCutOff = 192;
    }
    two_sin();
    break;
  case EFFECT_RAINBOW_MARCH_1:
    if (modeChange) {
      effectThisDelay = 50;
      effectPalleteChange = 0;
      effectThisDirection = 1;
      effectThisRotation = 1;
      effectThisDiff = 1;
    }
    rainbow_march();
    break;
  case EFFECT_THREE_SIN_2:
    if (modeChange) {
      effectThisDelay = 10;
      mul1 = 6;
      mul2 = 9;
      mul3 = 11;
    }
    three_sin_pal();
    break;
  case EFFECT_RAINBOW_MARCH_2:
    if (modeChange) {
      effectThisDelay = 10;
      effectPalleteChange = 0;
      effectThisDirection = 1;
      effectThisRotation = 2;
      effectThisDiff = 10;
    }
    rainbow_march();
    break;
  case EFFECT_NOISE16_1:
    if (modeChange) {
      effectThisDelay = 20;
      effectPalleteChange = 0;
      hXYinc = random16(1, 15);
      octaves = random16(1, 3);
      hueOctaves = random16(1, 5);
      hueScale = random16(10, 50);
      x = random16();
      xScale = random16();
      hxy = random16();
      hueTime = random16();
      hueSpeed = random16(1, 3);
      xSpeed = random16(1, 30);
    }
    noise16_pal();
    break;
  case EFFECT_ONE_SIN_5:
    if (modeChange) {
      effectThisDelay = 20;
      effectAllFrequency = 6;
      effectBackgroundColor = 0;
      effectBackgroundBrightness = 0;
      effectStartIndex = 64;
      effectThisSinc = 2;
      effectThisCutOff = 224;
      effectThisPhase = 0;
      effectThisCutOff = 224;
      effectThisRotation = 0;
      effectThisSpeed = 4;
    }
    one_sin_pal();
    break;
  case EFFECT_PLASMA_2:
    if (modeChange) {
      effectThisDelay = 10;
    }
    plasma(23, 15, 6, 7);
    break;
  case EFFECT_CONFETTI_1:
    if (modeChange) {
      effectThisDelay = 20;
      effectThisSinc = 1;
      effectThisFade = 2;
      effectThisDiff = 32;
    }
    confetti_pal();
    break;
  case EFFECT_TWO_SIN_6:
    if (modeChange) {
      effectThisDelay = 10;
      effectThisSpeed = 2;
      thatSpeed = 3;
      effectThisHue = 96;
      thatHue = 224;
      effectThisDirection = 1;
      effectThisRotation = 1;
      thatRotation = 2;
      effectThisCutOff = 128;
      thatCutOff = 64;
    }
    two_sin();
    break;
  case EFFECT_MATRIX_3:
    if (modeChange) {
      effectThisDelay = 30;
      effectThisIndex = 192;
      effectThisDirection = -1;
      effectThisRotation = 0;
      effectBackgroundColor = 50;
      effectBackgroundBrightness = 0;
    }
    matrix_pal();
    break;
  case EFFECT_ONE_SIN_6:
    if (modeChange) {
      effectThisDelay = 20;
      effectAllFrequency = 20;
      effectBackgroundColor = 0;
      effectBackgroundBrightness = 0;
      effectStartIndex = 64;
      effectThisSinc = 2;
      effectThisCutOff = 224;
      effectThisPhase = 0;
      effectThisCutOff = 224;
      effectThisRotation = 0;
      effectThisSpeed = 4;
    }
    one_sin_pal();
    break;
  case EFFECT_CONFETTI_2:
    if (modeChange) {
      effectThisDelay = 20;
      effectThisSinc = 2;
      effectThisFade = 8;
      effectThisDiff = 64;
    }
    confetti_pal();
    break;
  case EFFECT_PLASMA_3:
    if (modeChange) {
      effectThisDelay = 10;
    }
    plasma(8, 7, 9, 13);
    break;
  case EFFECT_JUGGLE_2:
    if (modeChange) {
      effectThisDelay = 10;
      numDots = 4;
      effectThisFade = 32;
      effectThisBeat = 12;
      effectThisDiff = 20;
    }
    juggle_pal();
    break;
  case EFFECT_ONE_SIN_7:
    if (modeChange) {
      effectThisDelay = 30;
      effectAllFrequency = 4;
      effectBackgroundColor = 64;
      effectBackgroundBrightness = 4;
      effectStartIndex = 64;
      effectThisSinc = 2;
      effectThisCutOff = 224;
      effectThisPhase = 0;
      effectThisCutOff = 128;
      effectThisRotation = 1;
      effectThisSpeed = 8;
    }
    one_sin_pal();
    break;
  case EFFECT_THREE_SIN_3:
    if (modeChange) {
      effectThisDelay = 50;
      mul1 = 3;
      mul2 = 4;
      mul3 = 5;
    }
    three_sin_pal();
    break;
  case EFFECT_RAINBOW_MARCH_3:
    if (modeChange) {
      effectThisDelay = 10;
      effectPalleteChange = 0;
      effectThisDirection = -1;
      effectThisRotation = 1;
      effectThisDiff = 5;
    }
    rainbow_march();
    break;
  case EFFECT_PLASMA_4:
    if (modeChange) {
      effectThisDelay = 10;
    }
    plasma(11, 17, 20, 23);
    break;
  case EFFECT_CONFETTI_3:
    if (modeChange) {
      effectThisDelay = 20;
      effectThisSinc = 1;
      effectThisFade = 1;
    }
    confetti_pal();
    break;
  case EFFECT_NOISE16_2:
    if (modeChange) {
      effectThisDelay = 20;
      effectPalleteChange = 0;
      octaves = 1;
      hueOctaves = 2;
      hxy = 6000;
      x = 5000;
      xScale = 3000;
      hueScale = 50;
      hueSpeed = 15;
      xSpeed = 100;
    }
    noise16_pal();
    break;
  case EFFECT_NOISE8_3:
    if (modeChange) {
      effectThisDelay = 10;
    }
    noise8_pal();
    break;
  case EFFECT_FIRE:
    if (modeChange) {
      effectThisDelay = 10;
      effectPalleteChange = 0;
    }
    fire();
    break;
  case EFFECT_CANDLES:
    if (modeChange) {
      effectThisDelay = 10;
      effectPalleteChange = 0;
    }
    candles();
    break;
  case EFFECT_COLORWAVES:
    if (modeChange) {
      effectThisDelay = 10;
    }
    colorwaves();
    break;
  default:
    ledMode = EFFECT_BLEND_WAVE;
    break;

  } // switch mode

  if (modeChange)
  {
    if (effectPalleteChange == 0)
      LOG_PRINTLN("Change palette off");
    else if (effectPalleteChange == 1)
      LOG_PRINTLN("Change palette Stop");
    else if (effectPalleteChange == 3)
      LOG_PRINTLN("Change palette ON");
  }
} // strobeMode()


// -------------------------------------------------------------------------------------------
void setupEffects() {
  delay(1000); // Slow startup so we can re-upload in the case of errors.

  loadFromEEPROM();

  LEDS.setBrightness(ledBrightness); // Set the generic maximum brightness value.
  LEDS.addLeds<LED_CHIPSET, PIN_LED_STRIP, LED_COLOR_ORDER>(leds, MAX_LEDS);

  set_max_power_in_volts_and_milliamps(POWER_V, POWER_I); // Power adapter setup

  random16_set_seed(4832); // Awesome randomizer of awesomeness
  random16_add_entropy(analogRead(2));

  ledMode = pgm_read_byte(modes + currentModePose);
  ledCount = MAX_LEDS;

  gCurrentPalette = gGradientPalettes[0];
  gTargetPalette = gGradientPalettes[0];
  strobeMode(ledMode, 1); // Initialize the first sequence
} // setup()

// -------------------------------------------------------------------------------------------
void addSparks(fract8 chanceOfSparks) {
  if (random8() < chanceOfSparks) {
    leds[randoml(ledCount)] += CRGB::White;
  }
} // addSparks()

// -------------------------------------------------------------------------------------------
void addBackground() {
  for (uintl i = 0; i < ledCount; i++)
    if ((leds[i].r < 5) &&
        (leds[i].g < 5) &&
        (leds[i].b < 5))
      leds[i] += CRGB(5, 5, 5);
} // addBackground()

// -------------------------------------------------------------------------------------------
void proceedCommands() {
  if(!isLedEnabled && pendingCommand != COMMAND_TOGGLE_LED_ON){
    return;
  }

  switch(pendingCommand){
    case COMMAND_EMPTY: // No commands to execute
      break;
    case COMMAND_NEXT_EFFECT: // Switch to next effect or color
      if(genericModes[genericModePosition] == GENERIC_MODE_NOTAMESH) {
        if (++currentModePose >= (modesCount - 1)) currentModePose = 0;
        ledMode = pgm_read_byte(modes + currentModePose);
        strobeMode(ledMode, 1);
      } else if(genericModes[genericModePosition] == GENERIC_MODE_COLORS){
        if (++colorModePosition >= colorModesCount) colorModePosition = 0;
      }
      setLedColorMagentaTime(100);
      break;
    case COMMAND_PREV_EFFECT: // Switch to previous effect or color
      if(genericModes[genericModePosition] == GENERIC_MODE_NOTAMESH) {
        if (--currentModePose < 0) currentModePose = modesCount - 1;
        ledMode = pgm_read_byte(modes + currentModePose);
        strobeMode(ledMode, 1);
      } else if(genericModes[genericModePosition] == GENERIC_MODE_COLORS){
        if (--colorModePosition < 0) colorModePosition = colorModesCount - 1;
      }
      setLedColorMagentaTime(100);
      break;
    case COMMAND_BRIGHTNESS_UP:
      if(ledBrightness <= (MAX_BRIGHTNESS - BRIGHTNESS_STEP)){
        ledBrightness += BRIGHTNESS_STEP;
      }
      LEDS.setBrightness(ledBrightness);
      setLedColorCyanTime(100);
      break;
    case COMMAND_BRIGHTNESS_DOWN:
      if(ledBrightness >= (MIN_BRIGHTNESS + BRIGHTNESS_STEP)){
        ledBrightness -= BRIGHTNESS_STEP;
      }
      LEDS.setBrightness(ledBrightness);
      setLedColorCyanTime(100);
      break;
    case COMMAND_TOGGLE_LED_ON:
      isLedEnabled = !isLedEnabled;
      if(isLedEnabled){
        if(isEffectSwitchEnabled){
          setLedColorGreenTime(2000);
        } else {
          setLedColorBlueTime(2000);
        }
        LEDS.setBrightness(ledBrightness);
      } else {
        setLedColorRed();
        for (uintl i = 0; i < ledCount; i++) {
          leds[i] = CRGB::Black;
        }
        FastLED.show();
      }
      break;
    case COMMAND_TOGGLE_EFFECT_SWITCH_ON:
      isEffectSwitchEnabled = !isEffectSwitchEnabled;
      if(isEffectSwitchEnabled){
        setLedColorGreenTime(2000);
      } else {
        setLedColorBlueTime(2000);
      }
      break;
    case COMMAND_TOGGLE_SPARKS_ON:
      isSparksEnabled = !isSparksEnabled;
      isBackgroundEnabled = !isBackgroundEnabled;
      setLedColorWhiteTime(100);
      break;
    case COMMAND_NEXT_GENERIC_MODE:
      if (++genericModePosition >= (sizeof(genericModes) / sizeof(genericModes[0]))) {
        genericModePosition = 0;
      }
      if (genericModePosition == GENERIC_MODE_NOTAMESH) {
        setLedColorGreenTime(100);
      } else if(genericModePosition == GENERIC_MODE_COLORS){
        setLedColorBlueTime(100);
      } else {
        setLedColorRedTime(100);
      }
      
      break;
  }

  if(pendingCommand != COMMAND_EMPTY) {
    saveToEEPROM();
    pendingCommand = COMMAND_EMPTY;
  }
}

// -------------------------------------------------------------------------------------------
void notameshLoop()
{
  EVERY_N_MILLISECONDS(50) { // Smooth pallete change
    uint8_t maxChanges = 24;
    nblendPaletteTowardPalette(gCurrentPalette, gTargetPalette, maxChanges);
  }

#if PALETTE_TIME > 0
  if (effectPalleteChange) {
    EVERY_N_SECONDS(PALETTE_TIME)
    { // Смена палитры
      if (effectPalleteChange == 3)
      {
        if (gCurrentPaletteNumber < (gGradientPaletteCount - 1))
          gCurrentPaletteNumber++;
        else
          gCurrentPaletteNumber = 0;
      }
      gTargetPalette = gGradientPalettes[gCurrentPaletteNumber];
    }
  }
#endif

  EVERY_N_MILLIS_I(thistimer, effectThisDelay) {
    thistimer.setPeriod(effectThisDelay);
    ledCount = MAX_LEDS;
    strobeMode(ledMode, 0);
  }

  if(isEffectSwitchEnabled) {
    EVERY_N_MINUTES(EFFECT_SWITCH_MINUTES) {
      queueCommand(COMMAND_NEXT_EFFECT);
    }
  }

  if (isSparksEnabled) {
    addSparks(10);
  }
      
  if (isBackgroundEnabled) {
    addBackground();
  }

  static uint32_t showTimer = 0;
  if (millis() - showTimer >= 10) {
    showTimer = millis();
    FastLED.show();
  }
} // loop()

// -------------------------------------------------------------------------------------------
void colorsLoop(){
  if (isSparksEnabled) {
    addSparks(10);
  }

  for (uintl i = 0; i < ledCount; i++) {
    leds[i] = pgm_read_dword(&colorModes[colorModePosition]);
  }

  FastLED.show();
}

// -------------------------------------------------------------------------------------------
void effectsLoop(){
  if(!isLedEnabled) {
    return;
  }

  switch(genericModes[genericModePosition]) {
    case GENERIC_MODE_NOTAMESH:
      notameshLoop();
      break;
    case GENERIC_MODE_COLORS:
      colorsLoop();
      break;
  }
}


#endif // EFFECTS_H
