#include "Characters/Character.h"

Character::Character():
posx(0),
posy(0),
id(0),
movementDirection('0'),
moved(false),
movCooldown(0),
lastCooldown(0)
{ 
}

Character::~Character()
{
}

int Character::getPositionX()
{
    return posx;
}

int Character::getPositionY()
{
    return posy;
}

void Character::setPosition(int posy, int posx)
{
    this->posx = posx; this->posy = posy;
}

int Character::getId()
{
    return id;
}

char Character::getMovementDirection()
{
    return movementDirection;
}

void Character::setMovementDirection(char movementDirection)
{
    this->movementDirection = movementDirection;
}

void Character::setMoved(bool moved)
{
    this->moved = moved;
}

bool Character::getMoved()
{
    return moved;
}