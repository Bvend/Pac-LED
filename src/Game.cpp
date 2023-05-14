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
    //matrices.reset();
    while(true) {
        button.update();
        if (button.getStart()) {
            delay(1000);
            //Serial.println("yay");
            initialize();
            while(button.getStart()) { mainLoop(); button.update();  }
            delay(1000);
            endGame();
            //Serial.println("yay2");
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
    listEnt.clear();
    pPlayer = NULL;
    matrices.reset();
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
