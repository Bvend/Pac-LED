#pragma once

class Scenery {
private:
    static char scenery[16][32], cherryPosy[17], cherryPosx[17];
    static int totalNumCherrys, currentNumCherrys;
public:
    static void initializeScenery();
    static char getCherryPosy(int index);
    static char getCherryPosx(int index);
    static bool checkWall(int posy, int posx);
    static void eatCherry(int posy, int posx);
    static bool checkCherry(int posy, int posx);
    static int getTotalNumCherrys();
    static int getCurrentNumCherrys();
    ~Scenery();
};