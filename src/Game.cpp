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
player(),
goodCop(),
badCop(),
//coop(),
walls(),
collider(&player)
{
}

Game::~Game()
{
}

void Game::gameLoop()
{
    while (true)
    {
        button.update();
        if (button.getStart())
        {
            delay(500);
            initializeGame();
            while (button.getStart()) { runGame(); button.update(); }
            delay(500);
            endGame();
        }
    }
}

void Game::initializeGame()
{
    //digitalWrite(LED_BUILTIN, HIGH);
    totalGameTime = millis();
    Ghost::setPlayer(&player);
    player.initialize();
    goodCop.initialize(6, 8, 500, 5000, 10000);
    badCop.initialize(8, 8, 400, 10000, 5000);
    //coop.initialize(10, 8, 400, 10000, 5000);
    listCha.push(&player);
    listCha.push(&goodCop);
    listCha.push(&badCop);
    //listCha.push(&coop);
}

void Game::endGame()
{
    listCha.clear();
    matrices.reset();
}

void Game::runGame()
{
    updateCha();
    collider.checkCollisions();
    matrices.updateMatrices();
    //updateMatrices();
}

void Game::updateCha()
{
    totalGameTime = millis();
    player.update();
    goodCop.update();
    badCop.update();
    //coop.update();
    //Element<Character> *pElemCha = listCha.getPrimeiro();
    //for (int i = 0; i < listCha.getAmount(); i++)
    //{
    //    pElemCha->getItem()->update();
    //    pElemCha = pElemCha->getProx();
    //}
}

void Game::updateMatrices()
{
    matrices.empty();
    matrices.updatePic(player.getPositionY(), player.getPositionX(), player.getId());
    //matrices.updatePic(goodCop.getPositionY(), goodCop.getPositionX(), goodCop.getId());
    matrices.draw();
}
