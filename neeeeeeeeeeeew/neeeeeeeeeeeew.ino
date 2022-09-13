
#include "distance_sensors.h"
#include "barcode.h"
#include "motors.h"

#include <string>
#include <vector>

bool isGameOver = false;

extern bool isFinish;
extern std::vector<turn> instructions;
extern L298NX2* motors;

void setup() {
  isGameOver = false;
  isFinish = false;

  Serial.begin(115200);

  Serial.println("** STARTING ESP SETUP **");

  // Setting up barcode sensor
//  setupBarcode();

  // Setting up distance sensors
  setupDistanceSensors();

  // Setup motors 
//  setupMotorPins();

//  setupLedsPins()
  Serial.println("** FINISHED ESP SETUP **");
//  ESP.restart();
}

void loop() {
//  while (Serial2.available()) {
//            char temp = char(Serial2.read());
//            Serial.print("---");
//            Serial.print(temp);
//            Serial.println("---");
//        }
//  Serial.println(readDistanceFront());
  delay(100);
  Serial.println(readDistanceRight());
  delay(100);
  Serial.println(readDistanceLeft());
//    if (!isFinish) {
//        isGameOver = false;
//        motors->stop();
//        char temp;
//        while (Serial2.available()) {
//            temp = char(Serial2.read());
//            addInstruction(temp);
//            Serial.print("---");
//            Serial.print(temp);
//            Serial.println("---");
//        }
//        addInstruction(temp);
//    }
//    else {
//        if (instructions.size() == 0) {
//            Serial.println("Inatructions is empty!");
//            motors->stop();
//            isFinish = false;
//            if (!isGameOver) {
//                // voice "Banana!!!"
//                isGameOver = true;
//            }
//        }
//        else {
//            Serial.println("Inatructions is not empty, Minion is moving.");
//            int  distanceFrontSense = readDistanceFront();
//            int  distanceRightSense = readDistanceRight();
//            setMotorsValueBySensors(distanceFrontSense, distanceRightSense);
//        }
//    }
}



// TODO List: 
//     - To read again, we must start from beginning
//     - To add voice sensor
//     - To add light sensor
//     - To add leds
//     - Function havhav here
//     - Function recvMsg here
//     - 
//     -  
//     - 
