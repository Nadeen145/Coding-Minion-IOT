
#include "barcode.h"

extern List<turn> instructions;

void setupBarcode() {
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}

void addInstruction(string instruction) {
    if (instruction == "Right") {
        instructions.push_back(Right);
    }
    if (instruction == "Left") {
        instructions.push_back(Left);
    }
}
