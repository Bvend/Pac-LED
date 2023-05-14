#include "Game.h"
#include "Element.h"

unsigned long Game::totalGameTime = 0;

unsigned long Game::getTotalTime() { return totalGameTime; }

Game::Game() :
matrices(DATA, CLOCK, STORE, &listEnt),
button(BUTTON),
pPlayer(NULL),
collider(&listEnt, &listCha)
{
}

Game::~Game() {}

void Game::start()
{
    while(true) {
        button.update();
        if (button.getStart()) {
            initialize();
            while(!button.getStart()) mainLoop();
            endGame();
        }
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
    pPlayer = NULL;
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
    totalGameTime = millis();
    for (int i = 0; i < listEnt.getAmount(); i++) {
        pElemEnt->getItem()->update();
        pElemEnt = pElemEnt->getProx();
    }   
}
