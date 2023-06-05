#include "Characters/Ghost.h"
#include "Game.h"

Player* Ghost::pPlayer = NULL;

void Ghost::setPlayer(Player* player) { pPlayer = player; }

Ghost::Ghost(int atackMod, int posy, int posx, unsigned long atackTime, unsigned long scatterTime):
atackTime(atackTime),
scatterTime(scatterTime),
lastModeChange(0),
currentMode(0),
targety(0),
targetx(0),
distFromTarget(0),
atackMod(atackMod)
{
    id = GHOST;
    moved = true;
    this->posy = posy;
    this->posx = posx;
}

Ghost::~Ghost()
{
}

void Ghost::initialize(int posy, int posx, unsigned long cooldown, unsigned long atackTime, unsigned long scatterTime)
{
    this->atackTime = atackTime;
    this->scatterTime = scatterTime;
    this->posy = posy;
    this->posx = posx;
    movCooldown = cooldown;
    movementDirection = 's';
    targety = posy;
    targetx = posx; 
    distFromTarget = 0;
    currentMode = 0;
    lastCooldown = Game::getTotalTime();
    moved = false;
}

void Ghost::setTimes(unsigned long atackTime, unsigned long scatterTime)
{
    this->atackTime = atackTime;
    this->scatterTime = scatterTime;
}

int Ghost::calculateDistance(int posy1, int posx1, int posy2, int posx2)
{   
    return (int)sqrt((posx1-posx2)*(posx1-posx2) + (posy1-posy2)*(posy1-posy2));
}

void Ghost::updateMode(unsigned int totalTime)
{
    if (currentMode == 0 && totalTime - lastModeChange > scatterTime) {
        lastModeChange = totalTime;
        currentMode = 1;
    }
    else if (currentMode == 1 && totalTime - lastModeChange > atackTime) {
        targety = random(0, 15); targetx = random(0, 30);
        lastModeChange = totalTime;
        currentMode = 0;
        scatterTime = max(2000, scatterTime-1000);
    }
}

void Ghost::move()
{
    int minDist = 1000;
    int futurePosx = posx, futurePosy = posy;
    char movArray[4];
    int dir;
    movArray[0] = 'w'; movArray[1] = 'a'; movArray[2] = 's'; movArray[3] = 'd';

    for (int i = 0; i < 4; i++) {
        char it = movArray[i];
        int evenPosx = posx, oddPosx = posx, evenPosy = posy, oddPosy = posy;

        if (it == 'w' && movementDirection != 's') { oddPosy = (posy - 1 + 16) % 16; evenPosy = (posy - 2 + 16) % 16; }
        else if (it == 's' && movementDirection != 'w') { oddPosy = (posy + 1) % 16; evenPosy = (posy + 2) % 16; }
        else if (it == 'a' && movementDirection != 'd') { oddPosx = (posx + 1) % 32; evenPosx = (posx + 2) % 32; }
        else if (it == 'd' && movementDirection != 'a') { oddPosx = (posx - 1 + 32) % 32; evenPosx = (posx - 2 + 32) % 32; }

        if (!Scenery::checkWall(oddPosy, oddPosx) && !Scenery::checkWall(evenPosy, evenPosx)
            && !(evenPosx == posx && evenPosy == posy)) {
            int dist = calculateDistance(evenPosy, evenPosx, targety, targetx);
            if (dist < minDist) {
                futurePosx = evenPosx; futurePosy = evenPosy;
                minDist = dist;
                dir = it;
            }
        }
    }

    if (futurePosx == posx && futurePosy == posy) movementDirection = '0';
    else {
        distFromTarget = minDist;
        posy = futurePosy; posx = futurePosx;
        movementDirection = dir;
    }
}

void Ghost::update()
{
    unsigned long totalTime = Game::getTotalTime();
    updateMode(totalTime);
    if (totalTime - lastCooldown > movCooldown) {
        lastCooldown = totalTime;
        if (currentMode == 0) {
            if (distFromTarget <= 1) {
                targety = random(0, 15); targetx = random(0, 30);
            }
        }
        else {
            targety = pPlayer->getPositionY(); targetx = pPlayer->getPositionX();
            int dir = pPlayer->getPrevMovementDirection();
            if (dir == 'w') targety = targety - atackMod;
            else if (dir == 's') targety = targety + atackMod;
            else if (dir == 'a') targetx = targetx + atackMod;
            else if (dir == 'd') targetx = targetx - atackMod;
        }
        move();
    }
}
