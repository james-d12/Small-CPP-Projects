#ifndef _PLAYER_H
#define _PLAYER_H

#include <math.h>

#include "../Item/Weapon.h"
#include "../Item/Armor.h"

#include "Entity.h"

class Player : public Entity
{
    private:
    const int maxLevel = 100;

    float carryingCapacity = 100;
    float damageMult;
    float experience;
    float experienceNext;
    Weapon equippedWeapon;
    Armor equippedArmor;

    public:
    Player(std::string name,float health, unsigned int inventSize,
    Weapon& weapon,Armor& armor);
    ~Player();

    float getExperience() const;
    float getExperienceNext() const;
    int getArmorRating() const;
    float getDamage() const;
    Weapon getWeapon() const;
    Armor getArmor() const;

    void equipWeapon(Weapon&);
    void equipArmor(Armor&);
    void addExperience(float experience);
    void removeExperience(float experience);
    void addItem(Item& item);
    void removeItem(Item& item);
    void takeDamage(float damage) override;

    void levelUp();
    void print() const override;

};

#endif