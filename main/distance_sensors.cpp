
#include "distance_sensors.h"

// Sensor 0 - front facing Sensor
// Sensor 1 - right facing Sensor
// Sensor 2 - left facing Sensor

void setupDistanceSensors() {
  Serial.println("Setting up three VL53L1X - Distance Sensors");
  
  Wire.begin();
  Wire.setClock(400000);

  for (uint8_t i = 0; i < sensorCount; i++) {
      pinMode(xshutPins[i], OUTPUT);
      digitalWrite(xshutPins[i], LOW);
  }

  for (uint8_t i = 0; i < sensorCount; i++) {
      pinMode(xshutPins[i], INPUT);
      delay(10);

      sensors[i].setTimeout(500);
      if (!sensors[i].init())
      {
          Serial.print("Failed to detect and initialize sensor ");
          Serial.println(i);
          while (1);
      }

      sensors[i].setAddress(0x30 + i);
      sensors[i].startContinuous(50);
  }

  Serial.println("Distance sensors are online!");
}

// Returns the distance from the sensor in mm
int readDistanceFront() {
    Serial.println("Reading front distance...");
    uint16_t distance = sensors[0].read();

    if (sensors[0].timeoutOccurred()) {
        Serial.print(" TIMEOUT"); 
    }

    Serial.print("Distance of front facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceRight() {
    Serial.println("Reading front distance...");
    uint16_t distance = sensors[1].read();

    if (sensors[0].timeoutOccurred()) {
        Serial.print(" TIMEOUT");
    }

    Serial.print("Distance of front facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceLeft() {
    Serial.println("Reading front distance...");
    uint16_t distance = sensors[2].read();

    if (sensors[0].timeoutOccurred()) {
        Serial.print(" TIMEOUT");
    }

    Serial.print("Distance of front facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}
