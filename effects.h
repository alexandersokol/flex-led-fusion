#ifndef EFFECTS_H
#define EFFECTS_H

#include "FastLED.h"
#include "utilities.h"
#include "gradient_palettes.h"
#include "logging.h"
#include "config.h"
#include "commands.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

uintl ledCount = MAX_LEDS;

struct CRGB leds[MAX_LEDS];

uint8_t palchg = 3;
uint8_t thisdiff = 1;
uint8_t thisinc = 1;
uint8_t thisfade = 224;
uint8_t thisindex = 0;
int thisphase = 0;
int8_t thisspeed = 4;
int8_t thisdir = 1;
uint8_t thishue = 0;
uint8_t thisrot = 1;
uint8_t thiscutoff = 192;
uint8_t allfreq = 32;
uint8_t startindex = 0;
uint8_t bgclr = 0;
uint8_t bgbri = 0;
uint8_t wavebright = 255;
uint16_t thisdelay = 0;
uint8_t thisbeat;

CRGBPalette16 gCurrentPalette;
CRGBPalette16 gTargetPalette;

uint8_t gCurrentPaletteNumber = 0;
TBlendType currentBlending = LINEARBLEND;
CRGB solid = CRGB::Black;

uint8_t ledMode = 0;
uint16_t meshdelay;

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

#define EFFECT_TEST_PALLETE_CHANGE 100
#define EFFECT_TEST_LED_COUNT 200
#define EFFECT_TEST_MESH_DELAY 201

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

// Save this variable and read from EEPROM on setup
uint8_t ledBrightness = 255;
uint8_t currentModePose = 0;


// -------------------------------------------------------------------------------------------
void strobeMode(uint8_t mode, bool mc)
{ // mc stands for 'Mode Change', where mc = 0 is strobe the routine, while mc = 1 is change the routine

  if (mc)
  {
    fill_solid(leds, ledCount, CRGB(0, 0, 0)); // Clean up the array for the first time through. Don't show display though, so you may have a smooth transition.

#if PALETTE_TIME > 0
    if (palchg == 0)
      palchg = 3;
#else
    if (palchg == 0)
      palchg = 1;
#endif
  }

  switch (mode)
  { // First time through a new mode, so let's initialize the variables for a given display.
  case EFFECT_BLEND_WAVE:
    if (mc)
    {
      thisdelay = 10;
      palchg = 0;
    }
    blendwave();
    break;
  case EFFECT_RAINBOW_BEAT:
    if (mc)
    {
      thisdelay = 10;
      palchg = 0;
    }
    rainbow_beat();
    break;
  case EFFECT_TWO_SIN_1:
    if (mc)
    {
      thisdelay = 10;
      allfreq = 2;
      thisspeed = 1;
      thatspeed = 2;
      thishue = 0;
      thathue = 128;
      thisdir = 1;
      thisrot = 1;
      thatrot = 1;
      thiscutoff = 128;
      thatcutoff = 192;
    }
    two_sin();
    break;
  case EFFECT_ONE_SIN_1:
    if (mc)
    {
      thisdelay = 20;
      allfreq = 4;
      bgclr = 0;
      bgbri = 0;
      startindex = 64;
      thisinc = 2;
      thiscutoff = 224;
      thisphase = 0;
      thiscutoff = 224;
      thisrot = 0;
      thisspeed = 4;
      wavebright = 255;
    }
    one_sin_pal();
    break;
  case EFFECT_NOISE8_1:
    if (mc)
    {
      thisdelay = 10;
    }
    noise8_pal();
    break;
  case EFFECT_TWO_SIN_2:
    if (mc)
    {
      thisdelay = 10;
      allfreq = 4;
      thisspeed = -1;
      thatspeed = 0;
      thishue = 64;
      thathue = 192;
      thisdir = 1;
      thisrot = 0;
      thatrot = 0;
      thiscutoff = 64;
      thatcutoff = 192;
    }
    two_sin();
    break;
  case EFFECT_ONE_SIN_2:
    if (mc)
    {
      thisdelay = 20;
      allfreq = 10;
      bgclr = 64;
      bgbri = 4;
      startindex = 64;
      thisinc = 2;
      thiscutoff = 224;
      thisphase = 0;
      thiscutoff = 224;
      thisrot = 0;
      thisspeed = 4;
      wavebright = 255;
    }
    one_sin_pal();
    break;
  case EFFECT_JUGGLE_1:
    if (mc)
    {
      thisdelay = 10;
      numdots = 2;
      thisfade = 16;
      thisbeat = 8;
      thisdiff = 64;
    }
    juggle_pal();
    break;
  case EFFECT_MATRIX_1:
    if (mc)
    {
      thisdelay = 40;
      thisindex = 128;
      thisdir = 1;
      thisrot = 0;
      bgclr = 200;
      bgbri = 6;
    }
    matrix_pal();
    break;
  case EFFECT_TWO_SIN_3:
    if (mc)
    {
      thisdelay = 10;
      allfreq = 6;
      thisspeed = 2;
      thatspeed = 3;
      thishue = 96;
      thathue = 224;
      thisdir = 1;
      thisrot = 0;
      thatrot = 0;
      thiscutoff = 64;
      thatcutoff = 64;
    }
    two_sin();
    break;
  case EFFECT_ONE_SIN_3:
    if (mc)
    {
      thisdelay = 20;
      allfreq = 16;
      bgclr = 0;
      bgbri = 0;
      startindex = 64;
      thisinc = 2;
      thiscutoff = 224;
      thisphase = 0;
      thiscutoff = 224;
      thisrot = 0;
      thisspeed = 4;
      wavebright = 255;
    }
    one_sin_pal();
    break;
  case EFFECT_THREE_SIN_1:
    if (mc)
    {
      thisdelay = 50;
      mul1 = 5;
      mul2 = 8;
      mul3 = 7;
    }
    three_sin_pal();
    break;
  case EFFECT_SERENDIPITOUS:
    if (mc)
    {
      thisdelay = 10;
    }
    serendipitous_pal();
    break;
  case EFFECT_ONE_SIN_4:
    if (mc)
    {
      thisdelay = 20;
      allfreq = 8;
      bgclr = 0;
      bgbri = 4;
      startindex = 64;
      thisinc = 2;
      thiscutoff = 224;
      thisphase = 0;
      thiscutoff = 224;
      thisrot = 0;
      thisspeed = 4;
      wavebright = 255;
    }
    one_sin_pal();
    break;
  case EFFECT_TWO_SIN_4:
    if (mc)
    {
      thisdelay = 10;
      allfreq = 20;
      thisspeed = 2;
      thatspeed = -1;
      thishue = 24;
      thathue = 180;
      thisdir = 1;
      thisrot = 0;
      thatrot = 1;
      thiscutoff = 64;
      thatcutoff = 128;
    }
    two_sin();
    break;
  case EFFECT_MATRIX_2:
    if (mc)
    {
      thisdelay = 50;
      thisindex = 64;
      thisdir = -1;
      thisrot = 1;
      bgclr = 100;
      bgbri = 10;
    }
    matrix_pal();
    break;
  case EFFECT_NOISE8_2:
    if (mc)
    {
      thisdelay = 10;
    }
    noise8_pal();
    break; // By: Andrew Tuline
  case EFFECT_PLASMA_1:
    if (mc)
    {
      thisdelay = 10;
    }
    plasma(11, 23, 4, 18);
    break;
  case EFFECT_TWO_SIN_5:
    if (mc)
    {
      thisdelay = 20;
      allfreq = 10;
      thisspeed = 1;
      thatspeed = -2;
      thishue = 48;
      thathue = 160;
      thisdir = -1;
      thisrot = 1;
      thatrot = -1;
      thiscutoff = 128;
      thatcutoff = 192;
    }
    two_sin();
    break;
  case EFFECT_RAINBOW_MARCH_1:
    if (mc)
    {
      thisdelay = 50;
      palchg = 0;
      thisdir = 1;
      thisrot = 1;
      thisdiff = 1;
    }
    rainbow_march();
    break;
  case EFFECT_THREE_SIN_2:
    if (mc)
    {
      thisdelay = 10;
      mul1 = 6;
      mul2 = 9;
      mul3 = 11;
    }
    three_sin_pal();
    break;
  case EFFECT_RAINBOW_MARCH_2:
    if (mc)
    {
      thisdelay = 10;
      palchg = 0;
      thisdir = 1;
      thisrot = 2;
      thisdiff = 10;
    }
    rainbow_march();
    break;
  case EFFECT_NOISE16_1:
    if (mc)
    {
      thisdelay = 20;
      palchg = 0;
      hxyinc = random16(1, 15);
      octaves = random16(1, 3);
      hue_octaves = random16(1, 5);
      hue_scale = random16(10, 50);
      x = random16();
      xscale = random16();
      hxy = random16();
      hue_time = random16();
      hue_speed = random16(1, 3);
      x_speed = random16(1, 30);
    }
    noise16_pal();
    break;
  case EFFECT_ONE_SIN_5:
    if (mc)
    {
      thisdelay = 20;
      allfreq = 6;
      bgclr = 0;
      bgbri = 0;
      startindex = 64;
      thisinc = 2;
      thiscutoff = 224;
      thisphase = 0;
      thiscutoff = 224;
      thisrot = 0;
      thisspeed = 4;
      wavebright = 255;
    }
    one_sin_pal();
    break;
  case EFFECT_PLASMA_2:
    if (mc)
    {
      thisdelay = 10;
    }
    plasma(23, 15, 6, 7);
    break;
  case EFFECT_CONFETTI_1:
    if (mc)
    {
      thisdelay = 20;
      thisinc = 1;
      thisfade = 2;
      thisdiff = 32;
    }
    confetti_pal();
    break;
  case EFFECT_TWO_SIN_6:
    if (mc)
    {
      thisdelay = 10;
      thisspeed = 2;
      thatspeed = 3;
      thishue = 96;
      thathue = 224;
      thisdir = 1;
      thisrot = 1;
      thatrot = 2;
      thiscutoff = 128;
      thatcutoff = 64;
    }
    two_sin();
    break;
  case EFFECT_MATRIX_3:
    if (mc)
    {
      thisdelay = 30;
      thisindex = 192;
      thisdir = -1;
      thisrot = 0;
      bgclr = 50;
      bgbri = 0;
    }
    matrix_pal();
    break;
  case EFFECT_ONE_SIN_6:
    if (mc)
    {
      thisdelay = 20;
      allfreq = 20;
      bgclr = 0;
      bgbri = 0;
      startindex = 64;
      thisinc = 2;
      thiscutoff = 224;
      thisphase = 0;
      thiscutoff = 224;
      thisrot = 0;
      thisspeed = 4;
      wavebright = 255;
    }
    one_sin_pal();
    break;
  case EFFECT_CONFETTI_2:
    if (mc)
    {
      thisdelay = 20;
      thisinc = 2;
      thisfade = 8;
      thisdiff = 64;
    }
    confetti_pal();
    break;
  case EFFECT_PLASMA_3:
    if (mc)
    {
      thisdelay = 10;
    }
    plasma(8, 7, 9, 13);
    break;
  case EFFECT_JUGGLE_2:
    if (mc)
    {
      thisdelay = 10;
      numdots = 4;
      thisfade = 32;
      thisbeat = 12;
      thisdiff = 20;
    }
    juggle_pal();
    break;
  case EFFECT_ONE_SIN_7:
    if (mc)
    {
      thisdelay = 30;
      allfreq = 4;
      bgclr = 64;
      bgbri = 4;
      startindex = 64;
      thisinc = 2;
      thiscutoff = 224;
      thisphase = 0;
      thiscutoff = 128;
      thisrot = 1;
      thisspeed = 8;
      wavebright = 255;
    }
    one_sin_pal();
    break;
  case EFFECT_THREE_SIN_3:
    if (mc)
    {
      thisdelay = 50;
      mul1 = 3;
      mul2 = 4;
      mul3 = 5;
    }
    three_sin_pal();
    break;
  case EFFECT_RAINBOW_MARCH_3:
    if (mc)
    {
      thisdelay = 10;
      palchg = 0;
      thisdir = -1;
      thisrot = 1;
      thisdiff = 5;
    }
    rainbow_march();
    break;
  case EFFECT_PLASMA_4:
    if (mc)
    {
      thisdelay = 10;
    }
    plasma(11, 17, 20, 23);
    break;
  case EFFECT_CONFETTI_3:
    if (mc)
    {
      thisdelay = 20;
      thisinc = 1;
      thisfade = 1;
    }
    confetti_pal();
    break;
  case EFFECT_NOISE16_2:
    if (mc)
    {
      thisdelay = 20;
      palchg = 0;
      octaves = 1;
      hue_octaves = 2;
      hxy = 6000;
      x = 5000;
      xscale = 3000;
      hue_scale = 50;
      hue_speed = 15;
      x_speed = 100;
    }
    noise16_pal();
    break;
  case EFFECT_NOISE8_3:
    if (mc)
    {
      thisdelay = 10;
    }
    noise8_pal();
    break;
  case EFFECT_FIRE:
    if (mc)
    {
      thisdelay = 10;
      palchg = 0;
    }
    fire();
    break;
  case EFFECT_CANDLES:
    if (mc)
    {
      thisdelay = 10;
      palchg = 0;
    }
    candles();
    break;
  case EFFECT_COLORWAVES:
    if (mc)
    {
      thisdelay = 10;
    }
    colorwaves();
    break;
  case EFFECT_TEST_PALLETE_CHANGE: // Установить цвет
    if (mc)
    {
      palchg = 0;
    }
    fill_solid(leds, ledCount, solid);
    break;
  case EFFECT_TEST_LED_COUNT: // Зажеч гирлянду длинной MAX_LEDS (регулировка длинны гирлянды)
    fill_solid(leds, MAX_LEDS, CRGB::Black);
    fill_solid(leds, ledCount, CRGB(255, 255, 255));
    break;
  case EFFECT_TEST_MESH_DELAY: // Зажеч гирлянду длинной meshdelay
    fill_solid(leds, MAX_LEDS, CRGB::Black);
    fill_solid(leds, meshdelay, CRGB(255, 255, 255));
    break;
  default: // нет такого режима принудительно ставим нулевой
    ledMode = EFFECT_BLEND_WAVE;
    break;

  } // switch mode

  if (mc)
  {
    if (palchg == 0)
      LOG_PRINTLN("Change palette off");
    else if (palchg == 1)
      LOG_PRINTLN("Change palette Stop");
    else if (palchg == 3)
      LOG_PRINTLN("Change palette ON");
  }
} // strobeMode()


// -------------------------------------------------------------------------------------------
void setupEffects() {
  delay(1000); // Slow startup so we can re-upload in the case of errors.
  LEDS.setBrightness(ledBrightness); // Set the generic maximum brightness value.
  LEDS.addLeds<LED_CHIPSET, PIN_LED_STRIP, LED_COLOR_ORDER>(leds, MAX_LEDS);

  set_max_power_in_volts_and_milliamps(POWER_V, POWER_I); // Power adapter setup

  random16_set_seed(4832); // Awesome randomizer of awesomeness
  random16_add_entropy(analogRead(2));

  ledMode = pgm_read_byte(modes + currentModePose);
  ledCount = MAX_LEDS;
  meshdelay = 0;

  gCurrentPalette = gGradientPalettes[0];
  gTargetPalette = gGradientPalettes[0];
  strobeMode(ledMode, 1); // Initialize the first sequence
} // setup()

// -------------------------------------------------------------------------------------------
void addGlitter(fract8 chanceOfGlitter) {
  if (random8() < chanceOfGlitter) {
    leds[randoml(ledCount)] += CRGB::White;
  }
} // addGlitter()

// -------------------------------------------------------------------------------------------
void addBackground() {
  uintl i;
  for (i = 0; i < ledCount; i++)
    if ((leds[i].r < 5) &&
        (leds[i].g < 5) &&
        (leds[i].b < 5))
      leds[i] += CRGB(5, 5, 5);
} // addBackground()

// -------------------------------------------------------------------------------------------
void proceedCommands() {
  switch(pendingCommand){
    case COMMAND_EMPTY: // No commands to execute
      break;
    case COMMAND_NEXT_EFFECT: // Switch to next effect
      if (++currentModePose >= (modesCount - 1)) currentModePose = 0;
      ledMode = pgm_read_byte(modes + currentModePose);
      strobeMode(ledMode, 1);
      break;
    case COMMAND_PREV_EFFECT: // Switch to previous effect
      if (--currentModePose < (0)) modesCount - 1;
      ledMode = pgm_read_byte(modes + currentModePose);
      strobeMode(ledMode, 1);
      break;
  }
  pendingCommand = COMMAND_EMPTY;
}
























#define GLITER_ON 1
#define BACKGR_ON 1

uint32_t demo_time = 0;
bool glitter = GLITER_ON;
bool background = BACKGR_ON;

// -------------------------------------------------------------------------------------------
void effectsLoop()
{
    EVERY_N_MILLISECONDS(50)
    { // Плавный переход от одной палитры в другую
      uint8_t maxChanges = 24;
      nblendPaletteTowardPalette(gCurrentPalette, gTargetPalette, maxChanges);
    }

#if PALETTE_TIME > 0
    if (palchg)
    {
      EVERY_N_SECONDS(PALETTE_TIME)
      { // Смена палитры
        if (palchg == 3)
        {
          if (gCurrentPaletteNumber < (gGradientPaletteCount - 1))
            gCurrentPaletteNumber++;
          else
            gCurrentPaletteNumber = 0;
        }
        gTargetPalette = gGradientPalettes[gCurrentPaletteNumber]; // We're just ensuring that the gTargetPalette WILL be assigned.
      }
    }
#endif

    EVERY_N_MILLIS_I(thistimer, thisdelay)
    {                                 // Sets the original delay time.
      thistimer.setPeriod(thisdelay); // This is how you update the delay value on the fly.
      ledCount = MAX_LEDS;            // Выводим Эффект на все светодиоды
      strobeMode(ledMode, 0);        // отобразить эффект;
    }

    EVERY_N_SECONDS(60){
      queueCommand(COMMAND_NEXT_EFFECT);
    }

    if (glitter) {
      addGlitter(10);
    }
      
    if (background) {
      addBackground();
    }

  static uint32_t showTimer = 0;
  if (millis() - showTimer >= 10)
  {
    showTimer = millis();
    FastLED.show();
  }
} // loop()


#endif // EFFECTS_H
