#include "Scenery.h"

char Scenery::scenery[16][32] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                                 {0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
                                 {0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1},
                                 {0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                                 {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0},
                                 {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
                                 {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0},
                                 {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
                                 {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0},
                                 {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                                 {0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1},
                                 {0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                                 {1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0}};

char Scenery::cherryPosy[17] = {0,0,14,14,2,12,10,2,12,6,8,6,8,4,10,4,10};

char Scenery::cherryPosx[17] = {0,28,28,0,14,14,20,8,8,30,30,12,16,26,26,2,2};

int Scenery::totalNumCherrys = 17;

int Scenery::currentNumCherrys = 17;

void Scenery::initializeScenery() { 
    for (int i = 0; i < totalNumCherrys; i++) scenery[(int)cherryPosy[i]][(int)cherryPosx[i]] = 2;
    currentNumCherrys = 17;
}

char Scenery::getCherryPosy(int index) { return cherryPosy[index]; }

char Scenery::getCherryPosx(int index) { return cherryPosx[index]; }

bool Scenery::checkWall(int posy, int posx) { return (scenery[posy][posx] == 1); }

void Scenery::eatCherry(int posy, int posx) { scenery[posy][posx] = 0; currentNumCherrys--; }

bool Scenery::checkCherry(int posy, int posx) { return (scenery[posy][posx] == 2); }

int Scenery::getTotalNumCherrys() { return totalNumCherrys; }

int Scenery::getCurrentNumCherrys() { return currentNumCherrys; }

Scenery::~Scenery()
{
}
