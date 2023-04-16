#include "Game.h"
#include "managers/Matrices.h"
#include "Joystick.h"
#include "Button.h"

#define DATA 8
#define CLOCK 10
#define STORE 9
#define VRX A1
#define VRY A0
#define BUTTON 6

Button button(BUTTON);

Matrices matricesManager(DATA, CLOCK, STORE);

Joystick joystick(VRX, VRY);

int picGreen[2][8] = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0}},
    picRed[2][8] = {{0,0,0,0,0,0,0,1}, {0,0,0,0,0,0,0,0}},
    posx = 0, posy = 7, valx[] = {1,2,4,8,16,32,64,128,1,2,4,8,16,32,64,128};
unsigned long total_time = 0, interval = 250, previous_time = 0;

void restart()
{
   for (int i = 0; i < 8; i++) {
      picGreen[0][i] = 0;
      picGreen[1][i] = 0;
      picRed[0][i] = 0;
      picRed[1][i] = 0;
   }

   picGreen[0][7] = 1;
   picRed[0][7] = 1;
   posx = 0; posy = 7;
}

void setup() { pinMode(DATA,OUTPUT); pinMode(CLOCK,OUTPUT); pinMode(STORE,OUTPUT); Serial.begin(9600); pinMode(BUTTON, INPUT); }

void loop() {
  button.update();
  while(button.getStart()){
    for (int i = 0; i < 8; i++) {
      shiftOut(DATA, CLOCK, LSBFIRST, ~picGreen[0][i]);
      shiftOut(DATA, CLOCK, LSBFIRST, ~picRed[0][i]);
      shiftOut(DATA, CLOCK, LSBFIRST, ~picGreen[1][i]);
      shiftOut(DATA, CLOCK, LSBFIRST, ~picRed[1][i]);
      shiftOut(DATA, CLOCK, LSBFIRST, 128 >> i);
      matricesManager.retainInfo();
    }

    total_time = millis();
    if (total_time-previous_time>interval) {
      char dir = joystick.getInput();
      previous_time = total_time;
      //Serial.println((int)dir);
      // Serial.print("Y = ");
      //Serial.println(posy);
      // Serial.print("X = ");
      // Serial.println(posx);
      if (dir == 'w') {
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posy = (posy - 1 + 8) % 8;
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
        //previous_time = total_time;
      } else if (dir == 's') {
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posy = (posy + 1) % 8;
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
        //previous_time = total_time;
      } else if (dir == 'a') {
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posx = (posx + 1) % 16;
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
      } else if (dir == 'd') {
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posx = (posx - 1 + 16) % 16;
        picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
      }
      
    }
    button.update();
  }
  restart();
}

/*
#define DATA 8
#define CLOCK 10
#define REGISTRO 9

int picGreen[] = {0,96,96,24,24,0,0,0}, picRed[] = {0,0,0,24,24,6,6,0};
unsigned long total_time = 0, interval = 1000, previous_time = 0;
int currentRed = 5;
 
void registrar() {
  digitalWrite(REGISTRO, HIGH);
  delayMicroseconds(10); // Talvez tenhamos que mudar essa função no futuro pq ela pausa o programa completamente
  digitalWrite(REGISTRO, LOW);
  delayMicroseconds(10);
}

void setup() { pinMode(DATA,OUTPUT); pinMode(CLOCK,OUTPUT); pinMode(REGISTRO,OUTPUT); }

void loop() {
  for (int i = 0; i < 8; i++) {
    shiftOut(DATA, CLOCK, LSBFIRST, ~picGreen[i]);
    shiftOut(DATA, CLOCK, LSBFIRST, ~picRed[i]);
    shiftOut(DATA, CLOCK, LSBFIRST, 128 >> i);
    registrar();
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
*/