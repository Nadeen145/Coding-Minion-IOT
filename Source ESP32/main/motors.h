#ifndef MOTORS_H
#define MOTORS_H

#include "barcode.h"
#include "L298NX2.h"
#include "distance_sensors.h"
#include "voice.h"

#include <Arduino.h>
#include <vector>
#include <string>

#define MIN_DISTANCE_FRONT 55
#define MIN_DISTANCE_SIDE 45
#define MAX_DISTANCE_SIDE 210
#define CORNER_DELAY 2200
#define RIGHT_DELAY_CORRECTION 250
#define RIGHT_DELAY_CORRECTION_FORWARD 1000
#define LEFT_DELAY_CORRECTION 250
#define LEFT_DELAY_CORRECTION_FORWARD 1000

// motor A is the left side motor
// motor B is the right side motor

// Motor A
#define EN_A    13
#define IN1_A   12
#define IN2_A   14
#define PWMA    255    // Value from 0 to 255

// Motor B
#define EN_B    25
#define IN1_B   27
#define IN2_B   26
#define PWMB    7    // Value from 0 to 255

void setupMotorPins();
void turn_90_degree_right();
void turn_90_degree_left();
void setMotorsValueBySensors(int distance_right, int distance_left);
void setMotorsValueBySensors(int distance_front, int distance_right, int distance_left);
void goBack(int distance_front, int distance_right, int distance_left);

#endif
