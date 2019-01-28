#include <SoftwareSerial.h>

#define MERCURY 3
#define VENUS 4
#define EARTH 5
#define MARS 6
#define JUPITER 7
#define SATURN 8
#define URANUS 9
#define NEPTUNE 10
#define MOON 11
#define SUN 12

SoftwareSerial SerialtoUNO(A5, A4); //komunikacja z uno
SoftwareSerial SerialtoLED(A2, A1); //komunikacja z ledami
byte planetState = 100;
int waga = 60;

void setup() {
  SerialtoLED.begin(4800);
  Serial.begin(9600);

  pinMode(MERCURY, INPUT_PULLUP);
  pinMode(VENUS, INPUT_PULLUP);
  pinMode(EARTH, INPUT_PULLUP);
  pinMode(MARS, INPUT_PULLUP);
  pinMode(JUPITER, INPUT_PULLUP);
  pinMode(SATURN, INPUT_PULLUP);
  pinMode(URANUS, INPUT_PULLUP);
  pinMode(NEPTUNE, INPUT_PULLUP);
  pinMode(MOON, INPUT_PULLUP);
  pinMode(SUN, INPUT_PULLUP);

}

void loop() {

 /* if (digitalRead(MERCURY) == 0) {
    SerialtoLED.print("1");
    SerialtoUNO.print("1");
    Serial.print("1");
  }
  else if (digitalRead(VENUS) == 0) {
    SerialtoLED.print("2");
    SerialtoUNO.print("2");
    Serial.print("2");
  }
  else if (digitalRead(EARTH) == 0) {
    SerialtoLED.print("3");
    SerialtoUNO.print("3");
    Serial.print("3");
  }
  else if (digitalRead(MARS) == 0) {
    SerialtoLED.print("4");
    SerialtoUNO.print("4");
    Serial.print("4");
  }
  else if (digitalRead(JUPITER) == 0) {
    SerialtoLED.print("5");
    SerialtoUNO.print("5");
    Serial.print("5");
  }
  else if (digitalRead(SATURN) == 0) {
    SerialtoLED.print("6");
    SerialtoUNO.print("6");
    Serial.print("6");
  }
  else if (digitalRead(URANUS) == 0) {
    SerialtoLED.print("7");
    SerialtoUNO.print("7");
    Serial.print("7");
  }
  else if (digitalRead(NEPTUNE) == 0) {
    SerialtoLED.print("8");
    SerialtoUNO.print("8");
    Serial.print("8");
  }
  else if (digitalRead(MOON) == 0) {
    SerialtoLED.print("9");
    SerialtoUNO.print("9");
    Serial.print("9");
  }
  else if (digitalRead(SUN) == 0) {
    SerialtoLED.print("0");
    SerialtoUNO.print("0");
    Serial.print("0");
  } else {
    //SerialtoLED.print("0");
    //SerialtoUNO.print("0");
    //Serial.print("100");
    }*/
  if(digitalRead(MERCURY) == 0) planetState = 1;
  else if(digitalRead(VENUS) == 0) planetState = 2;
  else if(digitalRead(EARTH) == 0) planetState = 3;
  else if(digitalRead(MARS) == 0) planetState = 4;
  else if(digitalRead(JUPITER) == 0) planetState = 5;
  else if(digitalRead(SATURN) == 0) planetState = 6;
  else if(digitalRead(URANUS) == 0) planetState = 7;
  else if(digitalRead(NEPTUNE) == 0) planetState = 8;
  else if(digitalRead(MOON) == 0) planetState = 9;
  else if(digitalRead(SUN) == 0) planetState = 0;

  if (planetState == 1) {
    SerialtoLED.print("1");
    SerialtoUNO.print("1");
    Serial.print("1");
  }
  else if (planetState == 2) {
    SerialtoLED.print("2");
    SerialtoUNO.print("2");
    Serial.print("2");
  }
  else if (planetState == 3) {
    SerialtoLED.print("3");
    SerialtoUNO.print("3");
    Serial.print("3");
  }
  else if (planetState == 4) {
    SerialtoLED.print("4");
    SerialtoUNO.print("4");
    Serial.print("4");
  }
  else if (planetState == 5) {
    SerialtoLED.print("5");
    SerialtoUNO.print("5");
    Serial.print("5");
  }
  else if (planetState == 6) {
    SerialtoLED.print("6");
    SerialtoUNO.print("6");
    Serial.print("6");
  }
  else if (planetState == 7) {
    SerialtoLED.print("7");
    SerialtoUNO.print("7");
    Serial.print("7");
  }
  else if (planetState == 8) {
    SerialtoLED.print("8");
    SerialtoUNO.print("8");
    Serial.print("8");
  }
  else if (planetState == 9) {
    SerialtoLED.print("9");
    SerialtoUNO.print("9");
    Serial.print("9");
  }
  else if (planetState == 0) {
    SerialtoLED.print("0");
    SerialtoUNO.print("0");
    Serial.print("0");
  }

  Serial.print(" ");
  Serial.print(waga);
  Serial.print(",");

  delay(100);

}
