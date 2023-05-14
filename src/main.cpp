#include "Game.h"

// millis para movimento de personagens
// fazer paredes existirem
// pensar em fazer classe cenário
// testar as coisa nas matrizes
// separar as coisas em pastas

void setup() { 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  Game game;
  game.start();
  /*
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
      //Serial.println((int)dir);ss
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
  */
}