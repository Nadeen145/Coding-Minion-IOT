
#include "leds.h"

void setColorR(int R, int G, int B) {
	analogWrite(PIN_RED_R, R);
	analogWrite(PIN_GREEN_R, G);
	analogWrite(PIN_BLUE_R, B);
}

void setColorC(int R, int G, int B) {
//	analogWrite(PIN_RED_C, R);
//	analogWrite(PIN_GREEN_C, G);
//	analogWrite(PIN_BLUE_C, B);
}

void setColorL(int R, int G, int B) {
//	analogWrite(PIN_RED_L, R);
//	analogWrite(PIN_GREEN_L, G);
//	analogWrite(PIN_BLUE_L, B);
}

void havhavTheSelectedOne(char p) {
	int R = PIN_RED_R;
	int G = PIN_GREEN_R;
	int B = PIN_BLUE_R;

	if (p == 'C') {
		R = PIN_RED_C;
		G = PIN_GREEN_C;
		B = PIN_BLUE_C;
	}

	if (p == 'L') {
		R = PIN_RED_L;
		G = PIN_GREEN_L;
		B = PIN_BLUE_L;
	}

	for (int i = 0; i < 8; i++) {
		delay(250);
		analogWrite(R, HIGH);
		analogWrite(G, HIGH);
		analogWrite(B, HIGH);
		delay(250);
		analogWrite(R, LOW);
		analogWrite(G, LOW);
		analogWrite(B, LOW);
	}
}

void setupLedsPins() {
  Serial.println("Starting leds setup pins");

  // The right led
  pinMode(PIN_RED_R, OUTPUT);
  pinMode(PIN_GREEN_R, OUTPUT);
  pinMode(PIN_BLUE_R, OUTPUT);

//
//  // The center led
//  pinMode(PIN_RED_C, OUTPUT);
//  pinMode(PIN_GREEN_C, OUTPUT);
//  pinMode(PIN_BLUE_C, OUTPUT);
//
//  // The left led
//  pinMode(PIN_RED_L, OUTPUT);
//  pinMode(PIN_GREEN_L, OUTPUT);
//  pinMode(PIN_BLUE_L, OUTPUT);

    color_hair();
}


void color_hair() {
  setColorR(100, 75, 150);
	setColorC(100, 75, 150);
	setColorL(100, 75, 150);
}

void color_S() {
	setColorR(0, 10, 150);
	setColorC(0, 10, 150);
	setColorL(0, 10, 150);
}

void color_M() {
	setColorR(255, 85, 0);
	setColorC(255, 85, 0);
	setColorL(255, 85, 0);
}

void color_A() {
	setColorR(125, 10, 0);
	setColorC(125, 10, 0);
	setColorL(125, 10, 0);
}

void color_B() {
	setColorR(45, 100, 10);
	setColorC(45, 100, 10);
	setColorL(45, 100, 10);
}

void color_C() {
	setColorR(120, 0, 175);
	setColorC(120, 0, 175);
	setColorL(120, 0, 175);
}

void color_D() {
  setColorR(40, 110, 255);
	setColorC(40, 110, 255);
	setColorL(40, 110, 255);
}

void color_E() {
	setColorR(255, 3, 45);
	setColorC(255, 3, 45);
	setColorL(255, 3, 45);
}

void color_a() {
	setColorR(255, 5, 5);
	setColorC(255, 5, 10);
	setColorL(255, 5, 10);
}

void color_b() {
  setColorR(0, 60, 45);
	setColorC(0, 60, 45);
	setColorL(0, 60, 45);
}

void color_c() {
  setColorR(150, 80, 30);
	setColorC(150, 80, 30);
	setColorL(150, 80, 30);
}

void color_d() {
  setColorR(85, 3, 25);
	setColorC(85, 3, 25);
	setColorL(85, 3, 25);
}

void color_e() {
  setColorR(25, 0, 20);
	setColorC(25, 0, 20);
	setColorL(25, 0, 20);
}
