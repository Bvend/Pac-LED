#include "Game.h"
#include "Element.h"
#include <MemoryFree.h>
#include <pgmStrToRAM.h>

unsigned long Game::totalGameTime = 0;

unsigned long Game::getTotalTime()
{
    return totalGameTime;
}

Game::Game() : matrices(DATA, CLOCK, STORE, &listEnt),
button(BUTTON),
pPlayer(NULL),
gameBoard(),
collider(&gameBoard, &listEnt, &listCha)
{
}

Game::~Game()
{
}

void Game::start()
{
    while (true)
    {
        button.update();
        if (button.getStart())
        {
            delay(1000);
            initialize();
            while (button.getStart()) { mainLoop(); button.update(); }
            delay(1000);
            endGame();
        }
    }
}

void Game::initialize()
{
    pPlayer = new Player();
    listEnt.push(pPlayer);
    listCha.push(pPlayer);

    int walls[58][2] = {{2,2},{2,4},{1,8},{1,12},{2,13},{3,14},{2,15},{0,15},{1,18},{1,20},
                        {1,22},{0,23},{2,19},{2,26},{2,28},{5,0},{5,2},{5,4},{7,0},{7,2},
                        {7,4},{9,0},{9,2},{9,4},{5,8},{6,7},{8,7},{4,10},{6,10},{8,10},
                        {10,10},{6,14},{8,14},{5,30},{5,28},{5,26},{7,30},{7,28},{7,26},
                        {9,30},{9,28},{9,26},{12,2},{12,4},{13,8},{13,12},{11,14},{12,13},
                        {12, 15},{14,15},{13,18},{13,20},{13,22},{12,19},{14,23},
                        {12,28},{12,26}};
    //for (int i = 0; i < 5; i++) {
    //    wallArray[i].setPosition(walls[i][1], walls[i][0]);
    //    listEnt.push(&wallArray[i]);
    //}
    //for (auto &it : walls) listEnt.push(new Wall(it[0], it[1]));
    //Wall* pWall = NULL;
    //for (int i = 0; i < 9; i++) {
    //    pWall = new Wall(walls[i][0], walls[i][1]);
    //    listEnt.push(pWall);
    //    pWall = NULL;
    //}
    //collider.emptyBoard();
    //collider.fillBoard();
}

void Game::endGame()
{
    listCha.clear();
    //listEnt.clear();
    listEnt.clearAndDelete();
    //delete pPlayer;
    pPlayer = NULL;
    matrices.reset();
    //collider.emptyBoard();
}

void Game::mainLoop()
{
    //Serial.println(freeMemory());
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
