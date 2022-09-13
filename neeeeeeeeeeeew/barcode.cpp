
using namespace std;

#include "barcode.h"

bool isFinish = false;
std::vector<turn> instructions;

void setupBarcode() {
  isFinish = false;
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}

void addInstruction(char instruction) {
    if (!isFinish) {
        Serial.println(instruction);
        if (instruction == '7') {
            instructions.push_back(Right);
        }
        if (instruction == '8') {
            instructions.push_back(Left);
        }
        if (instruction == '5') {
            Serial.println("Here is 5");
            vector<turn> temp = instructions;
            instructions.clear();
            while(temp.size()>0){
              turn e = temp.back();
              temp.pop_back();
              instructions.push_back(e);
            }
            
            Serial.print("isFinish = ");
            isFinish = true;
            Serial.println(isFinish);
        }
    }
}
