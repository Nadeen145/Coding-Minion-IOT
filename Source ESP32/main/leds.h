
#ifndef LEDS_H
#define LEDS_H

#include <analogWrite.h>

// The RGB leds
#define PIN_RED     3  
#define PIN_GREEN   1
#define PIN_BLUE    5

// The right led
#define PIN_RIGHT   32 

// The left led
#define PIN_LEFT    33

// Havhav times
#define LONG        8
#define SHORT       4 


void setRGBColor(int R, int G, int B);
void havhavAllRGB(int times, char c);
void havhavRight();
void havhavLeft();

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
