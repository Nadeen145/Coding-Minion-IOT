
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
turn lastMove = Nothing;

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
    lastMove = Right;
}

void turn_90_degree_left() {
    Serial.println("Go Left (90 degree corner)");
    motors->backwardA();
    motors->forwardB();
    havhavLeft();
    motors->forwardA();
    lastMove = Left;
}

void turn_180_degree_left() {
    Serial.println("Go Left (90 degree corner)");
    motors->backwardA();
    motors->forwardB();
    havhavLeft_180();
    motors->forwardA();
    lastMove = Left;
}

void wallOrConjunction(bool isRegular){
  if((isRegular == true)){
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


      if(readDistanceFront() < WALL_DISTANCE_FRONT){
        while(readDistanceFront() > MIN_DISTANCE_FRONT){
//          if(readDistanceFront() < MIN_DISTANCE_FRONT + EXTRA_FOR_MIN_DISTANCE_FRONT){
//            moveCorrect();
//            if(lastMove == Forward){
//                delay(FORWARD_DELAY_CORRECTION_MOVE);
//            }
//            break;
//          }
          moveCorrect();
        }
      } else{
        int cm = BEFORE_CORNER_DELAY/10;
        for(int i = 0; i < BEFORE_CORNER_DELAY; i += cm){
          delay(cm);
          moveCorrect();
        }
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
        lastMove = Forward;
      }

//      switch (temp) {
//        case(Right_A): color_A(); break;
//        case(Right_B): color_B(); break;
//        case(Right_C): color_C(); break;
//        case(Right_D): color_D(); break;
//        case(Left_a): color_a(); break;
//        case(Left_b): color_b(); break;
//        case(Left_c): color_c(); break;
//        case(Left_d): color_d(); break;
//        case(Forward_E): color_E(); break;
//        case(Forward_e): color_e(); break;
//      } 

      if(readDistanceFront() > MAX_DISTANCE_FRONT/2){
        int cm = FRONT_DELAY_CORRECTION/10;
        for(int i = 0; i < FRONT_DELAY_CORRECTION; i += cm){
          delay(cm);
          moveCorrect();
        }
      }
      color_hair();
  } 
  
  else{
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

    if(readDistanceFront() < WALL_DISTANCE_FRONT){
      while(readDistanceFront() > MIN_DISTANCE_FRONT){
//        if(readDistanceFront() < MIN_DISTANCE_FRONT + EXTRA_FOR_MIN_DISTANCE_FRONT){
//          moveCorrect();
//          if(lastMove == Forward){
//            delay(FORWARD_DELAY_CORRECTION_MOVE);
//          }
//          break;
//        }
        moveCorrect();
      }
    } else{
      int cm = BEFORE_CORNER_DELAY/10;
      for(int i = 0; i < BEFORE_CORNER_DELAY; i += cm){
        delay(cm);
        moveCorrect();
      }
    }
      
    if (current == Left) {
      turn_90_degree_left();
    }
    else if (current == Right) {
      turn_90_degree_right();
    }
    else if (current == Forward) {
      motors->forward();
      lastMove = Forward;
    }

//    switch (temp) {
//      case(Right_A): color_A(); break;
//      case(Right_B): color_B(); break;
//      case(Right_C): color_C(); break;
//      case(Right_D): color_D(); break;
//      case(Left_a): color_a(); break;
//      case(Left_b): color_b(); break;
//      case(Left_c): color_c(); break;
//      case(Left_d): color_d(); break;
//      case(Forward_E): color_E(); break;
//      case(Forward_e): color_e(); break;
//    } 

    if(readDistanceFront() > MAX_DISTANCE_FRONT/2){
      int cm = FRONT_DELAY_CORRECTION/10;
      for(int i = 0; i < FRONT_DELAY_CORRECTION; i += cm){
        delay(cm);
        moveCorrect();
      }
    }
  }
}

void moveCorrect(){
  if((readDistanceLeft() < MIN_DISTANCE_SIDE)) { // The minion is too close to the wall from the left side
    int sum = 0;
    while((readDistanceLeft() < MIN_DISTANCE_SIDE)){

      if(readDistanceFront() < MIN_DISTANCE_FRONT + EXTRA_FOR_MIN_DISTANCE_FRONT){
        break;
      }
      
      Serial.println("Go Right");
      // turn to the right
      motors->forwardA();
      motors->stopB();
      sum += 50;
    }

    motors->forwardB();

    delay(FORWARD_DELAY_CORRECTION);
    int left = readDistanceLeft();
    int right = 310 - left;

    sum = (sum > MAX_LIMIT_SUM)? MAX_LIMIT_SUM:sum;

    Serial.println("Go Left");
    motors->stopA();
    motors->forwardB();
    delay(sum);
    motors->forwardA();
    lastMove = Left;
  }

  else if ((readDistanceRight() < MIN_DISTANCE_SIDE)) { // The minion is too close to the wall from the right side
    int sum = 0;
    while((readDistanceRight() < MIN_DISTANCE_SIDE)){

      if(readDistanceFront() < MIN_DISTANCE_FRONT + EXTRA_FOR_MIN_DISTANCE_FRONT){
        break;
      }
      
      Serial.println("Go Left");
      // turn to the left
      motors->stopA();
      motors->forwardB();
      sum += 60;
    }
    
    motors->forwardA();

    delay(FORWARD_DELAY_CORRECTION);
    int left = readDistanceLeft();
    int right = 310 - left;

    sum = (sum > MAX_LIMIT_SUM)? MAX_LIMIT_SUM:sum;

    Serial.println("Go Right");
    motors->forwardA();
    motors->stopB();
    delay(sum);
    motors->forwardB();
    lastMove = Right;
  }

//  else if((MIN_DISTANCE_SIDE_LINE < readDistanceLeft()) && (readDistanceLeft() < MAX_DISTANCE_SIDE_LINE)){
//      Serial.println("Go Left");
//      motors->stopA();
//      motors->forwardB();
//      delay(FORWARD_DELAY_CORRECTION_LINE);
//      motors->forwardA();
//      
//      delay(FORWARD_DELAY_CORRECTION * 2);
//      
//      Serial.println("Go Right");
//      motors->forwardA();
//      motors->stopB();
//      delay(FORWARD_DELAY_CORRECTION_LINE_12);
//      motors->forwardB();
//      lastMove = Right;
//  }
//
//  else if((MIN_DISTANCE_SIDE_LINE < readDistanceRight()) && (readDistanceRight() < MAX_DISTANCE_SIDE_LINE)){
//      Serial.println("Go Right");
//      motors->forwardA();
//      motors->stopB();
//      delay(FORWARD_DELAY_CORRECTION_LINE_12);
//      motors->forwardB();
//      
//      delay(FORWARD_DELAY_CORRECTION * 2);
//      
//      Serial.println("Go Left");
//      motors->stopA();
//      motors->forwardB();
//      delay(FORWARD_DELAY_CORRECTION_LINE);
//      motors->forwardA();
//      lastMove = Left;
//  }
  
  else { // The minion is ok, keep moving forward
    Serial.println("Go Forward");
    motors->forward();
    lastMove = Forward;
  }
}

void setMotorsValueBySensors() {
  if ((readDistanceRight() > MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_DISTANCE_SIDE) || (readDistanceFront() < MIN_DISTANCE_FRONT)) { // The minion in front of a wall or in a conjunction
    wallOrConjunction(true);
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
//        coffin_dance();
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
  if ((readDistanceRight() > MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_DISTANCE_SIDE) || (readDistanceFront() < MIN_DISTANCE_FRONT)) { // The minion in front of a wall or in a conjunction
    wallOrConjunction(false);
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