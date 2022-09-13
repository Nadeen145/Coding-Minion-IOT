#ifndef BARCODE_H
#define BARCODE_H

#include <Arduino.h>
#include <vector>
#include <string>

#define RXD2 16
#define TXD2 17

enum turn { Right, Left };

void setupBarcode();
void addInstruction(char instruction);

#endif
