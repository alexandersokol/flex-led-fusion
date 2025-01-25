#include "dependencies.h"

uint8_t commandToExecute = COMMAND_EMPTY;

void setup() {
  Serial.begin(9600);

  IR_BEGIN();
  setupEffects();
  setupSingleLed();
}

void loop() {
  IR_LOOP();

  BUTTONS_LOOP();

  effectsLoop();
  proceedCommands();
  loopSingleLed();
}
