
#ifndef MOTORS_H
#define MOTORS_H

#include "connection.h"
#include "barcode.h"
#include <Arduino.h>
#include <L298NX2.h>
#include <WebSerial.h>
#include <list>
#include <string>

#define MIN_DISTANCE_FRONT 150
#define MIN_DISTANCE_SIDE 130

#define CORNER_DELAY 500
#define CORNER_DELAY_FORWARD 400
#define RIGHT_DELAY_CORRECTION 120
#define RIGHT_DELAY_CORRECTION_FORWARD 180
#define LEFT_DELAY_CORRECTION 100
#define LEFT_DELAY_CORRECTION_FORWARD 160


// #define WALL_DIST_CORRECTION_DELAY 85

// motor A is the left side motor
// motor B is the right side motor

// Motor A
#define EN_A 14
#define IN1_A 27
#define IN2_A 26
#define PWMA 210    // Value from 0 to 255.

// Motor B
#define EN_A 25
#define IN1_B 13
#define IN2_B 12
#define PWMB 210    // Value from 0 to 255.


// #define PWM_TO_TURN 25    // Value from 0 to 255.

extern List<turn> instructions;

/*
extern int speed;          // Value from 0 to 255.
extern int speed_to_turn;  // Value from 0 to 255.
extern bool backward;
extern bool right;
extern bool left;
extern bool forward;
*/


void setupMotorPins();

void turn_90_degree_left();
void turn_90_degree_right();

void setMotorsValueBySensors(int distance_front, int distance_right, int distance_left, int turn_direction);

#endif
