# Coding Minion ----------
// A robotic minion that can navigate around the house like an IROBOT, take pictures, provide live video feed, and has a self charging function.

# Goal 
A robotic minion that solves mazes with the help of the user's programming. The minion walks straight, and when it hits a wall it turns to the right or left and continues to walk. The direction of rotation is determined according to a program that the user "programs" by arranging colored cards containing barcodes. The entire programming is done before starting the trip by scanning the barcodes. If there is a mistake, the user rearranges the tabs and scans again.

## Backstory
This repo is the product of the course 236333 - Project in IoT, at the Technion university. This project was created by Nadeen Bawardi, Banan Ashkar, Dalal Eghbaria and guided with the help of Tom Sopher, Itay Dabran and Natali Uda.

## Features ----------
/* Move autonomously around a perimeter.
Move manually via controls used with a matching application.
Provide live-stream video to the application.
Take pictures on user request and every few minutes automatically, the pictures are then uploaded to cloud, and and can be view via the application.
Recognize when there is low battery and dock into a charging point, exiting when fully charged or on user request.
*/

## System Parts ////////// <=4
* ESP32 Dev Module.
* Three SparkFun VL53L1X Distance Sensors.
* GM65
* Two Adafruit N20 DC Motors.
* Two L298 motors driver.
* Two 3D-Printed wheels.
* Two guiding rolling wheels.
* Minion skeleton (Handmade, as shown [here](https://www.youtube.com/watch?v=xytOwOuyp5M)).
* Silver power bank miracase.
* On/Off button.

## Used Libraries //////////
The external libraries used in the project are:
* [WebSerial](https://randomnerdtutorials.com/esp32-webserial-library/)
* [SparkFun VL53L1X](https://github.com/sparkfun/SparkFun_VL53L1X_Arduino_Library)
* AnalogWrite

## Helping Links //////////
Links that helped us to deal with the sensors:


## Contributors
* Nadeen Bawardi
* Banan Ashkar
* Dalal Eghbaria


# TODO List: 
- To add voice sensor
- To add light sensor
- To add leds
- Function havhav here
- Led light according to the color of the card

