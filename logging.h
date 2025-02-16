#ifndef LOGGING_H
#define LOGGING_H

#include "config.h"

#if IS_LOGS_ON
  #define LOG_PRINT(...) Serial.print(__VA_ARGS__)
  #define LOG_PRINTLN(...) Serial.println(__VA_ARGS__)
#else
  #define LOG_PRINT(...)   // Do nothing
  #define LOG_PRINTLN(...) // Do nothing
#endif

#if IS_LOGS_ON
  #define LOG_SERIAL(...) Serial.begin(__VA_ARGS__)
#else
  #define LOG_SERIAL(...)   // Do nothing
#endif

#endif // LOGGING_H