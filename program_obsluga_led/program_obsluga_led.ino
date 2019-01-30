#include <SoftwareSerial.h>

SoftwareSerial SerialtoButtons(A3, A2);

char znak = '\n';
byte planetState = 100;

void setup() {
  SerialtoButtons.begin(4800);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
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

  if (planetState == 1) digitalWrite(12, HIGH);
  else if (planetState == 2) digitalWrite(11, HIGH);
  else if (planetState == 3) digitalWrite(10, HIGH);
  else if (planetState == 4) digitalWrite(9, HIGH);
  else if (planetState == 5) digitalWrite(8, HIGH);
  else if (planetState == 6) digitalWrite(7, HIGH);
  else if (planetState == 7) digitalWrite(6, HIGH);
  else if (planetState == 8) digitalWrite(5, HIGH);
  else if (planetState == 9) digitalWrite(4, HIGH);
  else if (planetState == 10) digitalWrite(3, HIGH);
  else if (planetState == 100) {   
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  }

  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

}
