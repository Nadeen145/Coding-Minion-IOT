
#ifndef DISTANCE_SENSORS_H
#define DISTANCE_SENSORS_H

#include <Arduino.h>
#include <Wire.h>
#include <VL53L1X.h> 

// Sensor 0 - front facing Sensor
// Sensor 1 - right facing Sensor
// Sensor 2 - left facing Sensor

void setupDistanceSensors();
int readDistanceFront();  
int readDistanceRight();  
int readDistanceLeft();

#endif
