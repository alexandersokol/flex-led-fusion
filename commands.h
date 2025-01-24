#ifndef COMMANDS_H
#define COMMANDS_H

#include "logging.h"

#define COMMAND_EMPTY 0
#define COMMAND_NEXT_EFFECT 1
#define COMMAND_PREV_EFFECT 2
#define COMMAND_BRIGHTNESS_UP 3
#define COMMAND_BRIGHTNESS_DOWN 4
#define COMMAND_TOGGLE_LED_ON 5
#define COMMAND_TOGGLE_EFFECT_SWITCH_ON 6
#define COMMAND_TOGGLE_SPARKS_ON 7
#define COMMAND_NEXT_GENERIC_MODE 8

uint8_t pendingCommand = COMMAND_EMPTY;

void queueCommand(uint8_t newCommand){
  pendingCommand = newCommand;
  LOG_PRINT("Command queued: ");
  LOG_PRINTLN(pendingCommand);
}

#endif // COMMANDS_H