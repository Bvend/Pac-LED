#include "Game.h"

unsigned long Game::totalGameTime = 0;

unsigned long Game::getTotalTime()
{
    return totalGameTime;
}

void Game::updateTotalTime()
{
    totalGameTime = millis();
}

Game::Game():
button(BUTTON),
player(),
goodCop(),
badCop(),
vinDiesel(),
ghostList(),
matrices(DATA, CLOCK, STORE, &player, &ghostList),
collider(&player, &ghostList),
level(0)
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
            matrices.transtitionAnimation(true, 8);
            initializeGame();
            level = 0;
            while (button.getStart()) { 
                runGame();
                button.update();
                if (!Scenery::getCurrentNumCherrys()) {
                    matrices.transtitionAnimation(true, level+1);
                    level++;
                    if (level > 7) button.setStart(false);
                    else { endGame(); initializeGame(); }   
                }
                else if (!player.getAlive()) {
                    button.setStart(false);
                    matrices.transtitionAnimation(false, 8);
                }
            }
            delay(500);
            endGame();
        }
    }
}

void Game::initializeGame()
{
    Ghost::setPlayer(&player);
    Scenery::initializeScenery();
    player.initialize();
    updateTotalTime();

    ghostList.push(&goodCop);
    ghostList.push(&badCop);

    goodCop.initialize(6, 8, 800 - 20 * level, 5000 + 500 * level, 10000 - 750 * level);
    badCop.initialize(8, 8, 700 - 30 * level, 6000 + 500 * level, 9000 - 1000 * level);

    if (level >= 6) {
        vinDiesel.initialize(4, 8, 600 - 100 * (level - 6), 8000 + 2000 * (level - 6), 6000 - 2000 * (level - 6));
        ghostList.push(&vinDiesel);
    }

    unsigned long animationTime = 1000;
    unsigned long initialTime = totalGameTime;
    while (totalGameTime - initialTime < animationTime) { matrices.updateMatrices(); updateTotalTime(); }
}

void Game::endGame()
{
    matrices.reset();
    ghostList.clear();
}

void Game::runGame()
{
    updateCha();
    collider.checkCollisions();
    matrices.updateMatrices();
}

void Game::updateCha()
{
    updateTotalTime();
    player.update();
    Element<Character> *pElemGhost = ghostList.getFirst();
    for (int i = 0; i < ghostList.getAmount(); i++)
    {
        pElemGhost->getItem()->update();
        pElemGhost = pElemGhost->getNext();
    }
}
