#ifndef LOGGING_H
#define LOGGING_H

// Define IS_LOGS_ON to 1 to enable logs, or 0 to disable them
#define IS_LOGS_ON 1

#if IS_LOGS_ON
  #define LOG_PRINT(...) Serial.print(__VA_ARGS__)
  #define LOG_PRINTLN(...) Serial.println(__VA_ARGS__)
#else
  #define LOG_PRINT(...)   // Do nothing
  #define LOG_PRINTLN(...) // Do nothing
#endif

#endif // LOGGING_H