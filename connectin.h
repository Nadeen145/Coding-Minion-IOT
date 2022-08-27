#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>

#define MANUAL 0
#define AUTONOMOUS 1
// #define AUTONOMOUS_IN_CHARGE 2 // In charging in the autonomus mode

#include <WiFi.h>

void connectToWiFi();

#endif
