#include "dependencies.h"

GButton buttonYellow(PIN_BUTTON_YELLOW);
GButton buttonBlue(PIN_BUTTON_BLUE);

uint8_t commandToExecute = COMMAND_EMPTY;

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(PIN_IR_RECEIVE, false);
}

void loop() {
  buttonYellow.tick();
  buttonBlue.tick();

  loopButtonInputs();
  loopIRInputs();

  proceedCommands();
}

void loopButtonInputs() {
  if(buttonYellow.isSingle()){
    LOG_PRINTLN("Yellow button single click");
    // TODO Yellow button single click
  }
  if(buttonYellow.isDouble()){
    LOG_PRINTLN("Yellow button double click");
    // TODO Yellow button double click
  }
  if(buttonYellow.isTriple()){
    LOG_PRINTLN("Yellow button tripple click");
    // TODO Yellow button tripple click
  }
  if(buttonBlue.isSingle()){
    LOG_PRINTLN("Blue button single click");
    // TODO Blue button single click
  }
  if(buttonBlue.isDouble()){
    LOG_PRINTLN("Blue button double click");
    // TODO Blue button double click
  }
  if(buttonBlue.isTriple()){
    LOG_PRINTLN("Blue button tripple click");
    // TODO Blue button tripple click
  }
}

void loopIRInputs() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();

    if (IrReceiver.decodedIRData.command == 0x0){
      return;
    }
    LOG_PRINT("IR Command code received: 0x");
    LOG_PRINTLN(IrReceiver.decodedIRData.command, HEX);

    if (IrReceiver.decodedIRData.command == 0x10) {
        // do somethings
    } else if (IrReceiver.decodedIRData.command == 0x11) {
        // do something else
    }
  }
}

void proceedCommands() {
  switch(commandToExecute){
    case COMMAND_EMPTY:
      break;
  }
}
