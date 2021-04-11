
/*  Hacker HotKey sample firmware
 *   
 *  Copyright 2021 Kernelcon
 *  SPDX-License-Identifier: Apache-2.0
 *   
 *  Button layout is top to bottom, left to right.  So..
 *  1 2 3 4
 *  5 6 7 8
 */

#include <Keyboard.h>

#define BTN1  13
#define BTN2  5
#define BTN3  10
#define BTN4  9
#define BTN5  8
#define BTN6  6
#define BTN7  12
#define BTN8  4

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);
  pinMode(BTN5, INPUT_PULLUP);
  pinMode(BTN6, INPUT_PULLUP);
  pinMode(BTN7, INPUT_PULLUP);
  pinMode(BTN8, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(BTN1) == LOW) {
    Keyboard.println("https://kernelcon.org");
    delay(200);
  }
  else if (digitalRead(BTN2) == LOW) {
    Keyboard.println("https://twitch.kernelcon.org");
    delay(200);
  }
  else if (digitalRead(BTN3) == LOW) {
    Keyboard.println("https://discord.kernelcon.org");
    delay(200);
  }
  else if (digitalRead(BTN4) == LOW) {
    Keyboard.println("https://github.com/kernelcon/hacker-hotkey");
    delay(200);
  }
  else if (digitalRead(BTN5) == LOW) {
    Keyboard.println("!vote 4");
    delay(200);
  }
  else if (digitalRead(BTN6) == LOW) {
    Keyboard.println("!vote 3");
    delay(200);
  }
  else if (digitalRead(BTN7) == LOW) {
    Keyboard.println("!vote 2");
    delay(200);
  }
  else if (digitalRead(BTN8) == LOW) {
    Keyboard.println("!vote 1");
    delay(200);
  }
}
