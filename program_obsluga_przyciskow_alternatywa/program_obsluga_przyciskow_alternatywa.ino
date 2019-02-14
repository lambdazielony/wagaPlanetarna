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

SoftwareSerial SerialtoWAGA(A5, A4); //komunikacja z arduino w wadze
SoftwareSerial SerialtoLED(A2, A1); //komunikacja z ledami
byte planetState = 100;
char znak = '\n';

void setup() {
  SerialtoLED.begin(4800);
  SerialtoWAGA.begin(4800);
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
  if (digitalRead(MERCURY) == 0) {
    SerialtoLED.print("1");
    SerialtoWAGA.print("1");
    //Serial.print("1");
  }
  else if (digitalRead(VENUS) == 0) {
    SerialtoLED.print("2");
    SerialtoWAGA.print("2");
    //Serial.print("2");
  }
  else if (digitalRead(EARTH) == 0) {
    SerialtoLED.print("3");
    SerialtoWAGA.print("3");
    //Serial.print("3");
  }
  else if (digitalRead(MARS) == 0) {
    SerialtoLED.print("4");
    SerialtoWAGA.print("4");
    //Serial.print("4");
  }
  else if (digitalRead(JUPITER) == 0) {
    SerialtoLED.print("5");
    SerialtoWAGA.print("5");
    //Serial.print("5");
  }
  else if (digitalRead(SATURN) == 0) {
    SerialtoLED.print("6");
    SerialtoWAGA.print("6");
    //Serial.print("6");
  }
  else if (digitalRead(URANUS) == 0) {
    SerialtoLED.print("7");
    SerialtoWAGA.print("7");
    //Serial.print("7");
  }
  else if (digitalRead(NEPTUNE) == 0) {
    SerialtoLED.print("8");
    SerialtoWAGA.print("8");
    //Serial.print("8");
  }
  else if (digitalRead(MOON) == 0) {
    SerialtoLED.print("9");
    SerialtoWAGA.print("9");
    //Serial.print("9");
  }
  else if (digitalRead(SUN) == 0) {
    SerialtoLED.print("0");
    SerialtoWAGA.print("0");
    //Serial.print("0");
  }
  
 if(SerialtoWAGA.available()){
    znak = SerialtoWAGA.read();
    switch(znak){
      case 'e': SerialtoLED.print("e"); break;
    }
  }

  delay(100);
}
