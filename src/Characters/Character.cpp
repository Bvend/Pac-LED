#include "Characters/Character.h"

Character::Character():
movementDirection('0'),
collided(false),
movCooldown(0),
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

void Character::setMovementDirection(char movementDirection)
{
    this->movementDirection = movementDirection;
}

void Character::setCollided(bool collided)
{
    this->collided = collided;
}

bool Character::getCollided()
{
    return collided;
}