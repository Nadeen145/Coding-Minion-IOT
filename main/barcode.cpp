
using namespace std;

#include "barcode.h"

bool isFinish = false;
std::vector<turn> instructions;
std::vector<turn> reverse_instructions;

void setupBarcode() {
  isFinish = false;
  Serial2.begin(9600, SERIAL_8N1, RXD, TXD);
}

void addInstruction(char instruction) {
    if (!isFinish) {
        
        if (instruction == 'A') {
            instructions.push_back(Right_A);
            color_A();
            havhavAllRGB(3, 'A');
            color_hair();
        }
        if (instruction == 'B') {
            instructions.push_back(Right_B);
            color_B();
            havhavAllRGB(3, 'B');
            color_hair();
        }
        if (instruction == 'C') {
            instructions.push_back(Right_C);
            color_C();
            havhavAllRGB(3, 'C');
            color_hair();
        }
        if (instruction == 'D') {
            instructions.push_back(Right_D);
            color_D();
            havhavAllRGB(3, 'D');
            color_hair();
        }       

        if (instruction == 'a') {
            instructions.push_back(Left_a);
            color_a();
            havhavAllRGB(3, 'a');
            color_hair();
        }
        if (instruction == 'b') {
            instructions.push_back(Left_b);
            color_b();
            havhavAllRGB(3, 'b');
            color_hair();
        }
        if (instruction == 'c') {
            instructions.push_back(Left_c);
            color_c();
            havhavAllRGB(3, 'c');
            color_hair();
        }
        if (instruction == 'd') {
            instructions.push_back(Left_d);
            color_d();
            havhavAllRGB(3, 'd');
            color_hair();
        }

        if (instruction == 'E') {
            instructions.push_back(Forward_E);
            color_E();
            havhavAllRGB(3, 'E');
            color_hair();
        }
        if (instruction == 'e') {
            instructions.push_back(Forward_e);
            color_e();
            havhavAllRGB(3, 'e');
            color_hair();
        }

        if (instruction == 'S') {
            Serial.println("Start Scanning...");
            instructions.clear();
            isFinish = false;
            color_S();
            havhavAllRGB(3, 'S');
            color_hair();
        }

        if (instruction == 'M') {
            color_M();
            havhavAllRGB(3, 'M');
            color_hair();
            Serial.println("Start Moving...");
            reverse_instructions.clear();
            reverse_instructions = instructions;
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
