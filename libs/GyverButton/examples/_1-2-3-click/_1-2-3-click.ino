#define BTN_PIN_1 3   // Button 1 pin
#define BTN_PIN_2 4   // Button 2 pin

#include "GyverButton.h"
GButton butt1(BTN_PIN_1); // Set HIGH as default state (internal pull-up)
GButton butt2(BTN_PIN_2); // Set HIGH as default state (internal pull-up)

void setup() {
  Serial.begin(9600);

  // Configure button pins as INPUT_PULLUP
  // pinMode(BTN_PIN_1, INPUT_PULLUP);
  // pinMode(BTN_PIN_2, INPUT_PULLUP);
}

void loop() {
  butt1.tick();  // Mandatory tick function
  butt2.tick();  // Mandatory tick function

  // Button 1
  if (butt1.isSingle()) Serial.println("Single 1");
  if (butt1.isDouble()) Serial.println("Double 1");
  if (butt1.isTriple()) Serial.println("Triple 1");
  if (butt1.isHolded()) Serial.println("Holded 1");

  // Button 2
  if (butt2.isSingle()) Serial.println("Single 2");
  if (butt2.isDouble()) Serial.println("Double 2");
  if (butt2.isTriple()) Serial.println("Triple 2");
  if (butt2.isHolded()) Serial.println("Holded 2");

  // Both buttons held
  if (butt1.isHolded() && butt2.isHolded()) {
    Serial.println("Both buttons held");
  }
}
