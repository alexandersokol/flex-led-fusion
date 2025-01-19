#include "dependencies.h"

GButton buttonYellow(PIN_BUTTON_YELLOW);
GButton buttonBlue(PIN_BUTTON_BLUE);

uint8_t commandToExecute = COMMAND_EMPTY;

void setup() {
  Serial.begin(9600);

  IR_BEGIN();
}

void loop() {
  buttonYellow.tick();
  buttonBlue.tick();

  loopButtonInputs();
  IR_LOOP();

  proceedCommands();
}

void loopButtonInputs() {
  if(buttonYellow.isSingle()){
    // TODO Yellow button single click
  }
  if(buttonYellow.isDouble()){
    // TODO Yellow button double click
  }
  if(buttonYellow.isTriple()){
    // TODO Yellow button tripple click
  }
  if(buttonBlue.isSingle()){
    // TODO Blue button single click
  }
  if(buttonBlue.isDouble()){
    // TODO Blue button double click
  }
  if(buttonBlue.isTriple()){
    // TODO Blue button tripple click
  }
}

void proceedCommands() {
  switch(commandToExecute){
    case COMMAND_EMPTY:
      break;
  }
}
