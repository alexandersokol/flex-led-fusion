#ifndef CONFIG_H
#define CONFIG_H

// Pins
#define PIN_BUTTON_YELLOW 3
#define PIN_BUTTON_BLUE 4

#define PIN_LED_RED 10
#define PIN_LED_GREEN 9
#define PIN_LED_BLUE 8

#define PIN_IR_RECEIVE A4
#define PIN_LED_STRIP 6

// Variables
#define MAX_LEDS 150
#define PALETTE_TIME 30 // Seconds to change palette
#define LED_COLOR_ORDER GRB // LED color order RGB or GRB
#define LED_CHIPSET WS2812B // LED Chipset
#define POWER_V 5 // Power adapter Volts
#define POWER_I 10000 // Power adaptar milliamps

#define MIN_BRIGHTNESS 30
#define MAX_BRIGHTNESS 255
#define BRIGHTNESS_STEP 20

#define EFFECT_SWITCH_MINUTES 5

#define IS_SPARKS_ENABLED 1
#define IS_BACKGROUND_ENABLED 1

// Modules
#define IS_LOGS_ON 0
#define IS_IR_ON 1
#define IS_BUTTONS_ON 1

// Commands
#define COMMAND_EMPTY 0

#endif // CONFIG_H
