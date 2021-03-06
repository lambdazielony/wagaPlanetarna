#include <HX711.h>
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
 
#define PIN 6
#define LICZBADIOD 220

#define DOUT  2
#define CLK  3

SoftwareSerial SerialtoNANO(5, 4);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
HX711 scale(DOUT, CLK);

byte planetState = 100;
float calibration_factor = 780; //780
int rejestr[3];
int srednia = 0;
char znak = '\n';

void setup() {
  Serial.begin(9600);
  SerialtoNANO.begin(4800);
  
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading

  pixels.begin(); // Inicjalizacja 
  for(int i=0; i<LICZBADIOD; i++)
    pixels.setPixelColor(i, 128, 128, 128);
  pixels.show();
}

void loop() {
 
  //jezeli waga bedzie rowna zero to ustaw satus planety na 100 (ekran powitalny)
  if (int(abs(scale.get_units())) <= 0){ 
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 128, 128, 128);
    pixels.show(); 
    planetState = 100;
    SerialtoNANO.print("e");
  }

  if (SerialtoNANO.available()) {
    znak = SerialtoNANO.read();
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
      case '0': planetState = 0; break;
      default: planetState = 100; break;
    }
  }

  if (planetState == 1) {
    Serial.print("1"); //wysłanie informacji do komputera 
    for(int i=0; i<LICZBADIOD; i++) //---------------\\
      pixels.setPixelColor(i, 219, 206, 202);//------ustawienie koloru diod
    pixels.show(); //--------------------------------//
  }
  else if (planetState == 2) {
    Serial.print("2");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 199, 60, 7);
    pixels.show();
  }
  else if (planetState == 3) {
    Serial.print("3");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 11, 255, 30);
    pixels.show();
  }
  else if (planetState == 4) {
    Serial.print("4");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 233, 107, 57);
    pixels.show();
  }
  else if (planetState == 5) {
    Serial.print("5");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 157, 91, 3);
    pixels.show();
  }
  else if (planetState == 6) {
    Serial.print("6");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 255, 229, 180);
    pixels.show();
  }
  else if (planetState == 7) {
    Serial.print("7");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 0, 127, 255);
    pixels.show();
  }
  else if (planetState == 8) {
    Serial.print("8");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 3, 0, 253);
    pixels.show();
  }
  else if (planetState == 9) {
    Serial.print("9");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 219, 176, 239);
    pixels.show();
  }
  else if (planetState == 0) {
    Serial.print("0");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 255, 192, 0);
    pixels.show();
  } 
  else if (planetState == 100){
    //SerialtoNANO.print("e");
    Serial.print("100");
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 128, 128, 128);
    pixels.show();
  }

  Serial.print(" ");
  
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  
  for(int i=0; i<3; i++){
    rejestr[i] = (int)abs(scale.get_units());
  }
  
  for(int i=0; i<3; i++){
    srednia += rejestr[i];
  } 
  srednia /= 4;
  Serial.print(srednia);

  Serial.print(",");

  delay(100);

}
