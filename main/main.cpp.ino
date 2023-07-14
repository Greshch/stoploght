#include <NanitLib.h>

#define ON 1
#define OFF 0

const byte ledGreen = P3_2;
const byte ledYellow = P3_3;
const byte ledRed = P3_4;

const unsigned int IGNITE_TIME = 12000;
const unsigned int SLEEP_TIME = 500;

void Switch_On_Abstact(byte color, unsigned int ignite_time, unsigned int sleep_time) {
  digitalWrite(color, ON); 
  delay(ignite_time);
  digitalWrite(color, OFF); 
  delay(sleep_time);
}

void Switch_On_Red() {
  Switch_On_Abstact(ledRed, IGNITE_TIME, SLEEP_TIME);
}

void Switch_On_Yellow() {
  Switch_On_Abstact(ledYellow, IGNITE_TIME >> 1, SLEEP_TIME);
}

void Switch_On_Green() {
  Switch_On_Abstact(ledGreen,IGNITE_TIME, SLEEP_TIME);
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
