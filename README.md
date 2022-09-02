# Coding Minion ----------
// A robotic minion that can navigate around the house like an IROBOT, take pictures, provide live video feed, and has a self charging function.

# Goal 
A robotic minion that solves mazes with the help of the user's programming. The minion walks straight, and when it hits a wall it turns to the right or left and continues to walk. The direction of rotation is determined according to a program that the user "programs" by arranging colored cards containing barcodes. The entire programming is done before starting the trip by scanning the barcodes. If there is a mistake, the user rearranges the tabs and scans again.

## Backstory
This repo is the product of the course 236333 - Project in IoT, at the Technion university. This project was created by Nadeen Bawardi, Banan Ashkar, Dalal Eghbaria and guided with the help of Tom Sopher, Itay Dabran and Natali Uda.

## The Coding Minion, Capabilities ----------
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

## The Robot Physic ----------
/* The robot has an On/Off button outside, for easy access as shown here.

The robots physic is very tricycle like, with two wheels in the back, and a guiding rolling wheel in the front.
The robot has two distance sensors, as seen here, one facing forward and the other one, facing right. These sensors are used for the autonomous movement, and docking accurately into the charging station.

The charging device is based at the front of the robot, as shown here, so when the robot is charging, it will go to the charging station, and dock into it facing forward.
*/

## Autonomous Movement Algorithm Explanation ----------
/* Using the sensors in their placement as defined earlier, the robot could advance in a straight line, while using the right facing sensor in order to ensure it maintains the same distance from the right wall at any time, and using the front facing sensor in order to detect whenever the robot is approaching a corner in order to make the appropriate turn.

This algorithm is rather simple, but it makes sure the robot is walking in a perimeter around the requested area, and it is far more efficient then using four sensors and implementing a random-based movement algorithm.
*/

## Automated Charging Explanation ----------
/* The robot can be configured anytime with the number of corners in the room through the application. The robot will use that data, together with the data from the sensors, in order to detect when it's facing the corner containing the charging station.

It will then dock into the charging station, if one of the following conditions is met:

The robot didn't charge in a long time.
The user requested the robot to charge.
The battery is low (detected by cheking the battery's voltage).
The robot gets a feed from the charging component, and will try to adjust his position as long as it has not started charging.

After the robot is done charging, the application will notify the user, and the robot will continue moving.
*/

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

