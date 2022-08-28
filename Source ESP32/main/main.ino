
#include "connection.h"
#include "motors.h"
#include "distance_sensors.h"
#include "barcode.h"

#include <String.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

bool isGameOver = false;

extern L298NX2* motors;
extern bool isFinish;

AsyncWebServer server(80);

// ----------------------------------------------------------------------------------------------------------

void recvMsg(uint8_t* data, size_t len) {
    WebSerial.println("Received Data...");
    String d = "";
    for (int i = 0; i < len; i++) {
        d += char(data[i]);
    }
    WebSerial.println(d);
}

void havhav() {
    pinMode(2, OUTPUT);
    for (int i = 0; i < 4; i++) {
        delay(500);
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
    }
}

// ----------------------------------------------------------------------------------------------------------

void setup() {
    isGameOver = false;
    isFinished = false;
    Serial.begin(115200); // Serial port for debugging purposes

    Serial.println("** STARTING ESP SETUP **");
    
    // Connect to WiFi & setupWebSerial
    connectToWiFi();
    WebSerial.begin(&server);
    WebSerial.msgCallback(recvMsg);
    server.begin();

    // Setting up distance sensors
    setupDistanceSensors();

    // Setup motors and charging sensor
    setupMotorPins();

    WebSerial.println("** FINISHED ESP SETUP **");
}

void loop() {
    if (!isFinish) {
        isGameOver = false;
        motors->stop();
        string temp = "";
        while (Serial2.available()) {
            temp += char(Serial2.read());
        }
        addInstruction(temp);
    }
    else {
        if (instructions == NULL) {
            motors->stop();
            isFinished = false;
            if (!isGameOver) {
                // voice "Banana!!!"
                isGameOver = true;
            }
        }
        else {
            int  distanceFrontSense = readDistanceFront();
            int  distanceRightSense = readDistanceRight();
            int  distanceLeftSense = readDistanceLeft();
            setMotorsValueBySensors(distanceFrontSense, distanceRightSense, distanceLeftSense);
        }
    }
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
