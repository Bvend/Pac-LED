#include "Ent.h"

Ent::Ent():
id(-1) 
{
}

Ent::~Ent()
{

}

void Ent::setPosition(int posx, int posy)
{
    this->posx = posx;
    this->posy = posy;
}
