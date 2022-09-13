
#include "button.h"

void setupButtonPin() {
  Serial.println("Starting leds setup pins");

  // Setting up the push button
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

