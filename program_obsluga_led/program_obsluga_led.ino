#include <SoftwareSerial.h>

//definicja pinow odpowiedzialnych za diody pod przyciskami
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

  if (planetState == 1) {
    digitalWrite(MERCURY, HIGH);
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
  else if (planetState == 2) {
    digitalWrite(VENUS, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(MOON, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 3) {
    digitalWrite(EARTH, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(MOON, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 4) {
    digitalWrite(MARS, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(MOON, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 5) {
    digitalWrite(JUPITER, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(MOON, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 6) {
    digitalWrite(SATURN, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(MOON, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 7) {
    digitalWrite(URANUS, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(MOON, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 8) {
    digitalWrite(NEPTUNE, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(MOON, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 9) {
    digitalWrite(MOON, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(SUN, LOW);
  }
  else if (planetState == 10) {
    digitalWrite(SUN, HIGH);
    digitalWrite(MERCURY, LOW);
    digitalWrite(VENUS, LOW);
    digitalWrite(EARTH, LOW);
    digitalWrite(MARS, LOW);
    digitalWrite(JUPITER, LOW);
    digitalWrite(SATURN, LOW);
    digitalWrite(URANUS, LOW);
    digitalWrite(NEPTUNE, LOW);
    digitalWrite(MOON, LOW);
  }
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
}
