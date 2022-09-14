
#ifndef LEDS_H
#define LEDS_H

#include <analogWrite.h>

// The right led
#define PIN_RED_R     35  
#define PIN_GREEN_R   33
#define PIN_BLUE_R    32


// The center led
#define PIN_RED_C     35 
#define PIN_GREEN_C   33
#define PIN_BLUE_C    32


// The left led
#define PIN_RED_L     35
#define PIN_GREEN_L   33
#define PIN_BLUE_L    32


void setColorR(int R, int G, int B);
void setColorC(int R, int G, int B);
void setColorL(int R, int G, int B);
void havhavTheSelectedOne(char p);
void havhavAll();

void setupLedsPins();

void color_hair();
void color_S();
void color_M();
void color_A();
void color_B();
void color_C();
void color_D();
void color_E();
void color_a();
void color_b();
void color_c();
void color_d();
void color_e();

#endif
