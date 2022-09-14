
#ifndef BARCODE_H
#define BARCODE_H

#include <Arduino.h>
#include <vector>
#include <string>

#include "leds.h"

#define RXD2   16
#define TXD2   17

enum turn {	Right, Left, Forward,
			Right_A, Right_B, Right_C, Right_D, 
			Left_a, Left_b, Left_c, Left_d, 
			Forward_E, Forward_e};

void setupBarcode();
void addInstruction(char instruction);

#endif
