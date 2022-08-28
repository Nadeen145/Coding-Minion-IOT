
#include "motors.h"
#include "distance_sensors.h"
#include "barcode.h"

#include <L298NX2.h>

// extern int cornerNumber;
// extern int currCornerNumber; //  0 - (corner_number-1)

L298NX2* motors;
extern List<turn> instructions;


void setupMotorPins() {
  // WebSerial.println("Starting motor setup pins");
  
  // With Enable pin to control speed
  //                         motor A             motor B
  //                   | --------------- | | --------------- |
  motors = new L298NX2(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);
  motors->setSpeedA(PWMA);
  motors->setSpeedB(PWMB);
  motors->forward();
}

void turn_90_degree_left() {
    WebSerial.println("Go Left (90 degree corner)");
    motors->forwardA();
    motors->stopB();
    delay(CORNER_DELAY);
    motors->forwardB();
    delay(CORNER_DELAY_FORWARD);
}

void turn_90_degree_right() {
    WebSerial.println("Go Right (90 degree corner)");
    motors->stopA();
    motors->forwardB();
    delay(CORNER_DELAY);
    motors->forwardA();
    delay(CORNER_DELAY_FORWARD);
}

void setMotorsValueBySensors(int distance_front, int distance_right, int distance_left) {
    if (distance_front < MIN_DISTANCE_FRONT) { // We have to turn according to turn_direction
        turn current = instructions.pop_front();

        if (current == Left) {
            turn_90_degree_left();
            delay(1500);
            WebSerial.print("Corner front: ");
            WebSerial.print(readDistanceFront());
            WebSerial.print(" right: ");
            WebSerial.print(readDistanceRight());
            WebSerial.print(" left: ");
            WebSerial.println(readDistanceLeft());
        }
        else if (current == Right) {
            turn_90_degree_right();
            delay(1500);
            WebSerial.print("Corner front: ");
            WebSerial.print(readDistanceFront());
            WebSerial.print(" right: ");
            WebSerial.print(readDistanceRight());
            WebSerial.print(" left: ");
            WebSerial.println(readDistanceLeft());
        }
    }
    else if (distance_right < MIN_DISTANCE_SIDE) { // We are too close to the wall from right side
        WebSerial.println("Go Left");
        // turn to the left
        motors->forwardA();
        motors->stopB();
        delay(RIGHT_DELAY_CORRECTION);
        motors->forwardB();
        delay(RIGHT_DELAY_CORRECTION_FORWARD);
    }
    else if (distance_left < MIN_DISTANCE_SIDE) { // We are too close to the wall from left side
        WebSerial.println("Go Right");
        // turn to the right
        motors->stopA();
        motors->forwardB();
        delay(CORNER_DELAY);
        motors->forwardA();
        delay(CORNER_DELAY_FORWARD);
    }
    else { // If we got to this point, we are not in a corner and the Minion is ok then move forward
        WebSerial.println("Go Forward");
        motors->forward();
    }
}
