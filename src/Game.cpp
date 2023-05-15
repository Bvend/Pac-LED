#include "Game.h"
#include "List/Element.h"
#include <MemoryFree.h>
#include <pgmStrToRAM.h>

unsigned long Game::totalGameTime = 0;

unsigned long Game::getTotalTime()
{
    return totalGameTime;
}

Game::Game():
matrices(DATA, CLOCK, STORE, &listCha),
button(BUTTON),
pPlayer(NULL),
walls(),
collider(&walls, &listCha)
{
}

Game::~Game()
{
}

void Game::runGame()
{
    while (true)
    {
        button.update();
        if (button.getStart())
        {
            delay(500);
            initializeGame();
            while (button.getStart()) { mainLoop(); button.update(); }
            delay(500);
            endGame();
        }
    }
}

void Game::initializeGame()
{
    pPlayer = new Player();
    listEnt.push(pPlayer);
    listCha.push(pPlayer);
}

void Game::endGame()
{
    listCha.clear();
    listEnt.clearAndDelete();
    pPlayer = NULL;
    matrices.reset();
}

void Game::mainLoop()
{
    updateCha();
    collider.checkCollisions();
    matrices.updateMatrices();
}

void Game::updateCha()
{
    Element<Character> *pElemCha = listCha.getPrimeiro();
    totalGameTime = millis();
    for (int i = 0; i < listCha.getAmount(); i++)
    {
        pElemCha->getItem()->update();
        pElemCha = pElemCha->getProx();
    }
}
