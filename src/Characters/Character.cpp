#include "Characters/Character.h"

Character::Character():
movementDirection('0'),
collided(false),
lastCooldown(0)
{ 
}

Character::~Character()
{
}

char Character::getMovementDirection()
{
    return movementDirection;
}

void Character::setCollided(bool collided)
{
    this->collided = collided;
}

bool Character::getCollided()
{
    return collided;
}