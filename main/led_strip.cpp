
#include "led_strip.h"

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN);

void setColor(int R, int G, int B) {
	uint32_t color = Color(R, G, B);
	strip.fill(color, 0, LED_COUNT - 1);
	strip.show();
}

void setColorTheSelectedOne(unit32_t color, int n) {
	strip.setPixelColor(n, color);
	strip.show();
}

void havhavTheSelectedOne(char p) {
	int n = N_R;

	if (p == 'C') {
		n = N_C;
	}
	if (p == 'L') {
		n = N_L;
	}

	unit32_t color = getPixelColor();

	for (int i = 0; i < 8; i++) {
		delay(250);
		setColorTheSelectedOne(color, n);
		delay(250);
		strip.clear();
		strip.show();
	}

	setColor(color);
}

void havhavAll() {
	unit32_t color = getPixelColor();
	for (int i = 0; i < 8; i++) {
		delay(250);
		setColor(color);
		delay(250);
		strip.clear();
		strip.show();
	}
	setColor(color);
}


void setupLedStripPin() {
  Serial.println("Starting led strip setup pin");

  strip.begin();
  strip.show();   

  color_hair();
}


void color_hair() {
	setColor(100, 75, 150);
}

void color_S() {
	setColor(0, 10, 150);
}

void color_M() {
	setColor(255, 85, 0);
}

void color_A() {
	setColor(125, 10, 0);
}

void color_B() {
	setColor(45, 100, 10);
}

void color_C() {
	setColor(120, 0, 175)
}

void color_D() {
	setColor(40, 110, 255);
}

void color_E() {
	setColor(255, 3, 45);
}

void color_a() {
	setColor(255, 5, 5);
}

void color_b() {
	setColor(0, 60, 45);
}

void color_c() {
	setColor(150, 80, 30);
}

void color_d() {
	setColor(85, 3, 25);
}

void color_e() {
	setColor(25, 0, 20);
}
