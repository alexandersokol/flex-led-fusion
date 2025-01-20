#ifndef IR_H
#define IR_H

#include "config.h"
#include "logging.h"

#if IS_IR_ON
  #include <IRremote.hpp> 

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
    IrReceiver.begin(PIN_IR_RECEIVE, false);
  }

  void irLoop() {
    if (IrReceiver.decode()) {
      IrReceiver.resume();

      if (IrReceiver.decodedIRData.command == 0x0){
        return;
      }
      if (millis() - lastIRDebunceTime < IR_DEBOUNCE_DELAY){
        return;
      }
      lastIRDebunceTime = millis();

      switch(IrReceiver.decodedIRData.command){
        case IR_CODE_POWER:
        // TODO Power pressed
        break;
        case IR_CODE_TIMER:
        // TODO Timer pressed
        break;
        case IR_CODE_CIRCLE_S_PLUS:
        // TODO Circle S+ pressed
        break;
        case IR_CODE_CIRCLE_S_MINUS:
        // TODO Circle S- pressed
        break;
        case IR_CODE_CIRCLE_B_PLUS:
        // TODO Circle B+ pressed
        break;
        case IR_CODE_CIRCLE_B_MINUS:
        // TODO Circle B- pressed
        break;
        case IR_CODE_NEBULA:
        // TODO Nebula pressed
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
        // TODO Star pressed
        break;
      }
    }
  }
#else
  #define IR_BEGIN(...)    // Do nothing
  #define IR_LOOP(...)     // Do nothing
#endif

#endif // IR_H