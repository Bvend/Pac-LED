#include "Game.h"

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  //randomSeed(analogRead(2));
}

void loop()
{
  Game game;
  game.gameLoop();
}