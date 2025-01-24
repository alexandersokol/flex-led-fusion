#ifndef BUTTONS_H
#define BUTTONS_H

#include "config.h"
#include "commands.h"
#include "logging.h"

#if IS_BUTTONS_ON
  #include "GyverButton.h"

  #define BUTTONS_LOOP(...) buttonsLoop()

  GButton buttonYellow(PIN_BUTTON_YELLOW);
  GButton buttonBlue(PIN_BUTTON_BLUE);

  void loopButtonInputs() {
    if(buttonYellow.isSingle()){
      queueCommand(COMMAND_PREV_EFFECT);
    }
    if(buttonYellow.isDouble()){
      queueCommand(COMMAND_BRIGHTNESS_DOWN);
    }
    if(buttonYellow.isTriple()){
      // TODO Yellow button tripple click
    }
    if(buttonBlue.isSingle()){
      queueCommand(COMMAND_NEXT_EFFECT);
    }
    if(buttonBlue.isDouble()){
      queueCommand(COMMAND_BRIGHTNESS_UP);
    }
    if(buttonBlue.isTriple()){
      queueCommand(COMMAND_NEXT_GENERIC_MODE);
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