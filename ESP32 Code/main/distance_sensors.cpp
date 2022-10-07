
#include "distance_sensors.h"

// Sensor 0 - front facing Sensor
// Sensor 1 - right facing Sensor
// Sensor 2 - left facing Sensor

const uint8_t sensorCount = 3;
const uint8_t xshutPins[sensorCount] = { 18, 23, 19 };
VL53L1X sensors[sensorCount];

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
    uint16_t distance = sensors[0].read();
    if (sensors[0].timeoutOccurred()) {
        Serial.print(" TIMEOUT");
    }
    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceRight() {
    uint16_t distance = sensors[1].read();
    if (sensors[0].timeoutOccurred()) {
        Serial.print(" TIMEOUT");
    }
    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceLeft() {
    uint16_t distance = sensors[2].read();
    if (sensors[0].timeoutOccurred()) {
        Serial.print(" TIMEOUT");
    }
    return distance;
}

void printDistances(){
   Serial.print(readDistanceLeft());
   Serial.print("          ");
   Serial.print(readDistanceFront());
   Serial.print("          ");
   Serial.println(readDistanceRight());
}
