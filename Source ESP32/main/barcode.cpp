
using namespace std;

#include "barcode.h"

bool isFinish = false;
std::vector<turn> instructions;

void setupBarcode() {
  isFinish = false;
  Serial2.begin(9600, SERIAL_8N1, RXD, TXD);
}

void addInstruction(char instruction) {
    if (!isFinish) {
        
        if (instruction == 'A') {
            instructions.push_back(Right_A);
            color_A();
        }
        if (instruction == 'B') {
            instructions.push_back(Right_B);
            color_B();
        }
        if (instruction == 'C') {
            instructions.push_back(Right_C);
            color_C();
        }
        if (instruction == 'D') {
            instructions.push_back(Right_D);
            color_D();
        }       

        if (instruction == 'a') {
            instructions.push_back(Left_a);
            color_a();
        }
        if (instruction == 'b') {
            instructions.push_back(Left_b);
            color_b();
        }
        if (instruction == 'c') {
            instructions.push_back(Left_c);
            color_c();
        }
        if (instruction == 'd') {
            instructions.push_back(Left_d);
            color_d();
        }

        if (instruction == 'E') {
            instructions.push_back(Forward_E);
            color_E();
        }
        if (instruction == 'e') {
            instructions.push_back(Forward_e);
            color_e();
        }

        if (instruction == 'S') {
            Serial.println("Start Scanning...");
            instructions.clear();
            isFinish = false;
            color_S();
        }

        if (instruction == 'M') {
            color_M();
            Serial.println("Start Moving...");
            vector<turn> temp = instructions;
            instructions.clear();
            while(temp.size()>0){
              turn e = temp.back();
              temp.pop_back();
              instructions.push_back(e);
            }
            isFinish = true;
            delay(1000);
            color_S();
        }

    }
}

