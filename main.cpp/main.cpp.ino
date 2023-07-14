#include <NanitLib.h>

byte ledGreen = P3_2;
byte ledYellow = P3_3;
byte ledRed = P3_4;

const unsigned int TIMER = 1000;
constexpr unsigned int IGNITE = TIMER;
constexpr unsigned int DARK = TIMER / 8;

#define ON 1
#define OFF 0

void Switch_On_Abstact(byte color) {
  digitalWrite(color, ON); 
  delay(IGNITE);
  digitalWrite(color, OFF); 
  delay(DARK);
}

void Switch_On_Red() {
  Switch_On_Abstact(ledRed);
}

void Switch_On_Yellow() {
  Switch_On_Abstact(ledYellow);
}

void Switch_On_Green() {
  Switch_On_Abstact(ledGreen);
}

void setup() {
  Nanit_Base_Start();
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  Switch_On_Green();
  Switch_On_Yellow();
  Switch_On_Red();
  Switch_On_Yellow();
}
