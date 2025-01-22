#include "dependencies.h"

uint8_t commandToExecute = COMMAND_EMPTY;

void setup() {
  Serial.begin(9600);

  IR_BEGIN();
  setupEffects();
}

void loop() {
  
  IR_LOOP();
  BUTTONS_LOOP();

  effectsLoop();

  proceedCommands();
}
