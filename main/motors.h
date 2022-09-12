
#ifndef MOTORS_H
#define MOTORS_H

#include "barcode.h"
#include "L298NX2.h"
#include "distance_sensors.h"
#include "leds.h"

#include <Arduino.h>
#include <vector>
#include <string>

#define MIN_DISTANCE_FRONT 200
#define MIN_DISTANCE_SIDE 150
#define MAX_DISTANCE_SIDE 750
#define CORNER_DELAY 3815
#define CORNER_DELAY_FORWARD 400
#define RIGHT_DELAY_CORRECTION 250
#define RIGHT_DELAY_CORRECTION_FORWARD 1000
#define LEFT_DELAY_CORRECTION 250
#define LEFT_DELAY_CORRECTION_FORWARD 1000

// motor A is the left side motor
// motor B is the right side motor

// Motor A
#define EN_A   25
#define IN1_A  26
#define IN2_A  27
#define PWMA   240    // Value from 0 to 255

// Motor B
#define EN_B   13
#define IN1_B  14
#define IN2_B  12
#define PWMB   210    // Value from 0 to 255

void setupMotorPins();
void turn_90_degree_right();
void turn_90_degree_left();
void setMotorsValueBySensors(int distance_front, int distance_right, int distance_left);
void setMotorsValueBySensors(int distance_right, int distance_left);

#endif
