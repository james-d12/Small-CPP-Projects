#include "Entity.h"

Entity::Entity(){}
Entity::Entity(std::string name, float health, unsigned int inventSize)
{
    this->name = name;
    this->health = health;
    inventory.create(inventSize);
}
Entity::~Entity(){}

std::string Entity::getName() const { return name;}
float Entity::getHealth() const { return health;}
float Entity::getDamage() const { return damage;}
float Entity::getDamageMult() const { return damageMult;}
int Entity::getLevel() const { return level;}

void Entity::printInventory() const 
{
    inventory.print();
}
bool Entity::isAlive() const { return ( health > 0) ? true : false;}
void Entity::addHealth(float health) { this->health += health;}

void Entity::setName(std::string name) { this->name = name;}