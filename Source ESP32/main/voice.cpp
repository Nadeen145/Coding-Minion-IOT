
#include "voice.h"

extern L298NX2* motors;

int melody_coffin_dance[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  
  // led
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,

  // moving forward and backword
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 

  // led
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5
 };

 int noteDurations_coffin_dance[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  };

void coffin_dance(){
  for (int thisNote = 0; thisNote < 100; thisNote++) {
    int noteDuration = 750 / noteDurations_coffin_dance[thisNote];
    tone(BUZZZER_PIN, melody_coffin_dance[thisNote]);

    switch(thisNote) {
      case(35): motors->forward(); break;
      case(36): motors->stop(); break;
        case(37): motors->forward(); break;
      case(38): motors->stop(); break;
      case(39): motors->backward(); break;
        case(40): motors->stop(); break;
      case(41): motors->backward(); break;
      case(42): motors->stop(); break;
        case(43): motors->forward(); break;
      case(44): motors->stop(); break;
      case(45): motors->forward(); break;
       case(46): motors->stop(); break;
      case(47): motors->backward(); break;
      case(48): motors->stop(); break;
        case(49): motors->backward(); break;
      case(50): motors->stop(); break;
      
      case(51): color_hair(); break;
      case(52): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(53): color_hair(); break;
      case(54): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(55): color_hair(); break;
      case(56): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(57): color_hair(); break;
      case(58): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(59): color_hair(); break;
      case(60): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(61): color_hair(); break;
      case(62): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(63): color_hair(); break;
      case(64): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(65): color_hair(); break;
      
      case(68): motors->forward(); break;
      case(69): motors->stop(); break;
      case(70): motors->forward(); break;
      case(71): motors->stop(); break;
      case(72): motors->backward(); break;
      case(73): motors->stop(); break;
      case(74): motors->backward(); break;
      case(75): motors->stop(); break;
      case(76): motors->forward(); break;
      case(77): motors->stop(); break;
      case(78): motors->forward(); break;
      case(79): motors->stop(); break;
      case(80): motors->backward(); break;
      case(81): motors->stop(); break;
      case(82): motors->backward(); break;
      case(83): motors->stop(); break;
      
      case(84): color_hair(); break;
      case(85): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(86): color_hair(); break;
      case(87): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(88): color_hair(); break;
      case(89): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(90): color_hair(); break;
      case(91): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(92): color_hair(); break;
      case(93): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(94): color_hair(); break;
      case(95): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(96): color_hair(); break;
      case(97): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
      case(98): color_hair(); break;
      case(99): analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0); break;
    }

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZZER_PIN);
  
  }
  color_hair();
  motors->stop();
}

int melody_keyboard_cat[] = {
    REST,1,
    REST,1,
    NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
    NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
    NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
    NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
    NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
    NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,

    NOTE_G3,4, NOTE_G3,8, NOTE_G3,-4, NOTE_G3,8, NOTE_G3,4, 
    NOTE_G3,4, NOTE_G3,4, NOTE_G3,8, NOTE_G3,4,
    NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
    NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
    NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
    NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
    NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
    NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,

    NOTE_G3,-1, 
};

int tempo_keyboard_cat = 250;
int notes = sizeof(melody_keyboard_cat) / sizeof(melody_keyboard_cat[0]) / 2;
int wholenote = (60000 * 4) / tempo_keyboard_cat;
int divider = 0, noteDuration_keyboard_cat = 0;

void keyboard_cat(){
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody_keyboard_cat[thisNote + 1];
    if (divider > 0) {
      noteDuration_keyboard_cat = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration_keyboard_cat = (wholenote) / abs(divider);
      noteDuration_keyboard_cat *= 1.5;
    }
    tone(BUZZZER_PIN, melody_keyboard_cat[thisNote], noteDuration_keyboard_cat * 0.9);
    delay(noteDuration_keyboard_cat);
    noTone(BUZZZER_PIN);
  }
}
