
#include "leds.h"

void setRGBColor(int R, int G, int B) {
	analogWrite(PIN_RED, R);
	analogWrite(PIN_GREEN, G);
	analogWrite(PIN_BLUE, B);
}

void havhavAllRGB(int times, char c) {

  void (*fun_color)();
  switch (c) {
    case('A'): fun_color = &color_A; break;
    case('B'): fun_color = &color_B; break;
    case('C'): fun_color = &color_C; break;
    case('D'): fun_color = &color_D; break;
    case('a'): fun_color = &color_a; break;
    case('b'): fun_color = &color_b; break;
    case('c'): fun_color = &color_c; break;
    case('d'): fun_color = &color_d; break;
    case('E'): fun_color = &color_E; break;
    case('e'): fun_color = &color_e; break;
    case('S'): fun_color = &color_S; break;
    case('M'): fun_color = &color_M; break;
    default: fun_color = &color_hair; break;
  }
  
	for (int i = 0; i < times; i++) {
    delay(250);
    analogWrite(PIN_RED, 0);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE, 0);
    
		delay(250);
		fun_color();
	}
}

void havhavRight() {
	analogWrite(PIN_RED, LOW);
	analogWrite(PIN_GREEN, LOW);
	analogWrite(PIN_BLUE, LOW);

	for (int i = 0; i < 8; i++) {
		delay(250);
		analogWrite(PIN_RIGHT, HIGH);
		delay(250);
		analogWrite(PIN_RED, LOW);
	}

	analogWrite(PIN_RED, HIGH);
	analogWrite(PIN_GREEN, HIGH);
	analogWrite(PIN_BLUE, HIGH);
}

void havhavLeft() {
	analogWrite(PIN_RED, LOW);
	analogWrite(PIN_GREEN, LOW);
	analogWrite(PIN_BLUE, LOW);

	for (int i = 0; i < 8; i++) {
		delay(250);
		analogWrite(PIN_LEFT, HIGH);
		delay(250);
		analogWrite(PIN_LEFT, LOW);
	}

	analogWrite(PIN_RED, HIGH);
	analogWrite(PIN_GREEN, HIGH);
	analogWrite(PIN_BLUE, HIGH);
}

void setupLedsPins() {
  Serial.println("Starting leds setup pins");

  // The RGB leds
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

  // The right led
  pinMode(PIN_RIGHT, OUTPUT);

  // The left led
  pinMode(PIN_LEFT, OUTPUT);

  color_hair();
}


void color_hair() {
	setRGBColor(100, 75, 150);
}

void color_S() {
	setRGBColor(0, 10, 150);
}

void color_M() {
	setRGBColor(255, 85, 0);
}

void color_A() {
	setRGBColor(125, 10, 0);
}

void color_B() {
	setRGBColor(45, 100, 10);
}

void color_C() {
	setRGBColor(120, 0, 175);
}

void color_D() {
	setRGBColor(40, 110, 255);
}

void color_E() {
	setRGBColor(255, 3, 45);
}

void color_a() {
	setRGBColor(255, 0, 0);
}

void color_b() {
	setRGBColor(0, 60, 45);
}

void color_c() {
	setRGBColor(150, 80, 30);
}

void color_d() {
	setRGBColor(85, 3, 25);
}

void color_e() {
	setRGBColor(25, 0, 20);
}
