#include <NanitLib.h>

byte const rLed = P3_2;
byte const yLed = P3_3;
byte const gLed = P3_4;

int const PAUSE = 500;
int const BLINK_IGNITE = 250;
int const BLINK_PAUSE = 250;
int const rTime = 3000;
int const yTime = 1500;
int const gTime = 3000;

//byte count; // = 0

enum Colors {
  E_RED,
  E_YELLOW,
  E_GREEN,
  E_YELLOW2,
  E_SIZE
};

void setup() {
  Nanit_Base_Start();
  pinMode(rLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(gLed, OUTPUT);
}

void loop() {
  static byte count = 0;
  if (count == E_RED) {
    shining(1, 0, 0, rTime);
    blinking(1, 0, 0, 3, BLINK_IGNITE, BLINK_PAUSE);
  } else if (count == E_YELLOW) {
    shining(0, 1, 0, yTime);
  } else if (count == E_GREEN) {
    shining(0, 0, 1, gTime);
    blinking(0, 0, 1, 3, BLINK_IGNITE, BLINK_PAUSE);
  } else if (count == E_YELLOW2) {
    shining(0, 1, 0, yTime);
  }
  ++count;
  count %= E_SIZE; 
}

void ledOn(bool rSig, bool ySig, bool gSig) {
  digitalWrite(rLed, rSig);
  digitalWrite(yLed, ySig);
  digitalWrite(gLed, gSig);
}

void shining(bool rSig, bool ySig, bool gSig, int ignite_time) {
  ledOn(rSig, ySig, gSig);
  delay(ignite_time);
  ledOn(0, 0, 0);
  delay(PAUSE);
}

void blinking(bool rSig, bool ySig, bool gSig, byte times, int ignite_time, int sleep_time) {
  for (int i = 0; i < times; ++i) {
    ledOn(rSig, ySig, gSig);
    delay(ignite_time);
    ledOn(0, 0, 0);
    delay(sleep_time);
  }
  delay(PAUSE);
}
