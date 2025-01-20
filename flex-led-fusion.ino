#include "dependencies.h"

uint8_t commandToExecute = COMMAND_EMPTY;

void setup() {
  Serial.begin(9600);

  IR_BEGIN();
}

void loop() {
  
  IR_LOOP();
  BUTTONS_LOOP();

  proceedCommands();
}

void proceedCommands() {
  switch(commandToExecute){
    case COMMAND_EMPTY:
      break;
  }
}
