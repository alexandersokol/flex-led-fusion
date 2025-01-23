#ifndef COMMANDS_H
#define COMMANDS_H

#define COMMAND_EMPTY 0
#define COMMAND_NEXT_EFFECT 1
#define COMMAND_PREV_EFFECT 2
#define COMMAND_BRIGHTNESS_UP 3
#define COMMAND_BRIGHTNESS_DOWN 4
#define COMMAND_TOGGLE_LED_ON 5
#define COMMAND_TOGGLE_EFFECT_SWITCH_ON 6
#define COMMAND_TOGGLE_SPARKS_ON 7

uint8_t pendingCommand = COMMAND_EMPTY;

void queueCommand(uint8_t newCommand){
  pendingCommand = newCommand;
}

#endif // COMMANDS_H