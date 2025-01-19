#include "button.h"
#include "logging.h"

Button::Button(int buttonPin, char buttonName) {
  pin = buttonPin;
  name = buttonName;
  pinMode(pin, INPUT_PULLUP);
}

void Button::loop() {
    bool currentState = digitalRead(pin) == LOW;

    if(currentState != state) {
      if(millis() - lastDebounceTime > BUTTON_DEBOUNCE_DELAY) {
        state = currentState;
        lastDebounceTime = millis();

        if (state) {
          LOG_PRINT(name);
          LOG_PRINTLN(" pressed!");
        }
      }
    }
}

int Button::clicks() {
  return clickCount;
}