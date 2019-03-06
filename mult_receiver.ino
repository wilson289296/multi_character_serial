#include <LiquidCrystal.h>
//display pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int rgbypin [4] = {9,8,6,7};
unsigned long rgbyrefr [4] = {0,0,0,0};
unsigned long lcdrefr = 0;

int ascii;
bool enddata = false;
String finaldata;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (Serial.available()>0){
    ascii = Serial.read();
  }
  lcd.begin(16, 2);
  lcd.leftToRight();
  lcd.setCursor(0,0);
  lcd.print("Signal received:");
  lcd.setCursor(0,1);
  for(int i = 0; i < 4; i++){
    pinMode(rgbypin[i], OUTPUT);
  }
  finaldata = "";
}

void loop() {
  //stay in this loop until data is done transmitting
  while(!enddata){
    ascii = Serial.read();
    if(ascii > 0){
      finaldata += String(char(ascii));
    }
    if(ascii == 0){
      enddata = true;
    }
  }
  if (finaldata.charAt(0) == 'B'){
    if (finaldata.charAt(1) == 'd'){
      digitalWrite(rgbypin[0], HIGH);
    } else if (finaldata.charAt(1) == 'u'){
      digitalWrite(rgbypin[0], LOW);
    }
  } else if (finaldata.charAt(0) == 'A'){
    if (finaldata.charAt(1) == 'd'){
      digitalWrite(rgbypin[1], HIGH);
    } else if (finaldata.charAt(1) == 'u'){
      digitalWrite(rgbypin[1], LOW);
    }
  } else if (finaldata.charAt(0) == 'X'){
    if (finaldata.charAt(1) == 'd'){
      digitalWrite(rgbypin[2], HIGH);
    } else if (finaldata.charAt(1) == 'u'){
      digitalWrite(rgbypin[2], LOW);
    }
  } else if (finaldata.charAt(0) == 'Y'){
    if (finaldata.charAt(1) == 'd'){
      digitalWrite(rgbypin[3], HIGH);
    } else if (finaldata.charAt(1) == 'u'){
      digitalWrite(rgbypin[3], LOW);
    }
  }
  lcd.setCursor(0,1);
  lcd.print(finaldata);
  finaldata = "";
  enddata = false;
}
