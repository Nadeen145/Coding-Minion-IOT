
#ifndef BARCODE_H
#define BARCODE_H

#include <Arduino.h>
#include <vector>
#include <string>

#include "leds.h"

#define RXD   4
#define TXD   2

enum turn {Right, Left, Forward,
			Right_A, Right_B, Right_C, Right_D, 
			Left_a, Left_b, Left_c, Left_d, 
			Forward_E, Forward_e, Nothing};

void setupBarcode();
void addInstruction(char instruction);

#endif
