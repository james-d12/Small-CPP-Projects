#ifndef _ENTITY_H
#define _ENTITY_H

#include <iostream>
#include <string>

#include "../Item/Inventory.h"

class Entity
{
    protected:
    std::string name;
    float health;
    float damage;
    float damageMult;
    int level;
    Inventory inventory;

    Entity();
    Entity(std::string name, float health, unsigned int inventSize);
    virtual ~Entity();

    public:

    std::string getName() const;
    float getHealth() const;
    float getDamage() const;
    float getDamageMult() const;
    int getLevel() const;

    void setName(std::string name);
    
    void printInventory() const;
    bool isAlive() const;
    void addHealth(float health);

    virtual void print() const = 0;
    virtual void addItem(Item& item) = 0;
    virtual void takeDamage(float damage) = 0;

};

#endif