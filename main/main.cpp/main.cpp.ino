#include <NanitLib.h>

// byte const rLed = P3_2;
// byte const yLed = P3_3;
// byte const gLed = P3_4;

int const PAUSE = 500;
int const BLINK_IGNITE = 250;
int const BLINK_PAUSE = 250;
int const rTime = 3000;
int const yTime = 1500;
int const gTime = 3000;

struct S_Light {
  byte rLed;
  byte yLed;
  byte gLed;
} first, second;

struct S_Matrix3 {
  byte fst;
  byte scn;
  byte thr;
};
 

//byte count; // = 0

enum Colors {
  E_RED,
  E_YELLOW,
  E_GREEN,
  E_YELLOW2,
  E_SIZE
};

void ledOn(S_Light& light, /*bool rSig, bool ySig, bool gSig*/ S_Matrix3 const& matrix);

void setup() {
  Nanit_Base_Start();
  first.rLed = P3_2;
  first.yLed = P3_3;
  first.gLed = P3_4;

  second.rLed = P4_2;
  second.yLed = P4_3;
  second.gLed = P4_4;

  pinMode(first.rLed, OUTPUT);
  pinMode(first.yLed, OUTPUT);
  pinMode(first.gLed, OUTPUT);

  pinMode(second.rLed, OUTPUT);
  pinMode(second.yLed, OUTPUT);
  pinMode(second.gLed, OUTPUT);
}

void loop() {
  static byte count = 0;
  if (count == 0) {
    // shining(1, 0, 0, rTime);
    // blinking(1, 0, 0, 3, BLINK_IGNITE, BLINK_PAUSE);
    ledOn(first, {1, 0, 0});
    ledOn(second, {0, 0, 1});
    delay(rTime);
  } else if (count == 1) {
    ledOn(first, {0, 1, 0});
    ledOn(second, {0, 1, 0});
    delay(yTime);
    //shining(0, 1, 0, yTime);
  } else if (count == 2) {
    // shining(0, 0, 1, gTime);
    // blinking(0, 0, 1, 3, BLINK_IGNITE, BLINK_PAUSE);
    ledOn(first, {0, 0, 1});
    ledOn(second, {1, 0, 0});
    delay(gTime);
  } else if (count == 3) {
    //shining(0, 1, 0, yTime);
    ledOn(first, {0, 1, 0});
    ledOn(second, {0, 1, 0});
    delay(yTime);
  }
  ++count;
  count %= E_SIZE; 
}

void ledOn(S_Light& light, /*bool rSig, bool ySig, bool gSig*/ S_Matrix3 const& matrix) {
  // digitalWrite(light.rLed, rSig);
  // digitalWrite(light.yLed, ySig);
  // digitalWrite(light.gLed, gSig);
  digitalWrite(light.rLed, matrix.fst);
  digitalWrite(light.yLed, matrix.scn);
  digitalWrite(light.gLed, matrix.thr);
}

// void shining(bool rSig, bool ySig, bool gSig, int ignite_time) {
//   ledOn(rSig, ySig, gSig);
//   delay(ignite_time);
//   ledOn(0, 0, 0);
//   delay(PAUSE);
// }

// void blinking(bool rSig, bool ySig, bool gSig, byte times, int ignite_time, int sleep_time) {
//   for (int i = 0; i < times; ++i) {
//     ledOn(rSig, ySig, gSig);
//     delay(ignite_time);
//     ledOn(0, 0, 0);
//     delay(sleep_time);
//   }
//   delay(PAUSE);
// }
