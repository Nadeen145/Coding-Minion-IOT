
//using namespace std;

#include "motors.h"

L298NX2* motors;
extern std::vector<turn> instructions;

void setupMotorPins() {
  Serial.println("Starting motor setup pins");
  
  // With Enable pin to control speed
  //                         motor A             motor B
  //                   | --------------- | | --------------- |
  motors = new L298NX2(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);
  motors->setSpeedA(PWMA);
  motors->setSpeedB(PWMB);
}

void turn_90_degree_left() {
    Serial.println("Go Right (90 degree corner)");
    motors->forwardA();
    motors->stopB();
    delay(CORNER_DELAY);
    motors->forwardB();
    delay(CORNER_DELAY_FORWARD);
}

void turn_90_degree_right() {
    Serial.println("Go Left (90 degree corner)");
    motors->stopA();
    motors->forwardB();
    delay(CORNER_DELAY);
    motors->forwardA();
    delay(CORNER_DELAY_FORWARD);
}

void setMotorsValueBySensors(int distance_front, int distance_right) {
    if (distance_front < MIN_DISTANCE_FRONT) { // We have to turn according to turn_direction
        turn current = instructions.back();
        instructions.pop_back();

        if (current == Left) {
            turn_90_degree_left();
            delay(1500);
            Serial.print("Corner front: ");
//            Serial.print(readDistanceFront());
            Serial.print(" right: ");
            Serial.print(readDistanceRight());
//            Serial.print(" left: ");
//            Serial.println(readDistanceLeft());
        }
        else if (current == Right) {
            turn_90_degree_right();
            delay(1500);
            Serial.print("Corner front: ");
//            Serial.print(readDistanceFront());
            Serial.print(" right: ");
            Serial.print(readDistanceRight());
//            Serial.print(" left: ");
//            Serial.println(readDistanceLeft());
        }
    }
    else if (distance_right < MIN_DISTANCE_SIDE) { // We are too close to the wall from the right side
        Serial.println("Go Left");
        // turn to the left
        motors->forwardA();
        motors->stopB();
        delay(RIGHT_DELAY_CORRECTION);
        motors->forwardB();
        delay(RIGHT_DELAY_CORRECTION_FORWARD);
    }
    else if (distance_right > MAX_DISTANCE_SIDE) { // We are too far from the wall from the left side
        Serial.println("Go Right");
        // turn to the right
        motors->stopA();
        motors->forwardB();
        delay(LEFT_DELAY_CORRECTION);
        motors->forwardA();
        delay(LEFT_DELAY_CORRECTION_FORWARD);
    }
    else { // If we got to this point, we are not in a corner and the Minion is ok then move forward
        Serial.println("Go Forward");
        motors->forward();
    }
}
