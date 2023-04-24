#include "Game.h"

Game::Game() :
matrices(DATA, CLOCK, STORE),
button(BUTTON)
{
    Ent::setMatrices(&matrices);
}

Game::~Game() {}

void Game::mainLoop()
{
    
}
