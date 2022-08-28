
#include "barcode.h"
#include <String.h>

extern List<turn> instructions;
extern bool isFinish;

void setupBarcode() {
    isFinish = false;
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}

void addInstruction(string instruction) {
    if (!isFinished) {
        if (instruction == "Right") {
            instructions.push_back(Right);
        }
        if (instruction == "Left") {
            instructions.push_back(Left);
        }
        if (instruction == "Banana") {
            isFinish = true;
        }
    }
}
