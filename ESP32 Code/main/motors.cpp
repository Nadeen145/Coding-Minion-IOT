
#include "motors.h"

L298NX2* motors;
turn closerWall = Right;
int currentDistanceWall = 50;

extern std::vector<turn> instructions;
extern std::vector<turn> reverse_instructions;
extern bool isFinish;
extern bool isGameOver;
extern bool isGoBack;
extern bool isMinionFinished;
extern bool isReturnBack;
extern bool isSolutionFinished;
extern bool isFirstMove;

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

void turn_little_right() {
  Serial.println("Go Right");
  motors->forwardA();
  motors->stopB();

  delay(FORWARD_DELAY_CORRECTION +RIGHT_DELAY_CORRECTION_R);
  reset();
  motors->forwardB();      
  delay(FORWARD_DELAY_CORRECTION*4);
  reset();
  
//  Serial.println("Go Left");
//  motors->stopA();
//  motors->forwardB();
//  delay(FORWARD_DELAY_CORRECTION +LEFT_DELAY_CORRECTION_R);
//  motors->forwardA();
}

void turn_little_left() {
  Serial.println("Go Left");
  // turn to the left
  motors->stopA();
  motors->forwardB();

  delay(FORWARD_DELAY_CORRECTION +LEFT_DELAY_CORRECTION_L);
  reset();
  motors->forwardA();
  delay(FORWARD_DELAY_CORRECTION*4);  
  reset();

//  Serial.println("Go Right");
//  motors->forwardA();
//  motors->stopB();
//  delay(FORWARD_DELAY_CORRECTION +RIGHT_DELAY_CORRECTION_L);
//  motors->forwardB();
}

void turn_180_degree_left() {
    Serial.println("Go Left (90 degree corner)");
    motors->backwardA();
    motors->forwardB();
    havhavLeft_180();
    motors->forwardA();
}

void changeCloserWall(){
  if((readDistanceRight() <= readDistanceLeft())){
    closerWall = Right;
    currentDistanceWall = (readDistanceRight() > MIN_MIN_DISTANCE_SIDE)? readDistanceRight():MIN_DISTANCE_SIDE;
  } else{
    closerWall = Left;
    currentDistanceWall = (readDistanceLeft() > MIN_MIN_DISTANCE_SIDE)? readDistanceLeft():MIN_DISTANCE_SIDE;;
  }    
}

void beforeTurn(){
  reset();
  changeCloserWall();

  if(readDistanceFront() < WALL_DISTANCE_FRONT){
    while(readDistanceFront() > MIN_DISTANCE_FRONT+EXTRA_FOR_MIN_DISTANCE_FRONT){
      moveCorrect();
    }
    while(readDistanceFront() > MIN_DISTANCE_FRONT){
      motors->forward();
    }
  } else{
    int front_distance = readDistanceFront();
    while(front_distance < WALL_DISTANCE_FRONT){
      front_distance = readDistanceFront();
    }
    while(readDistanceFront() > front_distance - MIN_DISTANCE_TO_TURN/2){
      if(readDistanceFront() < MIN_DISTANCE_FRONT){
        break;
      }
      moveCorrect();
    }
    while(readDistanceFront() > front_distance - MIN_DISTANCE_TO_TURN){
      if(readDistanceFront() < MIN_DISTANCE_FRONT){
        break;
      }
      motors->forward();
    }
  }
}

void afterTurn(){
  reset();
  changeCloserWall();
  
  while(((readDistanceRight() > MAX_MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE)) && ((readDistanceFront() > MIN_DISTANCE_FRONT+EXTRA_FOR_MIN_DISTANCE_FRONT))){
    moveCorrect();
  }
}

void wallOrConjunction(bool isRegular){  
  reset();
  changeCloserWall();
  if((isRegular == true)){
      turn current = instructions.back();
      instructions.pop_back();
      reverse_instructions.push_back(current);

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

      beforeTurn();

      if (current == Left) {
        if(readDistanceLeft() < MIN_DISTANCE_SIDE_NO_TURN){
          reverse_instructions.pop_back();
          instructions.clear();
          return;
        }
        turn_90_degree_left();
      }
      else if (current == Right) {
        if(readDistanceRight() < MIN_DISTANCE_SIDE_NO_TURN){
          reverse_instructions.pop_back();
          instructions.clear();
          return;
        }
        turn_90_degree_right();
      }
      else if (current == Forward) {
        if(readDistanceFront() < MIN_DISTANCE_SIDE_NO_TURN){
          reverse_instructions.pop_back();
          instructions.clear();
          return;
        }
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

      afterTurn();
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

    beforeTurn();
      
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

    afterTurn();
  }

  changeCloserWall();
}

void moveCorrect(){   
  changeCloserWall();
  reset();
  if((closerWall == Left)) { // The minion is closer to the left wall
    if((readDistanceLeft() < currentDistanceWall-Difference_DISTANCE_SIDE_HALF)) { // The minion is too close to the wall from the left side
      turn_little_right();
    }

    else if((readDistanceLeft() > currentDistanceWall+Difference_DISTANCE_SIDE_HALF)) { // The minion is too far to the wall from the left side
      turn_little_left();
    }
    
    else { // The minion is ok, keep moving forward
      Serial.println("Go Forward");
      motors->forward();
    }
  }

  else if((closerWall == Right)) { // The minion is closer to the left wall
    if((readDistanceRight() > currentDistanceWall+Difference_DISTANCE_SIDE_HALF)) { // The minion is too far to the wall from the left side
      turn_little_right();
    }

    else if((readDistanceRight() < currentDistanceWall-Difference_DISTANCE_SIDE_HALF)) { // The minion is too close to the wall from the left side
      turn_little_left();
    }

    else { // The minion is ok, keep moving forward
      Serial.println("Go Forward");
      motors->forward();
    }
  }
}

void setMotorsValueBySensors() {
  if(isFirstMove){
    isFirstMove = false;
    while((readDistanceRight() > MAX_MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE)){
      motors->forward();
    }
  }
 
  else if ((readDistanceRight() > MAX_MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE) || (readDistanceFront() < MIN_DISTANCE_FRONT)) { 
    Serial.println("There is a junction or wall !");
    wallOrConjunction(true);
  } 
  
  else {
    moveCorrect();
  }
}

void setMotorsValueBySensorsForF() {
    if(isFirstMove){
     isFirstMove = false;
     while((readDistanceRight() > MAX_MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE)){
        motors->forward();
      }
    }
    
    else if ((readDistanceFront() < MIN_DISTANCE_FRONT)){
      Serial.println("Wrong Solution :(");
      motors->stop();
      coffin_dance();
      color_hair();
      turn_180_degree_left();
      color_hair();
      isGoBack = true;
      isFirstMove = true;
      isMinionFinished = false;
      changeCloserWall();  
    }
    
    else if((readDistanceFront() > MAX_MAX_DISTANCE_SIDE) && (readDistanceRight() > MAX_MAX_DISTANCE_SIDE) && (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE)){ 
      Serial.println("Right Solution :(");
      isMinionFinished = true;
    } else {
      moveCorrect();
    }
}

void goBack(){  
  if(isFirstMove){
    isFirstMove = false;
    while((readDistanceRight() > MAX_MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE)){
      motors->forward();
    }
  }
  
  else if((readDistanceRight() > MAX_MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE) || (readDistanceFront() < MIN_DISTANCE_FRONT)) { 
    Serial.println("There is a junction or wall !");
    wallOrConjunction(false);
  } 
  
  else{
    moveCorrect();
  }
}

void goBackF() {
  if(isFirstMove){
    isFirstMove = false;
    while((readDistanceRight() > MAX_MAX_DISTANCE_SIDE) || (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE)){
      motors->forward();
    }
  }
  
  else if ((((readDistanceFront() > MAX_MAX_DISTANCE_SIDE) || (readDistanceFront() < MIN_DISTANCE_FRONT)) 
          && (readDistanceRight() > MAX_MAX_DISTANCE_SIDE) && (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE))){
    Serial.println("The minion return to start point ...");
    isReturnBack = true;
    isFirstMove = true;
  } else {
    moveCorrect();
  }
}

void setMotorsValueBySensorsForFMode2() {
  if (((readDistanceFront() < MIN_DISTANCE_FRONT))
     || ((readDistanceFront() > MAX_MAX_DISTANCE_SIDE) && (readDistanceRight() > MAX_MAX_DISTANCE_SIDE) && (readDistanceLeft() > MAX_MAX_DISTANCE_SIDE))){
    Serial.println("Solution is finished");
    motors->stop();
    color_hair();
    isFirstMove = true;
    isSolutionFinished = true;
  } else {
    moveCorrect();
  }
}
