#include <HX711.h>
#include <Adafruit_NeoPixel.h>
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

#define DOUT A4
#define CLK A5
#define PIN 2
#define LICZBADIOD 8 // 240

SoftwareSerial SerialtoLED(A2, A1); //komunikacja z ledami
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
HX711 scale(DOUT, CLK);

byte planetState = 100;
float calibration_factor = -7050; //780
int rejestr[3];
int srednia = 0;

void setup() {
  SerialtoLED.begin(4800);
  Serial.begin(9600);

  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading


  for (int i = 0; i < LICZBADIOD; i++)
    pixels.setPixelColor(i, 128, 128, 128);
  pixels.show();

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

  pixels.begin(); // Inicjalizacja

}

void loop() {

  //jezeli waga bedzie rowna zero to ustaw satus planety na 100 (ekran powitalny)
  if (int(abs(scale.get_units())) == 0) {
    for (int i = 0; i < LICZBADIOD; i++)
      pixels.setPixelColor(i, 128, 128, 128);
    pixels.show();
    planetState = 100;
  }

  if (digitalRead(MERCURY) == 0) planetState = 1;
  else if (digitalRead(VENUS) == 0) planetState = 2;
  else if (digitalRead(EARTH) == 0) planetState = 3;
  else if (digitalRead(MARS) == 0) planetState = 4;
  else if (digitalRead(JUPITER) == 0) planetState = 5;
  else if (digitalRead(SATURN) == 0) planetState = 6;
  else if (digitalRead(URANUS) == 0) planetState = 7;
  else if (digitalRead(NEPTUNE) == 0) planetState = 8;
  else if (digitalRead(MOON) == 0) planetState = 9;
  else if (digitalRead(SUN) == 0) planetState = 0;

  if (planetState == 1) {
    SerialtoLED.print("1");
    Serial.print("1");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 219, 206, 202);
    pixels.show();
  }
  else if (planetState == 2) {
    SerialtoLED.print("2");
    Serial.print("2");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 199, 60, 7);
    pixels.show();
  }
  else if (planetState == 3) {
    SerialtoLED.print("3");
    Serial.print("3");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 11, 255, 30);
    pixels.show();
  }
  else if (planetState == 4) {
    SerialtoLED.print("4");
    Serial.print("4");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 233, 107, 57);
    pixels.show();
  }
  else if (planetState == 5) {
    SerialtoLED.print("5");
    Serial.print("5");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 157, 91, 3);
    pixels.show();
  }
  else if (planetState == 6) {
    SerialtoLED.print("6");
    Serial.print("6");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 255, 229, 180);
    pixels.show();
  }
  else if (planetState == 7) {
    SerialtoLED.print("7");
    Serial.print("7");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 0, 127, 255);
    pixels.show();
  }
  else if (planetState == 8) {
    SerialtoLED.print("8");
    Serial.print("8");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 3, 0, 253);
    pixels.show();
  }
  else if (planetState == 9) {
    SerialtoLED.print("9");
    Serial.print("9");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 219, 176, 239);
    pixels.show();
  }
  else if (planetState == 0) {
    SerialtoLED.print("0");
    Serial.print("0");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 255, 192, 0);
    pixels.show();
  } else if (planetState == 100){
    SerialtoLED.print("e");
    Serial.print("100");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 128, 128, 128);
    pixels.show();
  }

  Serial.print(" ");

  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  for (int i = 0; i < 3; i++) 
      rejestr[i] = (int)abs(scale.get_units());
  
  for (int i = 0; i < 3; i++) 
    srednia += rejestr[i];
  
  srednia /= 4;
  Serial.print(srednia);

  Serial.print(",");

  delay(50);
}
