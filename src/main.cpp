#include "Game.h"

// millis para movimento de personagens
// fazer paredes existirem
// pensar em fazer classe cenário
// testar as coisa nas matrizes
// separar as coisas em pastas

void setup()
{
  //Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  Game game;
  game.start();
}