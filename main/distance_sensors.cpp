
#include "distance_sensors.h"

// Sensor 1 - front facing Sensor
// Sensor 2 - right facing Sensor
// Sensor 3 - left facing Sensor
  
TwoWire I2C_1 = TwoWire(0);
TwoWire I2C_2 = TwoWire(1);

SFEVL53L1X distanceSensor1(I2C_1);
SFEVL53L1X distanceSensor2(I2C_2);
SFEVL53L1X distanceSensor3(I2C_2);

// Sets up 3 sda and scl in the define pins
void setupDistanceSensors() {
  Serial.println("Setting up three VL53L1X - Distance Sensors");
  uint32_t my_freq = 100000;

  I2C_1.begin(SDA_1, SCL_1, my_freq);
  I2C_2.begin(SDA_2, SCL_2, my_freq);

  if (distanceSensor1.begin() != 0) { //Begin returns 0 on a good init
    Serial.println("Front facing sensor failed to begin. Please check wiring. Freezing...");
    while (1);
  }
  Serial.println("Front facing sensor is online!");
  
  pinMode(XSHUT_3, OUTPUT);
  digitalWrite(XSHUT_3, LOW);

  if (distanceSensor2.begin() != 0) { //Begin returns 0 on a good init
      Serial.println("Right facing sensor failed to begin. Please check wiring. Freezing...");
      while (1);
  }
  else {
      distanceSensor2.setI2CAddress(ADDRESS_2);
  }
  Serial.println("Right facing sensor is online!");

  if (distanceSensor3.begin() != 0) { //Begin returns 0 on a good init
      Serial.println("Left facing sensor failed to begin. Please check wiring. Freezing...");
      while (1);
  }
  else {
      digitalWrite(XSHUT_3, HIGH);
      distanceSensor3.setI2CAddress(ADDRESS_3);
  }
  Serial.println("Left facing sensor is online!");
}

// Returns the distance from the sensor in mm
int readDistanceFront() {
    Serial.println("Reading front distance...");
    distanceSensor1.startRanging(); // Write configuration bytes to initiate measurement
    while (!distanceSensor1.checkForDataReady()) {
        delay(1);
    }

    int distance = distanceSensor1.getDistance(); // Get the result of the measurement from the sensor
    distanceSensor1.clearInterrupt();
    distanceSensor1.stopRanging();

    Serial.print("Distance of front facing sensor (mm): ");
    Serial.println(distance);
    Serial.println("Done reading front distance");

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceRight() {
    Serial.println("Reading right distance...");
    distanceSensor2.startRanging(); // Write configuration bytes to initiate measurement
    while (!distanceSensor2.checkForDataReady()) {
        delay(1);
    }

    int distance = distanceSensor2.getDistance(); // Get the result of the measurement from the sensor
    distanceSensor2.clearInterrupt();
    distanceSensor2.stopRanging();

    Serial.print("Distance of right facing sensor (mm): ");
    Serial.println(distance);
    Serial.println("Done reading right distance");

    return distance;
}

// Returns the distance from the sensor in mm
int readDistanceLeft() {
    Serial.println("Reading left distance...");
    distanceSensor3.startRanging(); // Write configuration bytes to initiate measurement
    while (!distanceSensor3.checkForDataReady()) {
        delay(1);
    }

    int distance = distanceSensor3.getDistance(); // Get the result of the measurement from the sensor
    distanceSensor3.clearInterrupt();
    distanceSensor3.stopRanging();

    Serial.print("Distance of left facing sensor (mm): ");
    Serial.println(distance);
    Serial.println("Done reading left distance");

    return distance;
}
