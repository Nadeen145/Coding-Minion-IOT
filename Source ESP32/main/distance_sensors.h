#ifndef DISTANCE_SENSORS_H
#define DISTANCE_SENSORS_H

#include <Arduino.h>
#include <RangeSensor.h>
#include <SparkFun_VL53L1X.h>
#include <vl53l1x_class.h>
#include <vl53l1_error_codes.h>

#include <Wire.h>
#include "SparkFun_VL53L1X.h" 
#include <WebSerial.h>

// Sensor 1 - front facing Sensor
// Sensor 2 - right facing Sensor
// Sensor 3 - left facing Sensor

#define SCL_1 22
#define SDA_1 21

#define SCL_2 26
#define SDA_2 27

#define SCL_3 26
#define SDA_3 27

void setupDistanceSensors();
int readDistanceFront();  
int readDistanceRight();  
int readDistanceLeft();

#endif
