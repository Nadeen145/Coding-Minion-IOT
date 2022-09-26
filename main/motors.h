#ifndef MOTORS_H
#define MOTORS_H

#include "barcode.h"
#include "L298NX2.h"
#include "distance_sensors.h"
#include "voice.h"

#include <Arduino.h>
#include <vector>
#include <string>

#define MIN_DISTANCE_FRONT   70
#define MAX_DISTANCE_FRONT   300
#define SUPER_MAX_DISTANCE_FRONT   325

#define MIN_DISTANCE_SIDE    60
#define MAX_DISTANCE_SIDE    210
#define MAX_DISTANCE_DIFFERENCE_SIDES 15

#define BEFORE_CORNER_DELAY  1700
#define TURN_DELAY           1000

#define FRONT_DELAY_CORRECTION   2500
#define SIDE_DELAY_CORRECTION    250


// motor A is the left side motor
// motor B is the right side motor

// Motor A
#define EN_A    13
#define IN1_A   12
#define IN2_A   14
#define PWMA    225    // Value from 0 to 255

// Motor B
#define EN_B    25
#define IN1_B   27
#define IN2_B   26
#define PWMB    225    // Value from 0 to 255

void setupMotorPins();
void turn_90_degree_right();
void turn_90_degree_left();
void moveCorrect();
void setMotorsValueBySensors();
void setMotorsValueBySensorsForF();
void goBack();

#endif
