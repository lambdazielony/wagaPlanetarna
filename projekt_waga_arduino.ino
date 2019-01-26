#include <HX711.h>
#include <Adafruit_NeoPixel.h>
 
#define PIN A0
#define LICZBADIOD 240
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);

#define DOUT  3
#define CLK  2

byte planetState = 100;

HX711 scale(DOUT, CLK);

float calibration_factor = 780;

int rejestr[3];
int srednia = 0;


void setup() {
  Serial.begin(9600);

  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading

  pixels.begin(); // Inicjalizacja 
  for(int i=0; i<LICZBADIOD; i++){
  pixels.setPixelColor(i, 128, 128, 128);
  }
  pixels.show();
}

void loop() {
  if(digitalRead(4) == 1){ 
    for(int i=0; i<LICZBADIOD; i++)
      pixels.setPixelColor(i, 128, 128, 0);
    pixels.show();
    planetState = 1;
  }
  else if(digitalRead(5) == 1) { 
    for(int i=0; i<LICZBADIOD; i++
      pixels.setPixelColor(i, 128, 128, 0);
    pixels.show();
    planetState = 2;
  }
  else if(digitalRead(6) == 1) planetState = 3;
  else if(digitalRead(7) == 1) planetState = 4;
  else if(digitalRead(8) == 1) planetState = 5;
  else if(digitalRead(9) == 1) planetState = 6;
  else if(digitalRead(10) == 1) planetState = 7;
  else if(digitalRead(11) == 1) planetState = 8;
  else if(digitalRead(12) == 1) planetState = 9;
  else if(digitalRead(13) == 1) planetState = 0;


  //jezeli waga bedzie rowna zero to ustaw satus planety na 100 (ekran powitalny)
  if (int(abs(scale.get_units())) == 0){ 
    for(int i=0; i<240; i++)
      pixels.setPixelColor(i, 128, 128, 128);
    pixels.show(); 
    planetState = 100;
  }

  if(planetState == 1) Serial.print("1");
  else if(planetState == 2) Serial.print("2");
  else if(planetState == 3) Serial.print("3");
  else if(planetState == 4) Serial.print("4");
  else if(planetState == 5) Serial.print("5");
  else if(planetState == 6) Serial.print("6");
  else if(planetState == 7) Serial.print("7");
  else if(planetState == 8) Serial.print("8");
  else if(planetState == 9) Serial.print("9");
  else if(planetState == 0) Serial.print("0");
  else Serial.print("100");

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
