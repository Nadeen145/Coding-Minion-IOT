#ifndef BARCODE_H
#define BARCODE_H

#include <Arduino.h>

#define RXD2 16
#define TXD2 17

enum turn { Right, Left };
List<turn> instructions;


void setupBarcode();
void addInstruction(string instruction);

#endif