#pragma once
class Collision;

class Walls {
private:
    static int scenery[16][32], cherryPosy[9], cherryPosx[9];
    static int numCherrys;
public:
    static void initializeScenery();
    static int getCherryPosy(int index);
    static int getCherryPosx(int index);
    static bool checkWall(int posy, int posx);
    static void eatCherry(int posy, int posx);
    static bool checkCherry(int posy, int posx);
    static int getNumCherrys();
    ~Walls();
};