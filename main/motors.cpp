
#include "motors.h"

L298NX2* motors;
extern std::vector<turn> instructions;
extern bool isFinish;
extern bool isGameOver;

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

void setMotorsValueBySensors(int distance_front, int distance_right, int distance_left) {
    if ((distance_front < MIN_DISTANCE_SIDE) || (distance_right > MAX_DISTANCE_SIDE) || (distance_left > MAX_DISTANCE_SIDE)) { // The minion in front of a wall or in a conjunction
        turn current = instructions.back();
        instructions.pop_back();

        turn temp = current;
        switch (current) {
            case(Right_A): current = Right; break;
            case(Right_B): current = Right; break;
            case(Right_C): current = Right; break;
            case(Right_D): current = Right; break;
            case(Left_a): current = Left; break;
            case(Left_b): current = Left; break;
            case(Left_c): current = Left; break;
            case(Left_d): current = Left; break;
            case(Forward_E): current = Forward; break;
            case(Forward_e): current = Forward; break;
        }

        if (current == Left) {
            turn_90_degree_left();
            delay(1500);
            Serial.print("Corner front: ");
            Serial.print(readDistanceFront());
            Serial.print(" right: ");
            Serial.print(readDistanceRight());
            Serial.print(" left: ");
            Serial.println(readDistanceLeft());
        }
        else if (current == Right) {
            turn_90_degree_right();
            delay(1500);
            Serial.print("Corner front: ");
            Serial.print(readDistanceFront());
            Serial.print(" right: ");
            Serial.print(readDistanceRight());
            Serial.print(" left: ");
            Serial.println(readDistanceLeft());
        }
        else if (current == Forward) {
            motors->forward();
            delay(CORNER_DELAY);
            Serial.print("Corner front: ");
            Serial.print(readDistanceFront());
            Serial.print(" right: ");
            Serial.print(readDistanceRight());
            Serial.print(" left: ");
            Serial.println(readDistanceLeft());
        }

        switch (temp) {
            case(Right_A): color_A(); break;
            case(Right_B): color_B(); break;
            case(Right_C): color_C(); break;
            case(Right_D): color_D(); break;
            case(Left_a): color_a(); break;
            case(Left_b): color_b(); break;
            case(Left_c): color_c(); break;
            case(Left_d): color_d(); break;
            case(Forward_E): color_E(); break;
            case(Forward_e): color_e(); break;
        }

    }
    else if (distance_right < MIN_DISTANCE_SIDE) { // The minion is too close to the wall from the right side
        Serial.println("Go Left");
        // turn to the left
        motors->forwardA();
        motors->stopB();
        delay(RIGHT_DELAY_CORRECTION);
        motors->forwardB();
        delay(RIGHT_DELAY_CORRECTION_FORWARD);
    }
    else if (distance_left < MIN_DISTANCE_SIDE) { // The minion is too close to the wall from the left side
        Serial.println("Go Right");
        // turn to the right
        motors->stopA();
        motors->forwardB();
        delay(LEFT_DELAY_CORRECTION);
        motors->forwardA();
        delay(LEFT_DELAY_CORRECTION_FORWARD);
    }
    else { // The minion is ok, keep moving forward
        Serial.println("Go Forward");
        motors->forward();
    }
}

void setMotorsValueBySensors(int distance_right, int distance_left) {
    if ((distance_right > MAX_DISTANCE_SIDE) || (distance_left > MAX_DISTANCE_SIDE)) { // The minion in front of a wall or in a conjunction
        Serial.println("Wrong Solution :(");
        motors->stop();
        // voice "Game Over!!!"
        isFinish = false;
        isGameOver = true;
        color_hair();
    }
    if (distance_right < MIN_DISTANCE_SIDE) { // The minion is too close to the wall from the right side
        Serial.println("Go Left");
        // turn to the left
        motors->forwardA();
        motors->stopB();
        delay(RIGHT_DELAY_CORRECTION);
        motors->forwardB();
        delay(RIGHT_DELAY_CORRECTION_FORWARD);
    }
    else if (distance_left < MIN_DISTANCE_SIDE) { // The minion is too close to the wall from the left side
        Serial.println("Go Right");
        // turn to the right
        motors->stopA();
        motors->forwardB();
        delay(LEFT_DELAY_CORRECTION);
        motors->forwardA();
        delay(LEFT_DELAY_CORRECTION_FORWARD);
    }
    else { // The minion is ok, keep moving forward
        Serial.println("Go Forward");
        motors->forward();
    }
}
