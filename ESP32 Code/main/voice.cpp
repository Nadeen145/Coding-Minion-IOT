
#include "voice.h"

extern L298NX2* motors;


void buzzerOn(){
  tone(BUZZER_PIN, 1000);
}
void buzzerOff(){
  noTone(BUZZER_PIN);
}

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
    tone(BUZZER_PIN, melody_coffin_dance[thisNote]);

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
    noTone(BUZZER_PIN);
  
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
int notes_keyboard_cat = sizeof(melody_keyboard_cat) / sizeof(melody_keyboard_cat[0]) / 2;
int wholenote_keyboard_cat = (60000 * 4) / tempo_keyboard_cat;
int divider_keyboard_cat = 0, noteDuration_keyboard_cat = 0;

void keyboard_cat(){
  int j = 0;
  for (int thisNote = 0; thisNote < notes_keyboard_cat * 2; thisNote = thisNote + 2) {
    divider_keyboard_cat = melody_keyboard_cat[thisNote + 1];
    if (divider_keyboard_cat > 0) {
      analogWrite(PIN_RED, 0); analogWrite(PIN_GREEN, 0); analogWrite(PIN_BLUE, 0);
      if(j%2 == 0 && thisNote > 4){
        motors->forwardA(); 
        motors->backwardB();
      } else if (j%2 != 0 && thisNote > 4){
        motors->forwardB(); 
        motors->backwardA();
      }
      j += 1;
      noteDuration_keyboard_cat = (wholenote_keyboard_cat) / divider_keyboard_cat;
    } else if (divider_keyboard_cat < 0) {
      color_hair();
      motors->stop();
      noteDuration_keyboard_cat = (wholenote_keyboard_cat) / abs(divider_keyboard_cat);
      noteDuration_keyboard_cat *= 1.5;
    }
    tone(BUZZER_PIN, melody_keyboard_cat[thisNote], noteDuration_keyboard_cat * 0.9);
    delay(noteDuration_keyboard_cat);
    noTone(BUZZER_PIN);
  }
  color_hair();
  motors->stop();
}


int melody_harry_potter[] = {
    REST, 2, NOTE_D4, 4,
    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_G4, 2, NOTE_D5, 4,
    NOTE_C5, -2,
    NOTE_A4, -2,
    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_F4, 2, NOTE_GS4, 4,
    NOTE_D4, -1,
    NOTE_D4, 4,

    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
    NOTE_G4, 2, NOTE_D5, 4,
    NOTE_F5, 2, NOTE_E5, 4,
    NOTE_DS5, 2, NOTE_B4, 4,
    NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_B4, 4,
    NOTE_G4, -1,
    NOTE_AS4, 4,

    NOTE_D5, 2, NOTE_AS4, 4,//18
    NOTE_D5, 2, NOTE_AS4, 4,
    NOTE_DS5, 2, NOTE_D5, 4,
    NOTE_CS5, 2, NOTE_A4, 4,
    NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_D4, 4,
    NOTE_D5, -1,
    REST,4, NOTE_AS4,4,

    NOTE_D5, 2, NOTE_AS4, 4,//26
    NOTE_D5, 2, NOTE_AS4, 4,
    NOTE_F5, 2, NOTE_E5, 4,
    NOTE_DS5, 2, NOTE_B4, 4,
    NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_AS4, 4,
    NOTE_G4, -1,
};
int tempo_harry_potter = 350;
int notes_harry_potter = sizeof(melody_harry_potter) / sizeof(melody_harry_potter[0]) / 2;
int wholenote_harry_potter = (60000 * 4) / tempo_harry_potter;
int divider_harry_potter = 0, noteDuration_harry_potter = 0;

void harry_poter() {
    for (int thisNote = 0; thisNote < notes_harry_potter * 2; thisNote = thisNote + 2) {
        divider_harry_potter = melody_harry_potter[thisNote + 1];
        if (divider_harry_potter > 0) {
            noteDuration_harry_potter = (wholenote_harry_potter) / divider_harry_potter;
        }
        else if (divider_harry_potter < 0) {
            noteDuration_harry_potter = (wholenote_harry_potter) / abs(divider_harry_potter);
            noteDuration_harry_potter *= 1.5;
        }
        tone(BUZZER_PIN, melody_harry_potter[thisNote], noteDuration_harry_potter * 0.9);
        delay(noteDuration_harry_potter);
        noTone(BUZZER_PIN);
    }
}


int melody_games_of_thrones[] = {
    NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, //1
    NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,

    NOTE_G4,-4, NOTE_C4,-4, //5

    NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
    NOTE_D4,-1, //7 and 8
    NOTE_F4,-4, NOTE_AS3,-4,
    NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
    NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12
    NOTE_G4,-4, NOTE_C4,-4,
    NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4,  NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16,

    NOTE_D4,-2,//15
    NOTE_F4,-4, NOTE_AS3,-4,
    NOTE_D4,-8, NOTE_DS4,-8, NOTE_D4,-8, NOTE_AS3,-8,
    NOTE_C4,-1,
    NOTE_C5,-2,
    NOTE_AS4,-2,
    NOTE_C4,-2,
    NOTE_G4,-2,
    NOTE_DS4,-2,
    NOTE_DS4,-4, NOTE_F4,-4,
    NOTE_G4,-1,

    NOTE_C5,-2,//28
    NOTE_AS4,-2,
    NOTE_C4,-2,
    NOTE_G4,-2,
    NOTE_DS4,-2,
    NOTE_D4,-8,
    NOTE_DS4,-8, NOTE_D4,-8, NOTE_AS3,-8,
    NOTE_C4,-1,
};

int tempo_games_of_thrones = 300;
int notes_games_of_thrones = sizeof(melody_games_of_thrones) / sizeof(melody_games_of_thrones[0]) / 2;
int wholenote_games_of_thrones = (60000 * 4) / tempo_games_of_thrones;
int divider_games_of_thrones = 0, noteDuration_games_of_thrones = 0;

void games_of_thrones() {
    for (int thisNote = 0; thisNote < notes_games_of_thrones * 2; thisNote = thisNote + 2) {
        divider_games_of_thrones = melody_games_of_thrones[thisNote + 1];
        if (divider_games_of_thrones > 0) {
            noteDuration_games_of_thrones = (wholenote_games_of_thrones) / divider_games_of_thrones;
        }
        else if (divider_games_of_thrones < 0) {
            noteDuration_games_of_thrones = (wholenote_games_of_thrones) / abs(divider_games_of_thrones);
            noteDuration_games_of_thrones *= 1.5;
        }
        tone(BUZZER_PIN, melody_games_of_thrones[thisNote], noteDuration_games_of_thrones * 0.9);
        delay(noteDuration_games_of_thrones);
        noTone(BUZZER_PIN);
    }
}


int melody_starwar[] = {
    NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
    NOTE_F5,2, NOTE_C6,2,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,
    NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
    NOTE_F5,2, NOTE_C6,2,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,

    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
    NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16,
    NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
    NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
    NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,

    NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
    NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
    NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
    NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
    NOTE_C6,1

};
int tempo_starwar = 300;
int notes_starwar = sizeof(melody_starwar) / sizeof(melody_starwar[0]) / 2;
int wholenote_starwar = (60000 * 4) / tempo_starwar;
int divider_starwar = 0, noteDuration_starwar = 0;

void starwar() {
    for (int thisNote = 0; thisNote < notes_starwar * 2; thisNote = thisNote + 2) {
        divider_starwar = melody_starwar[thisNote + 1];
        if (divider_starwar > 0) {
            noteDuration_starwar = (wholenote_starwar) / divider_starwar;
        }
        else if (divider_starwar < 0) {
            noteDuration_starwar = (wholenote_starwar) / abs(divider_starwar);
            noteDuration_starwar *= 1.5;
        }
        tone(BUZZER_PIN, melody_starwar[thisNote], noteDuration_starwar * 0.9);
        delay(noteDuration_starwar);
        noTone(BUZZER_PIN);
    }
}


int melody_pacman[] = {
    NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
    NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
    NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,

    NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  //2
    NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
    NOTE_F5, 32,  NOTE_FS5, 32,  NOTE_G5, 32,  NOTE_G5, 32, NOTE_GS5, 32,  NOTE_A5, 16, NOTE_B5, 8
};
int tempo_pacman = 105;
int notes_pacman = sizeof(melody_pacman) / sizeof(melody_pacman[0]) / 2;
int wholenote_pacman = (60000 * 4) / tempo_pacman;
int divider_pacman = 0, noteDuration_pacman = 0;

void pacman() {
    for (int thisNote = 0; thisNote < notes_pacman * 2; thisNote = thisNote + 2) {
        divider_pacman = melody_pacman[thisNote + 1];
        if (divider_pacman > 0) {
            noteDuration_pacman = (wholenote_pacman) / divider_pacman;
        }
        else if (divider_pacman < 0) {
            noteDuration_pacman = (wholenote_pacman) / abs(divider_pacman);
            noteDuration_pacman *= 1.5;
        }
        tone(BUZZER_PIN, melody_pacman[thisNote], noteDuration_pacman * 0.9);
        delay(noteDuration_pacman);
        noTone(BUZZER_PIN);
    }
}


int melody_pink_panther[] = {
    REST,2, REST,4, REST,8, NOTE_DS4,8,
    NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
    NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,
    NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,
    NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,

    NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
    NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
    NOTE_DS5,1,
    NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8,
    NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
    NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,

    NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,
    NOTE_E4,-4, REST,4,
    REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
    NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,
    NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,

};
int tempo_pink_panther = 250;
int notes_pink_panther = sizeof(melody_pink_panther) / sizeof(melody_pink_panther[0]) / 2;
int wholenote_pink_panther = (60000 * 4) / tempo_pink_panther;
int divider_pink_panther = 0, noteDuration_pink_panther = 0;

void pink_panther() {
    for (int thisNote = 0; thisNote < notes_pink_panther * 2; thisNote = thisNote + 2) {
        divider_pink_panther = melody_pink_panther[thisNote + 1];
        if (divider_pink_panther > 0) {
            noteDuration_pink_panther = (wholenote_pink_panther) / divider_pink_panther;
        }
        else if (divider_pink_panther < 0) {
            noteDuration_pink_panther = (wholenote_pink_panther) / abs(divider_pink_panther);
            noteDuration_pink_panther *= 1.5;
        }
        tone(BUZZER_PIN, melody_pink_panther[thisNote], noteDuration_pink_panther * 0.9);
        delay(noteDuration_pink_panther);
        noTone(BUZZER_PIN);
    }
}
