#ifndef MOTORS_H
#define MOTORS_H

#include "barcode.h"
#include "L298NX2.h"
#include "distance_sensors.h"
#include "voice.h"

#include <Arduino.h>
#include <vector>
#include <string>

#define MIN_DISTANCE_FRONT             75  
#define EXTRA_FOR_MIN_DISTANCE_FRONT   100
#define WALL_DISTANCE_FRONT            160

#define MIN_MIN_DISTANCE_SIDE          65   
#define MIN_DISTANCE_SIDE              70
#define MAX_DISTANCE_SIDE              90       
#define Difference_DISTANCE_SIDE_HALF  7  

#define MIN_DISTANCE_TO_TURN           85
    
#define MAX_MAX_DISTANCE_SIDE          210    

#define FORWARD_DELAY_CORRECTION       150 


// motor A is the left side motor
// motor B is the right side motor

// Motor A
#define EN_A    13
#define IN1_A   12
#define IN2_A   14
#define PWMA    255    // 225Value from 0 to 255

// Motor B
#define EN_B    25
#define IN1_B   27
#define IN2_B   26
#define PWMB    255    // Value from 0 to 255

void setupMotorPins();

void turn_90_degree_right();
void turn_90_degree_left();
void turn_180_degree_left();

void changeCloserWall();
void beforeTurn();
void afterTurn();
void wallOrConjunction(bool isRegular);
void moveCorrect();

void setMotorsValueBySensors();
void setMotorsValueBySensorsForF();

void goBack();
void goBackF();

void setMotorsValueBySensorsForFMode2();

#endif
