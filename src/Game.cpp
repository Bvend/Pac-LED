#include "Game.h"
#include "Element.h"

Game::Game() :
matrices(DATA, CLOCK, STORE, &listEnt),
button(BUTTON)
{
    listEnt.push(&player);
}

Game::~Game() {}

void Game::mainLoop()
{
    updateEnt();
    
}

void Game::updateEnt()
{
    Element<Ent>* pElemEnt = listEnt.getPrimeiro();
    for (int i = 0; i < listEnt.getAmount(); i++) {
        pElemEnt->getItem()->update();
        pElemEnt = pElemEnt->getProx();
    }   
}
