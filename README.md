# Coding Minion
A robotic minion that can scan barcodes, move parallel to the wall, turn 90, 180 degree, blink, sing and dance.

[See me]([https://technionmail-my.sharepoint.com/:v:/g/personal/nadeen-ba_campus_technion_ac_il/Efm4IkHy2z5Fj8xSchvoOpwBdVrqAdZoOwcWUQ-_SPexBg?e=8ZwsAL](https://www.dropbox.com/scl/fi/y2xssjx69hejrivqjxy7q/Coding-Minion.mp4?rlkey=mbwz7omu8md29fg1xs7ji59vn&dl=0))

![poster](https://user-images.githubusercontent.com/49783776/194832594-05659edb-394e-4e85-9cf7-747585f29ad4.png)


# Goal 
A robotic minion that solves mazes with the help of the user's programming. The minion walks straight, and when it hits a wall or a junction, it turns to the right or left or forward and continues to walk. The direction of rotation is determined according to a program that the user "programs" by arranging colored cards containing barcodes. The entire programming is done before starting the trip by scanning the barcodes. If there is a mistake, the user rearranges the cards and scans again.


## Backstory
"Coding Minion" is the product of the course 236333 - Project in IoT, at the Technion university. This project was created by Nadeen Bawardi, Banan Ashkar, Dalal Eghbaria and guided with the help of Tom Sopher, Itay Dabran and Natali Uda.


## GitHub Content
| Folder Name | Content |
| ---- | ----------- |
| ESP32 Code | The code that we uploaded to the "Coding Minion" |
| Unit Tests | Folders such that, every folder with the name of a sensor, and this folder contains a code that check this specific sensor |
| Assets | Colorful cards that caontain barcodes |
| Activation & Duplicating | Details for running the "Coding Minion" or duplicating it |
| User Interface & Parameters | User Interface for the "Coding Minion" and important parameters |


## System Parts 
* ESP32 Dev Module.
* 3 VL53L1X Distance Sensors.
* GM65.
* Buzzer.
* 3 RGB LEDs.
* 2 white LEDs.
* 14 resistors.
* Two N20 DC Motors.
* L298 motors driver.
* Toggle Switcher.
* Silver power bank miracase.
* Two 3D-Printed wheels.
* Two guiding rolling wheels.
* Minion skeleton (Handmade, as shown [here](https://www.youtube.com/watch?v=xytOwOuyp5M)).


## Used Libraries
The external libraries used in the project are:
* [VL53L1X](https://www.arduino.cc/reference/en/libraries/vl53l1x/), version: 1.3.1.
* [ESP32 analogWrite](https://www.arduino.cc/reference/en/libraries/esp32-analogwrite/), version: 0.1.0.
* [L298N](https://www.arduino.cc/reference/en/libraries/l298n/), version: 2.0.2.


## Helping Links
Links that helped us to deal with the sensors:

| Sensor | Links |
| ---- | ----------- |
| ESP32 Dev Module | https://randomnerdtutorials.com/getting-started-with-esp32/ |
| VL53L1X Distance Sensors | 1. https://github.com/pololu/vl53l1x-arduino <br /> 2. https://youtu.be/dzbGmIZv26E <br /> 3. https://microcontrollerslab.com/esp32-i2c-communication-tutorial-arduino-ide/#Using_Multiple_I2C_Devices_with_ESP32_same_addresses <br /> 4. https://randomnerdtutorials.com/esp32-i2c-communication-arduino-ide/ |
| GM65 | 1. http://www.microtechnica.tv/support/manual/brm65_man.pdf <br /> 2. https://www.youtube.com/watch?v=aPUymNPWErE |
| Buzzer | https://github.com/robsoncouto/arduino-songs |
| RGB Leds | https://esp32io.com/tutorials/esp32-rgb-led |
| White Leds | https://esp32io.com/tutorials/esp32-led-fade |
| L298N & N20 DC Motors | 1. https://github.com/AndreaLombardo/L298N <br /> 2. https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/ <br /> 3. https://www.youtube.com/watch?v=2JTMqURJTwg |
| Toggle Switcher | https://create.arduino.cc/projecthub/GeneralSpud/toggle-switch-3763a2 |

## Contributors
* Nadeen Bawardi
* Banan Ashkar
* Dalal Eghbaria
