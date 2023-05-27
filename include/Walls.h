#pragma once
class Collision;

class Walls {
private:
    static int wallsMap[16][32];
public:
    Walls();
    ~Walls();
    static bool checkWall(int posy, int posx);
};