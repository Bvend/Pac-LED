#include "Characters/Character.h"

Character::Character():
movementDirection('0'),
moved(false),
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

void Character::setMoved(bool moved)
{
    this->moved = moved;
}

bool Character::getMoved()
{
    return moved;
}