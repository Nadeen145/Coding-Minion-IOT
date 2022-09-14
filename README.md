# Coding Minion ----------
// A robotic minion that can navigate around the house like an IROBOT, take pictures, provide live video feed, and has a self charging function.
https://he.aliexpress.com/item/1005002339981244.html?spm=a2g0o.ppclist.product.4.50361lmE1lmENW&pdp_npi=2%40dis%21USD%21US%20%241.01%21US%20%240.68%21%21%21%21%21%402103239b16631823707767455ec8fe%2112000020175288111%21btf&_t=pvid%3Aaf621d63-dd59-4dbf-b9c2-7263620d3aff&afTraceInfo=1005002339981244__pc__pcBridgePPC__xxxxxx__1663182371&gatewayAdapt=glo2isr

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
-To add the third distance sensor
- To add voice sensor
- To add leds
- To add button
- Function havhav here
- Led light according to the color of the card
- To add LCD
- To do the maze
- To correct barcodes
- To fix the minion
- barcodes for: velocity (3) + change color (-) + voice (-) + ...
