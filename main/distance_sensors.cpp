
#include "distance_sensors.h"

// Sensor 1 - front facing Sensor
// Sensor 2 - right facing Sensor
// Sensor 3 - left facing Sensor
  
VL53L1X distanceSensor1();
VL53L1X distanceSensor2();
VL53L1X distanceSensor3();

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
  distanceSensor1.init();
  distanceSensor1.setAddress(ADDRESS_1);
  distanceSensor1.setDistanceMode(VL53L1X::long);
  distanceSensor1.setMeasurementTimingBudget(MAX_DISTANCE);
  distanceSensor1.startContinuous(50);
  distanceSensor1.setTimeout(100);

  digitalWrite(XSHUT_2, HIGH);
  distanceSensor2.init();
  distanceSensor2.setAddress(ADDRESS_2);
  distanceSensor2.setDistanceMode(VL53L1X::long);
  distanceSensor2.setMeasurementTimingBudget(MAX_DISTANCE);
  distanceSensor2.startContinuous(50);
  distanceSensor2.setTimeout(100);

  digitalWrite(XSHUT_3, HIGH);
  distanceSensor3.init();
  distanceSensor3.setAddress(ADDRESS_3);
  distanceSensor3.setDistanceMode(VL53L1X::long);
  distanceSensor3.setMeasurementTimingBudget(MAX_DISTANCE);
  distanceSensor3.startContinuous(50);
  distanceSensor3.setTimeout(100);

  Wire.endTransmission();
  
  Serial.println("Distance sensors are online!");
}

// Returns the distance from the sensor in mm
int readDistanceFront() {
    Serial.println("Reading front distance...");
    distanceSensor1.read();
    uint16_t distance = distanceSensor1.ranging_data.range_status;
    
    if (distance < 3) {
        distanceSensor1.ranging_data.range_mm;
    }
    else {
        distance = 0;
    }

    if (distance > MAX_DISTANCE) {
        distance = MAX_DISTANCE;
    }

    Serial.print("Distance of front facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceRight() {
    Serial.println("Reading right distance...");
    distanceSensor2.read();
    uint16_t distance = distanceSensor2.ranging_data.range_status;

    if (distance < 3) {
        distanceSensor2.ranging_data.range_mm;
    }
    else {
        distance = 0;
    }

    if (distance > MAX_DISTANCE) {
        distance = MAX_DISTANCE;
    }

    Serial.print("Distance of right facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceLeft() {
    Serial.println("Reading left distance...");
    distanceSensor3.read();
    uint16_t distance = distanceSensor3.ranging_data.range_status;

    if (distance < 3) {
        distanceSensor3.ranging_data.range_mm;
    }
    else {
        distance = 0;
    }

    if (distance > MAX_DISTANCE) {
        distance = MAX_DISTANCE;
    }

    Serial.print("Distance of left facing sensor (mm): ");
    Serial.println(distance);

    return distance;
}
