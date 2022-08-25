# Coding-Minion IOT
// A robotic minion that can navigate around the house like an IROBOT, take pictures, provide live video feed, and has a self charging function.

# Goal
A robotic minion that solves mazes with the help of the user's programming. The minion walks straight, and when it hits a wall it turns to the right or left and continues to walk. The direction of rotation is determined according to a program that the user "programs" by arranging colored cards containing barcodes. The entire programming is done before starting the trip by scanning the barcodes. If there is a mistake, the user rearranges the tabs and scans again.

# Backstory
This repo is the product of the course 236333 - Project in IoT, at the Technion university. This project was created by Nadeen Bawardi, Banan Ashkar, Dalal Eghbaria and guided with the help of Tom Sopher, Itay Dabran and Natali Uda.

# The Coding Minion, Capabilities
/* Move autonomously around a perimeter.
Move manually via controls used with a matching application.
Provide live-stream video to the application.
Take pictures on user request and every few minutes automatically, the pictures are then uploaded to cloud, and and can be view via the application.
Recognize when there is low battery and dock into a charging point, exiting when fully charged or on user request.
*/

# System Parts
/* AI Thinker ESP32-cam.
ESP32 Dev Module.
Two SparkFun VL53L1X Distance Sensors.
Two Adafruit N20 DC Motors.
Sparkfun tb6612fng motors driver.
Two 3D-Printed wheels.
Robot Skeleton.
4V battery, equipped with Voltage Regulator.
Wireless Charging module for the battery, and a Wireless charging station.
Charging Rail.
On/Off button.
*/

# Used Libraries
/* The external libraries used in the project are:
WebSerial
Sparkfun tb6612fng
SparkFun VL53L1X
Firebase
time.h
*/ 

# The Robot Physic
/* The robot has an On/Off button outside, for easy access as shown here.

The robots physic is very tricycle like, with two wheels in the back, and a guiding rolling wheel in the front.
The robot has two distance sensors, as seen here, one facing forward and the other one, facing right. These sensors are used for the autonomous movement, and docking accurately into the charging station.

The charging device is based at the front of the robot, as shown here, so when the robot is charging, it will go to the charging station, and dock into it facing forward.
*/

# Autonomous Movement Algorithm Explanation
/* Using the sensors in their placement as defined earlier, the robot could advance in a straight line, while using the right facing sensor in order to ensure it maintains the same distance from the right wall at any time, and using the front facing sensor in order to detect whenever the robot is approaching a corner in order to make the appropriate turn.

This algorithm is rather simple, but it makes sure the robot is walking in a perimeter around the requested area, and it is far more efficient then using four sensors and implementing a random-based movement algorithm.
*/

# Automated Charging Explanation
/* The robot can be configured anytime with the number of corners in the room through the application. The robot will use that data, together with the data from the sensors, in order to detect when it's facing the corner containing the charging station.

It will then dock into the charging station, if one of the following conditions is met:

The robot didn't charge in a long time.
The user requested the robot to charge.
The battery is low (detected by cheking the battery's voltage).
The robot gets a feed from the charging component, and will try to adjust his position as long as it has not started charging.

After the robot is done charging, the application will notify the user, and the robot will continue moving.
*/

# The Barcode
/* What differs our robot from a regular old I-Robot, is the camera. The camera is able to send live footage constantly to the application, and it takes pictures when one of these conditions are met:

The user requested a picture be taken.
The allotted time interval (changeable through the application), has passed.
*/


# The Application
/* (if you want to check out the app the apk is available at hr_app\build\app\outputs\flutter-apk\app-release.apk) The application's purpose, is to grant the user access to the footage of the robot (both live feed and saved photos), and to control the robot's movement. The app's general structure is as follows:

The Main Screen (as seen here)
This is the first screen the user gets when launching the app. If the user is logged in (and has a robot connected to his firebase account), he can access the other pages by pressing the button of his choosing (or log-out using the icon button in the app bar). However, if the user is not logged in (as seen here), he can go to the sign in or sign up page using the icon button in the app bar.

Live Feed Screen
This is the primary function of the app (hence, the largest button in the main screen). The screen is mostly filled with the live video that the robot's camera is broadcasting online, and at the bottom there is a button that changes the robot's movement state - Autonomous or Manual. the rest of the screen depends on the type of state we're in:

Autonomous (as seen here) - the robot drives by itself. There is one button that the user can press - the "go charge" button.

Manual (as seen here) - the robot drives by user instructions. There is a Joystick for controlling the movement direction and speed, and a "take picture" button.
This screen also has some small UI changes and notifications to alert the user that the robot's battery is low, and when the robot is charging.

Control screen (as seen here)
This screen has some settings that the user can edit in order to affect the robot's autonomous movement, such as charging time, interval between taking photos, defining the number of corners (90 degree left turns) in the room and more.

Saved Footage Screen (as seen here)
This screen shows the user all of the saved pictures that the robot has taken, with their corresponding date of creation.

# Project Time Table
/* Week	Application	Hardware	Controller Code
3	-	Acquiring distance sensors	Writing basic examples and tests for controlling distance sensors
4	-	Acquiring Dc motors & controller	Writing basic examples and tests for the Dc motors
5	Application Design (UI), creating application user scheme, and connecting application to firebase	-	Adding firebase connection code to the controller
6	Work on the application, adding functionality of basic remote car control	-	-
7	Application work, adding manual control module	Battery & Engine testing	Manual control and state reading from firebase code
8	-	Connecting Dc motors, Esp32, and distance sensors	Designing the Autonomous movement algorithm & Testing
9 + 10	Writing application module for receiving and displaying live video & footage	AI Thinker Esp32 Cam, learning usages & building robot	Creating Esp32-cam basic code that transmits live footage to a desired ip address, and uploads footage to the cloud
11	Adding charging functionality into the app (user required charging)	Building charging station and railway	Docking in the charging station code
12	-	Polishing rail and connection to the docking station	Docking in charging station code fixing and tinkering
13	-	Building the final robot build	code bug-fixing
14	-	-	Move the firebase reading & updating into a separate thread in the esp32, in order to improve functionality, and add WebSerial connections in order to improve debugging capabilities
15	Adding more configurable parameters to the application	examining the robot build	Added more configurable parameters reading from firebase & bug-fixing
In Week 16 (right before the presentation), we filmed the video requested for the submission, and prepared for the final submission.
*/ 

# Contributors
Nadeen Bawardi
Banan Ashkar
Dalal Eghbaria
