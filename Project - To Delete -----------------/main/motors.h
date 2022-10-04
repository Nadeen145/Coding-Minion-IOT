#ifndef MOTORS_H
#define MOTORS_H

#include "barcode.h"
#include "L298NX2.h"
#include "distance_sensors.h"
#include "voice.h"

#include <Arduino.h>
#include <vector>
#include <string>

#define MIN_DISTANCE_FRONT             70  //75
#define EXTRA_FOR_MIN_DISTANCE_FRONT   45
#define MAX_DISTANCE_FRONT             300
#define WALL_DISTANCE_FRONT            250

#define MIN_MIN_DISTANCE_SIDE          60   
#define MIN_DISTANCE_SIDE              70
#define MAX_DISTANCE_SIDE              90   //95    
#define Difference_DISTANCE_SIDE_HALF  12  

#define MIN_DISTANCE_TO_TURN      100
    
#define MAX_MAX_DISTANCE_SIDE     210
#define MIN_DISTANCE_SIDE_LINE    180
#define MAX_DISTANCE_SIDE_LINE    200       

#define MAX_LIMIT_SUM             450
#define BEFORE_CORNER_DELAY       1800

#define FRONT_DELAY_CORRECTION            2500
#define FORWARD_DELAY_CORRECTION          250 
#define FORWARD_DELAY_CORRECTION_TURN     300 
#define FORWARD_DELAY_CORRECTION_LINE     1000 
#define FORWARD_DELAY_CORRECTION_LINE_12  1200 
#define FORWARD_DELAY_CORRECTION_MOVE     750 


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
