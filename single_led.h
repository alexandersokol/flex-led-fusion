#ifndef SINGLE_LED_H
#define SINGLE_LED_H

#include "config.h"

#define setLedColorRed() setLedColor(255, 0, 0)
#define setLedColorRed(delay) setLedColor(255, 0, 0, delay)
#define setLedColorGreen() setLedColor(0, 255, 0)
#define setLedColorGreen(delay) setLedColor(0, 255, 0, delay)
#define setLedColorBlue() setLedColor(0, 0, 255)
#define setLedColorBlue(delay) setLedColor(0, 0, 255, delay)
#define setLedColorYellow() setLedColor(255, 255, 0)
#define setLedColorYellow(delay) setLedColor(255, 255, 0, delay)
#define setLedColorCyan() setLedColor(0, 255, 255)
#define setLedColorCyan(delay) setLedColor(0, 255, 255, delay)
#define setLedColorMagenta() setLedColor(255, 0, 255)
#define setLedColorMagenta(delay) setLedColor(255, 0, 255, delay)
#define setLedColorWhite() setLedColor(255, 255, 255)
#define setLedColorWhite(delay) setLedColor(255, 255, 255, delay)

uint32_t lastLedChange = 0;
uint32_t ledTurnOffDelay = 0;

void setLedColor(uint8_t red, uint8_t green, uint8_t blue) {
  analogWrite(PIN_LED_RED, red);
  analogWrite(PIN_LED_GREEN, green);
  analogWrite(PIN_LED_BLUE, blue);
  lastLedChange = millis();
  ledTurnOffDelay = 0;
}

void setLedColor(uint8_t red, uint8_t green, uint8_t blue, uint32_t turnOffDelay) {
  setLedColor(red, green, blue);
  ledTurnOffDelay = turnOffDelay;
}

void turnOffLED() {
  setLedColor(0, 0, 0);
}

void setupSingleLed() {
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);
  turnOffLED();
}

void loopSingleLed() {
  if(ledTurnOffDelay > 0 && lastLedChange > 0 && (millis() - lastLedChange > ledTurnOffDelay)) {
    ledTurnOffDelay = 0;
    turnOffLED();
  }
}

#endif // SINGLE_LED_H