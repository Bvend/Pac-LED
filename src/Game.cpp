#include "Game.h"
#include "Element.h"

Game::Game() :
matrices(DATA, CLOCK, STORE, &listEnt),
button(BUTTON)
{
}

Game::~Game() {}

void Game::start()
{
    button.update();
    if (button.getStart()) {
        initialize();
        while(!button.getStart()) mainLoop();
        endGame();
    }
}

void Game::initialize()
{
    pPlayer = new Player();
    listEnt.push(pPlayer);
    listCha.push(pPlayer);
}

void Game::endGame()
{
    listCha.clear();
    Element<Ent>* pElem = listEnt.getPrimeiro();
    while (listEnt.getAmount()) {
        listEnt.pop(pElem->getItem());
        delete pElem->getItem();
        pElem = listEnt.getPrimeiro();
    }
}

void Game::mainLoop()
{
    updateEnt();
    collider.checkCollisions();
    matrices.updateMatrices();
}

void Game::updateEnt()
{
    Element<Ent>* pElemEnt = listEnt.getPrimeiro();
    for (int i = 0; i < listEnt.getAmount(); i++) {
        pElemEnt->getItem()->update();
        pElemEnt = pElemEnt->getProx();
    }   
}
