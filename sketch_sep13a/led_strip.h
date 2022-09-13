
#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <Adafruit_NeoPixel.h>

#define LED_PIN    32
#define LED_COUNT  7

// The right led
#define N_R     7  

// The center led
#define N_C     10 

// The left led
#define N_L     14


void setColor(int R, int G, int B);
void setColor(uint32_t color);
void setColorsetColorTheSelectedOne(uint32_t color, int n);

void havhavTheSelectedOne(char p);
void havhavAll();

void setupLedStripPin();

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
