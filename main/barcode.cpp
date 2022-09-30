
using namespace std;

#include "barcode.h"

bool isFinish = false;
std::vector<turn> instructions;
std::vector<turn> reverse_instructions;
std::vector<turn> maze_solution_0 = {Right_A, Right_C, Left_a, Left_c};
std::vector<turn> maze_solution_1 = {Right_B, Left_a, Left_d , Forward_e};
std::vector<turn> maze_solution_2 = {Right_C, Left_b, Left_a, Right_D , Forward_E};
extern int game_mode;
bool isS = false;

void setupBarcode() {
  isFinish = false;
  Serial2.begin(9600, SERIAL_8N1, RXD, TXD);
}

void addInstruction(char instruction) {
    if (!isFinish) {
        
        if (instruction == 'A') {
          if(((instructions.size() != 0) && (instructions.back() != Right_A)) || (instructions.size() == 0)){
            instructions.push_back(Right_A);
            color_A();
            havhavAllRGB(3, 'A');
            color_hair();
          }
        }
        if (instruction == 'B') {
          if(((instructions.size() != 0) && (instructions.back() != Right_B)) || (instructions.size() == 0)){
            instructions.push_back(Right_B);
            color_B();
            havhavAllRGB(3, 'B');
            color_hair();
          }
        }
        if (instruction == 'C') {
          if(((instructions.size() != 0) && (instructions.back() != Right_C)) || (instructions.size() == 0)){
            instructions.push_back(Right_C);
            color_C();
            havhavAllRGB(3, 'C');
            color_hair();
          }
        }
        if (instruction == 'D') {
          if(((instructions.size() != 0) && (instructions.back() != Right_D)) || (instructions.size() == 0)){
            instructions.push_back(Right_D);
            color_D();
            havhavAllRGB(3, 'D');
            color_hair();
          }
        }       

        if (instruction == 'a') {
          if(((instructions.size() != 0) && (instructions.back() != Left_a)) || (instructions.size() == 0)){
            instructions.push_back(Left_a);
            color_a();
            havhavAllRGB(3, 'a');
            color_hair();
          }
        }
        if (instruction == 'b') {
          if(((instructions.size() != 0) && (instructions.back() != Left_b)) || (instructions.size() == 0)){
            instructions.push_back(Left_b);
            color_b();
            havhavAllRGB(3, 'b');
            color_hair();
          }
        }
        if (instruction == 'c') {
          if(((instructions.size() != 0) && (instructions.back() != Left_c)) || (instructions.size() == 0)){
            instructions.push_back(Left_c);
            color_c();
            havhavAllRGB(3, 'c');
            color_hair();
          }
        }
        if (instruction == 'd') {
          if(((instructions.size() != 0) && (instructions.back() != Left_d)) || (instructions.size() == 0)){
            instructions.push_back(Left_d);
            color_d();
            havhavAllRGB(3, 'd');
            color_hair();
          }
        }

        if (instruction == 'E') {
          if(((instructions.size() != 0) && (instructions.back() != Forward_E)) || (instructions.size() == 0)){
            instructions.push_back(Forward_E);
            color_E();
            havhavAllRGB(3, 'E');
            color_hair();
          }
        }
        if (instruction == 'e') {
          if(((instructions.size() != 0) && (instructions.back() != Forward_e)) || (instructions.size() == 0)){
            instructions.push_back(Forward_e);
            color_e();
            havhavAllRGB(3, 'e');
            color_hair();
          }
        }

        if (instruction == 'S') {
            Serial.println("Start Scanning...");
            instructions.clear();
            isFinish = false;
            color_S();
            havhavAllRGB(3, 'S');
            color_hair();
            isS = true;
        }

        if ((instruction == 'M') && (isS == true)) {
            isS = false;
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
            color_S();
        }

        if(instruction == '0'){
          color_e();
          havhavAllRGB(3, 'e');

          Serial.println("Start Solving Maze 0...");

          vector<turn> temp = maze_solution_0;
          instructions.clear();
          while(temp.size()>0){
            turn e = temp.back();
            temp.pop_back();
            instructions.push_back(e);
          }
          isFinish = true;
          color_S();

          game_mode = 2;
        }

        if(instruction == '1'){

        }

        if(instruction == '2'){

        }

    }
}
