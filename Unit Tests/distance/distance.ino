
#include "distance_sensors.h"

void setup() {
  Serial.begin(115200);

  Serial.println("** STARTING ESP SETUP **");

  // Setting up distance sensors
  setupDistanceSensors();

  Serial.println("** FINISHED ESP SETUP **");
}

void loop() { 
  printDistances();
}
