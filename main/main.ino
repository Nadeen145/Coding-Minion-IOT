
#include "distance_sensors.h"
#include "barcode.h"
#include "motors.h"
#include "leds.h"
#include "voice.h"

#include <string>
#include <vector> 

int game_mode = 1;
bool isSolutionFinished = false;
bool isGameOver = false;
bool isGoBack = false;
bool isStartingNow = true;
bool isReturnBack = false;

extern bool isFinish;
extern std::vector<turn> instructions;
extern std::vector<turn> reverse_instructions;
extern L298NX2* motors;

void setup() {
  isGameOver = false;
  isFinish = false;
  isStartingNow = true;
  isReturnBack = false;
  game_mode = 1;
  isSolutionFinished = false;

  reverse_instructions.clear();
  instructions.clear();
  
  Serial.begin(115200);

  Serial.println("** STARTING ESP SETUP **");

  // Setting up barcode sensor
  setupBarcode();

  // Setting up distance sensors
  setupDistanceSensors();

  // Setup motors 
  setupMotorPins();

  // Setup leds 
  setupLedsPins();

  Serial.println("** FINISHED ESP SETUP **");
}

void loop() {   
    if (!isFinish) {
        isGameOver = false;
        isStartingNow = true;
        isGoBack = false;
        game_mode = 1;
        isSolutionFinished = false;
        motors->stop();
        char temp;
        while (Serial2.available()) { 
            temp = char(Serial2.read());
            addInstruction(temp);
            Serial.print("---");
            Serial.print(temp);
            Serial.println("---");
        }
    }
    else {

        if((instructions.size() == 0) && (game_mode == 2)){
          if(isGameOver == false){
            color_M();
          }
          Serial.println("Inatructions is empty!");
          setMotorsValueBySensorsForFMode2();

          if (!isGameOver && isSolutionFinished == true) {
             Serial.println("Banana !!!");
             reverse_instructions.clear();
             instructions.clear();
             isFinish = false;
             isGameOver = true;
             motors->stop();
             havhavAllRGB(3, 'M');
             color_hair();
             keyboard_cat();
             game_mode = 1;
             isSolutionFinished = false;
          }

          
        }
      
        else if ((instructions.size() == 0) && (game_mode == 1) && (isGoBack == false)) {
            if(isGameOver == false){
              color_M();
            }
            Serial.println("Inatructions is empty!");

            setMotorsValueBySensorsForF();
            
            char temp;
            while (Serial2.available()) {
                temp = char(Serial2.read());
                Serial.print("---");
                Serial.print(temp);
                Serial.println("---");
                if (!isGameOver && temp == 'F') {
                  Serial.println("Banana !!!");
                  reverse_instructions.clear();
                  instructions.clear();
                  isFinish = false;
                  isGameOver = true;
                  motors->stop();
                  havhavAllRGB(3, 'M');
                  color_hair();
                  keyboard_cat();
                  game_mode = 1;
              }
            }
        }
        
        else if((instructions.size() == 0) && (isGoBack == true)){
          if ((reverse_instructions.size() == 0) && (isReturnBack == true)) {
            isGoBack = false;
            isFinish = false;
            isGameOver = true;
            isStartingNow = true;
            isReturnBack = false;
            motors->stop();
            turn_180_degree_left();
            motors->stop();
            color_hair();
          } else if ((reverse_instructions.size() == 0) && (isReturnBack == false)) {
            goBackF();
          }
          else{
            goBack();
          }
        }
        
        else{
            Serial.println("Inatructions is not empty, Minion is moving.");
            setMotorsValueBySensors();
        }
    }
}
