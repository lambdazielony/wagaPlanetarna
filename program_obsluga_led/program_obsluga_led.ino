#include <SoftwareSerial.h>

//definicja pinow odpowiedzialnych za diody pod przyciskami
#define MERCURY 12
#define VENUS 11
#define EARTH 10
#define MARS 9
#define JUPITER 8
#define SATURN 7
#define URANUS 6
#define NEPTUNE 5
#define MOON 4
#define SUN 3

//komunikacja z glownym arduino
SoftwareSerial SerialtoButtons(A3, A2);

char znak = '\n';
byte planetState = 100;

void setup() {
  SerialtoButtons.begin(4800);
  pinMode(SUN, OUTPUT);
  pinMode(MOON, OUTPUT);
  pinMode(NEPTUNE, OUTPUT);
  pinMode(URANUS, OUTPUT);
  pinMode(SATURN, OUTPUT);
  pinMode(JUPITER, OUTPUT);
  pinMode(MARS, OUTPUT);
  pinMode(EARTH, OUTPUT);
  pinMode(VENUS, OUTPUT);
  pinMode(MERCURY, OUTPUT);
}

void loop() {
  if (SerialtoButtons.available()) {
    znak = SerialtoButtons.read();
    switch (znak) {
      case '1': planetState = 1; break;
      case '2': planetState = 2; break;
      case '3': planetState = 3; break;
      case '4': planetState = 4; break;
      case '5': planetState = 5; break;
      case '6': planetState = 6; break;
      case '7': planetState = 7; break;
      case '8': planetState = 8; break;
      case '9': planetState = 9; break;
      case '0': planetState = 10; break;
      default: planetState = 100; break;
    }
  }

  if (planetState == 1) digitalWrite(MERCURY, HIGH);
  else if (planetState == 2) digitalWrite(VENUS, HIGH);
  else if (planetState == 3) digitalWrite(EARTH, HIGH);
  else if (planetState == 4) digitalWrite(MARS, HIGH);
  else if (planetState == 5) digitalWrite(JUPITER, HIGH);
  else if (planetState == 6) digitalWrite(SATURN, HIGH);
  else if (planetState == 7) digitalWrite(URANUS, HIGH);
  else if (planetState == 8) digitalWrite(NEPTUNE, HIGH);
  else if (planetState == 9) digitalWrite(MOON, HIGH);
  else if (planetState == 10) digitalWrite(SUN, HIGH);
  else if (planetState == 100) {   
  digitalWrite(MERCURY, LOW);
  digitalWrite(VENUS, LOW);
  digitalWrite(EARTH, LOW);
  digitalWrite(MARS, LOW);
  digitalWrite(JUPITER, LOW);
  digitalWrite(SATURN, LOW);
  digitalWrite(URANUS, LOW);
  digitalWrite(NEPTUNE, LOW);
  digitalWrite(MOON, LOW);
  digitalWrite(SUN, LOW);
  }

  digitalWrite(MERCURY, LOW);
  digitalWrite(VENUS, LOW);
  digitalWrite(EARTH, LOW);
  digitalWrite(MARS, LOW);
  digitalWrite(JUPITER, LOW);
  digitalWrite(SATURN, LOW);
  digitalWrite(URANUS, LOW);
  digitalWrite(NEPTUNE, LOW);
  digitalWrite(MOON, LOW);
  digitalWrite(SUN, LOW);
}
