//Project 5
#include <TimerOne.h>
int catchPin = 10;
int dataPin = 11;
int clockPin = 12;
byte led[8];

void setup() {
  pinMode(catchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  led[0] = 0b11111111;
  led[1] = 0b10000001;
  led[2] = 0b10111101;
  led[3] = 0b10100101;
  led[4] = 0b10100101;
  led[5] = 0b10111101;
  led[6] = 0b10000001;
  led[7] = 0b11111111;

  Timer1.initialize(1000);
  Timer1.attachInterrupt(screenUpdate);

}

void loop() {
  for(int i = 0; i < 8; i++) {
    led[i] = ~led[i];
  }
  delay(250);
}

void screenUpdate() {
  byte row = 0b10000000;
  for(int i = 0; i < 8; i++) {
    shiftOut(dataPin, clockPin, LSBFIRST, led[i]);
    shiftOut(dataPin, clockPin, LSBFIRST, ~row);
    digitalWrite(catchPin, LOW);
    digitalWrite(catchPin, HIGH);
    row >>= 1;
  }
  shiftOut(dataPin, clockPin, LSBFIRST, 0);
  shiftOut(dataPin, clockPin, LSBFIRST, ~0);
  digitalWrite(catchPin, LOW);
  digitalWrite(catchPin, HIGH);
}

