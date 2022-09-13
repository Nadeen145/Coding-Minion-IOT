
#include "led_strip.h"

void setup() {
  Serial.begin(115200);
  Serial.println("** STARTING ESP SETUP **");
  
  setupLedStripPin();
  
  Serial.println("** FINISHED ESP SETUP **");
}

void loop() {
  color_hair();
    delay(3000);
  color_S();
    delay(3000);
  color_M();
    delay(3000);
  color_A();
    delay(3000);
  color_B();
    delay(3000);
  color_C();
    delay(3000);
  color_D();
    delay(3000);
  color_E();
    delay(3000);
  color_a();
    delay(3000);
  color_b();
    delay(3000);
  color_c();
    delay(3000);
  color_d();
    delay(3000);
  color_e();
    delay(3000);
}
