#ifndef IR_H
#define IR_H

#if IS_IR_ON
  #include <IRremote.hpp> 
  #include "config.h"
  #include "logging.h"
  #include "commands.h"

  #define DECODE_NEC
  #define IR_CODE_POWER 0x45
  #define IR_CODE_TIMER 0x47
  #define IR_CODE_CIRCLE_S_PLUS 0x43
  #define IR_CODE_CIRCLE_S_MINUS 0x40
  #define IR_CODE_CIRCLE_B_PLUS 0x9
  #define IR_CODE_CIRCLE_B_MINUS 0x15
  #define IR_CODE_NEBULA 0x44
  #define IR_CODE_S_PLUS 0x19
  #define IR_CODE_S_MINUS 0x46
  #define IR_CODE_B_PLUS 0xD
  #define IR_CODE_B_MINUS 0x7
  #define IR_CODE_STAR 0xFF

  #define IR_DEBOUNCE_DELAY 100

  #define IR_BEGIN(...) irBegin()
  #define IR_LOOP(...) irLoop()

  unsigned long lastIRDebunceTime = 0;

  void irBegin() {
    IrReceiver.begin(PIN_IR_RECEIVE, true);
  }

  void irLoop() {
    if (IrReceiver.decode()) {
      IrReceiver.resume();

      if (IrReceiver.decodedIRData.command == 0x0) {
        return;
      }

      if (millis() - lastIRDebunceTime < IR_DEBOUNCE_DELAY) {
        return;
      }
      lastIRDebunceTime = millis();

      LOG_PRINT("IR command received: 0x");
      LOG_PRINTLN(IrReceiver.decodedIRData.command, HEX);

      switch(IrReceiver.decodedIRData.command) {
        case IR_CODE_POWER:
          queueCommand(COMMAND_TOGGLE_LED_ON);
          break;
        case IR_CODE_TIMER:
          queueCommand(COMMAND_TOGGLE_EFFECT_SWITCH_ON);
          break;
        case IR_CODE_CIRCLE_S_PLUS:
          queueCommand(COMMAND_NEXT_EFFECT);
          break;
        case IR_CODE_CIRCLE_S_MINUS:
          queueCommand(COMMAND_PREV_EFFECT);
          break;
        case IR_CODE_CIRCLE_B_PLUS:
          queueCommand(COMMAND_BRIGHTNESS_UP);
          break;
        case IR_CODE_CIRCLE_B_MINUS:
          queueCommand(COMMAND_BRIGHTNESS_DOWN);
          break;
        case IR_CODE_NEBULA:
          queueCommand(COMMAND_NEXT_GENERIC_MODE);
        break;
        case IR_CODE_S_PLUS:
        // TODO S+ pressed
        break;
        case IR_CODE_S_MINUS:
        // TODO S- pressed
        break;
        case IR_CODE_B_PLUS:
        // TODO B+ pressed
        break;
        case IR_CODE_B_MINUS:
        // TODO B- pressed
        break;
        case IR_CODE_STAR:
          queueCommand(COMMAND_TOGGLE_SPARKS_ON);
          break;
      }
    }
  }
#else
  #define IR_BEGIN(...)    // Do nothing
  #define IR_LOOP(...)     // Do nothing
#endif

#endif // IR_H