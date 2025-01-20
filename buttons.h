#ifndef BUTTONS_H
#define BUTTONS_H

#include "config.h"
#include "logging.h"

#if IS_BUTTONS_ON
  #include "GyverButton.h"

  #define BUTTONS_LOOP(...) buttonsLoop()

  GButton buttonYellow(PIN_BUTTON_YELLOW);
  GButton buttonBlue(PIN_BUTTON_BLUE);

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

  void buttonsLoop() {
    buttonYellow.tick();
    buttonBlue.tick();

    loopButtonInputs();
  }
#else
  #define BUTTONS_LOOP(...)    // Do nothing
#endif

#endif // BUTTONS_H