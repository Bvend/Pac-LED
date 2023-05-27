#include "Ent.h"

Ent::Ent(int posy, int posx, int id):
posx(posx),
posy(posy),
id(id)
{
}

Ent::~Ent()
{
}

int Ent::getPositionX()
{
    return posx;
}

int Ent::getPositionY()
{
    return posy;
}

void Ent::setPosition(int posy, int posx)
{
    this->posx = posx; this->posy = posy;
}

int Ent::getId()
{
    return id;
}
