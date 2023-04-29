#include "Game.h"

Game::Game() :
matrices(DATA, CLOCK, STORE),
button(BUTTON)
{
    listEnt.push(&player);
}

Game::~Game() {}

void Game::mainLoop()
{
    
}
