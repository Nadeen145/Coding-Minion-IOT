#include "leds.h"
#include "Arduino.h"


void setup() {
  setupLedsPins();
}

void loop() {
  havhavRight();
  havhavLeft();

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
