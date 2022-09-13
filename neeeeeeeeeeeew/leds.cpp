//
//#include "leds.h"
//
//void setColorR(int R, int G, int B) {
//	analogWrite(PIN_RED_R, R);
//	analogWrite(PIN_GREEN_R, G);
//	analogWrite(PIN_BLUE_R, B);
//}
//
//void setColorC(int R, int G, int B) {
//	analogWrite(PIN_RED_C, R);
//	analogWrite(PIN_GREEN_C, G);
//	analogWrite(PIN_BLUE_C, B);
//}
//
//void setColorL(int R, int G, int B) {
//	analogWrite(PIN_RED_L, R);
//	analogWrite(PIN_GREEN_L, G);
//	analogWrite(PIN_BLUE_L, B);
//}
//
//void havhavTheSelectedOne(char p) {
//	int R = PIN_RED_R;
//	int G = PIN_GREEN_R;
//	int B = PIN_BLUE_R;
//
//	if (p == 'C') {
//		R = PIN_RED_C;
//		G = PIN_GREEN_C;
//		B = PIN_BLUE_C;
//	}
//
//	if (p == 'L') {
//		R = PIN_RED_L;
//		G = PIN_GREEN_L;
//		B = PIN_BLUE_L;
//	}
//
//	for (int i = 0; i < 7; i++) {
//		delay(500);
//		digitalWrite(R, HIGH);
//		digitalWrite(G, HIGH);
//		digitalWrite(B, HIGH);
//		delay(500);
//		digitalWrite(R, LOW);
//		digitalWrite(G, LOW);
//		digitalWrite(B, LOW);
//	}
//}
//
//void setupLedsPins() {
//  Serial.println("Starting leds setup pins");
//
//  // The right led
//  pinMode(PIN_RED_R, OUTPUT);
//  pinMode(PIN_GREEN_R, OUTPUT);
//  pinMode(PIN_BLUE_R, OUTPUT);
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
//
//  color_black();
//}
//
//
//void color_black() {
//
//	// rgb(0, 0, 0)
//	setColorR(0, 0, 0);
//	setColorC(0, 0, 0);
//	setColorL(0, 0, 0);
//}
//
//void color_S() {
//
//	// rgb(40, 113, 204)
//	setColorR(40, 113, 204);
//	setColorC(40, 113, 204);
//	setColorL(40, 113, 204);
//}
//
//void color_M() {
//
//	// rgb(255, 217, 0)
//	setColorR(255, 217, 0;
//	setColorC(255, 217, 0);
//	setColorL(255, 217, 0);
//}
//
//void color_A() {
//
//	// rgb(239, 114, 22)
//	setColorR(239, 114, 22);
//	setColorC(239, 114, 22);
//	setColorL(239, 114, 22);
//}
//
//void color_B() {
//
//	// rgb(0, 77, 37)
//	setColorR(0, 77, 37);
//	setColorC(0, 77, 37);
//	setColorL(0, 77, 37);
//}
//
//void color_C() {
//
//	// rgb(116, 0, 173)
//	setColorR(116, 0, 173);
//	setColorC(116, 0, 173);
//	setColorL(116, 0, 173);
//}
//
//void color_D() {
//
//	// rgb(24, 165, 255)
//	setColorR(24, 165, 255);
//	setColorC(24, 165, 255);
//	setColorL(24, 165, 255);
//}
//
//void color_E() {
//
//	// rgb(246, 3, 139)
//	setColorR(246, 3, 139);
//	setColorC(246, 3, 139);
//	setColorL(246, 3, 139);
//}
//
//void color_a() {
//
//	// rgb(208, 27, 36)
//	setColorR(208, 27, 36);
//	setColorC(208, 27, 36);
//	setColorL(208, 27, 36);
//}
//
//void color_b() {
//
//	// rgb(0, 128, 128)
//	setColorR(0, 128, 128);
//	setColorC(0, 128, 128);
//	setColorL(0, 128, 128);
//}
//
//void color_c() {
//
//	// rgb(128, 72, 28)
//	setColorR(128, 72, 28);
//	setColorC(128, 72, 28);
//	setColorL(128, 72, 28);
//}
//
//void color_d() {
//
//	// rgb(247, 135, 154)
//	setColorR(247, 135, 154);
//	setColorC(247, 135, 154);
//	setColorL(247, 135, 154);
//}
//
//void color_e() {
//
//	// rgb(88, 98, 97)
//	setColorR(88, 98, 97);
//	setColorC(88, 98, 97);
//	setColorL(88, 98, 97);
//}
