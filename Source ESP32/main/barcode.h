#ifndef BARCODE_H
#define BARCODE_H

#include <Arduino.h>
#include <String.h>

#define RXD2 16
#define TXD2 17

enum turn { Right, Left };
List<turn> instructions;
bool isFinish = false;

void setupBarcode();
void addInstruction(string instruction);

#endif
