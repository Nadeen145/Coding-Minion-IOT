
#include "distance_sensors.h"

// Sensor 1 - front facing Sensor
// Sensor 2 - right facing Sensor
// Sensor 3 - left facing Sensor
  
VL53L1X distanceSensors[3];

// Sets up 3 sda and scl in the define pins
void setupDistanceSensors() {
  Serial.println("Setting up three VL53L1X - Distance Sensors");
  
  pinMode(XSHUT_1, OUTPUT);
  pinMode(XSHUT_2, OUTPUT);
  pinMode(XSHUT_3, OUTPUT);
  digitalWrite(XSHUT_1, LOW);
  digitalWrite(XSHUT_2, LOW);
  digitalWrite(XSHUT_3, LOW);
  
  Wire.begin();
  Wire.setClock(400000);
  Wire.beginTransmission(0x29);

  digitalWrite(XSHUT_1, HIGH);
  distanceSensors[0].init();
  distanceSensors[0].setAddress(ADDRESS_1);
  distanceSensors[0].setDistanceMode(VL53L1X::Long);
  distanceSensors[0].setMeasurementTimingBudget(MAX_DISTANCE);
  distanceSensors[0].startContinuous(50);
  distanceSensors[0].setTimeout(100);

  digitalWrite(XSHUT_2, HIGH);
  distanceSensors[1].init();
  distanceSensors[1].setAddress(ADDRESS_2);
  distanceSensors[1].setDistanceMode(VL53L1X::Long);
  distanceSensors[1].setMeasurementTimingBudget(MAX_DISTANCE);
  distanceSensors[1].startContinuous(50);
  distanceSensors[1].setTimeout(100);

  digitalWrite(XSHUT_3, HIGH);
  distanceSensors[2].init();
  distanceSensors[2].setAddress(ADDRESS_3);
  distanceSensors[2].setDistanceMode(VL53L1X::Long);
  distanceSensors[2].setMeasurementTimingBudget(MAX_DISTANCE);
  distanceSensors[2].startContinuous(50);
  distanceSensors[2].setTimeout(100);

  Wire.endTransmission();
  
  Serial.println("Distance sensors are online!");
}

// Returns the distance from the sensor in mm
int readDistanceFront() {
    Serial.println("Reading front distance...");
    distanceSensors[0].read();
    uint16_t distance = distanceSensors[0].ranging_data.range_status;

    Serial.print(distance);
    Serial.println("-------------------");
    
    if (distance < 3) {
        distanceSensors[0].ranging_data.range_mm;
    }
    else {
        distance = 0;
    }

    if (distance > MAX_DISTANCE) {
        distance = 0;
    }

    Serial.print("Distance of front facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceRight() {
    Serial.println("Reading right distance...");
    distanceSensors[1].read();
    uint16_t distance = distanceSensors[1].ranging_data.range_status;

    if (distance < 3) {
        distanceSensors[1].ranging_data.range_mm;
    }
    else {
        distance = 0;
    }

    if (distance > MAX_DISTANCE) {
        distance = 0;
    }

    Serial.print("Distance of right facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceLeft() {
    Serial.println("Reading left distance...");
    distanceSensors[2].read();
    uint16_t distance = distanceSensors[2].ranging_data.range_status;

    if (distance < 3) {
        distanceSensors[2].ranging_data.range_mm;
    }
    else {
        distance = 0;
    }

    if (distance > MAX_DISTANCE) {
        distance = 0;
    }

    Serial.print("Distance of left facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}
