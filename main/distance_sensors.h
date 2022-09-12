
#ifndef DISTANCE_SENSORS_H
#define DISTANCE_SENSORS_H

#include <Arduino.h>
//#include <RangeSensor.h>
//#include <SparkFun_VL53L1X.h>
//#include <vl53l1x_class.h>
//#include <vl53l1_error_codes.h>

#include <Wire.h>
#include <VL53L1X.h> 

// Sensor 1 - front facing Sensor
// Sensor 2 - right facing Sensor
// Sensor 3 - left facing Sensor

#define MAX_DISTANCE 4000

#define ADDRESS_1  0x30
#define SCL_1      21
#define SDA_1      19
#define XSHUT_1    23

#define ADDRESS_2  0x31
#define SCL_2      21
#define SDA_2      19
#define XSHUT_2    21

#define ADDRESS_3  0x32
#define SCL_3      21
#define SDA_3      19
#define XSHUT_3    18


void setupDistanceSensors();
int readDistanceFront();  
int readDistanceRight();  
int readDistanceLeft();

#endif
