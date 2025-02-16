#include "dependencies.h"

void setup() {
  LOG_SERIAL(9600);

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
