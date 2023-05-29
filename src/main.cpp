#include "Game.h"

void setup()
{
  randomSeed(analogRead(2));
}

void loop()
{
  Game game;
  game.gameLoop();
}