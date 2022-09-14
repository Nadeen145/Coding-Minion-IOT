
#include "distance_sensors.h"
#include "barcode.h"
#include "motors.h"
#include "leds.h"

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
        if (instructions.size() == 0) {
            Serial.println("Inatructions is empty!");
            motors->forward();
            int distanceRightSense = readDistanceRight();
            int distanceLeftSense = readDistanceLeft();
            setMotorsValueBySensors(distanceRightSense, distanceLeftSense);
            char temp = '';
            while (Serial2.available()) {
                temp = char(Serial2.read());
                Serial.print("---");
                Serial.print(temp);
                Serial.println("---");
            }
            if (!isGameOver && temp == 'F') {
                // voice "Banana!!!"
                isFinish = false;
                isGameOver = true;
                color_M();
                motors->stop();
                havhavAll()
                color_hair();
            }
        }
        else {
            Serial.println("Inatructions is not empty, Minion is moving.");
            int distanceFrontSense = readDistanceFront();
            int distanceRightSense = readDistanceRight();
            int distanceLeftSense = readDistanceLeft();
            setMotorsValueBySensors(distanceFrontSense, distanceRightSense, distanceLeftSense);
        }
    }
}

