#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON_DEBOUNCE_DELAY 100

#include <Arduino.h>

class Button {
  private:
    int pin;
    char name;
    int clickCount = 0;
    bool state = HIGH;
    unsigned long lastDebounceTime = 0;
  
  public:
    Button(int buttonPin, char buttonName);

    void loop();
    int clicks();
    bool isSingleClick();
    bool isDoubleClick();
    bool isTripleClick();
};

#endif // BUTTON_H