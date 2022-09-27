
#include "motors.h"

L298NX2* motors;
extern std::vector<turn> instructions;
extern std::vector<turn> reverse_instructions;
extern bool isFinish;
extern bool isGameOver;
extern bool isGoBack;
extern bool isStartingNow;
extern bool isReturnBack;
extern bool isSolutionFinished;

void setupMotorPins() {
  Serial.println("Starting motor setup pins");
  
  // With Enable pin to control speed
  //                         motor A             motor B
  //                   | --------------- | | --------------- |
  motors = new L298NX2(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);
  motors->setSpeedA(PWMA);
  motors->setSpeedB(PWMB);
}

void turn_90_degree_right() {
    Serial.println("Go Right (90 degree corner)");
    motors->forwardA();
    motors->backwardB();
    havhavRight();
    motors->forwardB();
}

void turn_90_degree_left() {
    Serial.println("Go Left (90 degree corner)");
    motors->backwardA();
    motors->forwardB();
    havhavLeft();
    motors->forwardA();
}

void turn_180_degree_left() {
    Serial.println("Go Left (90 degree corner)");
    motors->backwardA();
    motors->forwardB();
    havhavLeft_180();
    motors->forwardA();
}

void moveCorrect(){
  if ((readDistanceLeft() < MIN_DISTANCE_SIDE)) { // The minion is too close to the wall from the left side
    Serial.println("Go Right");
    // turn to the right
    motors->forwardA();
    motors->stopB();
    delay(SIDE_DELAY_CORRECTION);
    motors->forwardB();
  }

  else if ((readDistanceRight() < MIN_DISTANCE_SIDE)) { // The minion is too close to the wall from the right side
    Serial.println("Go Left");
    // turn to the left
    motors->stopA();
    motors->forwardB();
    delay(SIDE_DELAY_CORRECTION);
    motors->forwardA();
  }

//  else if (readDistanceFront() < MIN_MAX_DISTANCE_FRONT) { // The minion is too close to the wall from the front side
//    if(readDistanceRight() < readDistanceLeft()){
//      Serial.println("Go Left");
//      // turn to the left
//      motors->stopA();
//      motors->forwardB();
//      delay(SIDE_DELAY_CORRECTION);
//      motors->forwardA();
//    } else{
//      Serial.println("Go Right");
//      // turn to the right
//      motors->forwardA();
//      motors->stopB();
//      delay(SIDE_DELAY_CORRECTION);
//      motors->forwardB();
//    }
//  }
    
  else { // The minion is ok, keep moving forward
    Serial.println("Go Forward");
    motors->forward();
  }
}

void setMotorsValueBySensors() {
//  if(isStartingNow == true){
//    if(readDistanceFront() > MAX_DISTANCE_FRONT){
//      int cm = START_DELAY_CORRECTION/10;
//      for(int i = 0; i < START_DELAY_CORRECTION; i += cm){
//        delay(cm);
//        moveCorrect();
//      }
//    }
//    isStartingNow = false;
//  }
    
  if ((readDistanceRight() > MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_DISTANCE_SIDE)) { // The minion in front of a wall or in a conjunction
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

      int cm = BEFORE_CORNER_DELAY/10;
      for(int i = 0; i < BEFORE_CORNER_DELAY; i += cm){
        delay(cm);
        moveCorrect();
      }
      color_hair();

      if (current == Left) {
        turn_90_degree_left();
      }
      else if (current == Right) {
        turn_90_degree_right();
      }
      else if (current == Forward) {
        motors->forward();
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

      if(readDistanceFront() > MAX_DISTANCE_FRONT/2){
        int cm = FRONT_DELAY_CORRECTION/10;
        for(int i = 0; i < FRONT_DELAY_CORRECTION; i += cm){
          delay(cm);
          moveCorrect();
        }
      }
      color_hair();
  }
    
  else {
    moveCorrect();
  }
}

void setMotorsValueBySensorsForF() {
    if (((readDistanceFront() < MIN_DISTANCE_FRONT))
        || ((readDistanceFront() > MAX_DISTANCE_SIDE) && (readDistanceRight() > MAX_DISTANCE_SIDE) && (readDistanceLeft() > MAX_DISTANCE_SIDE))){ // The minion in front of a wall or in a conjunction
        Serial.println("Wrong Solution :(");
        motors->stop();
        coffin_dance();
        color_hair();
        turn_180_degree_left();
        color_hair();
        isGoBack = true;
        isStartingNow = true;
    } 

    else {
      moveCorrect();
    }
}

void goBack(){
//  if(isStartingNow == true){
//    if(readDistanceFront() > MAX_DISTANCE_FRONT){
//      int cm = START_DELAY_CORRECTION/10;
//      for(int i = 0; i < START_DELAY_CORRECTION; i += cm){
//        delay(cm);
//        moveCorrect();
//      }
//    }
//    isStartingNow = false;
//  }
      
  if ((readDistanceRight() > MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_DISTANCE_SIDE)) { // The minion in front of a wall or in a conjunction
    turn current = reverse_instructions.back();
    reverse_instructions.pop_back();

    turn temp = current;
    switch (current) {
      case(Right_A): current = Left; break;
      case(Right_B): current = Left; break;
      case(Right_C): current = Left; break;
      case(Right_D): current = Left; break;
      case(Left_a): current = Right; break;
      case(Left_b): current = Right; break;
      case(Left_c): current = Right; break;
      case(Left_d): current = Right; break;
      case(Forward_E): current = Forward; break;
      case(Forward_e): current = Forward; break;
    }

    int cm = BEFORE_CORNER_DELAY/10;
    for(int i = 0; i < BEFORE_CORNER_DELAY; i += cm){
      delay(cm);
      moveCorrect();
    }
      
    if (current == Left) {
      turn_90_degree_left();
    }
    else if (current == Right) {
      turn_90_degree_right();
    }
    else if (current == Forward) {
      motors->forward();
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

    if(readDistanceFront() > MAX_DISTANCE_FRONT/2){
      int cm = FRONT_DELAY_CORRECTION/10;
      for(int i = 0; i < FRONT_DELAY_CORRECTION; i += cm){
        delay(cm);
        moveCorrect();
      }
    }
  }

  else{
    moveCorrect();
  }
}

void goBackF() {
    if (((readDistanceFront() > MAX_DISTANCE_SIDE) && (readDistanceRight() > MAX_DISTANCE_SIDE) && (readDistanceLeft() > MAX_DISTANCE_SIDE))){ // The minion in front of a wall or in a conjunction
        Serial.println("The minion return to start point ...");
        isReturnBack = true;
        isStartingNow = true;
    } 

    else {
      moveCorrect();
    }
}

void setMotorsValueBySensorsForFMode2() {
    if (((readDistanceFront() < MIN_DISTANCE_FRONT))
        || ((readDistanceFront() > MAX_DISTANCE_SIDE) && (readDistanceRight() > MAX_DISTANCE_SIDE) && (readDistanceLeft() > MAX_DISTANCE_SIDE))){ // The minion in front of a wall or in a conjunction
        Serial.println("Solution is finished");
        motors->stop();
        color_hair();
        isSolutionFinished = true;
    } 

    else {
      moveCorrect();
    }
}