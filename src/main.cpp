#include "Game.h"

#define DATA 8
#define CLOCK 10
#define STORE 9

/*
 * Bottom-left: (0,0) 
 */

Matrices matricesManager(DATA, CLOCK, STORE);

int picGreen[] = {0,96,96,24,24,0,0,0}, picRed[] = {0,0,0,24,24,6,6,0};
unsigned long total_time = 0, interval = 1000, previous_time = 0;
int currentRed = 5;

void setup() { pinMode(DATA,OUTPUT); pinMode(CLOCK,OUTPUT); pinMode(STORE,OUTPUT); }

void loop() {
  for (int i = 0; i < 8; i++) {
    shiftOut(DATA, CLOCK, LSBFIRST, ~picGreen[i]);
    shiftOut(DATA, CLOCK, LSBFIRST, ~picRed[i]);
    shiftOut(DATA, CLOCK, LSBFIRST, 128 >> i);
    matricesManager.retainInfo();
  }
  total_time = millis();
  if (total_time-previous_time>interval) {
    previous_time = total_time;
    picGreen[1] = picGreen[2] = (picGreen[1] * 2) % 255;

    picRed[currentRed] -= 6;
    currentRed = (currentRed+1)%8;
    picRed[(currentRed+1)%8] += 6;
  }
  
  //shiftOut(DATA, CLOCK, LSBFIRST, ~255);
  //shiftOut(DATA, CLOCK, LSBFIRST, ~255);
  //shiftOut(DATA, CLOCK, LSBFIRST, 1);
  //registrar();
}