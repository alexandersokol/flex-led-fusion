#ifndef COMMANDS_H
#define COMMANDS_H

#define COMMAND_EMPTY 0
#define COMMAND_NEXT_EFFECT 1
#define COMMAND_PREV_EFFECT 2

uint8_t pendingCommand = COMMAND_EMPTY;

void queueCommand(uint8_t newCommand){
  pendingCommand = newCommand;
}

#endif // COMMANDS_H